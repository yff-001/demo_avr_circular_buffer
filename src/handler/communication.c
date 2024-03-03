#include "communication.h"
#include "../circular_buffer.h"
#include "../driver/uart.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdlib.h>
#include <string.h>

void init_communication() {
    set_sleep_mode(0);
    sei();
}

void handle_communication() {
    char message[100] = {0};
    int i = 0;

    for (;;) {
        /* CPU wakes up and checks buffer */
        if (rx_buffer_available()) {
            char u = rx_buffer_get();
            if (u == '\r') {
                uart0_puts(message);
                uart0_puts("\r\n");
                memset(message, 0, 100);
                i = 0;
            }
            message[i++] = u;
        }

        sleep_mode();
    }
}
