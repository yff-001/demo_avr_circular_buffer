#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart0_init(uint8_t (*callback)(uint8_t));
void uart0_transmit(uint8_t data);
void uart0_puts(char* message);

#endif