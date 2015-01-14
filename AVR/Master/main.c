/**
 * Project: AVR ATtiny USB Tutorial at http://codeandlife.com/
 * Author: Joonas Pihlajamaa, joonas.pihlajamaa@iki.fi
 * Inspired by V-USB example code by Christian Starkjohann
 * Copyright: (C) 2012 by Joonas Pihlajamaa
 * License: GNU GPL v3 (see License.txt)
 */
/* dit moet nog getest worden op µc
 * doel: de com van PC naar SPI via USB
 *
 *
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "usbdrv.h"
#include <util/delay.h>
/* com SPI:
 * Master               slave                Master             slave
 *                                          status  datacont    status  datacont
 * SPI_start_stop       SPI_slave_start_data      FF      0           FD      0
 * SPI_zent_datacont    SPI_slave_start_data      FD      0           FD      0
 * SPI_zent_datacont    [datacont 1-255]    FD      0           FC      n
 * [datacont 1-255]     [data 0]            FC      n           FC      n-1
 * [data 0]             [data 1]            FC      n-1         FC      n-2
 * [data 1]             [data n]            FC      n-2         FC      0
 * [data n]             SPI_start_stop      FC      0           FF      0
 *
 * bij fout:
 *
 * Master               slave                Master             slave
 *                                          status  datacont    status  datacont
 * SPI_start_stop       SPI_slave_start_data      FF      0           FF      0
 * SPI_zent_datacont    SPI_slave_start_data      FD      0           FD      0
 * SPI_zent_datacont    [datacont 1-255]    FD      0           FC      n
 * [datacont 1-255]     [data 0]            FC      n           FC      n-1
 * [data 0]             [data 1]            FC      n-1         FC      n-2
 * [FFFFFF]             [data 2]            FC      n-2         FC      n-3
 * [data 2]             SPI_error_massa           FC      n-3         00      n-4
 * SPI_error_massa            SPI_error_massa           FC      n-4         00      n-5
 * SPI_error_massa            SPI_error_massa => totdat datacont berijkt is
 * .....
 * bij [data n]         SPI_error_massa           00      0           00      0
 *
 * data 0 : is de identifier (Pin/port verandering nzv..)
 * data 1..n : is data
 * */

/* debug **********************************************************************/
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
#define SPI_slave_stop_data     0xF9 /* slave heeft de data verstuurt */
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
#define SPI_sent_in_uit_data    0x07 /* is voor de in_uit_gangen */

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

/* SPI master *****************************************************************/
#define SPI_error_VCC           0xFF /* de data is 255  is aleen voor de master de slave krijgt dit als heartbeat */
#define SPI_aantal_slave        8 /*  */

/* master SPI debug ***********************************************************/
#ifdef debug_SPI
#define SPI_debug_slave         1
#endif
/* master SPI ring buffer uit *************************************************/
#define BUF_LEN_BITS 7      // e.g. 8 byte buffer
#define BUF_LEN   (1<<BUF_LEN_BITS) //0b0000 1000 0x08
#define BUF_MASK (BUF_LEN - 1)  // 0x08-0x01 =0x07 0b0000 0111
/*############################################################################*/
/* USB ************************************************************************/
#include "define_USB_com.c"
/*############################################################################*/

/* master SPI buffer in *******************************************************/
uint8_t SPI_slave_datacont[SPI_aantal_slave] = { 0 };
uint8_t SPI_received_data_pointor[SPI_aantal_slave] = { 0 };
uint8_t SPI_received_data[SPI_aantal_slave][SPI_max_data_slave] = { { 0 },{ 0 } };

uint8_t SPI_slave_data_van_master=SPI_heartbeat_master;
uint8_t SPI_status[SPI_aantal_slave] = { SPI_heartbeat_master };
uint8_t SPI_slave_data_van_slave[SPI_aantal_slave] = { 0 };
uint8_t slave;

/* master SPI ring buffer uit *************************************************/
uint8_t ring_buffer_SPI[SPI_aantal_slave][BUF_LEN] = { { 0 },{ 0 } };
uint8_t ring_buffer_head_SPI[SPI_aantal_slave] = { 0 };
uint8_t ring_buffer_tail_SPI[SPI_aantal_slave] = { 0 };
uint8_t ring_buffer_count_SPI[SPI_aantal_slave] = { 0 };

uint8_t ring_buffer_zent_SPI[SPI_aantal_slave] = { 0 };
uint8_t ring_buffer_receive_SPI[SPI_aantal_slave] = { 0 };
uint8_t ring_buffer_zent_count_SPI[SPI_aantal_slave] = { 0 };
uint8_t replyBuf[USB_Buffer] = { 0 };
uint8_t dataReceived = 0, dataLength = 0; // for USB_DATA_IN
uint8_t data_pointor=0;

