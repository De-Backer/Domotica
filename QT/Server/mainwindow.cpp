#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    mdiarea = new QMdiArea();
    //mdiarea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(mdiarea);

    QFormLayout *formlayout =new QFormLayout;
    Button_stop= new QPushButton("connect",this);
    formlayout->addRow(Button_stop);
    QPointer<QGridLayout>GridLayout=new QGridLayout();
    GridLayout->addLayout(formlayout,0,0);

    QPointer<QWidget> widget = new QWidget();
    widget->setLayout(GridLayout);
    mdiarea->addSubWindow(widget);
    widget->show();

    // start thread
    QThread *thread_com_usb = new QThread;
    com_usb *Com_usb= new com_usb();
    connect(thread_com_usb, SIGNAL(finished()),thread_com_usb, SLOT(deleteLater()));
    connect(Button_stop,SIGNAL(clicked()),Com_usb, SLOT(test()));
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
    connect(this,SIGNAL(start_usb()),
            Com_usb, SLOT(test()),Qt::QueuedConnection);

    connect(Com_usb,SIGNAL(set_text(QString)),
            this, SLOT(get_text(QString)),Qt::QueuedConnection);

    Com_usb->moveToThread(thread_com_usb);
    thread_com_usb->start();

    emit start_usb();
}

MainWindow::~MainWindow()
{

}

void MainWindow::get_text(QString text)
{

}
void MainWindow::get_data_usb(unsigned char *data, int size)
{

}
