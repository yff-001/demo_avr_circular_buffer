#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

void init_rx_buffer();
uint8_t rx_buffer_available();
uint8_t rx_buffer_get();
uint8_t rx_buffer_put(uint8_t value);

#endif