/* USB debug SPI **************************************************************/
#ifdef debug_SPI
uint8_t USB_Buffer_SPI_debug[USB_Buffer] = { 0 };
uint8_t USB_Buffer_SPI_debug_pointor=0;
#endif

/*############################################################################*/
/* in/uit-gangen **************************************************************/
uint8_t in_uit_data[255][17];/*[ingang] [funcie/uitgang]
                              *
                              * [ingang]
                              * 0-255 zij de ingangen
                              * 000-031 slave0
                              * 032-063 slave1
                              * 064-095 slave2
                              * 096-127 slave3
                              * 128-159 slave4
                              * 160-191 slave5
                              * 192-223 slave6
                              * 224-255 slave7
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
                              *
                              * */
/*############################################################################*/

void SPI_buffer_Write(uint8_t slave,uint8_t var)
{

    if (ring_buffer_count_SPI[slave] == BUF_LEN)return;

    ring_buffer_SPI[slave][ring_buffer_head_SPI[slave]++]=var;
    ring_buffer_head_SPI[slave] &= BUF_MASK;
    ++ring_buffer_count_SPI[slave];
    return;
}
// this gets called when custom control message is received
USB_PUBLIC uchar usbFunctionSetup(uchar data[8]) {

    uint8_t temp;
    usbRequest_t *rq = (void *)data; // cast data to correct type
    switch(rq->bRequest) { // custom command is in the bRequest field


    case USB_bRequest_SPI_data://tba

        return 0;
    case USB_bRequest_SPI_status:
        USB_Buffer_SPI_debug_pointor=0;
        for (temp = 0; temp < SPI_aantal_slave; ++temp) {
            USB_Buffer_SPI_debug[USB_Buffer_SPI_debug_pointor++]=SPI_status[temp];
        }
        temp=USB_Buffer_SPI_debug_pointor;
        USB_Buffer_SPI_debug_pointor=0;
        usbMsgPtr = USB_Buffer_SPI_debug;// * zorgt voor fouten (is mimeri var ipv data)
        return temp;

    case USB_bRequest_SPI_set:/* set SPI */
        DDRB |=(1<<PORTB4);         //SS   out
        DDRB |=(1<<PORTB5);         //MOSI out
        DDRB &=~(1<<PORTB6);        //MISO in
        DDRB |=(1<<PORTB7);         //SCK  out
        SPCR=rq->wIndex.bytes[0];   //SPI control Register
        return 0;

#ifdef debug_SPI
    case USB_bRequest_SPI_debug:
        temp=USB_Buffer_SPI_debug_pointor;
        USB_Buffer_SPI_debug_pointor=0;
        usbMsgPtr = USB_Buffer_SPI_debug;// * zorgt voor fouten (is mimeri var ipv data)
        return temp;
#endif

    case 6:/* data van pc naar µc */
        dataLength  = (uchar)rq->wLength.word;
        dataReceived = 0;

        if(dataLength  > sizeof(replyBuf)) // limit to buffer size
            dataLength  = sizeof(replyBuf);

        return USB_NO_MSG; // usbFunctionWrite will be called now
    }
    return 0; // should not get here
}
// This gets called when data is sent from PC to the device
USB_PUBLIC uchar usbFunctionWrite(uchar *data, uchar len) {
    uint8_t i;
			
    for(i = 0; dataReceived < dataLength && i < len; i++, dataReceived++)
        replyBuf[dataReceived] = data[i];
		
    return (dataReceived == dataLength); // 1 if we received it all, 0 if not
}

void verwerk_data_slave(uint8_t slave)
{
    if((USB_Buffer_SPI_debug_pointor<248)&&(slave==0))
    {
        /* data naar USB */
        USB_Buffer_SPI_debug[USB_Buffer_SPI_debug_pointor++]=slave;
        USB_Buffer_SPI_debug[USB_Buffer_SPI_debug_pointor++]=SPI_status[slave];
        USB_Buffer_SPI_debug[USB_Buffer_SPI_debug_pointor++]=SPI_uitgang;
        USB_Buffer_SPI_debug[USB_Buffer_SPI_debug_pointor++]=SPI_received_data[slave][1];
    }
    /* verwerk de data */
    if(SPI_received_data[slave][0]==SPI_ingang)
    {
        /* SPI_buffer controleer de lenkte */
        if((ring_buffer_count_SPI[slave]+2) < BUF_LEN)
        {
            /* SPI_buffer SPI_datacont */
            SPI_buffer_Write(slave,0x02);
            /* SPI_buffer data 0 */
            SPI_buffer_Write(slave,SPI_uitgang);
            /* SPI_buffer data 1*/
            SPI_buffer_Write(slave,SPI_received_data[slave][1]);

            if(SPI_status[slave]==SPI_heartbeat_master)
            {
                //bij data varander van "geen data" naar "data"
                SPI_status[slave]=SPI_master_zent_start;
            }
        }
    }
}

