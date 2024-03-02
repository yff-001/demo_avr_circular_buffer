CC = avr-gcc
CC_OBJCOPY = avr-objcopy
CC_SIZE = avr-size
CC_UPLOAD = avrdude
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
USBPORT = COM3

all: main.elf

main.elf: main.o adc.o circular_buffer.o uart.o
	$(CC) $(CFLAGS) main.o adc.o circular_buffer.o uart.o -o main.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $^

main.hex: main.elf
	$(CC_OBJCOPY) -O ihex -R .eeprom $< $@

size: main.elf
	$(CC_SIZE) --mcu=atmega328p --format=avr main.elf

install.main: main.hex
	$(CC_UPLOAD) -v -V -D -p atmega328p -c arduino -P $(USBPORT)  -b 115200 -U flash:w:$<

clean:
	del *.o *.elf *.hex