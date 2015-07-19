#include "LED.h"
#include "ADC.h"
#include "switch.h"
#include "USART.h"

#include <util/delay.h>
#include <stdio.h>

char string[100];

int main(void) {
    LED_init();
    USART_init();
    switch_init();
    ADC_init();
    _delay_ms(100);
    LED_SET_D0;
    _delay_ms(100);
    LED_CLR_D0;
    _delay_ms(100);
    LED_SET_D0;
    _delay_ms(100);
    LED_CLR_D0;
    _delay_ms(100);
    if (switch_get_state())
        while (1) {
            USART_putc(USART_getc());
            LED_REV_D0;
        }
    else
        while (1) {
            int val = getADCValue(0);
            sprintf(string, "Voltage: %d", val);
            USART_puts(string);
            unsigned sw = switch_get_state();
            sprintf(string, "Switch: %d", sw);
            USART_puts(string);
            LED_REV_D0;
            _delay_ms(500);
        }
}
