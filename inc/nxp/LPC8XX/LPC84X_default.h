/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC840 series default configuration used by libMcuLL
*/

#ifndef LPC84X_DEFAULT_H
#define LPC84X_DEFAULT_H

#if !defined(CLOCK_XTAL) && !defined(CLOCK_EXT_IN) && !defined(CLOCK_CPU) && !defined(CLOCK_AHB) && !defined(CLOCK_MAIN)
#warning default configuration is loaded!
// default clock configuration
#define CLOCK_XTAL (12000000u)
#define CLOCK_EXT_IN (0u)
#define CLOCK_CPU (30000000u)
#define CLOCK_AHB (30000000u)
#define CLOCK_MAIN (60000000u)
// predefine main clock source, reduce code size
// #define CLOCK_MAIN_SOURCE   SYSCTL_MAINCLKSRC_IRC
#endif

#endif
