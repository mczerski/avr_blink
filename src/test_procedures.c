#include "LED.h"
#include "switch.h"
#include "ADC.h"
#include "USART.h"

#include <util/delay.h>
#include <string.h>

int test_led() {
    _delay_ms(100);
    LED_SET_D0;
    _delay_ms(100);
    LED_CLR_D0;
    _delay_ms(100);
    LED_SET_D0;
    _delay_ms(100);
    LED_CLR_D0;
    _delay_ms(100);

    return 0;
}

int test_switch() {
    unsigned val = switch_get_state();
    if (val == 1)
        return 0;
    else
        return -1;
}

int test_adc() {
    int voltage_mV = ADC_convert2mV(ADC_getValue(0));
    if (voltage_mV > 2000 && voltage_mV < 5500)
        return 0;
    else
        return -1;
}

static char response[20];

static int check_response() {
    memset(response, 0, sizeof(response));
    USART_gets(response, sizeof(response));
    if (strcmp(response, "OK") != 0)
        return -1;
    else
        return 0;
}

int test_hc05() {
    USART_puts("AT");
    if (check_response() != 0)
        return -1;
    USART_puts("AT+NAME=led1");
    if (check_response() != 0)
        return -1;
    USART_puts("AT+UART=115200,1,0");
    if (check_response() != 0)
        return -1;
    return 0;
}
