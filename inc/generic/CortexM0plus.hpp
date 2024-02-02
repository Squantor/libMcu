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

namespace libMcuLL {
namespace hw {

// change into constexprs?
#define CORTEX_M0P_REVISION 0x0001   /**< Revision number */
#define CORTEX_M0P_MPU_PRESENT 0     /**< Presence of memory protection unit */
#define CORTEX_M0P_VTOR_PRESENT 1    /**< presence of vector relocation */
#define CORTEX_M0P_NVIC_PRIO_BITS 2  /**< NVIC priority bit count */
#define CORTEX_M0P_SYSTICK_VARIANT 0 /**< Type of systick */

enum class interrupts : int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
};
}  // namespace hw
}  // namespace libMcuLL

#include <CortexM/cortex_m0plus.hpp>

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
