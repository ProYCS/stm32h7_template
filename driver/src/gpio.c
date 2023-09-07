/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/
#include "gpio.h"

int gpio_init(GPIO_INIT_STRUCT *gpio_struct)
{
    unsigned long pins;
    unsigned long mode;
    unsigned long speed;
    unsigned long pull;

    if((gpio_struct->gpio_pins & 0xFFFF0000) != 0)
        return GPIO_ERROR_INVALID_PINS;

    if(gpio_struct->gpio_mode > 3 && gpio_struct->gpio_mode != GPIO_MODE_OUTPUT_OD)
        return GPIO_ERROR_INVALID_MODE;

    if(gpio_struct->gpio_speed > 3)
        return GPIO_ERROR_INVALID_SPEED;

    if(gpio_struct->gpio_pull > 2)
        return GPIO_ERROR_INVALID_PULL;

    pins = gpio_struct->gpio_pins;
    mode = gpio_struct->gpio_mode;

    for(int i = 0; i < 16; i++)
    {
        if((pins & 0x00000001) == 0x00000001)
        {
            
            if((mode & 0x10) == 0x10)
            {
                GPIOx_MODER(gpio_struct->gpio_port) |= (mode & 0x0000000F) << (i*2); 
                GPIOx_OTYPER(gpio_struct->gpio_port) |= (pins & 0x00000001) << i;
            }
            else
            {
                GPIOx_MODER(gpio_struct->gpio_port) |= mode << (i*2); 
                GPIOx_OTYPER(gpio_struct->gpio_port) &= ~((pins & 0x00000001) << i);
            }           
        }
        pins >>= 1;
    }

    pins = gpio_struct->gpio_pins;
    speed = gpio_struct->gpio_speed;

    for(int i = 0; i < 16; i++)
    {
        if((pins & 0x00000001) == 0x00000001)
        {
            GPIOx_OSPEEDR(gpio_struct->gpio_port) |= speed << (i*2);
        }
        pins >>= 1;
    }

    pins = gpio_struct->gpio_pins;
    pull = gpio_struct->gpio_pull;

    for(int i = 0; i < 16; i++)
    {
        if((pins & 0x00000001) == 0x00000001)
        {
            GPIOx_PUPDR(gpio_struct->gpio_port) |= pull << (i*2);
        }
        pins >>= 1;
    }

    return GPIO_SUCCESS;
}

int gpio_write_pins(unsigned long gpiox,unsigned long gpio_pins,unsigned int gpio_value)
{
    GPIOx_ODR(gpiox) = gpio_value & gpio_pins;
    return GPIO_SUCCESS;
}

int gpio_write_single_pin(unsigned long gpiox,unsigned long gpio_pin,GPIO_LEVEL gpio_level)
{
    if(gpio_level == GPIO_HIGH)
        GPIOx_BSRR(gpiox) = gpio_pin;
    else if(gpio_level == GPIO_LOW)
        GPIOx_BSRR(gpiox) = gpio_pin << 16;

    return GPIO_SUCCESS;
}
