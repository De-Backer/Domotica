# WinAVR cross-compiler toolchain is used here
CC = avr-gcc
OBJCOPY = avr-objcopy
DUDE = avrdude
F_CPU = 20000000    # in Hz

# If you are not using ATtiny2313 and the USBtiny programmer, 
# update the lines below to match your configuration
CFLAGS = -Wall -Os -Iusbdrv -mmcu=atmega1284p  -DF_CPU=$(F_CPU)
OBJFLAGS = -j .text -j .data -O ihex
# parallel
DUDEFLAGSp = -p atmega1284p -c bascom -v
#serial
DUDEFLAGSs = -p atmega1284p -c ponyser -v

# Object files for the firmware (usbdrv/oddebug.o not strictly needed I think)
OBJECTS =  main.o

# By default, build the firmware, but do not flash
all: main.hex

# With this, you can flash the firmware by just typing "make flash-p" or "make flash-s" on command-line
flash-p: main.hex
	$(DUDE) $(DUDEFLAGSp) -U flash:w:$<
flash-s: main.hex
	$(DUDE) $(DUDEFLAGSs) -P com2 -U flash:w:$<
flash-s-l: main.hex
	$(DUDE) $(DUDEFLAGSs) -P /dev/ttyS0 -U flash:w:$<


# Housekeeping if you want it
clean:
	$(RM) *.o *.hex *.elf

# From .elf file to .hex
%.hex: %.elf
	$(OBJCOPY) $(OBJFLAGS) $< $@

# Main.elf requires additional objects to the firmware, not just main.o
main.elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


# From C source to .o object file
%.o: %.c	
	$(CC) $(CFLAGS) -c $< -o $@

# From assembler source to .o object file
%.o: %.S
	$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@
