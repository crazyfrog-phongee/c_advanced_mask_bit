#include <stdio.h>
#include "main.h"

uint8_t PORTA = 0x00;

void digitalWrite(gpio_num_t pin, status_t status) {
    if(status == HIGH) {
        PORTA |= pin;
    } else {
        PORTA &= ~pin;
    }
}

void delay_ms(unsigned int ms) {
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


int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_NUM_0, HIGH);
    digitalWrite(GPIO_NUM_7, HIGH);
    blink_led(GPIO_NUM_3, 1000);
    blink_led(GPIO_NUM_3, 1000);
    return 0;
}


