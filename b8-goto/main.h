#ifndef MAIN_H__
#define MAIN_H__
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

#define BUTTON_BLINK_LED        4
#define BUTTON_SEQUENTIAL_LED   6

typedef enum {
  BLINK_LED,
  SEQUENTIAL_LED,
  BTN_OFF
} BUTTON_MODE;

typedef enum {
  TURN_OFF_BLINK_LED,
  TURN_OFF_SEQUENTIAL_LED
} STATUS;

typedef enum {
    LOW = 0x0,
    HIGH = 0x1
} status_t;


uint8_t arr_led[] = {8, 9, 11, 12, 13};
uint8_t count = 5;
uint8_t temp = 1;


void digitalWrite(gpio_num_t pin, status_t status);
void delay_ms(uint32_t ms);
void blink_led(void);

void turn_on_all(void);
void turn_off_all(void);
void sequential_led(void);
BUTTON_MODE button_press(void);
int delay_checks(void);


#endif