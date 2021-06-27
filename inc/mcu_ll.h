/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
Main entry point, one giant list of microcontroller targets that are supported.
Keep this header as small as possible, warnings definitions keep them in the 
MCU specific headers.
*/
#ifndef MCU_LL_H
#define MCU_LL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

// LPC812 variants
#if defined(MCU_LPC810M021FN8)
#include <nxp/LPC810M021FN8.h>
#elif defined(MCU_LPC811M001DH16)
#include <nxp/LPC811M001DH16.h>
#elif defined(MCU_LPC812M101D20)
#include <nxp/LPC812M101D20.h>
#elif defined(MCU_LPC812M101DH16)
#include <nxp/LPC812M101DH16.h>
#elif defined(MCU_LPC812M101DH20)
#include <nxp/LPC812M101DH20.h>
#elif defined(MCU_LPC812M101TB16)
#include <nxp/LPC812M101TB16.h>
#elif defined(MCU_LPC824M201HI33)
#include <nxp/LPC824M201HI33.h>
#elif defined(MCU_LPC824M201DH20)
#include <nxp/LPC824M201DH20.h>
#elif defined(MCU_LPC845M301BD48)
#include <nxp/LPC845M301BD48.h>
#elif defined(MCU_LPC844M201BD64)
#include <nxp/LPC844M201BD64.h>
#elif defined(MCU_CortexM0)
#include <generic/CortexM0.h>
#elif defined(MCU_CortexM0plus)
#include <generic/CortexM0plus.h>
#elif defined(MCU_CortexM3)
#include <generic/CortexM3.h>
#elif defined(MCU_CortexM4)
#include <generic/CortexM4.h>
#elif defined(MCU_CortexM7)
#include <generic/CortexM7.h>

#else
#error "Unknown or unsupported microcontroller defined, use MCU_Microcontroller"
#endif

#ifdef __cplusplus
}
#endif

#endif
