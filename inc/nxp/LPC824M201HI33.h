/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* Main entry point for the LPC824M201HI33 microcontroller definitions */
#ifndef LPC824M201JHI33_H
#define LPC824M201JHI33_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV             0x0001
#define __MPU_PRESENT             0
#define __VTOR_PRESENT            1
#define __NVIC_PRIO_BITS          2
#define __Vendor_SysTickConfig    0

typedef enum {
    Reset_IRQn          = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn      = -13,
    SVCall_IRQn         = -5,
    PendSV_IRQn         = -2,
    SysTick_IRQn        = -1,

    SPI0_IRQn           = 0,
    SPI1_IRQn           = 1,
    Reserved0_IRQn      = 2,
    UART0_IRQn          = 3,
    UART1_IRQn          = 4,
    UART2_IRQn          = 5,
    Reserved1_IRQn      = 6,
    I2C1_IRQn           = 7,
    I2C0_IRQn           = 8,
    I2C_IRQn            = 8,
    SCT_IRQn            = 9,
    MRT_IRQn            = 10,
    CMP_IRQn            = 11,
    WDT_IRQn            = 12,
    BOD_IRQn            = 13,
    FLASH_IRQn          = 14,
    WKT_IRQn            = 15,
    ADC_SEQA_IRQn       = 16,
    ADC_SEQB_IRQn       = 17,
    ADC_THCMP_IRQn      = 18,
    ADC_OVR_IRQn        = 19,
    DMA_IRQn            = 20,
    I2C2_IRQn           = 21,
    I2C3_IRQn           = 22,
    Reserved2_IRQn      = 23,
    PININT0_IRQn        = 24,
    PININT1_IRQn        = 25,
    PININT2_IRQn        = 26,
    PININT3_IRQn        = 27,
    PININT4_IRQn        = 28,
    PININT5_IRQn        = 29,
    PININT6_IRQn        = 30,
    PININT7_IRQn        = 31,
} IRQn_Type;

#include <CMSIS/core_cm0plus.h>

/* Base addresses */
#define LPC_FLASH_BASE      (0x00000000UL)
#define LPC_RAM_BASE        (0x10000000UL)
#define LPC_ROM_BASE        (0x1FFF0000UL)
#define LPC_APB0_BASE       (0x40000000UL)
#define LPC_AHB_BASE        (0x50000000UL)

/* APB0 peripherals */
#define LPC_WWDT_BASE       (0x40000000UL)
#define LPC_MRT_BASE        (0x40004000UL)
#define LPC_WKT_BASE        (0x40008000UL)
#define LPC_SWM_BASE        (0x4000C000UL)
#define LPC_ADC_BASE        (0x4001C000UL)
#define LPC_PMU_BASE        (0x40020000UL)
#define LPC_CMP_BASE        (0x40024000UL)
#define LPC_DMATIRGMUX_BASE (0x40028000UL)
#define LPC_INMUX_BASE      (0x4002C000UL)
#define LPC_FMC_BASE        (0x40040000UL)
#define IOCON_BASE          (0x40044000UL)
#define SYSCON_BASE         (0x40048000UL)
#define LPC_I2C0_BASE       (0x40050000UL)
#define LPC_I2C1_BASE       (0x40054000UL)
#define LPC_SPI0_BASE       (0x40058000UL)
#define LPC_SPI1_BASE       (0x4005C000UL)
#define LPC_USART0_BASE     (0x40064000UL)
#define LPC_USART1_BASE     (0x40068000UL)
#define LPC_USART2_BASE     (0x4006C000UL)
#define LPC_I2C2_BASE       (0x40070000UL)
#define LPC_I2C3_BASE       (0x40074000UL)

/* AHB peripherals */
#define LPC_CRC_BASE        (0x50000000UL)
#define LPC_SCT_BASE        (0x50004000UL)
#define LPC_DMA_BASE        (0x50008000UL)

#define LPC_GPIO_PORT_BASE  (0xA0000000UL)
#define LPC_PIN_INT_BASE    (0xA0004000UL)

#define LPC_WWDT        ((LPC_WWDT_T        *) LPC_WWDT_BASE)
#define LPC_SPI0        ((LPC_SPI_T         *) LPC_SPI0_BASE)
#define LPC_SPI1        ((LPC_SPI_T         *) LPC_SPI1_BASE)
#define LPC_USART0      ((LPC_USART_T       *) LPC_USART0_BASE)
#define LPC_USART1      ((LPC_USART_T       *) LPC_USART1_BASE)
#define LPC_USART2      ((LPC_USART_T       *) LPC_USART2_BASE)
#define LPC_WKT         ((LPC_WKT_T         *) LPC_WKT_BASE)
#define LPC_PMU         ((LPC_PMU_T         *) LPC_PMU_BASE)
#define LPC_CRC         ((LPC_CRC_T         *) LPC_CRC_BASE)
#define LPC_SCT         ((LPC_SCT_T         *) LPC_SCT_BASE)
#define LPC_GPIO_PORT   ((LPC_GPIO_T        *) LPC_GPIO_PORT_BASE)
#define LPC_PININT      ((LPC_PIN_INT_T     *) LPC_PIN_INT_BASE)
#define IOCON           ((IOCON_Type        *) IOCON_BASE)
#define LPC_SWM         ((LPC_SWM_T         *) LPC_SWM_BASE)
#define SYSCON          ((SYSCON_Type       *) SYSCON_BASE)
#define LPC_CMP         ((LPC_CMP_T         *) LPC_CMP_BASE)
#define LPC_FMC         ((LPC_FMC_T         *) LPC_FMC_BASE)
#define LPC_MRT         ((LPC_MRT_T         *) LPC_MRT_BASE)
#define LPC_I2C0        ((LPC_I2C_T         *) LPC_I2C0_BASE)
#define LPC_ADC         ((LPC_ADC_T         *) LPC_ADC_BASE)
#define LPC_I2C1        ((LPC_I2C_T         *) LPC_I2C1_BASE)
#define LPC_I2C2        ((LPC_I2C_T         *) LPC_I2C2_BASE)
#define LPC_I2C3        ((LPC_I2C_T         *) LPC_I2C3_BASE)
#define LPC_DMA         ((LPC_DMA_T         *) LPC_DMA_BASE)
#define LPC_DMATRIGMUX  ((LPC_DMATRIGMUX_T  *) LPC_DMATIRGMUX_BASE)
#define LPC_INMUX       ((LPC_INMUX_T       *) LPC_INMUX_BASE)

