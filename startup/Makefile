CC=arm-none-eabi-gcc

TARGET=startup

include ../config.mk

CFLAGS =  -W -Wall -g -mcpu=cortex-m7 -mthumb -D $(TARGET_DEVICE) $(INC_FLAGS) -O1 -std=gnu11
#ASM_SRC=$(shell find ./ -name '*.s')
ASM_OBJ=$(ASM_SRC:%.s=%.o)

$(TARGET):$(ASM_OBJ)

$(ASM_OBJ):%.o:%.s
	@echo AS $<
	@$(CC) -c $<  $(ASFLAGS) -o $@ 

