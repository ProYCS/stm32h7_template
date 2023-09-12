#include"stm32h7xx_hal.h"

void STM32_Clock_Init(unsigned long plln,unsigned long pllm,unsigned long pllp,unsigned long pllq)
{
    HAL_StatusTypeDef ret=HAL_OK;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;
    MODIFY_REG(PWR->CR3,PWR_CR3_SCUEN, 0);

    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    while ((PWR->D3CR & (PWR_D3CR_VOSRDY)) != PWR_D3CR_VOSRDY) {}

    RCC_OscInitStruct.OscillatorType=RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState=RCC_HSE_ON;
    RCC_OscInitStruct.HSIState=RCC_HSI_OFF;
    RCC_OscInitStruct.CSIState=RCC_CSI_OFF;
    RCC_OscInitStruct.PLL.PLLState=RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource=RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLN=plln;
    RCC_OscInitStruct.PLL.PLLM=pllm;
    RCC_OscInitStruct.PLL.PLLP=pllp;
    RCC_OscInitStruct.PLL.PLLQ=pllq;
    RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
    ret=HAL_RCC_OscConfig(&RCC_OscInitStruct);
    //if(ret!=HAL_OK) while(1);

    RCC_ClkInitStruct.ClockType=(RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_D1PCLK1|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2|RCC_CLOCKTYPE_D3PCLK1);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
    ret=HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
    //if(ret!=HAL_OK) while(1);

    __HAL_RCC_CSI_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    HAL_EnableCompensationCell();
}

void delay(void)
{
    volatile long i = 10000000;
    volatile long j;
    while(i--){
        j++;
    }
}

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    STM32_Clock_Init(160,5,2,4);
    //SystemCoreClockUpdate();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    HAL_Init();

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    while(1)
    {
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
        //HAL_Delay(100);
        //for(long i=0;i<100000;i++);
        delay();
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
        delay();
        //for(long i=0;i<100000;i++);
        //HAL_Delay(100);
    }
}
