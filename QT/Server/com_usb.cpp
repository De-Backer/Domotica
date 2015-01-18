#include "com_usb.h"

com_usb::com_usb()
{
    // Initialize libusb
    // This function must be called before calling any other libusb function.
    r = libusb_init(&ctx);

    if (r < 0)
        emit error(r,"Initialize libusb");

    libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation
}

// --- DECONSTRUCTOR ---
com_usb::~com_usb()
{
    // free resources

    // Deinitialize libusb.
    // Should be called after closing all open devices and before your application terminates.
    libusb_exit(ctx);
}

void com_usb::get_control_transfer(unsigned char bmrequesttype,
                                   unsigned char brequest,
                                   unsigned int wvalue,
                                   unsigned int windex,
                                   unsigned char *data,
                                   unsigned int wlength,
                                   unsigned int timeout)
{
    qDebug()<<"get_control_transfer";

    libusb_device_handle *dev_handle=NULL; //a device handle
    //
    dev_handle = libusb_open_device_with_vid_pid(ctx, 5824, 1500); //these are vendorID and productID I found for my usb device
    if(dev_handle == NULL)
    {
        qDebug()<<"Cannot open device"<<endl;
        return;
    }
    qDebug()<<"Device Opened"<<LIBUSB_API_VERSION;


        if(libusb_kernel_driver_active(dev_handle, 0) == 1) { //find out if kernel driver is attached
            qDebug()<<"Kernel Driver Active";
            if(libusb_detach_kernel_driver(dev_handle, 0) == 0) //detach it
                qDebug()<<"Kernel Driver Detached!";
        }
        r = libusb_claim_interface(dev_handle, 0); //claim interface 0 (the first) of device (mine had jsut 1)
        if(r < 0) {
            qDebug()<<"Cannot Claim Interface";
            return;
        }
        qDebug()<<"Claimed Interface";
        qDebug()<<"Writing Data...";
        qDebug()<<"dev_handle   : "<<dev_handle;
        qDebug()<<"bmrequesttype: "<<bmrequesttype;
        qDebug()<<"brequest     : "<<brequest;
        qDebug()<<"wvalue       : "<<wvalue;
        qDebug()<<"windex       : "<<windex;
        qDebug()<<"data         : "<<data;
        qDebug()<<"wlength      : "<<wlength;
        qDebug()<<"timeout      : "<<timeout;

        r=libusb_control_transfer(dev_handle,bmrequesttype,brequest,wvalue,windex,data, wlength,timeout);// norm // duurt 10ms

        emit zent_data(data,r);//is trager! 8KByte/s
        //
        r = libusb_release_interface(dev_handle, 0); //release the claimed interface
        if(r!=0) {
            qDebug()<<"Cannot Release Interface";
            return;
        }
        qDebug()<<"Released Interface";
    //
        libusb_close(dev_handle);
        qDebug()<<"close dev_handle";


//    vendor "16C0" 5824
//    product "05DC" 1500
//    vendorName "codeandlife.com"
//    productName "USBexample"

}
void com_usb::test()
{
    start();
}

int com_usb::start()
{

    libusb_device_handle *dev_handle=NULL; //a device handle
    //
    dev_handle = libusb_open_device_with_vid_pid(ctx, 5824, 1500); //these are vendorID and productID I found for my usb device
    if(dev_handle == NULL)
    {
        qDebug()<<"Cannot open device"<<endl;
        return 1;
    }
       else
            qDebug()<<"Device Opened"<<endl;

        unsigned char *data = new unsigned char[255]; //data to write
        data[0]='0';data[1]='0';data[2]='0';data[3]='0'; //some dummy values

        if(libusb_kernel_driver_active(dev_handle, 0) == 1) { //find out if kernel driver is attached
            qDebug()<<"Kernel Driver Active";
            if(libusb_detach_kernel_driver(dev_handle, 0) == 0) //detach it
                qDebug()<<"Kernel Driver Detached!";
        }
        r = libusb_claim_interface(dev_handle, 0); //claim interface 0 (the first) of device (mine had jsut 1)
        if(r < 0) {
            qDebug()<<"Cannot Claim Interface";
            return 1;
        }
        qDebug()<<"Claimed Interface";
        qDebug()<<"Writing Data...";


        //
        //r=libusb_control_transfer(dev_handle,((0x02 << 5)|0x00|0x80),4,0,0,data, sizeof(data),5000);
        forever
        {
            int var=test_com(dev_handle,data);
            if(var!=0)
            {
                qDebug()<<var<<libusb_error_name(var);
                break;
            }
            //if(t_adc.elapsed()>10000)break;
        }

        //
        r = libusb_release_interface(dev_handle, 0); //release the claimed interface
        if(r!=0) {
            qDebug()<<"Cannot Release Interface"<<endl;
            return 1;
        }
        qDebug()<<"Released Interface"<<endl;
    //

//    vendor "16C0" 5824
//    product "05DC" 1500
//    vendorName "codeandlife.com"
//    productName "USBexample"

        return 0;
}

