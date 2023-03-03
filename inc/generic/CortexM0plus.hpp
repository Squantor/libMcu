/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for a generic cortex M0+ microcontroller definitions
 */
#ifndef CORTEXM0PLUS_HPP
#define CORTEXM0PLUS_HPP

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0000
#define __MPU_PRESENT 0
#define __VTOR_PRESENT 0
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

#include <CMSIS/core_cm0plus.h>

#ifdef __cplusplus
}
#endif

/*
Copied orignally from the C header, the idea is to move more and more from
C definitions to C++. Step by step, C++ bits will go below
*/

#endif
