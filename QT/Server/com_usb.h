#ifndef COM_USB_H
#define COM_USB_H

#include <stdio.h>
#include <QObject>
#include <QDebug>
#include <QTime>
#include "libusb/libusb.h"

class com_usb : public QObject
{
    Q_OBJECT
public:
    explicit com_usb();
    ~com_usb();

signals:
    void error(int,QString);
    void zent_data(unsigned char *data,int size);

public slots:
    void test();
    void get_control_transfer(unsigned char bmrequesttype, //  8 bit (0-255)
                              //Bits 0:4 determine recipient "libusb_request_recipient"
                              //Bits 5:6 determine type "libusb_request_type"
                              //Bit 7 determines data transfer direction "libusb_endpoint_direction"
                              unsigned char brequest,      //  8 bit (0-255)   data
                              unsigned int  wvalue,        // 16 bit (0-65535) data
                              unsigned int  windex,        // 16 bit (0-65535) data
                              unsigned char *data,         //  8 bit data buffer (0-255)
                              unsigned int  wlength,       // 16 bit (0-65535)
                              unsigned int  timeout);      // 16 bit (0-65535)

private:
    libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices

    libusb_context *ctx = NULL; //a libusb session
    ssize_t cnt; //holding number of devices in list
    int r; //for return values

    int start();
    int test_com(libusb_device_handle *dev_handle, unsigned char *data);
private slots:

};

#endif // COM_USB_H