int main()
{
    /* JTD: JTAG Interface Disable zie bl:279 */
    MCUCR|=(1<<JTD);
    MCUCR|=(1<<JTD);

    PORTB=0b00010000;
    DDRC=0xFF;
    PORTC=0xFF;

    wdt_enable(WDTO_1S); // enable 1s watchdog timer

    usbInit();

    usbDeviceDisconnect(); // enforce re-enumeration

    for(slave = 0; slave<250; slave++) { // wait 500 ms
        wdt_reset(); // keep the watchdog happy
        _delay_ms(2);
    }

    usbDeviceConnect();

    sei(); // Enable interrupts after re-enumeration

    //set SPI
    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);//SPI control Register fcol/128
    DDRB |=(1<<PORTB5)|(1<<PORTB7);  //MOSI SCK  out
    DDRB &=~(1<<PORTB6); //MISO in

    /* selekt slave */
    slave=0;
    PORTC&=~(1<<slave);

    SPDR=SPI_slave_data_van_master;             /* Start transmission */
    for(;;)
    {
        wdt_reset();                           /* keep the watchdog happy */
        usbPoll();                                            /* USB poll */

        if(SPSR&(1<<SPIF))
        {
            /* lees de data van de slave */
            SPI_slave_data_van_slave[slave]=SPDR;
            /* stop selekt slave */
            PORTC=0xFF;

            /* selekt slave */
            ++slave;
            if(slave==SPI_aantal_slave){
                slave=0;
            }
            PORTC&=~(1<<slave);
            SPI_slave_data_van_master=SPI_heartbeat_master;
            switch (SPI_status[slave])
            {
            case SPI_heartbeat_master:               /* geen data van master  */
                /* is er data van slave? */
                if(SPI_slave_data_van_slave[slave]==SPI_slave_start_data)
                {
                    /* slave geeft data */
                    SPI_status[slave]=SPI_slave_start_data;
                }
                /* de SPDR schrijven */
                SPI_slave_data_van_master=SPI_status[slave];
                break;
/* ---------Com slave  => master -------------------------------------------- */
            case SPI_slave_start_data:/* slave start Transfer van de data */
                /* de datacont */
                SPI_slave_datacont[slave]=SPI_slave_data_van_slave[slave];
                SPI_status[slave]=SPI_slave_data;
                SPI_received_data_pointor[slave]=0;
                /* de SPDR schrijven (echo slave) */
                SPI_slave_data_van_master=SPI_slave_data_van_slave[slave];
                /* is de buffer groot genoeg? */
                if(SPI_slave_datacont[slave]>=SPI_max_data_slave)
                {
                    /* de data is groter dan de buffer */
                    SPI_status[slave]=SPI_heartbeat_master;
                }
                break;

            case SPI_slave_data:
                /* de SPDR schrijven (echo slave) */
                SPI_slave_data_van_master=SPI_slave_data_van_slave[slave];
                SPI_received_data[slave][(SPI_received_data_pointor[slave])]=SPI_slave_data_van_master;
                SPI_received_data_pointor[slave]++;
                --SPI_slave_datacont[slave];
                if(SPI_slave_datacont[slave]==0)
                {
                    SPI_status[slave]=SPI_slave_stop_data;
                }
                break;

            case SPI_slave_stop_data:      /* zent data en wacht op stop byte */
                /* de SPDR schrijven (echo slave) */
                SPI_slave_data_van_master=SPI_slave_data_van_slave[slave];
                SPI_received_data[slave][(SPI_received_data_pointor[slave])]=SPI_slave_data_van_master;
                switch (SPI_slave_data_van_master)
                {
                case SPI_slave_stop_data:/* de data is er nog niet gecontrollerd */
                    break;

                case SPI_slave_start_data:/* alle data is er en er is nog data*/
                    SPI_status[slave]=SPI_slave_start_data;
                    /* de data kan verwerkt worden */
                    verwerk_data_slave(slave);
                    break;

                case SPI_heartbeat_slave:  /* alle data is er, geen niwe data */
                    SPI_status[slave]=SPI_heartbeat_master;
                    /* de data kan verwerkt worden */
                    verwerk_data_slave(slave);
                    break;

                default:                                    /* data is corupt */
                    SPI_status[slave]=SPI_slave_error;
                    break;
                }
                break;

            case SPI_slave_error:
                /* wacht op slave voor com */
                switch (SPI_slave_data_van_slave[slave])
                {
                case SPI_slave_start_data:/* slave start Transfer van de data */
                    SPI_status[slave]=SPI_slave_data_van_slave[slave];
                    break;
                default:                             /* slave geeft geen data */
                    SPI_status[slave]=SPI_heartbeat_master;
                    break;
                }
                /* de SPDR schrijven */
                SPI_slave_data_van_master=SPI_status[slave];
                break;

/* ---------Com master => slave  -------------------------------------------- */
            case SPI_master_zent_start:      /* als de data com van nul start */

                if(SPI_slave_data_van_slave[slave]==SPI_heartbeat_slave)
                {
                    SPI_status[slave]=SPI_master_start_data;/* kan data zenden */
                } else if(SPI_slave_data_van_slave[slave]==SPI_slave_start_data)  /* is er data van master? */
                {
                    SPI_status[slave]=SPI_slave_start_data;            /* master geeft data */
                } else
                {
                    SPI_status[slave]=SPI_heartbeat_master;            /* master geeft data */
                }
                /* de SPDR schrijven */
                SPI_slave_data_van_master=SPI_status[slave];
                break;

            case SPI_master_start_data:                  /* start van de data */
                ring_buffer_zent_count_SPI[slave]=1;
                ring_buffer_zent_SPI[slave]=ring_buffer_tail_SPI[slave];
                ring_buffer_receive_SPI[slave]=ring_buffer_tail_SPI[slave];
                /* de SPDR schrijven */
                SPI_slave_data_van_master=ring_buffer_SPI[slave][ring_buffer_zent_SPI[slave]++];
                ring_buffer_zent_SPI[slave] &= BUF_MASK;
                SPI_status[slave]=SPI_master_data;
                break;

            case SPI_master_data:                            /* stuur de data */
                /* de SPDR schrijven */
                SPI_slave_data_van_master=ring_buffer_SPI[slave][ring_buffer_zent_SPI[slave]++];
                ring_buffer_zent_SPI[slave] &= BUF_MASK;
                /* is alle data versturd? */
                if(ring_buffer_SPI[slave][ring_buffer_tail_SPI[slave]]==ring_buffer_zent_count_SPI[slave])
                {
                    SPI_status[slave]=SPI_master_stop_data;
                }
                ring_buffer_zent_count_SPI[slave]++;
                /* controle van de data */
                if(SPI_slave_data_van_slave[slave]==ring_buffer_SPI[slave][ring_buffer_receive_SPI[slave]])
                {
                    ring_buffer_receive_SPI[slave]++;
                    ring_buffer_receive_SPI[slave] &= BUF_MASK;
                }
                break;

            case SPI_master_stop_data:                /* de data is verstuurt */
                /* waar zit de slave al? */
                if(SPI_slave_data_van_slave[slave]==ring_buffer_SPI[slave][ring_buffer_receive_SPI[slave]])
                {
                    /* bij de data */
                    ring_buffer_receive_SPI[slave]++;
                    ring_buffer_receive_SPI[slave] &= BUF_MASK;
                    if(ring_buffer_receive_SPI[slave]==ring_buffer_zent_SPI[slave])
                    {
                        ring_buffer_count_SPI[slave] -= ring_buffer_SPI[slave][ring_buffer_tail_SPI[slave]];
                        ring_buffer_count_SPI[slave] -=1;  /* count in buffer */
                        ring_buffer_tail_SPI[slave] = ring_buffer_receive_SPI[slave];
                        if(ring_buffer_count_SPI[slave]>0) /* is er nog data? */
                        {
                            /* ja, er is data. */
                            SPI_status[slave]=SPI_master_start_data;

                        } else {
                            /* nee, geen data. */
                            SPI_status[slave]=SPI_heartbeat_master;
                        }
                    }
                } else {
                    SPI_status[slave]=SPI_master_error;   /* error van data!! */
                }
                /* de SPDR schrijven */
                SPI_slave_data_van_master=SPI_status[slave];
                break;

            case SPI_master_error:
                if(ring_buffer_count_SPI[slave]>0) /* is er nog data? */
                {
                    /* ja, er is data. */
                    SPI_status[slave]=SPI_master_start_data;

                } else {
                    /* nee, geen data. */
                    SPI_status[slave]=SPI_heartbeat_master;
                }
                /* de SPDR schrijven */
                SPI_slave_data_van_master=SPI_status[slave];
                break;

/* ---------Com error ------------------------------------------------------- */

/* --------- start ---------------------------------------------------------- */
            default:                                         /* bij start com */
                SPI_status[slave]=SPI_heartbeat_master;
                break;
            }
            SPDR=SPI_slave_data_van_master;             /* Start transmission */
        }
    }
    return 0;
}
