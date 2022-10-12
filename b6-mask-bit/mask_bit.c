#include "mask_bit.h"

uint8_t PORTA = 0x00;

void digitalWrite(gpio_num_t pin, status_t status) {
    if(status == HIGH) {
        PORTA |= pin;
    } else {
        PORTA &= ~pin;
    }
}

void delay_ms(uint32_t ms) {
    clock_t start = clock();
    while (ms > 0) {
        while ((ms > 0) && ((clock() - start) >= 1)) {
            ms--;
            start += 1;
        }
    }
}

void blink_led(gpio_num_t pin, uint32_t delay_time) {
    PORTA ^= pin;
    delay_ms(delay_time);
}