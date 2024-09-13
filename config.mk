PROJECT = template
TARGET_DEVICE = STM32H723xx

INC_FLAGS= -I $(TOP)/core \
           -I $(TOP)/hal_library/inc \
           -I $(TOP)/startup \
           -I $(TOP)/user/inc \
           -I $(TOP)/user/inc/devices

