#include "circular_buffer.h"
#include "handler/communication.h"

int main() {
    init_rx_buffer();
    init_communication();

    handle_communication();

    return 0;
}
