CC=arm-none-eabi-gcc

TARGET=hal_library

include ../config.mk

CFLAGS =  -W -Wall -g -mcpu=cortex-m7 -mthumb -D $(TARGET_DEVICE) $(INC_FLAGS) -O1 -std=gnu11
SRC=$(shell find -name '*.c')
OBJ=$(SRC:%.c=%.o)

$(TARGET):$(OBJ)

$(OBJ):%.o:%.c
	@echo CC $<
	@$(CC) -c $< $(CFLAGS) -o $@

