#ifndef UART_H
#define UART_H

#define UART_SPBRG 51

void uart_init(void);
void uart_write(unsigned char value);
void uart_write_string(const char *text);
unsigned char uart_try_read(unsigned char *value);

#endif
