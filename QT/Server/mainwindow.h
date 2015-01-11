#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPointer>
#include <QMdiArea>
#include <QPushButton>
#include <QTextEdit>
#include <QProgressBar>
#include <QLabel>
#include <QFormLayout>
#include <QThread>
#include "com_usb.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void start_usb();
    void test();
    void sent_control_transfer(unsigned char bmrequesttype, //  8 bit (0-255)
                              unsigned char brequest,      //  8 bit (0-255)
                              unsigned int  wvalue,        // 16 bit (0-65535)
                              unsigned int  windex,        // 16 bit (0-65535)
                              unsigned char *data,         //  8 bit data buffer (0-255)
                              unsigned int  wlength,       // 16 bit (0-65535)
                              unsigned int  timeout);      // 16 bit (0-65535)

public slots:
    void get_text(QString text);
    void get_data_usb(unsigned char *data,int size);

private:
    QMdiArea *mdiarea;
    QPushButton *Button_stop;
private slots:
};

#endif // MAINWINDOW_H
