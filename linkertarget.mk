ifeq($(TARGET),STM32H750xx)
	LINKER_SCRIPT=./link/stm32h755xx_flash_CM7.ld

ifeq($(TARGET),STM32H743xx)
	LINKER_SCRIPT=./link/stm32h755xx_flash_CM7.ld
