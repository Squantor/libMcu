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

/** SWM port pin index */
typedef enum {
  SWM_PORTPIN_P0_0 = 0U,    /*!< Port pin P0_0. */
  SWM_PORTPIN_P0_1 = 1U,    /*!< Port pin P0_1. */
  SWM_PORTPIN_P0_2 = 2U,    /*!< Port pin P0_2. */
  SWM_PORTPIN_P0_3 = 3U,    /*!< Port pin P0_3. */
  SWM_PORTPIN_P0_4 = 4U,    /*!< Port pin P0_4. */
  SWM_PORTPIN_P0_5 = 5U,    /*!< Port pin P0_5. */
  SWM_PORTPIN_P0_6 = 6U,    /*!< Port pin P0_6. */
  SWM_PORTPIN_P0_7 = 7U,    /*!< Port pin P0_7. */
  SWM_PORTPIN_P0_8 = 8U,    /*!< Port pin P0_8. */
  SWM_PORTPIN_P0_9 = 9U,    /*!< Port pin P0_9. */
  SWM_PORTPIN_P0_10 = 10U,  /*!< Port pin P0_10. */
  SWM_PORTPIN_P0_11 = 11U,  /*!< Port pin P0_11. */
  SWM_PORTPIN_P0_12 = 12U,  /*!< Port pin P0_12. */
  SWM_PORTPIN_P0_13 = 13U,  /*!< Port pin P0_13. */
  SWM_PORTPIN_P0_14 = 14U,  /*!< Port pin P0_14. */
  SWM_PORTPIN_P0_15 = 15U,  /*!< Port pin P0_15. */
  SWM_PORTPIN_P0_16 = 16U,  /*!< Port pin P0_16. */
  SWM_PORTPIN_P0_17 = 17U,  /*!< Port pin P0_17. */
  SWM_PORTPIN_Reset = 0xffU /*!< port_pin reset number. */
} SWM_PORTPIN_Type;

typedef enum SWM_PIN_MOVABLE {
  SWM_USART0_TXD_O = 0U, /*!< UART0 TXD Output */
  SWM_USART0_RXD_I = 1U, /*!< UART0 RXD Input */
  SWM_USART0_RTS_O = 2U, /*!< UART0 RTS Output */
  SWM_USART0_CTS_I = 3U, /*!< UART0 CTS Input */

  SWM_USART0_SCLK_IO = 4U, /*!< UART0 SCLK I/O */
  SWM_USART1_TXD_O = 5U,   /*!< UART1 TXD Output */
  SWM_USART1_RXD_I = 6U,   /*!< UART1 RXD Input */
  SWM_USART1_RTS_O = 7U,   /*!< UART1 RTS Output */

  SWM_USART1_CTS_I = 8U,   /*!< UART1 CTS Input */
  SWM_USART1_SCLK_IO = 9U, /*!< UART1 SCLK I/O */
  SWM_USART2_TXD_O = 10U,  /*!< UART2 TXD Output */
  SWM_USART2_RXD_I = 11U,  /*!< UART2 RXD Input */

  SWM_USART2_RTS_O = 12U,   /*!< UART2 RTS Output */
  SWM_USART2_CTS_I = 13U,   /*!< UART2 CTS Input */
  SWM_USART2_SCLK_IO = 14U, /*!< UART2 SCLK I/O */
  SWM_SPI0_SCK_IO = 15U,    /*!< SPI0 SCK I/O */

  SWM_SPI0_MOSI_IO = 16U, /*!< SPI0 MOSI I/O */
  SWM_SPI0_MISO_IO = 17U, /*!< SPI0 MISO I/O */
  SWM_SPI0_SSEL_IO = 18U, /*!< SPI0 SSEL I/O */
  SWM_SPI1_SCK_IO = 19U,  /*!< SPI1 SCK I/O */

  SWM_SPI1_MOSI_IO = 20U, /*!< SPI1 MOSI I/O */
  SWM_SPI1_MISO_IO = 21U, /*!< SPI1 MISO I/O */
  SWM_SPI1_SSEL_IO = 22U, /*!< SPI1 SSEL I/O */
  SWM_SCT_IN_0_I = 23U,   /*!< SCT Input 0*/

  SWM_SCT_IN_1_I = 24U,  /*!< SCT Input 1*/
  SWM_SCT_IN_2_I = 25U,  /*!< SCT Input 2*/
  SWM_SCT_IN_3_I = 26U,  /*!< SCT Input 3*/
  SWM_SCT_OUT_0_O = 27U, /*!< SCT Output 0*/

  SWM_SCT_OUT_1_O = 28U, /*!< SCT Output 1*/
  SWM_SCT_OUT_2_O = 29U, /*!< SCT Output 2*/
  SWM_SCT_OUT_3_O = 30U, /*!< SCT Output 3*/
  SWM_I2C_SDA_IO = 31U,  /*!< I2C SDA I/O */

  SWM_I2C_SCL_IO = 32U,      /*!< I2C SCL I/O */
  SWM_ACMP_O_O = 33U,        /*!< ACMP Output */
  SWM_CLKOUT_O = 34U,        /*!< CLKOUT Output */
  SWM_GPIO_INT_BMAT_O = 35U, /*!< GPIO INT BMAT Output */
} SWM_MOVABLE_Type;

typedef enum SWM_PIN_FIXED {
  SWM_EN0_NONE = 0,           /*!< No change for enable 0 */
  SWM_EN0_ACMP_I1 = (1 << 0), /*!< ACMP I1 */
  SWM_EN0_ACMP_I2 = (1 << 1), /*!< ACMP I2 */
  SWM_EN0_SWCLK = (1 << 2),   /*!< SWCLK */
  SWM_EN0_SWDIO = (1 << 3),   /*!< SWDIO */
  SWM_EN0_XTALIN = (1 << 4),  /*!< XTALIN */
  SWM_EN0_XTALOUT = (1 << 5), /*!< XTALOUT */
  SWM_EN0_RST = (1 << 6),     /*!< Reset */
  SWM_EN0_CLKIN = (1 << 7),   /*!< Clock Input */
  SWM_EN0_VDDCMP = (1 << 8)   /*!< VDD */
} SWM_FIXED_Type;

#include "nxp/LPC8XX/LPC8XX_swm.h"

#endif