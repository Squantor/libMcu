/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC820 series common switch matrix control registers, defines and
functions.
*/
#ifndef LPC82X_SWM_H
#define LPC82X_SWM_H

typedef volatile struct {
  uint32_t PINASSIGN[12]; /* Pin Assign register array */
  const uint32_t RESERVED0[100];
  uint32_t PINENABLE0; /* Pin Enable register */
} SWM_Type;

#define SWM_PINENABLE0_RESERVED (~0x1FFFFFF)

/** SWM port pin index */
typedef enum {
  SWM_PORTPIN_P0_0 = 0U,   /*!< Port pin P0_0. */
  SWM_PORTPIN_P0_1 = 1U,   /*!< Port pin P0_1. */
  SWM_PORTPIN_P0_2 = 2U,   /*!< Port pin P0_2. */
  SWM_PORTPIN_P0_3 = 3U,   /*!< Port pin P0_3. */
  SWM_PORTPIN_P0_4 = 4U,   /*!< Port pin P0_4. */
  SWM_PORTPIN_P0_5 = 5U,   /*!< Port pin P0_5. */
  SWM_PORTPIN_P0_6 = 6U,   /*!< Port pin P0_6. */
  SWM_PORTPIN_P0_7 = 7U,   /*!< Port pin P0_7. */
  SWM_PORTPIN_P0_8 = 8U,   /*!< Port pin P0_8. */
  SWM_PORTPIN_P0_9 = 9U,   /*!< Port pin P0_9. */
  SWM_PORTPIN_P0_10 = 10U, /*!< Port pin P0_10. */
  SWM_PORTPIN_P0_11 = 11U, /*!< Port pin P0_11. */
  SWM_PORTPIN_P0_12 = 12U, /*!< Port pin P0_12. */
  SWM_PORTPIN_P0_13 = 13U, /*!< Port pin P0_13. */
  SWM_PORTPIN_P0_14 = 14U, /*!< Port pin P0_14. */
  SWM_PORTPIN_P0_15 = 15U, /*!< Port pin P0_15. */
  SWM_PORTPIN_P0_16 = 16U, /*!< Port pin P0_16. */
  SWM_PORTPIN_P0_17 = 17U, /*!< Port pin P0_17. */
  SWM_PORTPIN_P0_18 = 18U, /*!< Port pin P0_18. */
  SWM_PORTPIN_P0_19 = 19U, /*!< Port pin P0_19. */
  SWM_PORTPIN_P0_20 = 20U, /*!< Port pin P0_20. */
  SWM_PORTPIN_P0_21 = 21U, /*!< Port pin P0_21. */
  SWM_PORTPIN_P0_22 = 22U, /*!< Port pin P0_22. */
  SWM_PORTPIN_P0_23 = 23U, /*!< Port pin P0_23. */
  SWM_PORTPIN_P0_24 = 24U, /*!< Port pin P0_24. */
  SWM_PORTPIN_P0_25 = 25U, /*!< Port pin P0_25. */
  SWM_PORTPIN_P0_26 = 26U, /*!< Port pin P0_26. */
  SWM_PORTPIN_P0_27 = 27U, /*!< Port pin P0_27. */
  SWM_PORTPIN_P0_28 = 28U, /*!< Port pin P0_28. */

  SWM_PORTPIN_Reset = 0xffU /*!< port_pin reset number. */
} SWM_PORTPIN_Type;

