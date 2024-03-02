#include "handler/circular_buffer.h"
#include "handler/device.h"

/*  this part are necessary to make code block inside while loop work
    they can be removed to achieve a minimal program
*/
#include <avr/sleep.h>
#include <stdlib.h>
#include <string.h>
#include "driver/uart.h"

int main() {
    init_device();
    init_rx_buffer();

    char message[100] = {0};
    int i = 0;

    for(;;) {
        sleep_mode();
        
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
