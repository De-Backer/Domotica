/*
 * Copyright (c) 2014 Simon De Backer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/* info van de status (hoe ver staat het project)
 * doel:de usb com met spi en meerde slave werkent krijgen.
 *
 * - de ingangen: WERKT
 *      PINA en PORTC worden gebruikt
 *      in matrix configuration
 *      geeft de pin nr en stand weer
 *
 * - de uitgangen: WERKT met opm.
 *      PORTB en PORTD worden gebruikt (niet alle pinnen)
 *      in Charlieplexing
 *      opm:    de tijd AAN moet nog gedaan worden.
 *              is min 50msec tot 1sec
 *
 *              SPDT PCB Mount Latching Relay, 12V dc     RT314A12
 *              Min./Max. energization duration 30ms/1min at <10% duty factor
 *
 * - de SPI com: WERKT met opm. geeft nog bugs!!
 *      PORTB word gebruikt (niet alle pinnen)
 *      slave naar master werkt (met feedback).
 *      opm: com master naar slave nog niet.
 *           20141231: nu wel maar als men meer dan 1 slave gebrukt dan valt de usb com uit!
 *
 *      opm: als de com verstoort word dan stopt alles, moet opgelost worden!!
 *           20141231: was fout hartware. de SS pin was niet met de master verbonden
 *
 *      opm: 20141231: de usb com valt uit als meer dan 1 slave gebrukt word bij de master
 *      20150101: de code herschreven werkt nu.
 *
 *
 * - de ring buffer:WERKT met opm.
 *      is voor de SPI com slave naar master gebruikt en werkt
 *      opm:    in de omgekeerde richting master naar slave nog te doen.
 *              eerst de SPI com bugs oplossen!!
 *
 * - de PWM uitgangen: tba
 *      de pinen zijn:PB3(OC0A),PD5(OC1A),PD7(OC2A)
 *
 * -de koppeling in en uit-gangen: tba
 *      gebruik van SRAM en EEPROM
 *      de manier moet nog bepaalt worden
 *
*/

/* de in/uit-gangen verbinen: 1
 * -1 un arraje van 32*3
 * de 32 zijn de ingangen
 * de 3 zijn de uitgangen en funksie
 * voorbeelt:
 * Byte 0: funksie
 * Byte 1 en 2: uitgang
 *  Byte 1 bit 0 = uitgang 1
 *  Byte 1 bit 1 = uitgang 2
 *  Byte 1 bit 2 = uitgang 3
 *  Byte 1 bit 3 = uitgang 4
 *  Byte 1 bit 4 = uitgang 5
 *  Byte 1 bit 5 = uitgang 6
 *  Byte 1 bit 6 = uitgang 7
 *  Byte 1 bit 7 = uitgang 8
 *  Byte 2 bit 0 = uitgang 9
 *  Byte 2 bit 1 = uitgang 10
 *  Byte 2 bit 2 = uitgang 11
 *  Byte 2 bit 3 = uitgang 12
 *  Byte 2 bit 4 = uitgang PWM 0
 *  Byte 2 bit 5 = uitgang PWM 1
 *  Byte 2 bit 6 = uitgang PWM 2
 *  Byte 2 bit 7 = NC
 * {toggel},{0b010010010},{00001000}
 * is toggel de uitgangen 2,5,8,12
 **/
/* de in/uit-gangen verbinen: 2
 * -1 un arraje van max 500 Byte
 * voorbeelt:
 * - uitgang
 *
 * Byte 0: funksie [uitgang]
 * Byte 1: Slaves [S7,S6,S5,S4,S3,S2,S1,S0]
 * Byte 2 en 3: uitgang Slaves [S0]
 * kan oplopen tot 17 Byte (18 Byte tot)
 * Byte 4 en 5:
 * Byte 6 en 7:
 * Byte 8 en 9:
 * Byte 10 en 11:
 * Byte 12 en 13:
 * Byte 14 en 15:
 * Byte 16 en 17:
 *
 * -PWM
 * Byte 0: funksie [PWM] (on, up, down, off, on-down, off-up)
 * Byte 1: Slaves [S7,S6,S5,S4,S3,S2,S1,S0]
 * Byte 2: PWM_uitgang Slaves [S0]
 * kan oplopen tot 9 Byte (10 Byte tot)
 *
 * -NC
 * Byte 0: funksie [NC]
 *
 * max numbers:
 * 32 ingangen
 *  -18 Byte uitgang
 *  -10 Byte PWM_uitgang
 *  -1  Byte NC
 * => 32*18=576 Byte=> overflow ATMEGA8535 !!!!
 *
 **/
/* info Bit manipulation
 * | bit OR
 * 0 OR 0 = 0
 * 0 OR 1 = 1
 * 1 OR 0 = 1
 * 1 OR 1 = 1
 *
 * & bit AND
 * 0 AND 0 = 0
 * 0 AND 1 = 0
 * 1 AND 0 = 0
 * 1 AND 1 = 1
 *
 * ~ bit NOT
 * 0 NOT = 1
 * 1 NOT = 0
 *
 * ^ bit EXLUSIVE OR (XOR)
 * 0 XOR 0 = 0
 * 0 XOR 1 = 1
 * 1 XOR 0 = 1
 * 1 XOR 1 = 0
 *
 * << bit LEFT SHIFT
 * >> bit RIGHT SHIFT
 *
 * all de ander zoals NAND NOR NXOR zijn 2 instruksis.
 * bv:
 * NOR:  a = ~(b|c);
 * 0 NOR 0 = 1
 * 0 NOR 1 = 0
 * 1 NOR 0 = 0
 * 1 NOR 1 = 0
 *
 * NXOR:  a = ~(b^c);
 * 0 NXOR 0 = 1
 * 0 NXOR 1 = 0
 * 1 NXOR 0 = 0
 * 1 NXOR 1 = 1
 *
 * NAND:  a = ~(b&c);
 * 0 NAND 0 = 1
 * 0 NAND 1 = 1
 * 1 NAND 0 = 1
 * 1 NAND 1 = 0
 *
 *
 *
 **/
