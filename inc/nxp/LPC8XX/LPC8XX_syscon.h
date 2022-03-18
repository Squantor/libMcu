/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common system control registers, defines and functions.
*/
#ifndef LPC8XX_SYSCON_H
#define LPC8XX_SYSCON_H

/**
 * @brief   Sets up system PLL
 * @param   peripheral  base address of SYSCON peripheral
 * @param   msel        Feedback divider value
 * @param   psel        Post divider ratio
 * @return  Nothing
 */
static inline void sysconPllControl(SYSCON_Type *peripheral, uint32_t msel,
                                    SYSPLLCTRL_PSEL_Type psel) {
  peripheral->SYSPLLCTRL =
      (peripheral->SYSPLLCTRL & SYSPLLCTRL_MASK) | msel | (psel << 5);
}

/**
 * @brief   Checks the PLL status
 * @param   peripheral  base address of SYSCON peripheral
 * @return  PLL status, zero is not locked, one is locked
 */
static inline uint32_t sysconPllStatus(SYSCON_Type *peripheral) {
  return peripheral->SYSPLLSTAT;
}

/**
 * @brief   Sets up system oscillator
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Setting for the system oscillator
 * @return  Nothing
 */
static inline void sysconSysOscControl(SYSCON_Type *peripheral,
                                       uint32_t setting) {
  peripheral->SYSOSCCTRL = (peripheral->SYSOSCCTRL & SYSOSCCTRL_MASK) | setting;
}

/**
 * @brief   Select PLL clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the PLL
 * @return  Nothing
 */
static inline void sysconSysPllClockSelect(SYSCON_Type *peripheral,
                                           SYSPLLCLKSEL_Type setting) {
  peripheral->SYSPLLCLKSEL =
      (peripheral->MAINCLKSEL & SYSPLLCLKSEL_MASK) | setting;
  peripheral->SYSPLLCLKUEN = peripheral->MAINCLKUEN & ~SYSPLLCLKUEN_UPDATE;
  peripheral->SYSPLLCLKUEN = peripheral->MAINCLKUEN | SYSPLLCLKUEN_UPDATE;
}

/**
 * @brief   Select main clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the main clock network
 * @return  Nothing
 */
static inline void sysconMainClockSelect(SYSCON_Type *peripheral,
                                         MAINCLOCKSEL_Type setting) {
  peripheral->MAINCLKSEL = (peripheral->MAINCLKSEL & MAINCLKSEL_MASK) | setting;
  peripheral->MAINCLKUEN = peripheral->MAINCLKUEN & ~MAINCLKUEN_UPDATE;
  peripheral->MAINCLKUEN = peripheral->MAINCLKUEN | MAINCLKUEN_UPDATE;
}

/**
 * @brief   Set main clock divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   divider     Divider value, 0 is disable, 1 is divide by 1
 * @return  Nothing
 */
static inline void sysconMainClockDivider(SYSCON_Type *peripheral,
                                          uint32_t divider) {
  peripheral->SYSAHBCLKDIV =
      (peripheral->SYSAHBCLKDIV & SYSAHBCLKDIV_MASK) | divider;
}

/**
 * @brief   Enable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerEnables    set of peripherals to give power
 * @return  Nothing
 */
static inline void sysconPowerEnable(SYSCON_Type *peripheral,
                                     uint32_t powerEnables) {
  peripheral->PDRUNCFG = peripheral->PDRUNCFG & (~powerEnables | PDRUNCFG_MASK);
}

/**
 * @brief   Disable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerDisables   set of peripherals to remove power
 * @return  Nothing
 */
static inline void sysconPowerDisable(SYSCON_Type *peripheral,
                                      uint32_t powerDisables) {
  peripheral->PDRUNCFG =
      peripheral->PDRUNCFG | (powerDisables & ~PDRUNCFG_MASK);
}

#endif