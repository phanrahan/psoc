NAME = blinker01
OBJS = start.o blinker01.o 

ARM=arm-none-eabi
ARCHFLAGS = -mcpu=cortex-m3 -march=armv7-m -mthumb 
CFLAGS  = $(ARCHFLAGS)  -ffreestanding -std=c99
ASFLAGS = $(ARCHFLAGS) 
LDFLAGS = -nostdlib -T memmap 

all: $(NAME).elf

$(NAME).elf: $(OBJS) memmap
	$(ARM)-ld -T memmap  $(OBJS) -o $@

%.bin: %.elf
	$(ARM)-objcopy $< -O binary $@

%.hex: %.elf
	$(ARM)-objcopy $< -O ihex $@

%.elf: (OBJS)
	$(ARM)-gcc $(LDFLAGS) $^ -o $@

%.o: %.c
	$(ARM)-gcc $(CFLAGS) -c $< -o $@

%.o: %.s
	$(ARM)-as $(ASFLAGS) $< -o $@

%.list: %.elf
	$(ARM)-objdump --no-show-raw-insn -d $< > $@

upload: $(NAME).bin
	openocd -c "interface kitprog; kitprog_init_acquire_psoc" -f target/psoc5lp.cfg -c "init; halt; psoc5lp mass_erase 0; program $(NAME).bin 0x0 verify reset exit"

clean:
	rm -f *.o *.elf *.bin *.hex *.list
