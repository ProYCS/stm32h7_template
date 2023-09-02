#include"stm32h7xx_hal.h"

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    HAL_Init();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    while(1)
    {
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
        HAL_Delay(100);
        //for(long i=0;i<1000000;i++);
        HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
        HAL_Delay(100);
        //for(long i=0;i<1000000;i++);
    }
}
