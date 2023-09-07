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

/*Basic definitions*/
#define RCC_TIMED_OUT                1024

#define RCC_HSE_MODE_CRYSTAL         0x00
#define RCC_HSE_MODE_BYPASS          0x01


/*Register definitions*/
#define RCC_BASE_ADDR   0x58024400

#define RCC_CR          *(unsigned long*)(RCC_BASE_ADDR + 0x00)
#define RCC_HSICFGR     *(unsigned long*)(RCC_BASE_ADDR + 0x04)
#define RCC_CRRCR       *(unsigned long*)(RCC_BASE_ADDR + 0x08)
#define RCC_CSICFGR     *(unsigned long*)(RCC_BASE_ADDR + 0x0C)
#define RCC_CFGR        *(unsigned long*)(RCC_BASE_ADDR + 0x10)
#define RCC_D1CFGR      *(unsigned long*)(RCC_BASE_ADDR + 0x18)
#define RCC_D2CFGR      *(unsigned long*)(RCC_BASE_ADDR + 0x1C)
#define RCC_D3CFGR      *(unsigned long*)(RCC_BASE_ADDR + 0x20)
#define RCC_PLLCLKSELR  *(unsigned long*)(RCC_BASE_ADDR + 0x28)
#define RCC_PLLCFGR     *(unsigned long*)(RCC_BASE_ADDR + 0x2C)
#define RCC_PLL1DIVR    *(unsigned long*)(RCC_BASE_ADDR + 0x30)
#define RCC_PLL1FRACR   *(unsigned long*)(RCC_BASE_ADDR + 0x34)
#define RCC_PLL2DIVR    *(unsigned long*)(RCC_BASE_ADDR + 0x38)
#define RCC_PLL2FRACR   *(unsigned long*)(RCC_BASE_ADDR + 0x3C)
#define RCC_PLL3DIVR    *(unsigned long*)(RCC_BASE_ADDR + 0x40)
#define RCC_PLL3FRACR   *(unsigned long*)(RCC_BASE_ADDR + 0x44)
#define RCC_D1CCIPR     *(unsigned long*)(RCC_BASE_ADDR + 0x4C)
#define RCC_D2CCIP1R    *(unsigned long*)(RCC_BASE_ADDR + 0x50)
#define RCC_D2CCIP2R    *(unsigned long*)(RCC_BASE_ADDR + 0x54)
#define RCC_D3CCIPR     *(unsigned long*)(RCC_BASE_ADDR + 0x58)
#define RCC_CIER        *(unsigned long*)(RCC_BASE_ADDR + 0x60)

/*Return code definitions*/
#define RCC_SUCCESS                                  0
#define RCC_ERROR_HSE_READY                          1



#define RCC_ERROR_PLL_SYSCLK_OVER_HIGH_LIMITATION    1
#define RCC_ERROR_PLL_SYSCLK_UNDER_LOW_LIMITATION    2
#define RCC_ERROR_AHBCLK_OVER_HIGH_LIMITATION        3
#define RCC_ERROR_APBCLK_OVER_HIGH_LIMITATION        4

/*Functions*/
int rcc_hse_enable(unsigned char hse_mode);
int rcc_hse_disable(void);
int rcc_lse_enable(void);
int rcc_lse_disable(void);
int rcc_set_pll_frequency(unsigned long freq);

#endif
