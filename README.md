# PIC16F877A UART

Simple UART communication driver for the **Microchip PIC16F877A**, written in C using **mikroC PRO for PIC**.

## Configuration

| Parameter | Value |
| --- | --- |
| Microcontroller | PIC16F877A |
| Compiler | mikroC PRO for PIC |
| Oscillator | 8 MHz, external crystal (HS mode) |
| Interface | Hardware USART, asynchronous |
| Serial format | 9,600 baud, 8N1 |
| TX | RC6 (pin 25, 40-pin DIP) |
| RX | RC7 (pin 26, 40-pin DIP) |

With an 8 MHz oscillator and high-speed baud-rate mode (`BRGH = 1`), `SPBRG = 51` provides approximately 9,615 baud (0.16% error). The configured oscillator frequency must match the physical hardware.

## Build

1. Open **mikroC PRO for PIC** and create a project targeting `PIC16F877A`.
2. Set the project clock to **8 MHz** and configure the oscillator for **HS** mode.
3. Add `src/uart.c` and `examples/main.c` to the project, keeping `src/uart.h` in its current relative location.
4. Build in mikroC PRO for PIC and program the generated HEX file into the microcontroller.

The assembly listing is not required to compile the C sources. The GitHub Actions workflow performs source checks only; firmware compilation requires a configured mikroC PRO for PIC installation.

## Example

The example sends a startup message and then waits for incoming UART bytes. Each received byte is copied to `PORTB` and sent back over TX.

Connect a compatible logic-level USB-to-UART adapter with its TX connected to RC7, RX to RC6 and ground shared with the circuit. **Do not connect RS-232 voltage levels directly to the PIC.**

`uart_try_read()` returns `1` when a byte was received successfully and `0` when no data is available or a receive error occurs. This allows receiving `0x00` as a valid byte. `uart_write()` waits until the transmit register is available.

## References

- [PIC16F877A datasheet (DS39582C)](https://ww1.microchip.com/downloads/en/DeviceDoc/39582C.pdf)
