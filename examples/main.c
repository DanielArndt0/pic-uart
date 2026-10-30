#include "../src/uart.h"

void main(void)
{
    unsigned char received;

    TRISB = 0x00;
    PORTB = 0x00;
    s uart_init();
    uart_write_string("PIC16F877A UART ready\r\n");

    while (1)
    {
        if (uart_try_read(&received))
        {
            PORTB = received;
            uart_write(received);
        }
    }
}
