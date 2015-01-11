# WinAVR cross-compiler toolchain is used here
CC = avr-gcc
OBJCOPY = avr-objcopy
DUDE = avrdude

#µc
# atmega8535
# atmega1284p
microcontroller = atmega1284p 

F_CPU = 20000000L    # in Hz

CFLAGS = -Wall -Os -Iusbdrv -mmcu=$(microcontroller) -DF_CPU=$(F_CPU)
OBJFLAGS = -j .text -j .data -O ihex
# parallel
DUDEFLAGSp = -p $(microcontroller) -c bascom -v
#serial
DUDEFLAGSs = -p $(microcontroller) -c ponyser -v
#dragon 
DUDEFLAGSd-i = -p $(microcontroller) -c dragon_isp -v
DUDEFLAGSd-j = -p $(microcontroller) -c dragon_jtag -v

# Object files for the firmware (usbdrv/oddebug.o not strictly needed I think)
OBJECTS = main.o usbdrv/usbdrv.o usbdrv/oddebug.o usbdrv/usbdrvasm.o 

# By default, build the firmware, but do not flash
all: main.hex

# With this, you can flash the firmware by just typing "make flash-p" or "make flash-s" on command-line
flash-p: main.hex
	$(DUDE) $(DUDEFLAGSp) -U flash:w:$<
flash-s: main.hex
	$(DUDE) $(DUDEFLAGSs) -P com2 -U flash:w:$<
flash-s-l: main.hex
	$(DUDE) $(DUDEFLAGSs) -P /dev/ttyS0 -U flash:w:$<
flash-d-i-l: main.hex
	$(DUDE) $(DUDEFLAGSd-i) -P usb 03eb:2107 -U flash:w:$<
flash-d-j-l: main.hex
	$(DUDE) $(DUDEFLAGSd-j) -P usb 03eb:2107 -U flash:w:$<

# Housekeeping if you want it
clean:
	$(RM) *.o *.hex *.elf usbdrv/*.o

# From .elf file to .hex
%.hex: %.elf
	$(OBJCOPY) $(OBJFLAGS) $< $@

# Main.elf requires additional objects to the firmware, not just main.o
main.elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Without this dependance, .o files will not be recompiled if you change 
# the config! I spent a few hours debugging because of this...
$(OBJECTS): usbdrv/usbconfig.h

# From C source to .o object file
%.o: %.c	
	$(CC) $(CFLAGS) -c $< -o $@

# From assembler source to .o object file
%.o: %.S
	$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@
