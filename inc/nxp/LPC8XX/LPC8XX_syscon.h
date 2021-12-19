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
 * @brief   Select System clock clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the main clock network
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