/* is nog niet ok uitgang reageert op ingang
 * niewe idee: als de leds 1collom later staan dan kan de feedbak simpeler
 * bv.:
 * als 0,1,2,3 en 12,13,14,15 de ingang is dan is
 * 49,50,51,48 en 61,62,63,60
 * ====> de prindplaat moet aangepast worden!!!!
 * ====> de software van de µc zal de stand van de ingangen moeten bijhouden!
 * ====> 0==49 ipv 48
 * ====> software code:
 * uint8_t PINA_ex=(PINA<<4);
 * PORTA = 0b11111111;            // pul-up en Vcc
 * PORTC = 0b00000000;            // massa
 * DDRA  = 0b11110000             // LED en µcswits
 *
 * DDRC &=~(0b11111111);          // 1111 1111  1111 XXXX Tri-state
 * DDRC |=(0b10000000>>0);        // 1111 1111  0111 XXXX 1 Pin output massa
 * PINA_ex=((PINA<<4)|0b00001111);// 1111 1111  0111 XXXX sla input op
 * DDRC &=~(0b11111111);          // 1111 1111  1111 XXXX Tri-state
 *
 * PORTA =PINA_ex;                // AAAA 1111  1111 XXXX Port = 0bXXXX1111 X is de pinA
 * DDRC |=(0b10000000>>1);        // AAAA 1111  1011 XXXX 1 Pin output massa
 * PINA_ex=((PINA<<4)|0b00001111);// AAAA 1111  1011 XXXX sla input op
 * DDRC &=~(0b11111111);          // AAAA 1111  1111 XXXX Tri-state
 * PORTA =PINA_ex;                // BBBB 1111  1111 XXXX Port = 0bXXXX1111 X is de pinA
 * DDRC |=(0b10000000>>2);        // BBBB 1111  1101 XXXX 1 Pin output massa
 * PINA_ex=((PINA<<4)|0b00001111);// BBBB 1111  1101 XXXX sla input op
 * DDRC &=~(0b11111111);          // BBBB 1111  1111 XXXX Tri-state
 * PORTA =PINA_ex;                // CCCC 1111  1111 XXXX Port = 0bXXXX1111 X is de pinA
 * DDRC |=(0b10000000>>3);        // CCCC 1111  1110 XXXX 1 Pin output massa
 * PINA_ex=((PINA<<4)|0b00001111);// CCCC 1111  1110 XXXX sla input op
 * DDRC &=~(0b11111111);          // CCCC 1111  1111 XXXX Tri-state
 * PORTA =PINA_ex;                // DDDD 1111  1111 XXXX Port = 0bXXXX1111 X is de pinA
 * DDRC |=(0b10000000>>0);        // DDDD 1111  0111 XXXX 1 Pin output massa
 * PINA_ex=((PINA<<4)|0b00001111);// DDDD 1111  0111 XXXX sla input op
 * DDRC &=~(0b11111111);          // DDDD 1111  1111 XXXX Tri-state
 *
 * ====> voorstel de ingangen en uitgangen metvertraging van 1 siklie laten lopen.
 * bv.:
 * laat pin in
 * sla pin op
 * zet pin
 *
 * //start matrix
 * uint8_t var,matrix_PINA[11];
 * PORTA = 0b11111111;            // pul-up en Vcc
 * PORTC = 0b00000000;            // massa
 * DDRA  = 0b11110000             // LED en µcswits
 * //PortC
 * for (var = 0; var < 7; var++)
 * {
 *      DDRC &=~(0b11111111);                       // 1111 1111  Tri-state
 *      DDRC |=(0b10000000>>var);                   // 1111 1111  1 Pin output massa
 *      matrix_PINA[var]=((PINA<<4)|0b00001111);    // 1111 1111  sla input op
 * }
 * //PORTD
 * for (var = 0; var < 3; var++)
 * {
 *      DDRD &=~(0b11110000);                       // 1111 1111  Tri-state
 *      DDRD |=(0b10000000>>var);                   // 1111 1111  1 Pin output massa
 *      matrix_PINA[var+8]=((PINA<<4)|0b00001111);  // 1111 1111  sla input op
 * }
 * //loop matrix
 * for(;;)
 * {
 *  //PortC
 *  for (var = 0; var < 7; var++)
 *  {
 *      DDRC &=~(0b11111111);                       // 1111 1111  Tri-state
 *      PORTA =matrix_PINA[var];                    // MMMM 1111  zet vorech toestand op
 *      DDRC |=(0b10000000>>var);                   // 1111 1111  1 Pin output massa
 *      matrix_PINA[var]=((PINA<<4)|0b00001111);    // 1111 1111  sla input op
 *  }
 *  //PORTD
 *  for (var = 0; var < 3; var++)
 *  {
 *      DDRD &=~(0b11110000);                       // 1111 1111  1111 XXXX Tri-state
 *      PORTA =matrix_PINA[var];                    // MMMM 1111  zet vorech toestand op
 *      DDRD |=(0b10000000>>var);                   // 1111 1111  0111 XXXX 1 Pin output massa
 *      matrix_PINA[var+8]=((PINA<<4)|0b00001111);    // 1111 1111  0111 XXXX sla input op
 *  }
 * }
 * µc Virtual_pinnen
 *      |------------| |-------------|
 *
 * PA0  0   1   2   3   4   5   6   7   -ingang µswits 1
 * PA1  8   9   10  11  12  13  14  15  -ingang µswits 1
 * PA2  16  17  18  19  20  21  22  23  -ingang µswits 2
 * PA3  24  25  26  27  28  29  30  31  -ingang µswits 2
 *
 * PA4  32  33  34  35  36  37  38  39  -uigang µswits 1
 * PA5  40  41  42  43  44  45  46  47  -uigang µswits 1
 * PA6  48  49  50  51  52  53  54  55  -uigang µswits 2
 * PA7  56  57  58  59  60  61  62  63  -uigang µswits 2
 *
 * PC   7   6   5   4   3   2   1   0
*/
/* de uigangen
 * PB 0 1 2
 * PD 0 1 2 3 4 6
 *
 * PB 0
 *      2                        1  2
 * PB 1    2
 *      2     2                  3  6
 * PB 2    2     2
 *      2     2     2            6 12
 * PD 0    2     2     2
 *      2     2     2     2     10 20
 * PD 1    2     2     2     2
 *      2     2     2     2     16 32
 * PD 2    2     2     2
 *      2     2     2           21 42
 * PD 3    2     2
 *      2     2                 28 56
 * PD 4    2
 *      2                       36 72 => 4 byte * 72 = 248 byte
 * PD 6
 *
 * DDRB = 0b00000111
 * DDRD = 0b01011111
 * de tabel
 *   DDRB      DDRD      uitgang    PORTB     PORTD
 * 0000 0000 0000 0000    0       0000 0000 0000 0000
 * 0000 0000 0000 0011    1       0000 0000 0000 0001
 * 0000 0000 0000 0011    1       0000 0000 0000 0010
 * 0000 0000 0000 0101    2       0000 0000 0000 0001
 * 0000 0000 0000 0101    2       0000 0000 0000 0100
 * 0000 0000 0000 1001    3
 * 0000 0000 0001 0001    4
 * 0000 0000 0100 0001    5
 * 0000 0001 0000 0001    6
 * 0000 0010 0000 0001    7
 * 0000 0100 0000 0001    8
 *                          DDRB DDRD  PORB PORD PORB PORD
 * 0000 0000 0000 0110    9 0x00 0x06  0x00 0x02 0x00 0x04
 * 0000 0000 0000 1010   10 0x00 0x0A  0x00 0x02 0x00 0x08
 * 0000 0000 0001 0010   11 0x00 0x12  0x00 0x02 0x00 0x10
 * 0000 0000 0100 0010   12 0x00 0x42  0x00 0x02 0x00 0x40
 * 0000 0001 0000 0010   13 0x01 0x02  0x00 0x02 0x01 0x00
 * 0000 0010 0000 0010   14 0x02 0x02  0x00 0x02 0x02 0x00
 * 0000 0100 0000 0010   15 0x04 0x02  0x00 0x02 0x04 0x00
 *
 * 0000 0000 0000 1100   16 0x00 0x0C  0x00 0x04 0x00 0x08
 * 0000 0000 0001 0100   17 0x00 0x14  0x00 0x04 0x00 0x10
 * 0000 0000 0100 0100   18 0x00 0x44  0x00 0x04 0x00 0x40
 * 0000 0001 0000 0100   19 0x00 0x04  0x00 0x04 0x01 0x00
 * 0000 0010 0000 0100   20 0x00 0x04  0x00 0x04 0x02 0x00
 * 0000 0100 0000 0100   21 0x00 0x04  0x00 0x04 0x04 0x00
 *
 * 0000 0000 0001 1000   22 0x00 0x18  0x00 0x08 0x00 0x10
 * 0000 0000 0100 1000   23 0x00 0x48  0x00 0x08 0x00 0x40
 * 0000 0001 0000 1000   24 0x01 0x08  0x00 0x08 0x01 0x00
 * 0000 0010 0000 1000   25 0x02 0x08  0x00 0x08 0x02 0x00
 * 0000 0100 0000 1000   26 0x04 0x08  0x00 0x08 0x04 0x00
 *
 * 0000 0000 0101 0000   27 0x00 0x50  0x00 0x10 0x00 0x40
 * 0000 0001 0001 0000   28 0x01 0x10  0x00 0x10 0x01 0x00
 * 0000 0010 0001 0000   29 0x02 0x10  0x00 0x10 0x02 0x00
 * 0000 0100 0001 0000   30 0x04 0x10  0x00 0x10 0x04 0x00
 *
 * 0000 0001 0100 0000   31 0x01 0x40  0x00 0x40 0x01 0x00
 * 0000 0010 0100 0000   32 0x02 0x40  0x00 0x40 0x02 0x00
 * 0000 0100 0100 0000   33 0x04 0x40  0x00 0x40 0x04 0x00
 *
 * 0000 0011 0000 0000   34 0x03 0x00  0x01 0x00 0x02 0x00
 * 0000 0101 0000 0000   35 0x05 0x00  0x01 0x00 0x04 0x00
 *
 * 0000 0110 0000 0000   36 0x06 0x00  0x02 0x00 0x04 0x00
 *
 * PWM:
 * PB 3
 * PD 5 7
 *
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

/* debug **********************************************************************/
/* function that checks Allocated memory to buffer overflow *******************/
#define debug_CAMTBOF
/* debug SPI ******************************************************************/
#define debug_SPI
/*############################################################################*/
/* SPI ************************************************************************/
/* SPI gemeen *****************************************************************/
#define SPI_heartbeat_slave     0xFD /* bevat un nul zodat de master weet dat er gelustert word */
#define SPI_heartbeat_master    0xFF /* maakt niet uit want de master maakt de clock voor de SPI */

