#include "st7735.h"

SPI_HandleTypeDef spi4;


void st7735_write_cmd(unsigned char cmd)
{
    HAL_GPIO_WritePin(LCD_PORT,LCD_RS,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_PORT,LCD_CS,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&spi4,&cmd,1,0);
    HAL_GPIO_WritePin(LCD_PORT,LCD_CS,GPIO_PIN_SET);
}

void st7735_write_data(unsigned char data)
{
    HAL_GPIO_WritePin(LCD_PORT,LCD_RS,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LCD_PORT,LCD_CS,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&spi4,&data,1,0);
    HAL_GPIO_WritePin(LCD_PORT,LCD_CS,GPIO_PIN_SET);
}

void st7735_led_start(void)
{
    HAL_GPIO_WritePin(LCD_PORT,LCD_LED,GPIO_PIN_RESET);
}

void st7735_led_stop(void)
{
	HAL_GPIO_WritePin(LCD_PORT,LCD_LED,GPIO_PIN_SET);
}

void st7735_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI4;
    PeriphClkInitStruct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_D2PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
    __HAL_RCC_SPI4_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitStruct.Pin = LCD_CS|LCD_RS|LCD_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_14;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI4;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    spi4.Instance = SPI4;
    spi4.Init.Mode = SPI_MODE_MASTER;
    spi4.Init.Direction = SPI_DIRECTION_2LINES_TXONLY;
    spi4.Init.DataSize = SPI_DATASIZE_8BIT;
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

    HAL_GPIO_WritePin(LCD_PORT,LCD_CS,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LCD_PORT,LCD_RS,GPIO_PIN_SET);

    st7735_led_start();

    //st7735_write_cmd(0x28);

	st7735_write_cmd(0x01);

	st7735_write_cmd(0x11);//Sleep exit

	//ST7735R Frame Rate
	st7735_write_cmd(0xB1);
	st7735_write_data(0x02);
	st7735_write_data(0x35);
	st7735_write_data(0x36);

	st7735_write_cmd(0xB2);
	st7735_write_data(0x02);
	st7735_write_data(0x35);
	st7735_write_data(0x36);

	st7735_write_cmd(0xB3);
	st7735_write_data(0x02);
	st7735_write_data(0x35);
	st7735_write_data(0x36);
	st7735_write_data(0x02);
	st7735_write_data(0x35);
	st7735_write_data(0x36);

	st7735_write_cmd(0xB4); //Column inversion
	st7735_write_data(0x03);

	//ST7735R Power Sequence
	st7735_write_cmd(0xC0);
	st7735_write_data(0xA2);
	st7735_write_data(0x02);
	st7735_write_data(0x84);
	st7735_write_cmd(0xC1);
	st7735_write_data(0xC5);

	st7735_write_cmd(0xC2);
	st7735_write_data(0x0D);
	st7735_write_data(0x00);

	st7735_write_cmd(0xC3);
	st7735_write_data(0x8D);
	st7735_write_data(0x2A);
	st7735_write_cmd(0xC4);
	st7735_write_data(0x8D);
	st7735_write_data(0xEE);

	st7735_write_cmd(0xC5); //VCOM
	st7735_write_data(0x0A);

	st7735_write_cmd(0x36); //MX, MY, RGB mode
	st7735_write_data(0xEC); //竖屏C8 横屏08 A8

	//ST7735R Gamma Sequence
	st7735_write_cmd(0xE0);
	st7735_write_data(0x12);
	st7735_write_data(0x1C);
	st7735_write_data(0x00);
	st7735_write_data(0x18);
	st7735_write_data(0x33);
	st7735_write_data(0x2C);
	st7735_write_data(0x25);
	st7735_write_data(0x28);
	st7735_write_data(0x28);
	st7735_write_data(0x27);
	st7735_write_data(0x2F);
	st7735_write_data(0x3C);
	st7735_write_data(0x00);
	st7735_write_data(0x03);
	st7735_write_data(0x03);
	st7735_write_data(0x10);

	st7735_write_cmd(0xE1);
	st7735_write_data(0x12);
	st7735_write_data(0x1C);
	st7735_write_data(0x10);
	st7735_write_data(0x18);
	st7735_write_data(0x2D);
	st7735_write_data(0x28);
	st7735_write_data(0x23);
	st7735_write_data(0x28);
	st7735_write_data(0x28);
	st7735_write_data(0x26);
	st7735_write_data(0x2F);
	st7735_write_data(0x3B);
	st7735_write_data(0x00);
	st7735_write_data(0x03);
	st7735_write_data(0x03);
	st7735_write_data(0x10);

	//st7735_write_cmd(0xF0); //Enable test command
	//st7735_write_data(0x01);
	//st7735_write_cmd(0xF6); //Disable ram power save mode
	//st7735_write_data(0x00);

	st7735_write_cmd(0x3A); //65k mode
	st7735_write_data(0x05);

	st7735_write_cmd(0x29);//Display on
}

void st7735_set_pos(POS *start_pos,POS *end_pos)
{
    st7735_write_cmd(0x2a);
	st7735_write_data(0x00);
	st7735_write_data(start_pos->x+2);
	st7735_write_data(0x00);
	st7735_write_data(end_pos->x+2);

	st7735_write_cmd(0x2b);
	st7735_write_data(0x00);
	st7735_write_data(start_pos->y+3);
	st7735_write_data(0x00);
	st7735_write_data(end_pos->y+3);

	st7735_write_cmd(0x2c);
}

void st7735_write_2_bytes(unsigned int data)
{
    st7735_write_data(data>>8);
	st7735_write_data(data);
}

void st7735_fill_color(unsigned int color)
{
	unsigned char x = 0;
	unsigned char y = 0;
	POS startpos;
	POS stoppos;
	startpos.x = 0;
	startpos.y = 0;
	stoppos.x = 127;
	stoppos.y = 127;
	st7735_set_pos(&startpos,&stoppos);
	for ( y = 0; y < 127; y++ ) {
		for ( x = 0; x < 127; x++ ) {
			st7735_write_2_bytes(color);
		}
	}
}