typedef enum {
  SWM_USART0_TXD_O = 0U,   /* PINASSIGN0 - UART0 TXD Output */
  SWM_USART0_RXD_I = 1U,   /* PINASSIGN0 - UART0 RXD Input */
  SWM_USART0_RTS_O = 2U,   /* PINASSIGN0 - UART0 RTS Output */
  SWM_USART0_CTS_I = 3U,   /* PINASSIGN0 - UART0 CTS Input */
  SWM_USART0_SCLK_IO = 4U, /* PINASSIGN1 - UART0 SCLK I/O */

  SWM_USART1_TXD_O = 5U,   /* PINASSIGN1 - UART1 TXD Output */
  SWM_USART1_RXD_I = 6U,   /* PINASSIGN1 - UART1 RXD Input */
  SWM_USART1_RTS_O = 7U,   /* PINASSIGN1 - UART1 RTS Output */
  SWM_USART1_CTS_I = 8U,   /* PINASSIGN2 - UART1 CTS Input */
  SWM_USART1_SCLK_IO = 9U, /* PINASSIGN2 - UART1 SCLK I/O */

  SWM_USART2_TXD_O = 10U,   /* PINASSIGN2 - UART2 TXD Output */
  SWM_USART2_RXD_I = 11U,   /* PINASSIGN2 - UART2 RXD Input */
  SWM_USART2_RTS_O = 12U,   /* PINASSIGN3 - UART2 RTS Output */
  SWM_USART2_CTS_I = 13U,   /* PINASSIGN3 - UART2 CTS Input */
  SWM_USART2_SCLK_IO = 14U, /* PINASSIGN3 - UART2 SCLK I/O */

  SWM_SPI0_SCK_IO = 15U,   /* PINASSIGN3 - SPI0 SCK I/O */
  SWM_SPI0_MOSI_IO = 16U,  /* PINASSIGN4 - SPI0 MOSI I/O */
  SWM_SPI0_MISO_IO = 17U,  /* PINASSIGN4 - SPI0 MISO I/O */
  SWM_SPI0_SSEL0_IO = 18U, /* PINASSIGN4 - SPI0 SSEL0 I/O */
  SWM_SPI0_SSEL1_IO = 19U, /* PINASSIGN4 - SPI0 SSEL1 I/O */
  SWM_SPI0_SSEL2_IO = 20U, /* PINASSIGN5 - SPI0 SSEL2 I/O */
  SWM_SPI0_SSEL3_IO = 21U, /* PINASSIGN5 - SPI0 SSEL3 I/O */

  SWM_SPI1_SCK_IO = 22U,   /* PINASSIGN5 - SPI1 SCK I/O */
  SWM_SPI1_MOSI_IO = 23U,  /* PINASSIGN5 - SPI1 MOSI I/O */
  SWM_SPI1_MISO_IO = 24U,  /* PINASSIGN6 - SPI1 MISO I/O */
  SWM_SPI1_SSEL0_IO = 25U, /* PINASSIGN6 - SPI1 SSEL0 I/O */
  SWM_SPI1_SSEL1_IO = 26U, /* PINASSIGN6 - SPI1 SSEL1 I/O */

  SWM_SCT_IN0_I = 27U,  /* PINASSIGN6 - SCT INPUT_0 Input */
  SWM_SCT_IN1_I = 28U,  /* PINASSIGN7 - SCT INPUT_1 Input */
  SWM_SCT_IN2_I = 29U,  /* PINASSIGN7 - SCT INPUT_2 Input */
  SWM_SCT_IN3_I = 30U,  /* PINASSIGN7 - SCT INPUT_3 Input */
  SWM_SCT_OUT0_O = 31U, /* PINASSIGN7 - SCT OUTPUT_0 Output */
  SWM_SCT_OUT1_O = 32U, /* PINASSIGN8 - SCT OUTPUT_1 Output */
  SWM_SCT_OUT2_O = 33U, /* PINASSIGN8 - SCT OUTPUT_2 Output */
  SWM_SCT_OUT3_O = 34U, /* PINASSIGN8 - SCT OUTPUT_3 Output */
  SWM_SCT_OUT4_O = 35U, /* PINASSIGN8 - SCT OUTPUT_4 Output */
  SWM_SCT_OUT5_O = 36U, /* PINASSIGN9 - SCT OUTPUT_5 Output */

  SWM_I2C1_SDA_IO = 37U, /* PINASSIGN9 - I2C1 SDA I/O */
  SWM_I2C1_SCL_IO = 38U, /* PINASSIGN9 - I2C1 SCL I/O */

  SWM_I2C2_SDA_IO = 39U, /* PINASSIGN9 - I2C2 SDA I/O */
  SWM_I2C2_SCL_IO = 40U, /* PINASSIGN10 - I2C2 SCL I/O */

  SWM_I2C3_SDA_IO = 41U, /* PINASSIGN10 - I2C3 SDA I/O */
  SWM_I2C3_SCL_IO = 42U, /* PINASSIGN10 - I2C3 SCL I/O */

  SWM_ADC_PINTRIG0_I = 43U, /* PINASSIGN10 - ADC PIN TRIGGER-0 Input */
  SWM_ADC_PINTRIG1_I = 44U, /* PINASSIGN11 - ADC PIN TRIGGER-1 Input */

  SWM_ACMP_O_O = 45U, /* PINASSIGN11 - ACMP OUT Output */

  SWM_CLKOUT_O = 46U, /* PINASSIGN11 - CLKOUT Output */

  SWM_GPIO_INT_BMAT_O = 47U, /* PINASSIGN11 - GPIO INT BMAT Output */
} SWM_MOVABLE_Type;

typedef enum {
  SWM_EN0_NONE = 0,             /*!< No change for enable 0 */
  SWM_EN0_ACMP_I1 = (1 << 0),   /* ACMP I1 */
  SWM_EN0_ACMP_I2 = (1 << 1),   /* ACMP I2 */
  SWM_EN0_ACMP_I3 = (1 << 2),   /* ACMP I3 */
  SWM_EN0_ACMP_I4 = (1 << 3),   /* ACMP I4 */
  SWM_EN0_SWCLK = (1 << 4),     /* SWCLK */
  SWM_EN0_SWDIO = (1 << 5),     /* SWDIO */
  SWM_EN0_XTALIN = (1 << 6),    /* XTALIN */
  SWM_EN0_XTALOUT = (1 << 7),   /* XTALOUT */
  SWM_EN0_RST = (1 << 8),       /* Reset */
  SWM_EN0_CLKIN = (1 << 9),     /* Clock Input */
  SWM_EN0_VDDCMP = (1 << 10),   /* VDD */
  SWM_EN0_I2C0_SDA = (1 << 11), /* I2C0 SDA */
  SWM_EN0_I2C0_SCL = (1 << 12), /* I2C0 SCL */
  SWM_EN0_ADC0 = (1 << 13),     /* ADC0 */
  SWM_EN0_ADC1 = (1 << 14),     /* ADC1 */
  SWM_EN0_ADC2 = (1 << 15),     /* ADC2 */
  SWM_EN0_ADC3 = (1 << 16),     /* ADC3 */
  SWM_EN0_ADC4 = (1 << 17),     /* ADC4 */
  SWM_EN0_ADC5 = (1 << 18),     /* ADC5 */
  SWM_EN0_ADC6 = (1 << 19),     /* ADC6 */
  SWM_EN0_ADC7 = (1 << 20),     /* ADC7 */
  SWM_EN0_ADC8 = (1 << 21),     /* ADC8 */
  SWM_EN0_ADC9 = (1 << 22),     /* ADC9 */
  SWM_EN0_ADC10 = (1 << 23),    /* ADC10 */
  SWM_EN0_ADC11 = (1 << 24),    /* ADC11 */
} SWM_FIXED_Type;

#include "nxp/LPC8XX/LPC8XX_swm.h"

#endif