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
    QPointer<QWidget> widget = new QWidget();
    QPushButton * Button_sent_ping = new QPushButton("ping",this);
    Button_connect = new QPushButton("connect",this);
    QPointer<QGridLayout>GridLayout=new QGridLayout();
    connect(Button_sent_ping, SIGNAL(clicked()),
            this, SLOT(on_Button_ping()));
    GridLayout->addWidget(Button_connect,0,0);
    GridLayout->addWidget(Button_sent_ping,1,0);
    widget->setLayout(GridLayout);
    mdiarea->addSubWindow(widget);
    widget->show();

    //debug Gui
    QFormLayout *formlayout =new QFormLayout;
    QPushButton * Button_sent_debug = new QPushButton("debug",this);
    brequest = new QComboBox(this);
    brequest->addItem("USB_bRequest_SPI_data",USB_bRequest_SPI_data);
    brequest->addItem("USB_bRequest_SPI_status",USB_bRequest_SPI_status);
    brequest->addItem("USB_bRequest_SPI_set",USB_bRequest_SPI_set);
    brequest->addItem("USB_bRequest_SPI_debug",USB_bRequest_SPI_debug);
    wvalue = new QLineEdit("0",this);
    windex = new QLineEdit("0",this);
    data = new QTextEdit("0000 0000",this);
    timeout = new QLineEdit("5000",this);
    connect(Button_sent_debug, SIGNAL(clicked()),
            this, SLOT(on_Button_debug()));
    TextEdit_data_USB = new QTextEdit(this);
    TextEdit_data_USB->setReadOnly(true);

    formlayout->addRow(Button_sent_debug);
    formlayout->addRow("brequest",brequest);
    formlayout->addRow("wvalue",wvalue);
    formlayout->addRow("windex",windex);
    formlayout->addRow("data",data);
    formlayout->addRow("timeout",timeout);
    formlayout->addRow(TextEdit_data_USB);

    QPointer<QGridLayout>GridLayout_debug=new QGridLayout();
    GridLayout_debug->addLayout(formlayout,0,0);

    QPointer<QWidget> debug_widget = new QWidget();
    debug_widget->setLayout(GridLayout_debug);
    mdiarea->addSubWindow(debug_widget);
    debug_widget->show();
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
    emit sent_control_transfer(
                (
                    LIBUSB_ENDPOINT_IN
                    |LIBUSB_REQUEST_TYPE_VENDOR
                    |LIBUSB_RECIPIENT_DEVICE
                    ),
                USB_bRequest_SPI_status,
                0, //16bit
                0, //16bit
                buffer, //8bit arye
                sizeof(buffer), //16bit
                5000); //16bit
}

void MainWindow::on_Button_debug()
{
    QString data_temp=data->toPlainText();
    data_temp.remove(" ");
    data_temp.remove("\n");
    unsigned char buffer[256];
    int var_buffer=0;
    for (int var = 0; var < data_temp.size();) {
        int itemp=0,var_t=7;
        for (; (var < data_temp.size())&(var<(8*var_buffer)); ++var) {
            QString temp=data_temp.at(var);
            itemp+=(temp.toInt()<<var_t);
            --var_t;
        }
        buffer[var_buffer]=itemp;
        qDebug()<<"."<<buffer[var_buffer]<<".";
        ++var_buffer;
    }

    emit sent_control_transfer(
                (
                    LIBUSB_ENDPOINT_IN
                    |LIBUSB_REQUEST_TYPE_VENDOR
                    |LIBUSB_RECIPIENT_DEVICE
                    ),
                brequest->currentData().toInt(), //8bit
                wvalue->text().toInt(), //16bit
                windex->text().toInt(), //16bit
                buffer, //8bit arye
                sizeof(buffer), //16bit
                5000); //16bit
}
