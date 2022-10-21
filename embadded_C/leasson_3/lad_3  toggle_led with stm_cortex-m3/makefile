#@copyright : ahmedshaban
project_name =leaen-in-depth-cortex-m3
CC=arm-none-eabi-
CFLAGES= -mcpu=cortex-m3 -gdwarf-2
INCS=-I.
LIBS=
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s) 
ASOBJ = $(AS:.s=.o)
all:$(project_name).bin
	@echo "<<<<<<<<<build is done <Ahmed> >>>>>>>>>>>"
startup.o : startup.s
	$(CC)as.exe $(CFLAGES) $< -o $@
%.o :%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGES) $< -o $@ 
$(project_name).elf: $(OBJ) $(ASOBJ) 
	$(CC)ld.exe -T linkerscript.ld $(LIBS ) $(OBJ) $(ASOBJ) -o $@ 
	
$(project_name).bin : $(project_name).elf
	$(CC)objcopy.exe  -O binary $<  $@  
clean_all:
	rm *.o *.elf *.bin
	@echo "<<<<<<<<<remove all file is done <Ahmed> >>>>>>>>>>>"
clean:
	rm *.elf *.bin 
	@echo "<<<<<<<<<remove .elf and .bin file is done <Ahmed> >>>>>>>>>>>"
	