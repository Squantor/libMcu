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
/* Main entry point for the LPC812M101JDH20 microcontroller definitions */
#ifndef LPC812M101JDH20_H
#define LPC812M101JDH20_H

#ifdef __cplusplus
extern "C" {
#endif

#warning "Microcontroller LPC812M101JDH20 support is WIP"

// Define peripheral addresses
// Define peripherals

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

#ifdef __cplusplus
}
#endif

#endif