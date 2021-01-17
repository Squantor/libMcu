/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Switch Matrix registers, defines and functions.
 */
#ifndef LPC84X_SWM_H
#define LPC84X_SWM_H

/** SWM - Register Layout Typedef */
typedef struct {
  union {                               /* offset: 0x0 */
    struct {                            /* offset: 0x0 */
      __IO uint32_t PINASSIGN0;         /**< Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS., offset: 0x0 */
      __IO uint32_t PINASSIGN1;         /**< Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS., offset: 0x4 */
      __IO uint32_t PINASSIGN2;         /**< Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD., offset: 0x8 */
      __IO uint32_t PINASSIGN3;         /**< Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK., offset: 0xC */
      __IO uint32_t PINASSIGN4;         /**< Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1., offset: 0x10 */
      __IO uint32_t PINASSIGN5;         /**< Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI, offset: 0x14 */
      __IO uint32_t PINASSIGN6;         /**< Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0., offset: 0x18 */
      __IO uint32_t PINASSIGN7;         /**< Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0., offset: 0x1C */
      __IO uint32_t PINASSIGN8;         /**< Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4., offset: 0x20 */
      __IO uint32_t PINASSIGN9;         /**< Pin assign register 9. Assign movable functions SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL., offset: 0x24 */
      __IO uint32_t PINASSIGN10;        /**< Pin assign register 10. Assign movable functions I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL., offset: 0x28 */
      __IO uint32_t PINASSIGN11;        /**< Pin assign register 11. Assign movable functions COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD, offset: 0x2C */
      __IO uint32_t PINASSIGN12;        /**< Pin assign register 12. Assign movable functions UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD., offset: 0x30 */
      __IO uint32_t PINASSIGN13;        /**< Pin assign register 13. Assign movable functions UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2., offset: 0x34 */
      __IO uint32_t PINASSIGN14;        /**< Pin assign register 14. Assign movable functions T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2., offset: 0x38 */
    } PINASSIGN;
    __IO uint32_t PINASSIGN_DATA[15];   /**< Pin assign register, array offset: 0x0, array step: 0x4 */
  };
       uint8_t RESERVED_0[388];
  __IO uint32_t PINENABLE0;             /**< Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP and so on., offset: 0x1C0 */
  __IO uint32_t PINENABLE1;             /**< Pin enable register 1. Enables fixed-pin functions CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_X4, CAPT_YL and CAPT_YH., offset: 0x1C4 */
} SWM_Type;

