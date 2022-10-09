/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the raspberry RP2040 microcontroller */
#ifndef RP2040_H
#define RP2040_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 1
#define __FPU_PRESENT 0
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
  // TODO: Interrupts
} IRQn_Type;

#include <CMSIS/core_cm0plus.h>

// TODO: Peripheral addresses

#define XIP_SSI_BASE (0x18000000UL)

#define XIP_SSI ((XIP_SSI_Type *)XIP_SSI_BASE)

// default configuration options, override with your own!
#include "raspberrypi/RP2040_default.h"

// Peripheral definition includes
#include "raspberrypi/xip_ssi.h"

#ifdef __cplusplus
}
#endif

#endif
