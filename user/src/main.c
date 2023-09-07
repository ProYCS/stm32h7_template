#include"stm32h7xx_hal.h"
#include"gpio.h"

int main(void)
{
    GPIO_INIT_STRUCT gpio_initstruct;
    gpio_initstruct.gpio_port = GPIOE;
    gpio_initstruct.gpio_pins = GPIO_PIN_3;
    gpio_initstruct.gpio_mode = GPIO_MODE_OUTPUT_PP;
    gpio_initstruct.gpio_speed = GPIO_SPEED_HIGH;
    gpio_initstruct.gpio_pull = GPIO_PULL_NOPULL;
    gpio_init(&gpio_initstruct);
    while(1)
    {
        gpio_write_single_pin(GPIOE,GPIO_PIN_3,GPIO_HIGH);
        for(int i=0;i<10000;i++);
        gpio_write_single_pin(GPIOE,GPIO_PIN_3,GPIO_LOW);
        for(int i=0;i<10000;i++);
    }
}
