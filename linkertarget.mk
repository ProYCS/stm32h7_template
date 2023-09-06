#select linker scripts

ifeq ($(TAREGT_DEVICE),STM32H750xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
else ifeq ($(TAREGT_DEVICE),STM32H743xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
endif

#select startup files
ifeq ($(TAREGT_DEVICE),STM32H750xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h750xx.s
endif

