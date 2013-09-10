include ./makefile.conf
NAME=LPC1769-Blinky
STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

LDSCRIPTS=-L. -L$(BASE)/ldscripts -T gcc.ld
LFLAGS=$(USE_NANO) $(USE_NOHOST) $(LDSCRIPTS) $(GC) $(MAP)

all: $(NAME)-$(CORE).axf $(NAME)-$(CORE).bin

$(NAME)-$(CORE).axf: $(NAME).c lpc1700/system_LPC17xx.c $(STARTUP)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@
	
$(NAME)-$(CORE).bin:$(NAME)-$(CORE).axf
	$(OBJCOPY) -O binary $(NAME)-$(CORE).axf $(NAME)-$(CORE).bin

clean: 
	rm -f $(NAME)*.axf *.map $(NAME)*.bin
