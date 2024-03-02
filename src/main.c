// #include <avr/interrupt.h>
// #include <avr/io.h>
// #include <avr/sleep.h>
// #include <avr/wdt.h>
// #include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circular_buffer.h"

void init_device();

int main() {
    init_device();

    char message[100] = {0};
    uint8_t i = 0;

    for(;;) {
        // sleep_mode();
        
        /* CPU wakes up and check UART receive buffer */
        if (rx_buffer_available()) {
            char u = rx_buffer_get();
            if (u == '\r') {
                uart0_puts(message);                                // 
                uart0_puts("\r\n");
                memset(message, 0, 100);
                i = 0;
            }
            message[i++] = u;
        }
    }

    return 0;
}

void init_device() {
    init_rx_buffer();
    set_sleep_mode(0);
    sei();
}