/** SWM port pin index */
typedef enum
{
    SWM_PORTPIN_P0_0 = 0U,      /*!< Port pin P0_0. */
    SWM_PORTPIN_P0_1 = 1U,      /*!< Port pin P0_1. */
    SWM_PORTPIN_P0_2 = 2U,      /*!< Port pin P0_2. */
    SWM_PORTPIN_P0_3 = 3U,      /*!< Port pin P0_3. */
    SWM_PORTPIN_P0_4 = 4U,      /*!< Port pin P0_4. */
    SWM_PORTPIN_P0_5 = 5U,      /*!< Port pin P0_5. */
    SWM_PORTPIN_P0_6 = 6U,      /*!< Port pin P0_6. */
    SWM_PORTPIN_P0_7 = 7U,      /*!< Port pin P0_7. */
    SWM_PORTPIN_P0_8 = 8U,      /*!< Port pin P0_8. */
    SWM_PORTPIN_P0_9 = 9U,      /*!< Port pin P0_9. */
    SWM_PORTPIN_P0_10 = 10U,    /*!< Port pin P0_10. */
    SWM_PORTPIN_P0_11 = 11U,    /*!< Port pin P0_11. */
    SWM_PORTPIN_P0_12 = 12U,    /*!< Port pin P0_12. */
    SWM_PORTPIN_P0_13 = 13U,    /*!< Port pin P0_13. */
    SWM_PORTPIN_P0_14 = 14U,    /*!< Port pin P0_14. */
    SWM_PORTPIN_P0_15 = 15U,    /*!< Port pin P0_15. */
    SWM_PORTPIN_P0_16 = 16U,    /*!< Port pin P0_16. */
    SWM_PORTPIN_P0_17 = 17U,    /*!< Port pin P0_17. */
    SWM_PORTPIN_P0_18 = 18U,    /*!< Port pin P0_18. */
    SWM_PORTPIN_P0_19 = 19U,    /*!< Port pin P0_19. */
    SWM_PORTPIN_P0_20 = 20U,    /*!< Port pin P0_20. */
    SWM_PORTPIN_P0_21 = 21U,    /*!< Port pin P0_21. */
    SWM_PORTPIN_P0_22 = 22U,    /*!< Port pin P0_22. */
    SWM_PORTPIN_P0_23 = 23U,    /*!< Port pin P0_23. */
    SWM_PORTPIN_P0_24 = 24U,    /*!< Port pin P0_24. */
    SWM_PORTPIN_P0_25 = 25U,    /*!< Port pin P0_25. */
    SWM_PORTPIN_P0_26 = 26U,    /*!< Port pin P0_26. */
    SWM_PORTPIN_P0_27 = 27U,    /*!< Port pin P0_27. */
    SWM_PORTPIN_P0_28 = 28U,    /*!< Port pin P0_28. */
    SWM_PORTPIN_P0_29 = 29U,    /*!< Port pin P0_29. */
    SWM_PORTPIN_P0_30 = 30U,    /*!< Port pin P0_30. */
    SWM_PORTPIN_P0_31 = 31U,    /*!< Port pin P0_31. */

    SWM_PORTPIN_P1_0 = 32U,     /*!< Port pin P1_0. */
    SWM_PORTPIN_P1_1 = 33U,     /*!< Port pin P1_1. */
    SWM_PORTPIN_P1_2 = 34U,     /*!< Port pin P1_2. */
    SWM_PORTPIN_P1_3 = 35U,     /*!< Port pin P1_3. */
    SWM_PORTPIN_P1_4 = 36U,     /*!< Port pin P1_4. */
    SWM_PORTPIN_P1_5 = 37U,     /*!< Port pin P1_5. */
    SWM_PORTPIN_P1_6 = 38U,     /*!< Port pin P1_6. */
    SWM_PORTPIN_P1_7 = 39U,     /*!< Port pin P1_7. */
    SWM_PORTPIN_P1_8 = 40U,     /*!< Port pin P1_8. */
    SWM_PORTPIN_P1_9 = 41U,     /*!< Port pin P1_9. */
    SWM_PORTPIN_P1_10 = 42U,    /*!< Port pin P1_10. */
    SWM_PORTPIN_P1_11 = 43U,    /*!< Port pin P1_11. */
    SWM_PORTPIN_P1_12 = 44U,    /*!< Port pin P1_12. */
    SWM_PORTPIN_P1_13 = 45U,    /*!< Port pin P1_13. */
    SWM_PORTPIN_P1_14 = 46U,    /*!< Port pin P1_14. */
    SWM_PORTPIN_P1_15 = 47U,    /*!< Port pin P1_15. */
    SWM_PORTPIN_P1_16 = 48U,    /*!< Port pin P1_16. */
    SWM_PORTPIN_P1_17 = 49U,    /*!< Port pin P1_17. */
    SWM_PORTPIN_P1_18 = 50U,    /*!< Port pin P1_18. */
    SWM_PORTPIN_P1_19 = 51U,    /*!< Port pin P1_19. */
    SWM_PORTPIN_P1_20 = 52U,    /*!< Port pin P1_20. */
    SWM_PORTPIN_P1_21 = 53U,    /*!< Port pin P1_21. */
    SWM_PORTPIN_Reset = 0xffU   /*!< port_pin reset number. */
} SWM_PORTPIN_Type;

