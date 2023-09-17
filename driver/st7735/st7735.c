#include "st7735.h"

SPI_HandleTypeDef spi4;

void st7735_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = LCD_CS|LCD_RS|LCD_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI4;
    PeriphClkInitStruct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_D2PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
    __HAL_RCC_SPI4_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_14;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI4;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    spi4.Instance = SPI4;
    spi4.Init.Mode = SPI_MODE_MASTER;
    spi4.Init.Direction = SPI_DIRECTION_2LINES_TXONLY;
    spi4.Init.DataSize = SPI_DATASIZE_4BIT;
    spi4.Init.CLKPolarity = SPI_POLARITY_LOW;
    spi4.Init.CLKPhase = SPI_PHASE_1EDGE;
    spi4.Init.NSS = SPI_NSS_SOFT;
    spi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    spi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
    spi4.Init.TIMode = SPI_TIMODE_DISABLE;
    spi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    spi4.Init.CRCPolynomial = 0x0;
    spi4.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
    spi4.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    spi4.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    spi4.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    spi4.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    spi4.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
    spi4.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    spi4.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    spi4.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    spi4.Init.IOSwap = SPI_IO_SWAP_DISABLE;
    HAL_SPI_Init(&spi4);
}
