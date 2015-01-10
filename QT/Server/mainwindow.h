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
    void get_device_list();
    void test();

public slots:
    void get_text(QString text);

private:
    QMdiArea *mdiarea;
    QPushButton *Button_stop;
private slots:
};

#endif // MAINWINDOW_H