/** SWM movable functions table */
typedef enum
{
    SWM_USART0_TXD = 0U,        /*!< movable functionUSART0_TXD. */
    SWM_USART0_RXD = 1U,        /*!< movable functionUSART0_RXD. */
    SWM_USART0_RTS = 2U,        /*!< movable functionUSART0_RTS. */
    SWM_USART0_CTS = 3U,        /*!< movable functionUSART0_CTS. */
    SWM_USART0_SCLK = 4U,       /*!< movable functionUSART0_SCLK. */

    SWM_USART1_TXD = 5U,        /*!< movable functionUSART1_TXD. */
    SWM_USART1_RXD = 6U,        /*!< movable functionUSART1_RXD. */
    SWM_USART1_RTS = 7U,        /*!< movable functionUSART1_RTS. */
    SWM_USART1_CTS = 8U,        /*!< movable functionUSART1_CTS. */
    SWM_USART1_SCLK = 9U,       /*!< movable functionUSART1_SCLK. */

    SWM_USART2_TXD = 10U,       /*!< movable functionUSART2_TXD. */
    SWM_USART2_RXD = 11U,       /*!< movable functionUSART2_RXD. */
    SWM_USART2_RTS = 12U,       /*!< movable functionUSART2_RTS. */
    SWM_USART2_CTS = 13U,       /*!< movable functionUSART2_CTS. */
    SWM_USART2_SCLK = 14U,      /*!< movable functionUSART2_SCLK. */

    SWM_SPI0_SCK = 15U,         /*!< movable functionSPI0_SCK. */
    SWM_SPI0_MOSI = 16U,        /*!< movable functionSPI0_MOSI. */
    SWM_SPI0_MISO = 17U,        /*!< movable functionSPI0_MISO. */
    SWM_SPI0_SSEL0 = 18U,       /*!< movable functionSPI0_SSEL0. */
    SWM_SPI0_SSEL1 = 19U,       /*!< movable functionSPI0_SSEL1. */
    SWM_SPI0_SSEL2 = 20U,       /*!< movable functionSPI0_SSEL2. */
    SWM_SPI0_SSEL3 = 21U,       /*!< movable functionSPI0_SSEL3. */

    SWM_SPI1_SCK = 22U,         /*!< movable functionSPI1_SCK. */
    SWM_SPI1_MOSI = 23U,        /*!< movable functionSPI1_MOSI. */
    SWM_SPI1_MISO = 24U,        /*!< movable functionSPI1_MISO. */
    SWM_SPI1_SSEL0 = 25U,       /*!< movable functionSPI1_SSEL0. */
    SWM_SPI1_SSEL1 = 26U,       /*!< movable functionSPI1_SSEL1. */

    SWM_SCT_PIN0 = 27U,         /*!< movable functionSCT_PIN0. */
    SWM_SCT_PIN1 = 28U,         /*!< movable functionSCT_PIN1. */
    SWM_SCT_PIN2 = 29U,         /*!< movable functionSCT_PIN2. */
    SWM_SCT_PIN3 = 30U,         /*!< movable functionSCT_PIN3. */
    SWM_SCT_OUT0 = 31U,         /*!< movable functionSCT_OUT0. */
    SWM_SCT_OUT1 = 32U,         /*!< movable functionSCT_OUT1. */
    SWM_SCT_OUT2 = 33U,         /*!< movable functionSCT_OUT2. */
    SWM_SCT_OUT3 = 34U,         /*!< movable functionSCT_OUT3. */
    SWM_SCT_OUT4 = 35U,         /*!< movable functionSCT_OUT4. */
    SWM_SCT_OUT5 = 36U,         /*!< movable functionSCT_OUT5. */
    SWM_SCT_OUT6 = 37U,         /*!< movable functionSCT_OUT6. */

    SWM_I2C1_SDA = 38U,         /*!< movable functionI2C1_SDA. */
    SWM_I2C1_SCL = 39U,         /*!< movable functionI2C1_SCL. */
    SWM_I2C2_SDA = 40U,         /*!< movable functionI2C2_SDA. */
    SWM_I2C2_SCL = 41U,         /*!< movable functionI2C2_SCL. */
    SWM_I2C3_SDA = 42U,         /*!< movable functionI2C3_SDA. */
    SWM_I2C3_SCL = 43U,         /*!< movable functionI2C3_SCL. */

    SWM_ACMP_OUT = 44U,         /*!< movable functionACMP_OUT. */
    SWM_CLKOUT = 45U,           /*!< movable functionCLKOUT. */
    SWM_GPIO_INT_BMAT = 46U,    /*!< movable functionGPIO_INT_BMAT. */

    SWM_USART3_TXD = 47U,       /*!< movable functionUSART3_TXD. */
    SWM_USART3_RXD = 48U,       /*!< movable functionUSART3_RXD. */
    SWM_USART3_SCLK = 49U,      /*!< movable functionUSART3_SCLK. */
    SWM_USART4_TXD = 50U,       /*!< movable functionUSART4_TXD. */
    SWM_USART4_RXD = 51U,       /*!< movable functionUSART4_RXD. */
    SWM_USART4_SCLK = 52U,      /*!< movable functionUSART4_SCLK. */
    SWM_T0_MAT_CHN0 = 53U,      /*!< movable functionTimer Match Channel 0. */
    SWM_T0_MAT_CHN1 = 54U,      /*!< movable functionTimer Match Channel 1. */
    SWM_T0_MAT_CHN2 = 55U,      /*!< movable functionTimer Match Channel 2. */
    SWM_T0_MAT_CHN3 = 56U,      /*!< movable functionTimer Match Channel 3. */
    SWM_T0_CAP_CHN0 = 57U,      /*!< movable functionTimer Capture Channel 0. */
    SWM_T0_CAP_CHN1 = 58U,      /*!< movable functionTimer Capture Channel 1. */
    SWM_T0_CAP_CHN2 = 59U,      /*!< movable functionTimer Capture Channel 2. */

    SWM_MOVABLE_NUM_FUNCS = 60U,/*!< Movable function number. */
} SWM_MOVABLE_Type;

