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
    void list_usb_device(int idVendor,int idProduct);
    void set_text(QString text);
    void zent_data_adc(unsigned char *data,int size);

public slots:
    void get_device_list();
    void get_sent_cont(int var);
    void test();

private:
    int tijd_adc[6000],var_adc[6000],ch_adc[6000],pionter;
    libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices

    libusb_context *ctx = NULL; //a libusb session
    ssize_t cnt; //holding number of devices in list
    int r; //for return values
    QString adc0,adc1,adc2,adc3,adc4,adc5,adc6,adc7;
    int number_adc,max_cont;
    QTime t_adc;

    int start();
    int test_com(libusb_device_handle *dev_handle, unsigned char *data);

    unsigned char data_b[255]; //data to write
private slots:

};

#endif // COM_USB_H
