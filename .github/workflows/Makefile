PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy

CFLAGS = -mthumb-interwork -mthumb -O2 -Wall -I./include
LDFLAGS = -T gba.ld

OBJS = main.o sound.o input.o ui.o

all: stepper.gba

stepper.elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

stepper.gba: stepper.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.elf *.gba
