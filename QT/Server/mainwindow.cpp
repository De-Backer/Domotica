#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setup_Gui();
    setup_com_usb();
}

MainWindow::~MainWindow()
{

}

void MainWindow::get_data_usb(unsigned char *data, int size)
{
    unsigned char buffer[256];
    for (int var = 0; var < size; ++var) {
        buffer[var]=data[var];
    }
    QString txt;
    for (int var = 0; var < size; ++var) {
        txt.append(QString::number(buffer[var],2).rightJustified(8,'0')+"\n");
    }
    TextEdit_data_USB->append(txt);
}

void MainWindow::setup_Gui()
{
    //Gui
    mdiarea = new QMdiArea();
    setCentralWidget(mdiarea);
    //usb Gui
    QFormLayout *formlayout =new QFormLayout;
    QPushButton * Button_sent_ping = new QPushButton("ping",this);
    QPushButton * Button_sent_debug = new QPushButton("debug",this);
    connect(Button_sent_ping, SIGNAL(clicked()),
            this, SLOT(on_Button_ping()));
    connect(Button_sent_debug, SIGNAL(clicked()),
            this, SLOT(on_Button_debug()));
    Button_connect = new QPushButton("connect",this);
    TextEdit_data_USB = new QTextEdit(this);
    TextEdit_data_USB->setReadOnly(true);

    formlayout->addRow(Button_connect);
    formlayout->addRow(Button_sent_ping);
    formlayout->addRow(Button_sent_debug);
    formlayout->addRow(TextEdit_data_USB);

    QPointer<QGridLayout>GridLayout=new QGridLayout();
    GridLayout->addLayout(formlayout,0,0);

    QPointer<QWidget> widget = new QWidget();
    widget->setLayout(GridLayout);
    mdiarea->addSubWindow(widget);
    widget->show();
}

void MainWindow::setup_com_usb()
{

    // start thread
    QThread *thread_com_usb = new QThread;
    com_usb *Com_usb= new com_usb();
    connect(thread_com_usb, SIGNAL(finished()),thread_com_usb, SLOT(deleteLater()));
    connect(Button_connect,SIGNAL(clicked()),Com_usb, SLOT(test()));
    connect(this, SIGNAL(
                sent_control_transfer(unsigned char,
                                      unsigned char,
                                      uint,
                                      uint,
                                      unsigned char*,
                                      uint,
                                      uint)),
            Com_usb,
            SLOT(
                get_control_transfer(unsigned char,
                                     unsigned char,
                                     uint,
                                     uint,
                                     unsigned char*,
                                     uint,
                                     uint)));

    connect(Com_usb,SIGNAL(zent_data(unsigned char*,int)),
            this,SLOT(get_data_usb(unsigned char*,int)),Qt::QueuedConnection);

    Com_usb->moveToThread(thread_com_usb);
    thread_com_usb->start();
}

void MainWindow::on_Button_ping()
{
    unsigned char buffer[256];
    emit sent_control_transfer(((0x02 << 5)|0x00|0x80),USB_bRequest_SPI_status, 0, 8,buffer, sizeof(buffer), 5000);
}

void MainWindow::on_Button_debug()
{
    unsigned char buffer[256];
    emit sent_control_transfer(((0x02 << 5)|0x00|0x80),USB_bRequest_SPI_debug, 0, 8,buffer, sizeof(buffer), 5000);
}
