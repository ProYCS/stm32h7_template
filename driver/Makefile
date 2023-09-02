CC=arm-none-eabi-gcc

TARGET=driver

INC_FLAGS= -I ../core \
           -I ../lib/inc \
	   -I ../driver/inc \
           -I ../startup \
           -I ../user/inc
CFLAGS =  -W -Wall -g -mcpu=cortex-m7 -mthumb -D $(DEVICE) $(INC_FLAGS) -O3 -std=gnu11
SRC=$(shell find -name '*.c')
OBJ=$(SRC:%.c=%.o)

$(TARGET):$(OBJ)

$(OBJ):%.o:%.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo CC $<