#define SPI_slave_zent_start    0xFC /* slave zent start Transfer van de data */
#define SPI_slave_start_data    0xFB /* slave start Transfer van de data */
#define SPI_slave_data          0xFA /* slave stuur de data */
#define SPI_slave_stop_data     0xF9/* slave heeft de data verstuurt */
#define SPI_slave_error         0xF8 /* probeem slave */

#define SPI_master_zent_start   0xF7 /* master start Transfer van de data */
#define SPI_master_start_data   0xF6 /* master start Transfer van de data */
#define SPI_master_data         0xF5 /* master stuur de data */
#define SPI_master_stop_data    0xF4 /* master heeft de data verstuurt */
#define SPI_master_error        0xF3 /* probeem master */

#define SPI_error               0xF2 /* probeem com */

#define SPI_error_massa         0x00 /* de data is 0 */

/* SPI start data byte 0 ******************************************************/
#define SPI_ingang              0x01
#define SPI_uitgang             0x02
#define SPI_status_slave        0x03

#define SPI_set_slave           0x04 /* is voor de in_uit_gangen */

#define SPI_set_in_uit_data     0x05 /* is voor de in_uit_gangen */
#define SPI_get_in_uit_data     0x06 /* is voor de in_uit_gangen */

/* SPI data buffer slave ******************************************************/
#define SPI_max_data_slave      20 /* max data van slave in een keer
                                    * * SPI_ingang:
                                    * {start data byte},{nr_key},      //  2
                                    * {aan/uit}                        //  3
                                    *
                                    * * SPI_uitgang:
                                    * {start data byte},{uitgang}      //  2
                                    *
                                    * * SPI_status_slave:
                                    * {start data byte},{data}         // niet bepaalt!!
                                    *
                                    * * SPI_set_slave:
                                    * {start data byte},{nr_slave}     //  2
                                    *
                                    *
                                    * * SPI_set_in_uit_data:
                                    * {start data byte},{nr_arrei},    //  2
                                    * {funcie},{slave0 byte0},         //  4
                                    * {slave0 byte1},{slave1 byte0},   //  6
                                    * {slave1 byte1},{slave2 byte0},   //  8
                                    * {slave2 byte1},{slave3 byte0},   // 10
                                    * {slave3 byte1},{slave4 byte0},   // 12
                                    * {slave4 byte1},{slave5 byte0},   // 14
                                    * {slave5 byte1},{slave6 byte0},   // 16
                                    * {slave6 byte1},{slave7 byte0},   // 18
                                    * {slave7 byte1}                   // 19
                                    *
                                    * * SPI_get_in_uit_data:
                                    * {start data byte},{nr_arrei}     //  2
                                    *
                                    * */
