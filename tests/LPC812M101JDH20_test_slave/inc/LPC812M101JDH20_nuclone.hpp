/*
MIT License

Copyright (c) 2019 Bart Bilos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef LPC812M101JDH20_NUCLONE
#define LPC812M101JDH20_NUCLONE

#include <mcu_ll.h>

// outside uart communications
#define UART_OUT_TXD    (13)
#define UART_OUT_RXD    (12)

// synchronisation pins
#define TEST_SYNC_OUT_IOCON (IOCON_PIO17)
#define TEST_SYNC_OUT_GPIO  (17)
#define TEST_SYNC_IN_IOCON  (IOCON_PIO14)
#define TEST_SYNC_IN_GPIO   (14)

// pins used for testing
#define TEST_UART_TXD   (16)
#define TEST_UART_RXD   (15)

#define TEST_I2C_SCL    (10)
#define TEST_I2C_SDA    (11)

#define TEST_SPI_MOSI   (16)
#define TEST_SPI_MISO   (15)




// how many ticks per second
#define TICKS_PER_S     (100)

void boardInit(void);

#endif