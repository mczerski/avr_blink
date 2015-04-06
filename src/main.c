#include <util/delay.h>
#include "LED.h"

int main(void) {

    LED_init();
    while (1) {
        _delay_ms(200);
        LED_REV_D0;
    }
}