/*############################################################################*/
#ifdef debug_CAMTBOF
uint16_t CAMTBOF_S(int8_t var)
{
    static uint16_t CAMTBOF_SRAM=0;
    CAMTBOF_SRAM+=var;
    return CAMTBOF_SRAM;

}
uint16_t CAMTBOF_E(int8_t var)
{
    static uint16_t CAMTBOF_EEPROM=0;
    CAMTBOF_EEPROM+=var;
    return CAMTBOF_EEPROM;

}

#endif
uint8_t SPI_status=SPI_heartbeat_slave;
uint8_t SPI_slave_datacont;
uint8_t SPI_received_data_pointor;
uint8_t SPI_received_data[SPI_max_data_slave];

#ifdef debug_CAMTBOF
CAMTBOF_S(4);
CAMTBOF_S(SPI_max_data_slave);
#endif

/* de ring buffer
 * c kk6gm
 * of http://www.avrfreaks.net/forum/circular-buffer-0
 *
 * #define BUF_LEN_BITS 7      // e.g. 128 byte buffer
 * #define BUF_LEN   (1<<BUF_LEN_BITS) //0b1000 0000 0x80
 * #define BUF_MASK (BUF_LEN - 1)  // 0x80-0x01 =0x7F 0b0111 1111
 *
 * #define IS_FULL  (-1)
 * #define IS_EMPTY (-2)
 * #define IS_OK    (0)
 *
 * u8 buffer[BUF_LEN];
 * u8 head = 0;
 * u8 tail = 0;
 * u8 count = 0;
 *
 * int write(u8 val)
 * {
 *   if (count == BUF_LEN)
 *     return IS_FULL;
 *   else
 *   {
 *     buffer[head++] = val;
 *     head &= BUF_MASK;
 *     ++count;
 *     return IS_OK;
 *   }
 * }
 *
 * int read(void)
 * {
 * u8 val;
 *
 *   if (count == 0)
 *     return IS_EMPTY;
 *   else
 *   {
 *     val = buffer[tail++];
 *     tail &= BUF_MASK;
 *     --count;
 *     return val;
 *   }
 * }
 **/
/* com ring buffer:
 * [datacont 1-255]
 * [data 0]
 * [data 1]
 * [data n]
 * [datacont 1-255]
 * [data 0]
 * [data 1]
 * [data 2]
 * [data n]
 * [0x02]
 * [0x10]
 * [0xFC]
 * [0x03]
 * [0xFA]
 * [0xAB]
 * [0x0C]
 *
 * if(datacont==0)error;
 * */
/* voorstel:ring buffer met meer pointor's
 * data gebruik:
 * de ring buffer:0-255byte
 * de pointor    :4byte
 * de count      :2byte
 * data_gebruik = 6 + ring_buffer[0-255] max=261byte min=7byte
 *
 * bv:
 * ring buffer  pointor         info data
 * data         buffer  SPI
 * 00
 * 01           tail            bevat lenkt data
 * 02                   tail        van de SPI gekregen
 * 03
 * 04
 * 05                   head        naar de SPI gezent
 * 06
 * 07
 * 08           head            niewste data
 * 09
 */

#define BUF_LEN_BITS 7      // e.g. 128 byte buffer
#define BUF_LEN   (1<<BUF_LEN_BITS) //0b1000 0000 0x80
#define BUF_MASK (BUF_LEN - 1)  // 0x80-0x01 =0x7F 0b0111 1111

uint8_t ring_buffer_SPI[BUF_LEN];
uint8_t ring_buffer_head_SPI=0;
uint8_t ring_buffer_tail_SPI=0;
uint8_t ring_buffer_count_SPI=0;

uint8_t ring_buffer_zent_SPI=0;
uint8_t ring_buffer_receive_SPI=0;
uint8_t ring_buffer_zent_count_SPI=0;

#ifdef debug_CAMTBOF
CAMTBOF_S(7);
CAMTBOF_S(BUF_LEN);
#endif

#ifdef debug_SPI
uint8_t debug[8];
#ifdef debug_CAMTBOF
CAMTBOF_S(9);
#endif
#endif
// 00 rechts links 1111
//debug[4]=0b00011111;
//debug[5]=0b00011111;
//debug[6]=0b00011111;
//debug[7]=0b00011111;

/* in/uit-gangen **************************************************************/
/* voorstel de in/uit-gangen verbinen
 * -1 un arraje van max 500 Byte
 * funksie
 *  -[uitgang]
 *      Slaves [S7,S6,S5,S4,S3,S2,S1,S0]
 *      Byte 2 en 3: uitgang Slaves [S0]
 *      kan oplopen tot 17 Byte (18 Byte tot)
 *  -[PWM]
 *      Slaves [S7,S6,S5,S4,S3,S2,S1,S0]
 *      Byte 2: PWM_uitgang Slaves [S0]
 *      kan oplopen tot 9 Byte (10 Byte tot)
 *  -NC
 *
 **/

/* memory IN/OUT-PUT_Funksie_ */
#define MIOP_F_NC       0x00 /* doe niets */

#define MIOP_F_OUT_K_ON    0x10 /* zet uitgang aan */
#define MIOP_F_OUT_K_OF    0x11 /* zet uitgang uit */
#define MIOP_F_OUT_K_TOG   0x12 /* zet uitgang toggel */

