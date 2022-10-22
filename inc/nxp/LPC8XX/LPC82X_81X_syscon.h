/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC820 and LPC810 series common functions
*/
#ifndef LPC82X_81X_SYSCON_H
#define LPC82X_81X_SYSCON_H

/**
 * @brief   Enables resets to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for reset control register, see
 * SYSCON_RESETCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconEnableResets(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->PRESETCTRL = setting | peripheral->PRESETCTRL;
}

/**
 * @brief   Disables resets to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for reset control register, see
 * SYSCON_RESETCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconDisableResets(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->PRESETCTRL = ~setting & peripheral->PRESETCTRL;
}

/**
 * @brief   Enables clocks to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock contro0 register, see
 * SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconEnableClocks(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->SYSAHBCLKCTRL = setting | peripheral->SYSAHBCLKCTRL;
}

/**
 * @brief   Disables clocks to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control register, see
 * SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconDisableClocks(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->SYSAHBCLKCTRL = ~setting & peripheral->SYSAHBCLKCTRL;
}

/**
 * @brief   Set the Uart baud rate generator clock divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control register, see
 * SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconUartClockDiv(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->UARTCLKDIV = setting;
}

/**
 * @brief   Set the Uart fractional baud rate generator clock divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control register, see
 * SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconUartFractionalDiv(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->UARTFRGDIV = setting;
}

/**
 * @brief   Set the Uart fractional baud rate generator clock divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control register, see
 * SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconUartFractionalMult(SYSCON_Type *peripheral, uint32_t setting) {
  peripheral->UARTFRGMULT = setting;
}

#endif