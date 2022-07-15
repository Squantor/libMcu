/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for a generic cortex M0 microcontroller */
#ifndef CORTEXM0_H
#define CORTEXM0_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV 0x0000
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

typedef enum {
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
} IRQn_Type;

#include <CMSIS/core_cm0.h>

#ifdef __cplusplus
}
#endif

#endif
