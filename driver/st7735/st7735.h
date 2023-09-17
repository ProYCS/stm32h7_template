#ifndef _ST7735_H
#define _ST7735_H

#include "stm32h7xx_hal.h"

#define LCD_PORT    GPIOE
#define LCD_SDA     GPIO_PIN_14
#define LCD_SCL     GPIO_PIN_12
#define LCD_CS      GPIO_PIN_11
#define LCD_RS      GPIO_PIN_13
#define LCD_LED     GPIO_PIN_10

typedef struct
{
    int x;
    int y;
} POS;

void st7735_init(void);
void st7735_led_start(void);
void st7735_led_stop(void);
void st7735_set_pos(POS *start_pos,POS *end_pos);
void st7735_write_2_bytes(unsigned int data);
void st7735_fill_color(unsigned int color);

#endif
