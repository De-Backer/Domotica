#=============================================================================#
# Server
#=============================================================================#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server_Domotica
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    com_usb.cpp \
    ../../AVR/Master/define_USB_com.c

HEADERS  += mainwindow.h \
    com_usb.h

DISTFILES += libusb/*
DISTFILES += libusb/os/*
# moet
# win32 {
# zijn en niet:
# win32
# {
# want dan voert qmake alles van win32 uit in linux!

win32 {
# niet getest op QT 5
    INCLUDEPATH += "/media/truecrypt1/QT_code_AVR_USB/libusb/windows/libusb/include/"
    LIBS += "/media/truecrypt1/QT_code_AVR_USB/libusb/windows/libusb/lib/msvc/libusb.lib"
 }

unix {
    INCLUDEPATH += "/libusb/include/"
# opm. libusb-1.0 moet gecompilt zijn zie INSTALL
    LIBS += "/usr/local/lib/libusb-1.0.so"
 }

