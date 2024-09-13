#select linker scripts

ifeq ($(TAREGT_DEVICE),STM32H750xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
else ifeq ($(TAREGT_DEVICE),STM32H743xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
else ifeq ($(TARGET_DEVICE),STM32H723xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
endif

#select startup files
ifeq ($(TAREGT_DEVICE),STM32H750xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h750xx.s
else ifeq ($(TARGET_DEVICE),STM32H743xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h743xx.s
else ifeq ($(TARGET_DEVICE),STM32H723xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h723xx.s
endif

