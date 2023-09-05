/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/

#ifndef _RCC_H
#define _RCC_H

/*Register definitions*/
#define RCC_BASE_ADDR   0x40023800

#define RCC_CR          *(unsigned long*)(RCC_BASE_ADDR + 0x00)
#define RCC_PLLCFGR     *(unsigned long*)(RCC_BASE_ADDR + 0x04)
#define RCC_CFGR        *(unsigned long*)(RCC_BASE_ADDR + 0x08)
#define RCC_CIR         *(unsigned long*)(RCC_BASE_ADDR + 0x0C)

/*Return code definitions*/
#define RCC_SUCCESS                                  0
#define RCC_ERROR_PLL_SYSCLK_OVER_HIGH_LIMITATION    1
#define RCC_ERROR_PLL_SYSCLK_UNDER_LOW_LIMITATION    2
#define RCC_ERROR_AHBCLK_OVER_HIGH_LIMITATION        3

/*Functions*/
int rcc_enable_high_external_crystal(void);
int rcc_disable_high_external_crystal(void);
int rcc_enable_low_external_crystal(void);
int rcc_disbale_low_external_crystal(void);
int rcc_set_pll_frequency(unsigned long freq);

#endif
