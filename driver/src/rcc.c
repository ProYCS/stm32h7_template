/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/
#include "rcc.h"
#include "gpio.h"

/*Enable HSE clock*/
int rcc_hse_enable(unsigned char hse_mode)
{
    unsigned int time_count = RCC_TIMED_OUT;
    if(hse_mode == RCC_HSE_MODE_BYPASS)
        RCC_CR |= 0x00040000; 
    else
        RCC_CR &= ~0x00040000;

    RCC_CR |= 0x00010000;

    while((RCC_CR & 0x00020000) != 0x00020000 && time_count--);

    if(time_count != 0)
        return RCC_SUCCESS;
    else    
        return RCC_ERROR_HSE_READY;
}

/*Disable HSE clock*/
int rcc_hse_disable(void)
{

}

int rcc_gpio_enable(unsigned long gpiox)
{
    int result;
    switch(gpiox)
    {
        case GPIOA:RCC_AHB4ENR |= 0x00000001;
                   result = RCC_SUCCESS;
                   break;
        case GPIOB:RCC_AHB4ENR |= 0x00000002;
                   result = RCC_SUCCESS;
                   break;
        case GPIOC:RCC_AHB4ENR |= 0x00000004;
                   result = RCC_SUCCESS;
                   break;
        case GPIOD:RCC_AHB4ENR |= 0x00000008;
                   result = RCC_SUCCESS;
                   break;
        case GPIOE:RCC_AHB4ENR |= 0x00000010;
                   result = RCC_SUCCESS;
                   break;
        case GPIOF:RCC_AHB4ENR |= 0x00000020;
                   result = RCC_SUCCESS;
                   break;
        case GPIOG:RCC_AHB4ENR |= 0x00000040;
                   result = RCC_SUCCESS;
                   break;
        default:result = RCC_ERROR_INVALID_PARAMETER;
                break
    }
    return result;
}

int rcc_gpio_disable(unsigned long gpiox)
{
    int result;
    switch(gpiox)
    {
        case GPIOA:RCC_AHB4ENR &=~ 0x00000001;
                   result = RCC_SUCCESS;
                   break;
        case GPIOB:RCC_AHB4ENR &=~ 0x00000002;
                   result = RCC_SUCCESS;
                   break;
        case GPIOC:RCC_AHB4ENR &=~ 0x00000004;
                   result = RCC_SUCCESS;
                   break;
        case GPIOD:RCC_AHB4ENR &=~ 0x00000008;
                   result = RCC_SUCCESS;
                   break;
        case GPIOE:RCC_AHB4ENR &=~ 0x00000010;
                   result = RCC_SUCCESS;
                   break;
        case GPIOF:RCC_AHB4ENR &=~ 0x00000020;
                   result = RCC_SUCCESS;
                   break;
        case GPIOG:RCC_AHB4ENR &=~ 0x00000040;
                   result = RCC_SUCCESS;
                   break;
        default:result = RCC_ERROR_INVALID_PARAMETER;
                break
    }
    return result;
}
