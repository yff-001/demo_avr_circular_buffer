#include <avr/io.h>
#include "adc.h"

void init_adc() {
    DIDR0 = 0xFF;                       // disable digital input buffers

    ADMUX |= (1 << REFS0);              // AVCC AREF
    ADMUX |= (1 << ADLAR);              // left aligned
    ADCSRA |= (1 << ADPS2);             // f/16
    ADCSRA |= (1 << ADATE);             // enable auto trigger
    ADCSRA |= (1 << ADIE);              // enable interrupt
}

void start_adc() {
    ADCSRA |= (1 << ADIE);
    ADCSRA |= (1 << ADSC);
}

void stop_adc() {
    ADCSRA &= ~(1 << ADIE);
}