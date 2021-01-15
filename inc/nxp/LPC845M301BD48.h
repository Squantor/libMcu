/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC845M301BD48 microcontroller definitions */
#ifndef LPC845M301BD48_H
#define LPC845M301BD48_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV             0x0001
#define __MPU_PRESENT             0
#define __VTOR_PRESENT            1
#define __NVIC_PRIO_BITS          2
#define __Vendor_SysTickConfig    0

#include <CMSIS/core_cm0plus.h>     /* Core Peripheral Access Layer */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48    /**< Number of interrupts in the Vector table */

typedef enum {
    Reset_IRQn              = -15,  /**< Reset entry  */
    NonMaskableInt_IRQn     = -14,  /**< Non Maskable Interrupt */
    HardFault_IRQn          = -13,  /**< Cortex-M0 SV Hard Fault Interrupt */
    SVCall_IRQn             = -5,   /**< Cortex-M0 SV Call Interrupt */
    PendSV_IRQn             = -2,   /**< Cortex-M0 Pend SV Interrupt */
    SysTick_IRQn            = -1,   /**< Cortex-M0 System Tick Interrupt */

    SPI0_IRQn               = 0,    /**< SPI0 interrupt */
    SPI1_IRQn               = 1,    /**< SPI1 interrupt */
    DAC0_IRQn               = 2,    /**< DAC0 interrupt */
    UART0_IRQn              = 3,    /**< USART0 interrupt */
    UART1_IRQn              = 4,    /**< USART1 interrupt */
    UART2_IRQn              = 5,    /**< USART2 interrupt */
    Reserved22_IRQn         = 6,    /**< Reserved interrupt */
    I2C1_IRQn               = 7,    /**< I2C1 interrupt */
    I2C0_IRQn               = 8,    /**< I2C0 interrupt */
    SCT_IRQn                = 9,    /**< State configurable timer interrupt */
    MRT_IRQn                = 10,   /**< Multi-rate timer interrupt */
    CMP_IRQn                = 11,   /**< Analog comparator interrupt or Capacitive Touch interrupt */
    WDT_IRQn                = 12,   /**< Windowed watchdog timer interrupt */
    BOD_IRQn                = 13,   /**< BOD interrupts */
    FLASH_IRQn              = 14,   /**< flash interrupt */
    WKT_IRQn                = 15,   /**< Self-wake-up timer interrupt */
    ADC_SEQA_IRQn           = 16,   /**< ADC0 sequence A completion. */
    ADC_SEQB_IRQn           = 17,   /**< ADC0 sequence B completion. */
    ADC_THCMP_IRQn          = 18,   /**< ADC0 threshold compare and error. */
    ADC_OVR_IRQn            = 19,   /**< ADC0 overrun */
    DMA_IRQn                = 20,   /**< DMA0 interrupt */
    I2C2_IRQn               = 21,   /**< I2C2 interrupt */
    I2C3_IRQn               = 22,   /**< I2C3 interrupt */
    CTIMER0_IRQn            = 23,   /**< Timer interrupt */
    PIN_INT0_IRQn           = 24,   /**< Pin interrupt 0 or pattern match engine slice 0 interrupt */
    PIN_INT1_IRQn           = 25,   /**< Pin interrupt 1 or pattern match engine slice 1 interrupt */
    PIN_INT2_IRQn           = 26,   /**< Pin interrupt 2 or pattern match engine slice 2 interrupt */
    PIN_INT3_IRQn           = 27,   /**< Pin interrupt 3 or pattern match engine slice 3 interrupt */
    PIN_INT4_IRQn           = 28,   /**< Pin interrupt 4 or pattern match engine slice 4 interrupt */
    PIN_INT5_DAC1_IRQn      = 29,   /**< Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt */
    PIN_INT6_USART3_IRQn    = 30,   /**< Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt */
    PIN_INT7_USART4_IRQn    = 31    /**< Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt */
} IRQn_Type;

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum dmaRequestSource
{
    kDmaRequestUSART0_RX_DMA        = 0U,          /**< USART0 RX DMA  */
    kDmaRequestUSART0_TX_DMA        = 1U,          /**< USART0 TX DMA  */
    kDmaRequestUSART1_RX_DMA        = 2U,          /**< USART1 RX DMA  */
    kDmaRequestUSART1_TX_DMA        = 3U,          /**< USART1 TX DMA  */
    kDmaRequestUSART2_RX_DMA        = 4U,          /**< USART2 RX DMA  */
    kDmaRequestUSART2_TX_DMA        = 5U,          /**< USART2 TX DMA  */
    kDmaRequestUSART3_RX_DMA        = 6U,          /**< USART3 RX DMA  */
    kDmaRequestUSART3_TX_DMA        = 7U,          /**< USART3 TX DMA  */
    kDmaRequestUSART4_RX_DMA        = 8U,          /**< USART4 RX DMA  */
    kDmaRequestUSART4_TX_DMA        = 9U,          /**< USART4 TX DMA  */
    kDmaRequestSPI0_RX_DMA          = 10U,         /**< SPI0 RX DMA  */
    kDmaRequestSPI0_TX_DMA          = 11U,         /**< SPI0 TX DMA  */
    kDmaRequestSPI1_RX_DMA          = 12U,         /**< SPI1 RX DMA  */
    kDmaRequestSPI1_TX_DMA          = 13U,         /**< SPI1 TX DMA  */
    kDmaRequestI2C0_SLV_DMA         = 14U,         /**< I2C0 SLAVE DMA  */
    kDmaRequestI2C0_MST_DMA         = 15U,         /**< I2C0 MASTER DMA  */
    kDmaRequestI2C1_SLV_DMA         = 16U,         /**< I2C1 SLAVE DMA  */
    kDmaRequestI2C1_MST_DMA         = 17U,         /**< I2C1 MASTER DMA  */
    kDmaRequestI2C2_SLV_DMA         = 18U,         /**< I2C2 SLAVE DMA  */
    kDmaRequestI2C2_MST_DMA         = 19U,         /**< I2C2 MASTER DMA  */
    kDmaRequestI2C3_SLV_DMA         = 20U,         /**< I2C3 SLAVE DMA  */
    kDmaRequestI2C3_MST_DMA         = 21U,         /**< I2C3 MASTER DMA  */
    kDmaRequestDAC0_DMAREQ          = 22U,         /**< DAC0 DMA REQUEST  */
    kDmaRequestDAC1_DMAREQ          = 23U,         /**< DAC1 DMA REQUEST  */
    kDmaRequestCAPT_DMA             = 24U,         /**< CAPT DMA  */
} dmaRequestSource_t;


