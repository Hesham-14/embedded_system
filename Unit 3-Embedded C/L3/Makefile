#@copyright : Hesham mohamed
#$< replaced by the dependencies
#$@ replaced by the target

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
#anything .c replace it with .o
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=learn_in_depth_cortex_m3

all: $(Project_name).bin
	@echo "=======Build is Done, Hesham!======="
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

#Here, it will use this target for every dependence with target .o and dependence .c
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) -mthumb $< -o $@
	
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker-script.ld $(LIBS) $(OBJ) $(ASOBJ) -Map=map_file.map -o $@


$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $(Project_name).elf $@
	
clean_all: 
	rm *.o *.elf *.bin *.map
	
clean: 
	rm *.elf *.bin *.map