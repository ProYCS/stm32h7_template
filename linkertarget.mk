#select linker scripts

ifeq ($(TARGET_DEVICE),STM32H750xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
endif
ifeq ($(TARGET_DEVICE),STM32H743xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
endif
ifeq ($(TARGET_DEVICE),STM32H723xx)
	LINKER_SCRIPT=$(shell pwd)/link/stm32h755xx_flash_CM7.ld
endif

#select startup files
ifeq ($(TARGET_DEVICE),STM32H750xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h750xx.s
endif
ifeq ($(TARGET_DEVICE),STM32H743xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h743xx.s
endif
ifeq ($(TARGET_DEVICE),STM32H723xx)
	ASM_SRC=$(shell pwd)/startup/startup_stm32h723xx.s
endif