/* Base addresses */
#define FLASH_BASE      (0x00000000u)
#define RAM_BASE        (0x10000000u)
#define ROM_BASE        (0x0F001FF1u)
#define APB0_BASE       (0x40000000u)
#define AHB_BASE        (0x50000000u)


/* APB peripherals, see UM11029 2.2.1 */
#define WWDT_BASE       (0x40000000u)
#define MRT0_BASE       (0x40004000u)
#define WKT_BASE        (0x40008000u)
#define SWM0_BASE       (0x4000C000u)
#define FAIM_BASE       (0x40010000u)
#define DAC0_BASE       (0x40014000u)
#define DAC1_BASE       (0x40018000u)
#define ADC0_BASE       (0x4001C000u)
#define PMU_BASE        (0x40020000u)
#define ACOMP_BASE      (0x40024000u)
#define INPUTMUX_BASE   (0x4002C000u)
#define I2C2_BASE       (0x40030000u)
#define I2C3_BASE       (0x40034000u)
#define CTIMER0_BASE    (0x40038000u)
#define FLASH_CTRL_BASE (0x40040000u)
#define IOCON_BASE      (0x40044000u)
#define SYSCON_BASE     (0x40048000u)
#define I2C0_BASE       (0x40050000u)
#define I2C1_BASE       (0x40054000u)
#define SPI0_BASE       (0x40058000u)
#define SPI1_BASE       (0x4005C000u)
#define CAPT_BASE       (0x40060000u)
#define USART0_BASE     (0x40064000u)
#define USART1_BASE     (0x40068000u)
#define USART2_BASE     (0x4006C000u)
#define USART3_BASE     (0x40070000u)

/* AHB peripherals, see UM11029 2.2.1 */
#define CRC_BASE        (0x50000000u)
#define SCT0_BASE       (0x50004000u)
#define DMA0_BASE       (0x50008000u)
#define MTB_SFR_BASE    (0x5000C000u)

