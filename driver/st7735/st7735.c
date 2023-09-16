#include "st7735.h"

SPI_HandleTypeDef spi3;

void st7735_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Pin = LCD_CS|LCD_RS|LCD_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LCD_SDA|LCD_SCL;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

    spi3.Instance = SPI3;
    spi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    spi3.Init.Direction = SPI_DIRECTION_2LINES;
    spi3.Init.CLKPhase = SPI_PHASE_1EDGE;
    spi3.Init.CLKPolarity = SPI_POLARITY_LOW;
    spi3.Init.DataSize = SPI_DATASIZE_8BIT;
    spi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
    spi3.Init.TIMode = SPI_TIMODE_DISABLE;
    spi3.Init.CRC.Calculation = SPI_CRCCALCULATION_DISABLE;
    spi3.Init.CRCPolynomial = 7;
    spi3.Init.NSS = SPI_NSS_SOFT;
    spi3.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_ENABLE;
    spi3.Init.Mode = SPI_MODE_MASTER;
    HAL_SPI_Init(&spi3);
}
