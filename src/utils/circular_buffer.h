#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

struct circular_buffer_t {
    uint8_t* buffer;
    uint8_t head;
    uint8_t tail;
    uint8_t maxlen;
};

#define CB_CREATE(x, y)             \
    uint8_t x##_data_space[y];      \
    struct circular_buffer_t x = {  \
        .buffer = x##_data_space,   \
        .head = 0,                  \
        .tail = 0,                  \
        .maxlen = y                 \
    }

void cb_init();
// uint8_t rx_buffer_available();
// uint8_t rx_buffer_get();
uint8_t cb_put(struct circular_buffer_t* buffer, uint8_t value);

#endif
