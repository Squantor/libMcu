/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/*
LPC810 series common switch matrix control registers, defines and
functions.
*/
#ifndef LPC81X_SWM_H
#define LPC81X_SWM_H

typedef struct {
  __IO uint32_t PINASSIGN[9]; /* Pin Assign register array */
  __I uint32_t RESERVED0[103];
  __IO uint32_t PINENABLE0; /* Pin Enable register */
} SWM_Type;

#define SWM_PINENABLE0_RESERVED (~0x1ff)

typedef enum SWM_PIN_MOVABLE {
  SWM_U0_TXD_O,            /* PINASSIGN0 - UART0 TXD Output */
  SWM_U0_RXD_I,            /* PINASSIGN0 - UART0 RXD Input */
  SWM_U0_RTS_O,            /* PINASSIGN0 - UART0 RTS Output */
  SWM_U0_CTS_I,            /* PINASSIGN0 - UART0 CTS Input */
  SWM_U0_SCLK_IO = 0x10,   /* PINASSIGN1 - UART0 SCLK I/O */
  SWM_U1_TXD_O,            /* PINASSIGN1 - UART1 TXD Output */
  SWM_U1_RXD_I,            /* PINASSIGN1 - UART1 RXD Input */
  SWM_U1_RTS_O,            /* PINASSIGN1 - UART1 RTS Output */
  SWM_U1_CTS_I = 0x20,     /* PINASSIGN2 - UART1 CTS Input */
  SWM_U1_SCLK_IO,          /* PINASSIGN2 - UART1 SCLK I/O */
  SWM_U2_TXD_O,            /* PINASSIGN2 - UART2 TXD Output */
  SWM_U2_RXD_I,            /* PINASSIGN2 - UART2 RXD Input */
  SWM_U2_RTS_O = 0x30,     /* PINASSIGN3 - UART2 RTS Output */
  SWM_U2_CTS_I,            /* PINASSIGN3 - UART2 CTS Input */
  SWM_U2_SCLK_IO,          /* PINASSIGN3 - UART2 SCLK I/O */
  SWM_SPI0_SCK_IO,         /* PINASSIGN3 - SPI0 SCK I/O */
  SWM_SPI0_MOSI_IO = 0x40, /* PINASSIGN4 - SPI0 MOSI I/O */
  SWM_SPI0_MISO_IO,        /* PINASSIGN4 - SPI0 MISO I/O */
  SWM_SPI0_SSEL_IO,        /* PINASSIGN4 - SPI0 SSEL I/O */
  SWM_SPI1_SCK_IO,         /* PINASSIGN4 - SPI1 SCK I/O */
  SWM_SPI1_MOSI_IO = 0x50, /* PINASSIGN5 - SPI1 MOSI I/O */
  SWM_SPI1_MISO_IO,        /* PINASSIGN5 - SPI1 MISO I/O */
  SWM_SPI1_SSEL_IO,        /* PINASSIGN5 - SPI1 SSEL I/O */
  SWM_CTIN_0_I,            /* PINASSIGN5 - CTIN0 Input */
  SWM_CTIN_1_I = 0x60,     /* PINASSIGN6 - CTIN1 Input */
  SWM_CTIN_2_I,            /* PINASSIGN6 - CTIN2 Input */
  SWM_CTIN_3_I,            /* PINASSIGN6 - CTIN3 Input */
  SWM_CTOUT_0_O,           /* PINASSIGN6 - CTOUT0 Output */
  SWM_CTOUT_1_O = 0x70,    /* PINASSIGN7 - CTOUT1 Output */
  SWM_CTOUT_2_O,           /* PINASSIGN7 - CTOUT2 Output */
  SWM_CTOUT_3_O,           /* PINASSIGN7 - CTOUT3 Output */
  SWM_I2C_SDA_IO,          /* PINASSIGN7 - I2C SDA I/O */
  SWM_I2C_SCL_IO = 0x80,   /* PINASSIGN8 - I2C SCL I/O */
  SWM_ACMP_O_O,            /* PINASSIGN8 - ACMP Output */
  SWM_CLKOUT_O,            /* PINASSIGN8 - CLKOUT Output */
  SWM_GPIO_INT_BMAT_O,     /* PINASSIGN8 - GPIO INT BMAT Output */
} SWM_PIN_MOVABLE_Type;

typedef enum SWM_PIN_FIXED {
  SWM_EN0_NONE = 0,           /*!< No change for enable 0 */
  SWM_EN0_ACMP_I1 = (1 << 0), /* ACMP I1 */
  SWM_EN0_ACMP_I2 = (1 << 1), /* ACMP I2 */
  SWM_EN0_SWCLK = (1 << 2),   /* SWCLK */
  SWM_EN0_SWDIO = (1 << 3),   /* SWDIO */
  SWM_EN0_XTALIN = (1 << 4),  /* XTALIN */
  SWM_EN0_XTALOUT = (1 << 5), /* XTALOUT */
  SWM_EN0_RST = (1 << 6),     /* Reset */
  SWM_EN0_CLKIN = (1 << 7),   /* Clock Input */
  SWM_EN0_VDDCMP = (1 << 8)   /* VDD */
} SWM_PIN_FIXED_Type;

#include "nxp/LPC8XX/LPC8XX_swm.h"

#endif