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
/* Main entry point for the LPC810M021FN8 microcontroller definitions */
#ifndef LPC810M021FN8_H
#define LPC810M021FN8_H

/*
Most information here derived/copied over from the LPCopen libraries.
*/

#ifdef __cplusplus
extern "C" {
#endif

#warning "Microcontroller LPC810M021FN8 support is WIP"

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
    Reserved2_IRQn      = 7,
    I2C0_IRQn           = 8,
    SCT_IRQn            = 9,
    MRT_IRQn            = 10,
    CMP_IRQn            = 11,
    WDT_IRQn            = 12,
    BOD_IRQn            = 13,
    Reserved3_IRQn      = 14,
    WKT_IRQn            = 15,
    Reserved4_IRQn      = 16,
    Reserved5_IRQn      = 17,
    Reserved6_IRQn      = 18,
    Reserved7_IRQn      = 19,
    Reserved8_IRQn      = 20,
    Reserved9_IRQn      = 21,
    Reserved10_IRQn     = 22,
    Reserved11_IRQn     = 23,
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

// Define peripheral addresses on APB0 bus
#define LPC_WWDT_BASE         (0x40000000UL)
#define LPC_MRT_BASE          (0x40004000UL)
#define LPC_WKT_BASE          (0x40008000UL)
#define LPC_SWM_BASE          (0x4000C000UL)
#define LPC_PMU_BASE          (0x40020000UL)
#define LPC_CMP_BASE          (0x40024000UL)

#define LPC_FMC_BASE          (0x40040000UL)
#define LPC_IOCON_BASE        (0x40044000UL)
#define LPC_SYSCTL_BASE       (0x40048000UL)
#define LPC_I2C0_BASE         (0x40050000UL)
#define LPC_SPI0_BASE         (0x40058000UL)
#define LPC_SPI1_BASE         (0x4005C000UL)
#define LPC_USART0_BASE       (0x40064000UL)
#define LPC_USART1_BASE       (0x40068000UL)
#define LPC_USART2_BASE       (0x4006C000UL)

/* AHB peripherals */
#define LPC_CRC_BASE          (0x50000000UL)
#define LPC_SCT_BASE          (0x50004000UL)

#define LPC_GPIO_PORT_BASE    (0xA0000000UL)
#define LPC_PIN_INT_BASE      (0xA0004000UL)

// Define peripherals
#define LPC_WWDT        ((LPC_WWDT_T    *) LPC_WWDT_BASE)
#define LPC_SPI0        ((LPC_SPI_T     *) LPC_SPI0_BASE)
#define LPC_USART0      ((LPC_USART_T   *) LPC_USART0_BASE)
#define LPC_USART1      ((LPC_USART_T   *) LPC_USART1_BASE)
#define LPC_WKT         ((LPC_WKT_T     *) LPC_WKT_BASE)
#define LPC_PMU         ((LPC_PMU_T     *) LPC_PMU_BASE)
#define LPC_CRC         ((LPC_CRC_T     *) LPC_CRC_BASE)
#define LPC_SCT         ((LPC_SCT_T     *) LPC_SCT_BASE)
#define LPC_GPIO_PORT   ((LPC_GPIO_T    *) LPC_GPIO_PORT_BASE)
#define LPC_PININT      ((LPC_PIN_INT_T *) LPC_PIN_INT_BASE)
#define LPC_IOCON       ((LPC_IOCON_T   *) LPC_IOCON_BASE)
#define LPC_SWM         ((LPC_SWM_T     *) LPC_SWM_BASE)
#define LPC_SYSCTL      ((LPC_SYSCTL_T  *) LPC_SYSCTL_BASE)
#define LPC_CMP         ((LPC_CMP_T     *) LPC_CMP_BASE)
#define LPC_FMC         ((LPC_FMC_T     *) LPC_FMC_BASE)
#define LPC_MRT         ((LPC_MRT_T     *) LPC_MRT_BASE)
#define LPC_I2C0        ((LPC_I2C_T     *) LPC_I2C0_BASE)

// package specific structures
typedef enum PINx {
    IOCON_PIO0  =  0x11,
    IOCON_PIO1  =  0x0B,
    IOCON_PIO2  =  0x06,
    IOCON_PIO3  =  0x05,
    IOCON_PIO4  =  0x04,
    IOCON_PIO5  =  0x03,
} PINx_T;

// Peripheral definition includes, ordering matters
#include "nxp/LPC8XX/LPC81X_syscon.h"
#include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC81X_swm.h"
#include "nxp/LPC8XX/LPC81X_gpio.h"
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
#include "nxp/LPC8XX/LPC81X_acmp.h"
#include "nxp/LPC8XX/LPC81X_uart.h"
#include "nxp/LPC8XX/LPC8XX_spi.h"
#include "nxp/LPC8XX/LPC81X_i2c.h"

#ifdef __cplusplus
}
#endif

#endif