/** SWM fixed pin selection, group 0 */
typedef enum
{
    SWM_EN0_NONE = 0,               /*!< No change for enable 0 */
    SWM_EN0_ACMP_INPUT1 = (1 << 0), /*!< Fixed-pin function as ACMP_INPUT1. */
    SWM_EN0_ACMP_INPUT2 = (1 << 1), /*!< Fixed-pin function as ACMP_INPUT2. */
    SWM_EN0_ACMP_INPUT3 = (1 << 2), /*!< Fixed-pin function as ACMP_INPUT3. */
    SWM_EN0_ACMP_INPUT4 = (1 << 3), /*!< Fixed-pin function as ACMP_INPUT4. */
    SWM_EN0_ACMP_INPUT5 = (1 << 4), /*!< Fixed-pin function as ACMP_INPUT5. */
    SWM_EN0_SWCLK = (1 << 5),       /*!< Fixed-pin function as SWCLK. */
    SWM_EN0_SWDIO = (1 << 6),       /*!< Fixed-pin function as SWDIO. */
    SWM_EN0_XTALIN = (1 << 7),      /*!< Fixed-pin function as XTALIN. */
    SWM_EN0_XTALOUT = (1 << 8),     /*!< Fixed-pin function as XTALOUT. */
    SWM_EN0_RESETN = (1 << 9),      /*!< Fixed-pin function as RESETN. */
    SWM_EN0_CLKIN = (1 << 10),      /*!< Fixed-pin function as CLKIN. */
    SWM_EN0_VDDCMP = (1 << 11),     /*!< Fixed-pin function as VDDCMP. */
    SWM_EN0_I2C0_SDA = (1 << 12),   /*!< Fixed-pin function as I2C0_SDA. */
    SWM_EN0_I2C0_SCL = (1 << 13),   /*!< Fixed-pin function as I2C0_SCL. */
    SWM_EN0_ADC_CHN0 = (1 << 14),   /*!< Fixed-pin function as ADC_CHN0. */
    SWM_EN0_ADC_CHN1 = (1 << 15),   /*!< Fixed-pin function as ADC_CHN1. */
    SWM_EN0_ADC_CHN2 = (1 << 16),   /*!< Fixed-pin function as ADC_CHN2. */
    SWM_EN0_ADC_CHN3 = (1 << 17),   /*!< Fixed-pin function as ADC_CHN3. */
    SWM_EN0_ADC_CHN4 = (1 << 18),   /*!< Fixed-pin function as ADC_CHN4. */
    SWM_EN0_ADC_CHN5 = (1 << 19),   /*!< Fixed-pin function as ADC_CHN5. */
    SWM_EN0_ADC_CHN6 = (1 << 20),   /*!< Fixed-pin function as ADC_CHN6. */
    SWM_EN0_ADC_CHN7 = (1 << 21),   /*!< Fixed-pin function as ADC_CHN7. */
    SWM_EN0_ADC_CHN8 = (1 << 22),   /*!< Fixed-pin function as ADC_CHN8. */
    SWM_EN0_ADC_CHN9 = (1 << 23),   /*!< Fixed-pin function as ADC_CHN9. */
    SWM_EN0_ADC_CHN10 = (1 << 24),  /*!< Fixed-pin function as ADC_CHN10. */
    SWM_EN0_ADC_CHN11 = (1 << 25),  /*!< Fixed-pin function as ADC_CHN11. */
    SWM_EN0_DAC_OUT0 = (1 << 26),   /*!< Fixed-pin function as DACOUT0. */
    SWM_EN0_DAC_OUT1 = (1 << 27),   /*!< Fixed-pin function as DACOUT1. */
    SWM_EN0_CAPT_X0 = (1 << 28),    /*!< Fixed-pin function as CAPT_X0. */
    SWM_EN0_CAPT_X1 = (1 << 29),    /*!< Fixed-pin function as CAPT_X1. */
    SWM_EN0_CAPT_X2 = (1 << 30),    /*!< Fixed-pin function as CAPT_X2. */
    SWM_EN0_CAPT_X3 = (1 << 31),    /*!< Fixed-pin function as CAPT_X3. */
    SWM_EN1_NONE = 0,               /*!< No change for enable 1 */
    SWM_EN1_CAPT_X4 = (1 << 0),     /*!< Fixed-pin function as CAPT_X4. */
    SWM_EN1_CAPT_X5 = (1 << 1),     /*!< Fixed-pin function as CAPT_X5. */
    SWM_EN1_CAPT_X6 = (1 << 2),     /*!< Fixed-pin function as CAPT_X6. */
    SWM_EN1_CAPT_X7 = (1 << 3),     /*!< Fixed-pin function as CAPT_X7. */
    SWM_EN1_CAPT_X8 = (1 << 4),     /*!< Fixed-pin function as CAPT_X8. */
    SWM_EN1_CAPT_YL = (1 << 5),     /*!< Fixed-pin function as CAPT_YL. */
    SWM_EN1_CAPT_YH = (1 << 6),     /*!< Fixed-pin function as CAPT_YH. */
} SWM_FIXED_Type;

#endif

static inline void SwmMovablePinAssign(SWM_MOVABLE_Type function, SWM_PORTPIN_Type pin)
{
    int index = function >> 2;
    SWM0->PINASSIGN_DATA[index] = pin << (function & 0x3 << 3);
}

/**
 * @brief   Enable fixed SWM pin functions
 * @param   setting0 : setting for PINENABLE0 register
 * @param   setting1 : setting for PINENABLE1 register
 * @return  Nothing
 */
static inline void swmEnableFixedPin(SWM_FIXED_Type setting0, SWM_FIXED_Type setting1)
{
    SWM0->PINENABLE0 = SWM0->PINENABLE0 & ~setting0;
    SWM0->PINENABLE1 = SWM0->PINENABLE1 & ~setting1;
}

/**
 * @brief   Disable fixed SWM pin functions
 * @param   setting0 : setting for PINENABLE0 register
 * @param   setting1 : setting for PINENABLE1 register
 * @return  Nothing
 */
static inline void swmDisableFixedPin(SWM_FIXED_Type setting0, SWM_FIXED_Type setting1)
{
    SWM0->PINENABLE0 = SWM0->PINENABLE0 | setting0;
    SWM0->PINENABLE1 = SWM0->PINENABLE1 | setting1;
}