#define MIOP_F_OUT_L1_ON   0x13 /* zet uitgang aan op L1 */
#define MIOP_F_OUT_L1_OF   0x14 /* zet uitgang uit op L1 */
#define MIOP_F_OUT_L1_TOG  0x15 /* zet uitgang toggel op L1 */

#define MIOP_F_OUT_L2_ON   0x16 /* zet uitgang aan op L2 */
#define MIOP_F_OUT_L2_OF   0x17 /* zet uitgang uit op L2 */
#define MIOP_F_OUT_L2_TOG  0x18 /* zet uitgang toggel op L2 */

#define MIOP_F_OUT_L3_ON   0x19 /* zet uitgang aan op L3 */
#define MIOP_F_OUT_L3_OF   0x1A /* zet uitgang uit op L3 */
#define MIOP_F_OUT_L3_TOG  0x1B /* zet uitgang toggel op L3 */

#define MIOP_F_PWM_0    0x20
#define MIOP_F_PWM_1    0x21
#define MIOP_F_PWM_2    0x22
/*
 * ingang is pin nr in
 * uitgang geen
 * verwerking zet uitgang in funsie
 */
uint8_t io_memory_slave(uint8_t slave)
{
    uint8_t var=0;
    if(slave&0b00000001)++var; /* Slave 0 */
    if(slave&0b00000010)++var; /* Slave 1 */
    if(slave&0b00000100)++var; /* Slave 2 */
    if(slave&0b00001000)++var; /* Slave 3 */
    if(slave&0b00010000)++var; /* Slave 4 */
    if(slave&0b00100000)++var; /* Slave 5 */
    if(slave&0b01000000)++var; /* Slave 6 */
    if(slave&0b10000000)++var; /* Slave 7 */
    return var;
}

void io_memory(uint8_t pin_nr)
{
    static uint8_t pin_nr_data[33];
    static uint8_t io_data[200];
    if(pin_nr_data[2]<1)/* test de 2de data moet groter dan 0 zijn ander ...*/
    {
        /* .... de pin_nr_data zijn nog niet gemaakt */
        uint8_t pin_var=0;
        uint8_t var=0;
        for (; (var < 201)&(pin_var<34); ++var) {
            switch (io_data[var]) {
            case MIOP_F_NC:
                pin_nr_data[pin_var++]=var;/* plaats waar de funsie staat */
                break;
            case MIOP_F_OUT_K_ON:
            case MIOP_F_OUT_K_OF:
            case MIOP_F_OUT_K_TOG:
            case MIOP_F_OUT_L1_ON:
            case MIOP_F_OUT_L1_OF:
            case MIOP_F_OUT_L1_TOG:
            case MIOP_F_OUT_L2_ON:
            case MIOP_F_OUT_L2_OF:
            case MIOP_F_OUT_L2_TOG:
            case MIOP_F_OUT_L3_ON:
            case MIOP_F_OUT_L3_OF:
            case MIOP_F_OUT_L3_TOG:
                pin_nr_data[pin_var++]=var;/* plaats waar de funsie staat */
                ++var;
                var += (io_memory_slave(io_data[var]) * 2);        /* slave */
                /* aantal slave 2 byte */
                break;
            case MIOP_F_PWM_0:
            case MIOP_F_PWM_1:
            case MIOP_F_PWM_2:
                pin_nr_data[pin_var++]=var;/* plaats waar de funsie staat */
                ++var;
                var += io_memory_slave(io_data[var]);        /* slave */
                /* aantal slave 1 byte */
                break;
            default:/* onbekend! */
                break;
            }
        }

    }
    switch (io_data[pin_nr_data[pin_nr]]) {
    case MIOP_F_NC:
        break;

    case MIOP_F_OUT_K_ON:

        break;
    case MIOP_F_OUT_K_OF:

        break;
    case MIOP_F_OUT_K_TOG:

        break;

    case MIOP_F_OUT_L1_ON:

        break;
    case MIOP_F_OUT_L1_OF:

        break;
    case MIOP_F_OUT_L1_TOG:

        break;

    case MIOP_F_OUT_L2_ON:

        break;
    case MIOP_F_OUT_L2_OF:

        break;
    case MIOP_F_OUT_L2_TOG:

        break;

    case MIOP_F_OUT_L3_ON:

        break;
    case MIOP_F_OUT_L3_OF:

        break;
    case MIOP_F_OUT_L3_TOG:

        break;

    case MIOP_F_PWM_0:

        break;
    case MIOP_F_PWM_1:

        break;
    case MIOP_F_PWM_2:

        break;
    default:/* onbekend! */
        break;
    }

}

//uint8_t in_uit_data[32][17];
/*[ingang] [funcie/uitgang]
                              *
                              * [ingang]
                              * 0-255 zij de ingangen
                              * 000-031 slave
                              *
                              * [funcie/uitgang]:
                              * funcie
                              *
                              * slave0 byte0
                              * slave0 byte1
                              *
                              * slave1 byte0
                              * slave1 byte1
                              *
                              * slave2 byte0
                              * slave2 byte1
                              *
                              * slave3 byte0
                              * slave3 byte1
                              *
                              * slave4 byte0
                              * slave4 byte1
                              *
                              * slave5 byte0
                              * slave5 byte1
                              *
                              * slave6 byte0
                              * slave6 byte1
                              *
                              * slave7 byte0
                              * slave7 byte1
                              *_________________________
                              *
                              * funcie: bij de ingang wordt get volgend gedaan
                              * bv:
                              * 000 = OFF
                              * 001 = togel (^)
                              * 002 = PWM_up
                              * 003 = PWM_neer
                              * 004 = PWM_up_ON
                              * 005 = PWM_neer_OFF
                              * ...
                              * 200 = L1_OFF
                              * 201 = L2_OFF
                              * 202 = L3_OFF
                              * 203 = L1_togel (^)
                              * 204 = L2_togel (^)
                              * 205 = L3_togel (^)
                              * 206 = L1_ON
                              * 207 = L2_ON
                              * 208 = L3_ON
                              * ...
                              * 255 = ON
                              *
                              * kan meerder handelingen doen bv: ON-PWM-OFF
                              * puls<1s = togel
                              * puls>1s = start met pwm
                              *           -bij OFF naar ON
                              *           -bij ON naar OFF
                              *
                              * */
