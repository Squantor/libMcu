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

#define GPIO_00_SWM     IOCON_PIO7
#define GPIO_00_PIO     7
#define GPIO_01_SWM     IOCON_PIO14
#define GPIO_01_PIO     14
#define GPIO_02_SWM     IOCON_PIO15
#define GPIO_02_PIO     15
#define GPIO_03_SWM     IOCON_PIO16
#define GPIO_03_PIO     16
#define GPIO_04_SWM     IOCON_PIO5
#define GPIO_04_PIO     5
#define GPIO_05_SWM     IOCON_PIO8
#define GPIO_05_PIO     8
#define GPIO_06_SWM     IOCON_PIO9
#define GPIO_06_PIO     9
#define GPIO_07_SWM
#define GPIO_07_PIO
#define GPIO_08_SWM
#define GPIO_08_PIO
#define GPIO_09_SWM
#define GPIO_09_PIO
#define GPIO_10_SWM
#define GPIO_10_PIO
#define GPIO_11_SWM
#define GPIO_11_PIO
#define GPIO_12_SWM
#define GPIO_12_PIO
#define GPIO_13_SWM
#define GPIO_13_PIO

// busses
#define I2C_SDA_SWM     IOCON_PIO10
#define I2C_SDA_PIO     10
#define I2C_SCL_SWM     IOCON_PIO11
#define I2C_SCL_PIO     11

#define SPI_MOSI_SWM    IOCON_PIO17
#define SPI_MOSI_PIO    17
#define SPI_MISO_SWM    IOCON_PIO13
#define SPI_MISO_PIO    13
#define SPI_SCK_SWM     IOCON_PIO12
#define SPI_SCK_PIO     12
#define SPI_CE_SWM      IOCON_PIO4
#define SPI_CE_PIO      4

// analog pins
#define VREF_SWM        IOCON_PIO6
#define VREF_PIO        6
#define AN_00_SWM       IOCON_PIO0
#define AN_00_PIO       0
#define AN_01_SWM       IOCON_PIO1
#define AN_01_PIO       1


// how many ticks per second
#define TICKS_PER_S     (100)

void boardInit(void);

#endif