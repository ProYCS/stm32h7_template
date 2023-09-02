TARGET = template
TAREGT_DEVICE = STM32H750xx


CC             = arm-none-eabi-gcc           
AS             = arm-none-eabi-as
LD             = arm-none-eabi-ld
OBJCOPY        = arm-none-eabi-objcopy

TOP=$(shell pwd)

INC_FLAGS= -I $(TOP)/core \
           -I $(TOP)/lib/inc \
           -I $(TOP)/driver/inc \
           -I $(TOP)/startup \
           -I $(TOP)/user

CFLAGS =  -W -Wall -g -mcpu=cortex-m7 -mthumb  $(INC_FLAGS) -O3 -std=gnu11
ASFLAGS = -W -Wall -g -Wall -mcpu=cortex-m7 -mthumb

C_SRC=$(shell find ./ -name '*.c')  
C_OBJ=$(C_SRC:%.c=%.o)          
DIR=lib driver startup user
ASM_SRC=$(shell find ./ -name '*.s')
ASM_OBJ=$(ASM_SRC:%.s=%.o)

.PHONY: all clean $(DIR)

all:$(DIR)
	@echo LINK $(TARGET)
	@$(CC) $(C_OBJ) $(ASM_OBJ) -T ./link/stm32h755xx_flash_CM7.ld -o $(TARGET).elf  -mthumb -mcpu=cortex-m7 -Wl,--start-group -lc -lm -Wl,--end-group -specs=nano.specs -specs=nosys.specs -static -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(TARGET).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80
	@echo OBJCOPY $(TARGET).elf  $(TARGET).bin
	@$(OBJCOPY) $(TARGET).elf  $(TARGET).bin -Obinary 
	@echo OBJCOPY $(TARGET).elf  $(TARGET).hex
	@$(OBJCOPY) $(TARGET).elf  $(TARGET).hex -Oihex
	
$(DIR):
	@make -C $@ DEVICE=$(TAREGT_DEVICE)

clean:
	@rm -f $(shell find ./ -name '*.o')
	@rm -f $(shell find ./ -name '*.d')
	@rm -f $(shell find ./ -name '*.map')
	@rm -f $(shell find ./ -name '*.elf')
	@rm -f $(shell find ./ -name '*.bin')
	@rm -f $(shell find ./ -name '*.hex')
	@echo Clean up.
	



