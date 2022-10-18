/*
SPDX-License-Identifier: Unlicense
Copyright (c) 2022 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
RP2040 default settings for stuff like clocks etcetera
*/
#ifndef RP2040_DEFAULT_H
#define RP2040_DEFAULT_H

#if !defined(CLOCK_XTAL) && !defined(CLOCK_CPU)
#warning default configuration is loaded!
// default clock configuration
#define CLOCK_XTAL (12000000u)
#define CLOCK_CPU (12000000u)
// TODO: Define the clocking network of the RP2040
#endif

#endif