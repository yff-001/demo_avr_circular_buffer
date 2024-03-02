#include "circular_buffer.h"
#include "../driver/uart.h"

#define BUFFER_SIZE  8

volatile uint8_t rx_buffer[BUFFER_SIZE] = {0};
volatile uint8_t rx_buffer_index = 0;
volatile uint8_t rx_buffer_head = 0;
volatile uint8_t rx_buffer_tail = 0;

void init_rx_buffer() {
    uart0_init(&rx_buffer_put);
}

uint8_t rx_buffer_available() {
    return (BUFFER_SIZE + rx_buffer_head - rx_buffer_tail) % BUFFER_SIZE;
}

uint8_t rx_buffer_get() {
    uint8_t ret = rx_buffer[rx_buffer_tail];
    rx_buffer_tail = (rx_buffer_tail + 1) % BUFFER_SIZE;
    return ret;
}

uint8_t rx_buffer_put(uint8_t value) {
    rx_buffer_index = (rx_buffer_index + 1) % BUFFER_SIZE;
    if (rx_buffer_index != rx_buffer_tail) {                        // if buffer is full, discard u
        rx_buffer[rx_buffer_head] = value;
        rx_buffer_head = rx_buffer_index;
    }
}
