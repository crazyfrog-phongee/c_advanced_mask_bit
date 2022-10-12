#ifndef MASK_BIT_H__
#define MASK_BIT_H__
#include <stdio.h>
#include <time.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

typedef enum {
    GPIO_NUM_0 = (1 << 0),
    GPIO_NUM_1 = (1 << 1),
    GPIO_NUM_2 = (1 << 2),
    GPIO_NUM_3 = (1 << 3),
    GPIO_NUM_4 = (1 << 4),
    GPIO_NUM_5 = (1 << 5),
    GPIO_NUM_6 = (1 << 6),
    GPIO_NUM_7 = (1 << 7)   
} gpio_num_t;

typedef enum {
    LOW = 0x0,
    HIGH = 0x1
} status_t;

void digitalWrite(gpio_num_t pin, status_t status);
void delay_ms(uint32_t ms);
void blink_led(gpio_num_t pin, uint32_t delay_time);
#endif