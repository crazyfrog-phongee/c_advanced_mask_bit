#include <stdio.h>
#include "mask_bit.c"

int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_NUM_0, HIGH);
    digitalWrite(GPIO_NUM_7, HIGH);
    clock_t start, end;
    start = clock();
    blink_led(GPIO_NUM_3, 1000);
    blink_led(GPIO_NUM_3, 1000);
    end = clock();
    printf("%f", (double)(end - start));
    return 0;
}


