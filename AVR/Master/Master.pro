#=============================================================================#
# bevat alle project-file's
#
#=============================================================================#

TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

NAME = Master

# WinAVR cross-compiler toolchain is used here
QMAKE_CC = avr-gcc
QMAKE_CXX = avr-g++
QMAKE_LINK = avr-g++

# AVR info
#DEVICE     = atmega8535
DEVICE     = atmega1284p

F_CPU = 20000000    # in Hz

PROGRAMMER = ponyser
#PROGRAMMER = bascom
#PROGRAMMER = dragon_isp
#PROGRAMMER = dragon_jtag

OBJCOPY = avr-objcopy
DUDE = avrdude
QMAKE_CFLAGS = -Wall -Os -Iusbdrv -mmcu=$${DEVICE} -DF_CPU=$${F_CPU}

# Source files you need for your project go here.
INCLUDEPATH =/usr/local/avr/include/
SOURCES += main.c
SOURCES += define_USB_com.c
##############################################################################
# Fuse values for particular devices
##############################################################################
contains( DEVICE, atmega1284p ){
DEFINES += __AVR_ATmega1284P__
#set de FUSE
FUSE_L     = 0xCE
FUSE_H     = 0x09
}
contains( DEVICE, atmega8535 ){
DEFINES += __AVR_ATmega8535__
#set de FUSE
FUSE_L     = 0xC1
FUSE_H     = 0xD9
}

##############################################################################
# USB
# From assembler source to .o object file werkt niet!!!!!!!!!!!
# gebruik un makefile in de plaats
message("From assembler source to .o object file werkt niet!!!!!!!!!!! gebruik un makefile in de plaats")
##############################################################################
INCLUDEPATH +=./usbdrv/
HEADERS += usbdrv/*.h
SOURCES += usbdrv/*.c
HEADERS += usbdrv/*.asm
SOURCES += usbdrv/*.S
SOURCES += usbdrv/*.inc
DISTFILES += usbdrv/*.txt \
    Makefile
#_____________________________________________________________________________

contains( PROGRAMMER, ponyser ){
    win32{
        # te testen
        PORT = com2
    }
    linux-g++ {
        PORT = /dev/ttyS0
    }
}else:contains( PROGRAMMER, bascom ){
    win32{
        # te testen
        PORT = lpt1
    }
    linux-g++ {
        # te testen
        PORT = /dev/lp0
    }

}else:contains( PROGRAMMER, dragon_isp ){
# te testen
PORT = usb 03eb:2107
}else:contains( PROGRAMMER, dragon_jtag ){
# te testen
PORT = usb 03eb:2107
}


##############################################################################
# programma
##############################################################################
message("programma :"$${NAME})
message("DEFINES   :"$${DEFINES})
message("DEVICE    :"$${DEVICE})
message("FUSE_L    :"$${FUSE_L})
message("FUSE_H    :"$${FUSE_H})
message("PROGRAMMER:"$${PROGRAMMER})
message("PORT      :"$${PORT})

message("make program ... to flash fuses and firmware")
message("make fuse ...... to flash the fuses")
message("make flash ..... to flash the firmware")

QMAKE_EXTRA_TARGETS += eep hex flash fuse program

TARGET = $${NAME}.elf

QMAKE_CLEAN += $${NAME}.elf

eep.target = $${NAME}.eep

QMAKE_CLEAN += $${NAME}.eep

eep.commands = avr-objcopy -O ihex -j .eeprom

eep.commands += --set-section-flags=.eeprom=alloc,load --no-change-warnings

eep.commands += --change-section-lma .eeprom=0 $$TARGET $$eep.target

eep.depends = $$TARGET


hex.target = $${NAME}.hex

QMAKE_CLEAN += $${NAME}.hex

hex.commands = avr-objcopy -O ihex -R .eeprom $$TARGET $$hex.target

hex.depends = $${NAME}.eep

# make flash target to build and flash

flash.target = flash

flash.commands  = avrdude
flash.commands += -p $${DEVICE}
flash.commands += -c $${PROGRAMMER}
flash.commands += -P $${PORT}
flash.commands += -V
flash.commands += -U flash:w:$${NAME}.hex:i

flash.depends   = $${NAME}.hex

fuse.target = fuse

fuse.commands  = avrdude
fuse.commands += -p $${DEVICE}
fuse.commands += -c $${PROGRAMMER}
fuse.commands += -P $${PORT}
fuse.commands += -V
fuse.commands += -U hfuse:w:$${FUSE_H}:m
fuse.commands += -U lfuse:w:$${FUSE_L}:m

program.target  = program
program.depends = flash fuse
