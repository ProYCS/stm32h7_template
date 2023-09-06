include config.mk
include linkertarget.mk

CC             = arm-none-eabi-gcc           
AS             = arm-none-eabi-as
LD             = arm-none-eabi-ld
OBJCOPY        = arm-none-eabi-objcopy

TOP=$(shell pwd)

CFLAGS =  -W -Wall -g -mcpu=cortex-m7 -mthumb  $(INC_FLAGS) -O3 -std=gnu11
ASFLAGS = -W -Wall -g -Wall -mcpu=cortex-m7 -mthumb

C_SRC=$(shell find ./ -name '*.c')  
C_OBJ=$(C_SRC:%.c=%.o)          
DIR=lib driver startup user
#ASM_SRC=$(shell find ./ -name '*.s')
ASM_OBJ=$(ASM_SRC:%.s=%.o)

.PHONY: all clean $(DIR)

all:$(DIR)
	@echo LINK $(PROJECT)
	@echo Using $(LINKER_SCRIPT)
	@$(CC) $(C_OBJ) $(ASM_OBJ) -T $(LINKER_SCRIPT) -o $(PROJECT).elf  -mthumb -mcpu=cortex-m7 -Wl,--start-group -lc -lm -Wl,--end-group -specs=nano.specs -specs=nosys.specs -static -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(PROJECT).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80
	@echo OBJCOPY $(PROJECT).elf  $(PROJECT).bin
	@$(OBJCOPY) $(PROJECT).elf  $(PROJECT).bin -Obinary
	@echo OBJCOPY $(PROJECT).elf  $(PROJECT).hex
	@$(OBJCOPY) $(PROJECT).elf  $(PROJECT).hex -Oihex
	
$(DIR):
	@make -C $@ DEVICE=$(TAREGT_DEVICE) TOP=$(TOP) ASM_SRC=$(ASM_SRC)

clean:
	@rm -f $(shell find ./ -name '*.o')
	@rm -f $(shell find ./ -name '*.d')
	@rm -f $(shell find ./ -name '*.map')
	@rm -f $(shell find ./ -name '*.elf')
	@rm -f $(shell find ./ -name '*.bin')
	@rm -f $(shell find ./ -name '*.hex')
	@echo Clean up.
	



