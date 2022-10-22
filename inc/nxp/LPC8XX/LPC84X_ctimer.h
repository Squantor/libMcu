/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series counter/timer registers, defines and functions.
 */
#ifndef LPC84X_CTIMER_H
#define LPC84X_CTIMER_H

/** CTIMER - Register Layout Typedef */
typedef volatile struct CTIMER_Struct {
  uint32_t IR;  /**< Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight
                   possible interrupt sources are pending., offset: 0x0 */
  uint32_t TCR; /**< Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be
                   disabled or reset through the TCR., offset: 0x4 */
  uint32_t TC; /**< Timer Counter. The 32 bit TC is incremented every PR+1 cycles of the APB bus clock. The TC is controlled through
                  the TCR., offset: 0x8 */
  uint32_t PR; /**< Prescale Register. When the Prescale Counter (PC) is equal to this value, the next clock increments the TC and
                  clears the PC., offset: 0xC */
  uint32_t PC; /**< Prescale Counter. The 32 bit PC is a counter which is incremented to the value stored in PR. When the value in
                  PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus
                  interface., offset: 0x10 */
  uint32_t MCR;   /**< Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a
                     Match occurs., offset: 0x14 */
  uint32_t MR[4]; /**< Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate
                     an interrupt every time MR matches the TC., array offset: 0x18, array step: 0x4 */
  int32_t CCR;    /**< Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture
                     Registers and whether or not an interrupt is generated when a capture takes place., offset: 0x28 */
  const uint32_t CR[4]; /**< Capture Register . CR is loaded with the value of TC when there is an event on the CAPn. input., array
                           offset: 0x2C, array step: 0x4 */
  uint32_t EMR; /**< External Match Register. The EMR controls the match function and the external match pins., offset: 0x3C */
  uint8_t RESERVED_0[48];
  uint32_t CTCR;   /**< Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the
                      signal and edge(s) for counting., offset: 0x70 */
  uint32_t PWMC;   /**< PWM Control Register. The PWMCON enables PWM mode for the external match pins., offset: 0x74 */
  uint32_t MSR[4]; /**< Match Shadow Register . If enabled, the Match Register will be automatically reloaded with the contents of
                      this register whenever the TC is reset to zero., array offset: 0x78, array step: 0x4 */
} CTIMER_Type;

#endif
