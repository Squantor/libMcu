/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for a generic cortex M7 microcontroller */
#ifndef CORTEXM7_H
#define CORTEXM7_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M7 Processor and Core Peripherals */
#define __CM7_REV                 0x0000U
#define __FPU_PRESENT             0
#define __MPU_PRESENT             0
#define __ICACHE_PRESENT          0
#define __DCACHE_PRESENT          0
#define __DTCM_PRESENT            0
#define __NVIC_PRIO_BITS          3
#define __Vendor_SysTickConfig    0

typedef enum {
    Reset_IRQn          = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn      = -13,
    MemManage_IRQn      = -12,
    BusFault_IRQn       = -11,
    UsageFault_IRQn     = -10,
    SVCall_IRQn         = -5,
    PendSV_IRQn         = -2,
    SysTick_IRQn        = -1,
} IRQn_Type;

#include <CMSIS/core_cm7.h>

#ifdef __cplusplus
}
#endif

#endif
