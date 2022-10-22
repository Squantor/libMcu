/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series Windowed watchdog registers, defines and functions.
 */
#ifndef LPC84X_WWDT_H
#define LPC84X_WWDT_H

/** WWDT - Register Layout Typedef */
typedef volatile struct WWDT_Struct {
  uint32_t MOD; /**< Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer., offset: 0x0 */
  uint32_t TC;  /**< Watchdog timer constant register. This 24-bit register determines the time-out value., offset: 0x4 */
  uint32_t FEED; /**< Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer
                    with the value contained in TC., offset: 0x8 */
  const uint32_t
    TV; /**< Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer., offset: 0xC */
  uint8_t RESERVED_0[4];
  uint32_t WARNINT; /**< Watchdog Warning Interrupt compare value., offset: 0x14 */
  uint32_t WINDOW;  /**< Watchdog Window compare value., offset: 0x18 */
} WWDT_Type;

#endif