//uint8_t slave=255;/* anders weet de µc niet welke byte's voor wie zijn. */
//#ifdef debug_CAMTBOF
//CAMTBOF_S(544);
//CAMTBOF_S(1);
//#endif
/*############################################################################*/

void SPI_buffer_Write(uint8_t var)
{
    if (ring_buffer_count_SPI == BUF_LEN)return;

    ring_buffer_SPI[ring_buffer_head_SPI++]=var;
    ring_buffer_head_SPI &= BUF_MASK;
    ++ring_buffer_count_SPI;
    return;
}

/* uitgang
 * is nog te testen!!
 * */
void set_output(uint8_t uitgang)
{
    #define max_uitgang 72
    #define s_ddr_b 0b00000111
    #define s_ddr_d 0b01011111
    static const uint8_t ddr_b[max_uitgang] =
    {
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x01,0x01, 0x02,0x02, 0x04,0x04,
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x01,0x01, 0x02,0x02, 0x04,0x04,
        0x00,0x00, 0x00,0x00, 0x01,0x01, 0x02,0x02, 0x04,0x04,
        0x00,0x00, 0x01,0x01, 0x02,0x02, 0x04,0x04,
        0x01,0x01, 0x02,0x02, 0x04,0x04,
        0x03,0x03, 0x05,0x05,
        0x06,0x06
};
    static const uint8_t ddr_d[max_uitgang] =
    {
        0x03,0x03, 0x05,0x05, 0x09,0x09, 0x11,0x11, 0x41,0x41, 0x01,0x01, 0x01,0x01, 0x01,0x01,
        0x06,0x06, 0x0A,0x0A, 0x12,0x12, 0x42,0x42, 0x02,0x02, 0x02,0x02, 0x02,0x02,
        0x0C,0x0C, 0x14,0x14, 0x44,0x44, 0x04,0x04, 0x04,0x04, 0x04,0x04,
        0x18,0x18, 0x48,0x48, 0x08,0x08, 0x08,0x08, 0x08,0x08,
        0x50,0x50, 0x10,0x10, 0x10,0x10, 0x10,0x10,
        0x40,0x40, 0x40,0x40, 0x40,0x40,
        0x00,0x00, 0x00,0x00,
        0x00,0x00
};
    static const uint8_t port_b[max_uitgang] =
    {
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x01, 0x00,0x02, 0x00,0x04,
        0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x01, 0x00,0x02, 0x00,0x04,
        0x00,0x00, 0x00,0x00, 0x00,0x01, 0x00,0x02, 0x00,0x04,
        0x00,0x00, 0x00,0x01, 0x00,0x02, 0x00,0x04,
        0x00,0x01, 0x00,0x02, 0x00,0x04,
        0x01,0x02, 0x01,0x04,
        0x02,0x04
};
    static const uint8_t port_d[max_uitgang] =
    {
        0x01,0x02, 0x01,0x04, 0x01,0x08, 0x01,0x10, 0x01,0x40, 0x01,0x00, 0x01,0x00, 0x01,0x00,
        0x02,0x04, 0x02,0x08, 0x02,0x10, 0x02,0x40, 0x02,0x00, 0x02,0x00, 0x02,0x00,
        0x04,0x08, 0x04,0x10, 0x04,0x40, 0x04,0x00, 0x04,0x00, 0x00,0x00,
        0x08,0x10, 0x08,0x40, 0x08,0x00, 0x08,0x00, 0x08,0x00,
        0x10,0x40, 0x10,0x00, 0x10,0x00, 0x10,0x00,
        0x40,0x00, 0x40,0x00, 0x40,0x00,
        0x00,0x00, 0x00,0x00,
        0x00,0x00
};
    /* reset- zet de port op Tri-state of Low */
    PORTB &= ~(s_ddr_b);
    PORTD &= ~(s_ddr_d);
    /* reset- zet de data Direction op Tri-state */
    DDRB &= ~(s_ddr_b);
    DDRD &= ~(s_ddr_d);

    if(uitgang<= max_uitgang)
    {
        /* set-- zet de data Direction op Tri-state of output */
        DDRB |= ( ddr_b[uitgang] & s_ddr_b);
        DDRD |= ( ddr_d[uitgang] & s_ddr_d);
        /* set-- zet de port op Low of High */
        PORTB |= ( port_b[uitgang] & s_ddr_b);
        PORTD |= ( port_d[uitgang] & s_ddr_d);

    } else {
        /* als uitgang op 255 word guplaatst dan kan de master weten dat er geen uitgang actieve is */
        uitgang=0xFF;
    }

    if((ring_buffer_count_SPI+2) < BUF_LEN)/* SPI_buffer controleer de lenkte */
    {
        SPI_buffer_Write(0x02);                    /* SPI_buffer SPI_datacont */
        SPI_buffer_Write(SPI_uitgang);                   /* SPI_buffer data 0 */
        SPI_buffer_Write(uitgang);                        /* SPI_buffer data 1*/
        if(SPI_status==SPI_heartbeat_slave)
        {
            /* bij data varander van "geen data" naar "data"*/
            SPI_status=SPI_slave_zent_start;
        }
    }
}
void verbind_in_uit(uint8_t nr_in,uint8_t stand)
{
    /* SPI_buffer controleer de lenkte */
    if((ring_buffer_count_SPI+3) < BUF_LEN)
    {
        /* SPI_buffer SPI_datacont */
        SPI_buffer_Write(0x03);
        /* SPI_buffer data 0 */
        SPI_buffer_Write(SPI_ingang);
        /* SPI_buffer data 1*/
        SPI_buffer_Write(nr_in);
        /* SPI_buffer data 2 */
        SPI_buffer_Write(stand);

        if(SPI_status==SPI_heartbeat_slave)
        {
            //bij data varander van "geen data" naar "data"
            SPI_status=SPI_slave_zent_start;
        }
    }
    /*__________________________________*/
    if(slave>7)
    {
        return;// slave_nr niet bekend!!
    }
    in_uit_data[nr_in][0];//funcie

    uint8_t byte = in_uit_data[nr_in][slave+1];//uitgang byte0
    uint8_t var;

    for (var = 0; var < 7; ++var) {
        if(byte&(0b00000001<<var))/*  */
        {
            /*
             * 0 = aan
             * 1 = uit
             * 2 = L1
             * 3 = L2
             * 4 = L1/L2
             * 4 = L3
             * opm/
*/

            if(stand)
            {
                set_output();
            }
        }
    }
    byte = in_uit_data[nr_in][slave+2];//uitgang byte1
    for (var = 0; var < 7; ++var) {
        if(byte&(0b00000001<<var))/*  */
        {
                /*
                 * 0 = aan
                 * 1 = uit
                 * 2 = L1
                 * 3 = L2
                 * 4 = L1/L2
                 * 4 = L3
                 * opm/
*/

            if(stand)
            {
                set_output();
            }
        }
    }
}

