PROJECT = template
TAREGT_DEVICE = STM32H750xx

INC_FLAGS= -I $(TOP)/core \
           -I $(TOP)/hal_library/inc \
           -I $(TOP)/driver/dac \
           -I $(TOP)/startup \
           -I $(TOP)/user/inc