#define WWDT       ((struct WWDT_T      *) WWDT_BASE)
#define MRT0       ((struct MRT0_T      *) MRT0_BASE)
#define WKT        ((struct WKT_T       *) WKT_BASE)
#define SWM0       ((struct SWM0_T      *) SWM0_BASE)
#define FAIM       ((struct FAIM_T      *) FAIM_BASE)
#define DAC0       ((struct DAC0_T      *) DAC0_BASE)
#define DAC1       ((struct DAC1_T      *) DAC1_BASE)
#define ADC0       ((struct ADC0_T      *) ADC0_BASE)
#define PMU        ((struct PMU_T       *) PMU_BASE)
#define ACOMP      ((struct ACOMP_T     *) ACOMP_BASE)
#define INPUTMUX   ((struct INPUTMUX_T  *) INPUTMUX_BASE)
#define I2C2       ((struct I2C2_T      *) I2C2_BASE)
#define I2C3       ((struct I2C3_T      *) I2C3_BASE)
#define CTIMER0    ((struct CTIMER0_T   *) CTIMER0_BASE)
#define FLASH_CTRL ((struct FLASH_CTRL_T*) FLASH_CTRL_BASE)
#define IOCON      ((struct IOCON_T     *) IOCON_BASE)
#define SYSCON     ((struct SYSCON_T    *) SYSCON_BASE)
#define I2C0       ((struct I2C0_T      *) I2C0_BASE)
#define I2C1       ((struct I2C1_T      *) I2C1_BASE)
#define SPI0       ((struct SPI0_T      *) SPI0_BASE)
#define SPI1       ((struct SPI1_T      *) SPI1_BASE)
#define CAPT       ((struct CAPT_T      *) CAPT_BASE)
#define USART0     ((struct USART0_T    *) USART0_BASE)
#define USART1     ((struct USART1_T    *) USART1_BASE)
#define USART2     ((struct USART2_T    *) USART2_BASE)
#define USART3     ((struct USART3_T    *) USART3_BASE)
#define CRC        ((struct CRC_T       *) CRC_BASE)
#define SCT0       ((struct SCT0_T      *) SCT0)_BASE
#define DMA0       ((struct DMA0_T      *) DMA0_BASE)
#define MTB_SFR    ((struct MTB_SFR_T   *) MTB_SFR_BASE)

typedef enum PINx {
    IOCON_PIO0  =  0x11,
    IOCON_PIO1  =  0x0B,
    IOCON_PIO2  =  0x06,
    IOCON_PIO3  =  0x05,
    IOCON_PIO4  =  0x04,
    IOCON_PIO5  =  0x03,
    IOCON_PIO6  =  0x10,
    IOCON_PIO7  =  0x0F,
    IOCON_PIO8  =  0x0E,
    IOCON_PIO9  =  0x0D,
    IOCON_PIO10 =  0x08,
    IOCON_PIO11 =  0x07,
    IOCON_PIO12 =  0x02,
    IOCON_PIO13 =  0x01,
    IOCON_PIO14 =  0x12,
    IOCON_PIO15 =  0x0A,
    IOCON_PIO16 =  0x09,
    IOCON_PIO17 =  0x00,
    IOCON_PIO18 =  0x1E,
    IOCON_PIO19 =  0x1D,
    IOCON_PIO20 =  0x1C,
    IOCON_PIO21 =  0x1B,
    IOCON_PIO22 =  0x1A,
    IOCON_PIO23 =  0x19,
    IOCON_PIO24 =  0x18,
    IOCON_PIO25 =  0x17,
    IOCON_PIO26 =  0x16,
    IOCON_PIO27 =  0x15,
    IOCON_PIO28 =  0x14,
} PINx_T;

// default configuration options, override with your own!
#include "nxp/LPC8XX/LPC82X_default.h"
// Peripheral definition includes, ordering matters
#include "nxp/LPC8XX/LPC82X_syscon.h"
#include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC82X_swm.h"
#include "nxp/LPC8XX/LPC82X_gpio.h"
#include "nxp/LPC8XX/LPC8XX_iocon.h"
#include "nxp/LPC8XX/LPC8XX_wwdt.h"
#include "nxp/LPC8XX/LPC8XX_wkt.h"
#include "nxp/LPC8XX/LPC8XX_sct.h"
#include "nxp/LPC8XX/LPC8XX_ROM.h"
#include "nxp/LPC8XX/LPC8XX_pmu.h"
#include "nxp/LPC8XX/LPC8XX_pinint.h"
#include "nxp/LPC8XX/LPC8XX_mrt.h"
#include "nxp/LPC8XX/LPC8XX_fmc.h"
#include "nxp/LPC8XX/LPC8XX_irc.h"
#include "nxp/LPC8XX/LPC8XX_crc.h"
#include "nxp/LPC8XX/LPC82X_acmp.h"
#include "nxp/LPC8XX/LPC82X_uart.h"
#include "nxp/LPC8XX/LPC8XX_spi.h"
#include "nxp/LPC8XX/LPC82X_i2c.h"
#include "nxp/LPC8XX/LPC82X_adc.h"
#include "nxp/LPC8XX/LPC82X_dma.h"
#include "nxp/LPC8XX/LPC82X_inmux.h"

#ifdef __cplusplus
}
#endif

#endif