void verwerk_data_master()
{
    switch (SPI_received_data[0]) {
    case SPI_ingang://geen funie
        break;

    case SPI_uitgang:                                       /* zet un uitgang */
        if(SPI_received_data[1]>72)SPI_received_data[1]=0;
        set_output(SPI_received_data[1]);
        break;

    case SPI_status_slave:// tba zent status
        break;
    case SPI_set_slave:
        slave=SPI_received_data[1];
        break;

    default:// tba zent error
        break;
    }
}

/* set SPI */
void init_SPI()
{
    DDRB |=(1<<PORTB6); //MISO in
    SPCR =(1<<SPIE)|(1<<SPE);//SPI control Register
}

/* SPI Serial Transfer Complete
 *
 * SPDR : is de SPI Data Register
 *
 * The system is single buffered in the transmit direction
 * double buffered in the receive direction.
 *
 * This means that bytes to be transmitted
 * cannot be written to the SPI Data Register before
 * the entire shift cycle is completed.
 *
 * When receiving data, however,
 * a received character must be read from
 * the SPI Data Register before
 * the next character has been completely shifted in.
 * Otherwise, the first byte is lost.
 * -- als de SPI data niet gelezen is voordat de volgende data binnen komt
 *    dan is de data verloren.
 *
 * werking:
 * de SPDR lezen en schrijven en derna verwerken.
 *
 **/
