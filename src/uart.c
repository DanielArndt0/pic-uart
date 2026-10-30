#include "uart.h"

void uart_init(void)
{
    SPBRG = UART_SPBRG;
    TXSTA = 0x24;
    RCSTA = 0x90;
    TRISC.TRISC6 = 0;
    TRISC.TRISC7 = 1;
}

void uart_write(unsigned char value)
{
    while (!PIR1.TXIF)
    {
    }

    TXREG = value;
}

void uart_write_string(const char *text)
{
    if (text == 0)
    {
        return;
    }

    while (*text != '\0')
    {
        uart_write(*text++);
    }
}

unsigned char uart_try_read(unsigned char *value)
{
    unsigned char received;
    unsigned char framing_error;

    if (value == 0)
    {
        return 0;
    }

    if (RCSTA.OERR)
    {
        CREN_bit = 0;
        CREN_bit = 1;
        return 0;
    }

    if (!PIR1.RCIF)
    {
        return 0;
    }

    framing_error = RCSTA.FERR;
    received = RCREG;

    if (framing_error)
    {
        return 0;
    }

    *value = received;
    return 1;
}
