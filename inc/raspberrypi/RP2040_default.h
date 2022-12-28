/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
RP2040 default settings for stuff like clocks etcetera
*/
#ifndef RP2040_DEFAULT_H
#define RP2040_DEFAULT_H

#if !defined(FREQ_XTAL) && !defined(FREQ_CPU)
#warning default configuration is loaded!
// default clock configuration
#define FREQ_XTAL (12000000u)       /**< Crystal oscillator frequncy */
#define FREQ_CPU (12000000u)        /**< CPU frequency */
#define FREQ_USB (12000000u)        /**< USB frequency */
#define FREQ_ADC (12000000u)        /**< ADC frequency */
#define FREQ_RTC (CLOCK_XTAL / 256) /**< RTC frequency */
#define FREQ_PERI (CLOCK_CPU)       /**< Peripherals frequency */
#endif

#endif