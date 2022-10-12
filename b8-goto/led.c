#include "main.h"

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

void turn_on_all(void) {
    for (int i = 0; i < count; i++) {
        digitalWrite(arr_led[i], HIGH);
    }
}

void turn_off_all(void) {
    for (int i = 0; i < count; i++) {
        digitalWrite(arr_led[i], LOW);
    }
}

void blink_led(void) {
    while (1) {
        turn_on_all();
        delay(1000);
        if (delay_checks() == 2)
        {
        goto Out;
        }
        turn_off_all();
        delay(1000);
    }
    Out:
    temp = 1;
}

void sequential_led(void) {
    while (1) {
        for (int i = 0; i < count; i++) {

        if (delay_checks() == 1) {
            goto Out;
        }
        digitalWrite(arr_led[i], HIGH);
        delay(1000);
        digitalWrite(arr_led[i], LOW);
        }
    }
    Out:
    temp = 2;
}

BUTTON_MODE button_press(void) {
    if (digitalRead(BUTTON_BLINK_LED) == 1) {
        return BLINK_LED;
    }
    else if (digitalRead(BUTTON_SEQUENTIAL_LED) == 1) {
        return SEQUENTIAL_LED;
    }
    else {
        return BTN_OFF;
    }
}

int delay_checks(void) {
  BUTTON_MODE button;
  button = button_press();
  switch (button) {
    case BLINK_LED:
        blink_led();
        return 1;
        break;
    case SEQUENTIAL_LED:
        sequential_Led();
        return 2;
        break;
    case BTN_OFF:
        turn_off_all();
        return 0;
        break;
    default:
        break;
    }
}