ISR(SPI_STC_vect)
{
    uint8_t data_van_master=SPDR;                            /* de SPDR lezen */
    switch (SPI_status)
    {
    case SPI_heartbeat_slave:                       /* geen data van slave    */
        if(data_van_master==SPI_master_start_data)  /* is er data van master? */
        {
            SPI_status=SPI_master_start_data;            /* master geeft data */
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;
/* ---------Com slave  => master -------------------------------------------- */
    case SPI_slave_zent_start:               /* als de data com van nul start */
        if(data_van_master==SPI_heartbeat_master)
        {
            SPI_status=SPI_slave_start_data; /* kan data zenden */
        } else if(data_van_master==SPI_master_start_data)  /* is er data van master? */
        {
            SPI_status=SPI_master_start_data;            /* master geeft data */
        } else
        {
            SPI_status=SPI_heartbeat_slave;
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;

    case SPI_slave_start_data:                           /* start van de data */
        ring_buffer_zent_count_SPI=1;
        ring_buffer_zent_SPI=ring_buffer_tail_SPI;
        ring_buffer_receive_SPI=ring_buffer_tail_SPI;
        SPDR=ring_buffer_SPI[ring_buffer_zent_SPI++];    /* de SPDR schrijven */
        ring_buffer_zent_SPI &= BUF_MASK;
        SPI_status=SPI_slave_data;                  /* ga naar SPI_slave_data
                                                     * voor de data doorvoer  */
        break;

    case SPI_slave_data:                                     /* stuur de data */
        SPDR=ring_buffer_SPI[ring_buffer_zent_SPI++];    /* de SPDR schrijven */
        ring_buffer_zent_SPI &= BUF_MASK;
        /* is alle data versturd? */
        if(ring_buffer_SPI[ring_buffer_tail_SPI]==ring_buffer_zent_count_SPI)
        {
            SPI_status=SPI_slave_stop_data;
        }
        ring_buffer_zent_count_SPI++;
        /* controle van de data */
        if(data_van_master==ring_buffer_SPI[ring_buffer_receive_SPI])
        {
            ring_buffer_receive_SPI++;
            ring_buffer_receive_SPI &= BUF_MASK;
        }
        break;
    case SPI_slave_stop_data:       /* de data is verstuurt zent de stop byte
                                     * en controleer de data                  */

        /* waar zit de master al? */
        if(data_van_master==ring_buffer_SPI[ring_buffer_receive_SPI])
        {
            /* bij de data */
            ring_buffer_receive_SPI++;
            ring_buffer_receive_SPI &= BUF_MASK;
            if(ring_buffer_receive_SPI==ring_buffer_zent_SPI)
            {
                /* alle data is er */
                /* controlle */
                /* de data is ok */
                ring_buffer_count_SPI -= ring_buffer_SPI[ring_buffer_tail_SPI];
                ring_buffer_count_SPI -=1;                 /* count in buffer */
                ring_buffer_tail_SPI = ring_buffer_receive_SPI;
                if(ring_buffer_count_SPI>0)                /* is er nog data? */
                {
                    SPI_status=SPI_slave_start_data;       /* ja, er is data. */
                } else {
                    SPI_status=SPI_heartbeat_slave;        /* nee, geen data. */
                }
            }

        } else {
            SPI_status=SPI_slave_error;                   /* error van data!! */
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;

    case SPI_slave_error:                                     /* herstart com */
        if(ring_buffer_count_SPI>0)                        /* is er nog data? */
        {
            SPI_status=SPI_slave_start_data;               /* ja, er is data. */
        } else {
            SPI_status=SPI_heartbeat_slave;                /* nee, geen data. */
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;

/* ---------Com master => slave  -------------------------------------------- */
    case SPI_master_start_data:          /* master start Transfer van de data */
        SPI_slave_datacont=data_van_master;                    /* de datacont */
        SPI_status=SPI_master_data;
        SPI_received_data_pointor=0;
        /* de SPDR blijft hetzelfde */
        break;

    case SPI_master_data:
        SPI_received_data[SPI_received_data_pointor++]=data_van_master;
        --SPI_slave_datacont;
        if(SPI_slave_datacont==0)
        {
            SPI_status=SPI_master_stop_data;
        }
        /* de SPDR blijft hetzelfde */
        break;

    case SPI_master_stop_data:/* zent data en wacht op stop byte */

        switch (data_van_master)
        {
        case SPI_master_stop_data:    /* de data is er nog niet gecontrollerd */
            break;

        case SPI_master_start_data:       /* alle data is er en er is nog data*/
            SPI_status=SPI_master_start_data;
            verwerk_data_master();             /* de data kan verwerkt worden */
            break;

        case SPI_heartbeat_master:         /* alle data is er, geen niwe data */
            SPI_status=SPI_heartbeat_slave;
            verwerk_data_master();             /* de data kan verwerkt worden */
            break;

        default:                                          /* SPI_master_error */
            SPI_status=SPI_master_error;
            break;
        }
        /* de SPDR blijft hetzelfde */
        break;

    case SPI_master_error:                                    /* herstart com */
        switch (data_van_master)                  /* wacht op master voor com */
        {
        case SPI_master_start_data:      /* master start Transfer van de data */
            SPI_status=data_van_master;
            break;
        default:                                    /* master geeft geen data */
            SPI_status=SPI_heartbeat_slave;
            break;
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;

/* ---------Com error ------------------------------------------------------- */
    case SPI_error:                                           /* herstart com */
        switch (data_van_master)
        {
        case SPI_master_start_data:
            SPI_status=SPI_master_start_data;
            break;
        case SPI_error:
            SPI_status=SPI_heartbeat_slave;
            break;
        case SPI_heartbeat_master:
            if(ring_buffer_count_SPI>0)                    /* is er nog data? */
            {
                SPI_status=SPI_slave_start_data;           /* ja, er is data. */
            } else {
                SPI_status=SPI_heartbeat_slave;            /* nee, geen data. */
            }
            break;
        default:/* als de master niet gepast reageert blijf in SPI_error staan*/
            break;
        }
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;
/* --------- Error ---------------------------------------------------------- */
    default:                  /* als de slave geen juste status geeft = error */
        SPI_status=SPI_error;
        SPDR=SPI_status;                                 /* de SPDR schrijven */
        break;
    }
}
/* Analize van test met timer in CTC mode is werkbaar.
 * daar kan op voort gewerkt worden, ivm. lichtsterkte van de led.
*/
int main(void)
{
    /* JTD: JTAG Interface Disable zie bl:279 */
    MCUCR|=(1<<JTD);
    MCUCR|=(1<<JTD);

    init_SPI();

    wdt_enable(WDTO_1S); // enable 1s watchdog timer

    TCCR0A|=(1<<WGM01); // Configure timer 0A for CTC mode
    TCCR0B|=(1<<CS02);  // Start timer at Fcpu/256
    OCR0A = 150;        // Set CTC compare value

    //start matrix

    /* set Data Register A  Tri-state en Pull-up */
    DDRA = 0b11110000;              //LED en µcswits
    PORTA = 0b11111111;             // pul-up en Vcc
    PORTC = 0b00000000;            // massa

    uint8_t var=0,matrix_PIN_out[8],timeout_led=0;
    DDRC &=~(0b11111111);                   // 1111 1111  Tri-state

    for (var = 0; var < 9; ++var) {
        debug[var]=0b00001111;
    }
    var=0;

    sei(); // Enable interrupts after re-enumeration

    //loop matrix
    for(;;)//Eternal loops are most efficiently constructed using for zie:AVR035.pdf
    {
        wdt_reset(); // keep the watchdog happy

        if(TIFR0 & (1<<OCF0A))
        {
            uint8_t t_pina=(PINA<<4);
            if((matrix_PIN_out[var]|0b00001111)^(t_pina|0b00001111))
            {
                if(matrix_PIN_out[var]!=0x00)//de eerste keer niet opslaan
                {
                    timeout_led=0;
                    //de pin is verandert
                    //welke?
                    uint8_t temp=0;
                    do {
                        if((0x10<<temp)&(~(matrix_PIN_out[var]&t_pina)))
                        {
                            /* Start met ingang naar uitgang met data_in_uit  */

                            verbind_in_uit(temp*8+var,(((0x10<<temp)&(~t_pina))>>(temp+4)));
                            /* _____________________________________________  */
                            //SPI_zent_Buf[data_pointor++]=temp*12+var;// dit werkt ook al = nr_key
                            //SPI_zent_Buf[data_pointor++]=(((0x10<<temp)&(~t_pina))>>(temp+4)); //aan of uit
                        }
                        temp++;
                    } while (temp<4);
                }
                matrix_PIN_out[var]&=0b00001111;
                matrix_PIN_out[var]|=t_pina;    // 1111 1111  sla input op
            }
            ++var;
            if(var>7)
            {
                var=0;
                if(timeout_led<255)
                {
                    timeout_led++;
                    if((timeout_led==255)&((ring_buffer_count_SPI+2) < BUF_LEN)){
                        /* SPI_buffer SPI_datacont */
                        SPI_buffer_Write(0x02);
                        /* SPI_buffer data 0 */
                        SPI_buffer_Write(SPI_status_slave);
                        /* SPI_buffer data 1 */
                        SPI_buffer_Write(0x00);

                        if(SPI_status==SPI_heartbeat_slave)
                        {
                            //bij data varander van "geen data" naar "data"
                            SPI_status=SPI_slave_zent_start;
                        }
                    }
                }
            }

            DDRC &=~(0b11111111);                   // 1111 1111  Tri-state

            /* debug */

//            PORTA =(debug[var]|0b00001111);// DDDD 1111  zet debug op
            /* normaal werking */
            if(timeout_led<255)
            {
                PORTA =(matrix_PIN_out[var]|0b00001111);// MMMM 1111  zet vorech toestand op
            } else {
                if((var==0)|(var==4))
                {
                    PORTA=0b10101111;//1 Led brand per paneel
                } else {
                    PORTA=0b00001111;
                }
            }
            /*  einde normaal werking */
            DDRC |=(0x80>>var);               // 1111 1111  1 Pin output massa
            TIFR0 = (1<<OCF0A);                         // clear the CTC flag
        }
    }
    //__asm__ __volatile__ ("nop"); //un korte wacht instruksie

    return 0;
}