int com_usb::test_com(libusb_device_handle *dev_handle,unsigned char *data)
{
    /*int LIBUSB_CALL libusb_control_transfer(
     * libusb_device_handle *dev_handle,    dev_handle
     * uint8_t request_type,                ((0x02 << 5)|0x00|0x80)
     *  uint8_t bRequest,                   254
     *  uint16_t wValue,                    0
     *  uint16_t wIndex,                    0
     * unsigned char *data,                 data
     *  uint16_t wLength,                   255
     *  unsigned int timeout);              5000
*/
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
#define SPI_slave_stop_data     0xF9/* slave heeft de data verstuurt */
#define SPI_slave_error         0xF8 /* probeem slave */

#define SPI_master_zent_start   0xF7 /* master start Transfer van de data */
#define SPI_master_start_data   0xF6 /* master start Transfer van de data */
#define SPI_master_data         0xF5 /* master stuur de data */
#define SPI_master_stop_data    0xF4 /* master heeft de data verstuurt */
#define SPI_master_error        0xF3 /* probeem master */

#define SPI_error               0xF2 /* probeem com */

#define SPI_error_massa         0x00 /* de data is 0 */

    #define SPI_ingang              0x01
    #define SPI_uitgang             0x02
    #define SPI_status_slave        0x03

    /* SPI master *****************************************************************/
    #define SPI_error_VCC           0xFF /* de data is 255  is aleen voor de master de slave krijgt dit als heartbeat */
    /* master SPI debug ***********************************************************/
    #ifdef debug_SPI
    #define SPI_debug_slave         0
    #endif
    /*############################################################################*/
    /* USB ************************************************************************/
    #define USB_bRequest_SPI_data       0xF0
    #define USB_bRequest_SPI_status     0xF1
    #define USB_bRequest_SPI_set        0xF2

    #define USB_Buffer                  254

    /* USB debug SPI **************************************************************/
    #ifdef debug_SPI
    #define USB_bRequest_SPI_debug      0xFF
    #endif
    /*############################################################################*/

    r=libusb_control_transfer(dev_handle,((0x02 << 5)|0x00|0x80),USB_bRequest_SPI_debug,0,0,data, 255,5000);// norm
    if(r<1)return r;
        qDebug()<<"----------------------------------------------------------------";
        int status=0;
        QString statuslist[5]={" slave                     ",
                               " SPI_status                ",
                               " SPI_status                ",
                               " SPI_slave_data_van_slave  ",
                               " SPI_slave_data_van_master "};
        for (int var = 0; var <r; ++var)//tba r kan -1 zijn!!
        {
            while ((status==0)&&(data[var]!=0)) {
                var+=5;
            }
            QString temp=QString::number(r,10).rightJustified(3,' ')+QString::number(var,10).rightJustified(3,' ');
            switch (data[var]) {
            case SPI_heartbeat_slave:
                temp+=statuslist[status]+" SPI_heartbeat_slave ";
                break;
            case SPI_slave_start_data:
                temp+=statuslist[status]+" SPI_slave_start_data ";
                break;
            case SPI_slave_data:
                temp+=statuslist[status]+" SPI_slave_data ";
                break;
            case SPI_slave_stop_data:
                temp+=statuslist[status]+" SPI_slave_stop_data ";
                break;
            case SPI_slave_error:
                temp+=statuslist[status]+" SPI_slave_error ";
                break;
            case SPI_master_start_data:
                temp+=statuslist[status]+" SPI_master_start_data ";
                break;
            case SPI_master_data:
                temp+=statuslist[status]+" SPI_master_data ";
                break;
            case SPI_master_stop_data:
                temp+=statuslist[status]+" SPI_master_stop_data ";
                break;
            case SPI_master_error:
                temp+=statuslist[status]+" SPI_master_error ";
                break;
            case SPI_error:
                temp+=statuslist[status]+" SPI_error ";
                break;
            case SPI_error_VCC:
                if((status==1)|(status==2)|(status==4)){
                    temp+=statuslist[status]+" SPI_heartbeat_master ";
                } else {
                    temp+=statuslist[status]+" SPI_error_VCC ";
                }
                break;
            case SPI_error_massa:
                temp+=statuslist[status]+" SPI_error_massa ";
                break;
            default:
                temp+=statuslist[status]+QString::number(data[var],10).rightJustified(3,' ')+" "+
                        QString::number(data[var],16).rightJustified(2,' ')+" "+
                        QString::number(data[var],2).rightJustified(8,'0');
                break;
            }
            qDebug()<<temp;
            ++status;
            if(status==5){
                status=0;
                qDebug()<<"";
            }
        }
        qDebug()<<"________________________________________________________________";


    return 0;
}
