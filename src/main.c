#include "test_procedures.h"
#include "LED.h"
#include "USART.h"
#include "switch.h"
#include "ADC.h"

#include <util/delay.h>
#include <stdio.h>

char string[100];

void blink_error(int count, double sleep)
{
    while (1) {
        for (int i=0; i<count; i++) {
            LED_SET_D0;
            _delay_ms(100);
            LED_CLR_D0;
            _delay_ms(100);
        }
        _delay_ms(sleep);
    }
}

int main(void) {
    LED_init();
    USART_init();
    switch_init();
    ADC_init();

    int result = test_led();

    if (result != 0)
        blink_error(1, 500);

    result = test_switch();

    if (result != 0)
        blink_error(2, 400);

    result = test_adc();

    if (result != 0)
        blink_error(3, 300);

    result = test_hc05();
    if (result != 0)
        blink_error(4, 200);

    LED_SET_D0;
//    if (switch_get_state())
//        while (1) {
//            USART_putc(USART_getc());
//            LED_REV_D0;
//        }
//    else
//        while (1) {
//            int val = ADC_convert2mV(ADC_getValue(0));
//            sprintf(string, "Voltage: %d", val);
//            USART_puts(string);
//            unsigned sw = switch_get_state();
//            sprintf(string, "Switch: %d", sw);
//            USART_puts(string);
//            LED_REV_D0;
//            _delay_ms(500);
//        }
}