typedef enum PINx {
    IOCON_PIO0_0  =  17,
    IOCON_PIO0_1  =  11,
    IOCON_PIO0_2  =  6,
    IOCON_PIO0_3  =  5,
    IOCON_PIO0_4  =  4,
    IOCON_PIO0_5  =  3,
    IOCON_PIO0_6  =  16,
    IOCON_PIO0_7  =  15,
    IOCON_PIO0_8  =  14,
    IOCON_PIO0_9  =  13,
    IOCON_PIO0_10 =  8,
    IOCON_PIO0_11 =  7,
    IOCON_PIO0_12 =  2,
    IOCON_PIO0_13 =  1,
    IOCON_PIO0_14 =  18,
    IOCON_PIO0_15 =  10,
    IOCON_PIO0_16 =  9,
    IOCON_PIO0_17 =  0,
    IOCON_PIO0_18 =  30,
    IOCON_PIO0_19 =  29,
    IOCON_PIO0_20 =  28,
    IOCON_PIO0_21 =  27,
    IOCON_PIO0_22 =  26,
    IOCON_PIO0_23 =  25,
    IOCON_PIO0_24 =  24,
    IOCON_PIO0_25 =  23,
    IOCON_PIO0_26 =  22,
    IOCON_PIO0_27 =  21,
    IOCON_PIO0_28 =  20,
} PINx_T;

// default configuration options, override with your own!
#include "nxp/LPC8XX/LPC82X_default.h"
// Peripheral definition includes, ordering matters
#include "nxp/LPC8XX/LPC82X_syscon.h"
#include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC82X_swm.h"
#include "nxp/LPC8XX/LPC82X_gpio.h"
#include "nxp/LPC8XX/LPC82X_gpio_old.h"
#include "nxp/LPC8XX/LPC8XX_iocon.h"
#include "nxp/LPC8XX/LPC8XX_wwdt.h"
#include "nxp/LPC8XX/LPC8XX_wwdt_old.h"
#include "nxp/LPC8XX/LPC8XX_wkt.h"
#include "nxp/LPC8XX/LPC8XX_wkt_old.h"
#include "nxp/LPC8XX/LPC8XX_sct.h"
#include "nxp/LPC8XX/LPC8XX_sct_old.h"
#include "nxp/LPC8XX/LPC8XX_ROM.h"
#include "nxp/LPC8XX/LPC8XX_pmu.h"
#include "nxp/LPC8XX/LPC8XX_pmu_old.h"
#include "nxp/LPC8XX/LPC8XX_pinint.h"
#include "nxp/LPC8XX/LPC8XX_pinint_old.h"
#include "nxp/LPC8XX/LPC8XX_mrt.h"
#include "nxp/LPC8XX/LPC8XX_mrt_old.h"
#include "nxp/LPC8XX/LPC8XX_fmc.h"
#include "nxp/LPC8XX/LPC8XX_fmc_old.h"
#include "nxp/LPC8XX/LPC8XX_irc.h"
#include "nxp/LPC8XX/LPC8XX_irc_old.h"
#include "nxp/LPC8XX/LPC8XX_crc.h"
#include "nxp/LPC8XX/LPC8XX_crc_old.h"
#include "nxp/LPC8XX/LPC82X_acmp.h"
#include "nxp/LPC8XX/LPC82X_acmp_old.h"
#include "nxp/LPC8XX/LPC82X_uart.h"
#include "nxp/LPC8XX/LPC82X_uart_old.h"
#include "nxp/LPC8XX/LPC8XX_spi.h"
#include "nxp/LPC8XX/LPC8XX_spi_old.h"
#include "nxp/LPC8XX/LPC82X_i2c.h"
#include "nxp/LPC8XX/LPC82X_i2c_old.h"
#include "nxp/LPC8XX/LPC82X_adc.h"
#include "nxp/LPC8XX/LPC82X_adc_old.h"
#include "nxp/LPC8XX/LPC82X_dma.h"
#include "nxp/LPC8XX/LPC82X_dma_old.h"
#include "nxp/LPC8XX/LPC82X_inmux.h"
#include "nxp/LPC8XX/LPC82X_inmux_old.h"

#ifdef __cplusplus
}
#endif

#endif