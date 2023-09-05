/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/

#ifndef _GPIO_H
#define _GPIO_H

/*Basic definitions*/
#define GPIO_BASE_ADDR        0x58020000

#define GPIOA                 0x00000000
#define GPIOB                 0x00000400
#define GPIOC                 0x00000800
#define GPIOD                 0x00000C00
#define GPIOE                 0x00001000
#define GPIOF                 0x00001400
#define GPIOG                 0x00001800
#define GPIOH                 0x00001C00
#define GPIOI                 0x00002000

#define GPIO_PIN_0            0x00000001
#define GPIO_PIN_1            0x00000002
#define GPIO_PIN_2            0x00000004
#define GPIO_PIN_3            0x00000008
#define GPIO_PIN_4            0x00000010
#define GPIO_PIN_5            0x00000020
#define GPIO_PIN_6            0x00000040
#define GPIO_PIN_7            0x00000080
#define GPIO_PIN_8            0x00000100
#define GPIO_PIN_9            0x00000200
#define GPIO_PIN_10           0x00000400
#define GPIO_PIN_11           0x00000800
#define GPIO_PIN_12           0x00001000
#define GPIO_PIN_13           0x00002000
#define GPIO_PIN_14           0x00004000
#define GPIO_PIN_15           0x00008000

#define GPIO_PIN_ALL          0x0000FFFF

#define GPIO_MODE_INPUT       0x00
#define GPIO_MODE_OUTPUT_PP   0x01
#define GPIO_MODE_OUTPUT_OD   0x11
#define GPIO_MODE_AF          0x02
#define GPIO_MODE_ANALOG      0x03

#define GPIO_SPEED_LOW        0
#define GPIO_SPEED_MEDIUM     1
#define GPIO_SPEED_HIGH       2
#define GPIO_SPEED_VERY_HIGH  3

typedef enum {
    GPIO_HIGH = 0x00,
    GPIO_LOW  = 0x01
}GPIO_LEVEL;

/*Register definitions*/
#define GPIOx_MODER(gpiox)    *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x00)
#define GPIOx_OTYPER(gpiox)   *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x04)
#define GPIOx_OSPEEDR(gpiox)  *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x08)
#define GPIOx_PUPDR(gpiox)    *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x0C)
#define GPIOx_IDR(gpiox)      *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x10)
#define GPIOx_ODR(gpiox)      *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x14)
#define GPIOx_BSRR(gpiox)     *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x18)
#define GPIOx_LCKR(gpiox)     *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x1C)
#define GPIOx_AFRL(gpiox)     *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x20)
#define GPIOx_AFRH(gpiox)     *(unsigned long*)(GPIO_BASE_ADDR + gpiox + 0x24)

/*Struct definitions*/
typedef struct {
    unsigned long gpio_port;
    unsigned long gpio_pins;
    unsigned long gpio_mode;
    unsigned long gpio_speed;
    unsigned long gpio_pull;
} GPIO_INIT_STRUCT;

/*Return code definitions*/
#define GPIO_SUCCESS                    0
#define GPIO_ERROR_INVALID_PINS         1
#define GPIO_ERROR_INVALID_MODE         2
#define GPIO_ERROR_INVALID_SPEED        3
#define GPIO_ERROR_INVALID_PULL         4


/*Functions*/
int gpio_init(GPIO_INIT_STRUCT *gpio_struct);
int gpio_write_pins(unsigned long gpiox,unsigned long gpio_pins,unsigned int gpio_value);
int gpio_read_pins(unsigned long gpiox,unsigned long gpio_pins,unsigned int *gpio_value);
int gpio_write_single_pin(unsigned long gpiox,unsigned long gpio_pin,GPIO_LEVEL gpio_level);
int gpio_read_single_pin(unsigned long gpiox,unsigned long gpio_pin,GPIO_LEVEL *gpio_level);

#endif
