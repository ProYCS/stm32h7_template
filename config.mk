TARGET = template
TAREGT_DEVICE = STM32H750xx

INC_FLAGS= -I $(TOP)/core \
           -I $(TOP)/lib/inc \
           -I $(TOP)/driver/inc \
           -I $(TOP)/startup \
           -I $(TOP)/user
