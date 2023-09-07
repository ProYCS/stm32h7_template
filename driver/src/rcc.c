/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/
#include "rcc.h"

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
