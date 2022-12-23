/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file System PLL peripheral definitions */
#ifndef PLL_SYS_H
#define PLL_SYS_H

/**
 * @brief System PLL peripheral registers
 *
 */
typedef volatile struct {
  uint32_t CS;        /**< Control and Status */
  uint32_t PWR;       /**< Controls the PLL power modes */
  uint32_t FBDIV_INT; /**< Feedback divisor */
  uint32_t PRIM;      /**< Controls the PLL post dividers for the primary output*/
} PLL_SYS_Type;

#define PLL_SYS_CS_LOCK_MASK (1 << 31)                         /**< PLL is locked */
#define PLL_SYS_CS_BYPASS (1 << 8)                             /**< Pass reference clock to output instead of divided VCO */
#define PLL_SYS_CS_REFDIV(divisor) ((divisor & 0x3F) << 0)     /**< Divides the PLL reference clock, zero undefined! */
#define PLL_SYS_PWR_VCOPD_EN (1 << 5)                          /**< PLL VCO powerdown */
#define PLL_SYS_PWR_POSTDIVPD_EN (1 << 3)                      /**< PLL post divider powerdown */
#define PLL_SYS_PWR_PD (1 << 0)                                /**< PLL powerdown */
#define PLL_SYS_FBDIV_INT(divisor) ((divisor & 0xFFF) << 0)    /**< Feedback divider */
#define PLL_SYS_PRIM_POSTDIV1(divisor) ((divisor & 0x7) << 16) /**< Post divider 1 */
#define PLL_SYS_PRIM_POSTDIV2(divisor) ((divisor & 0x7) << 12) /**< Post divider 2 */

/**
 * @brief
 *
 * @param refDiv
 * @param fbDiv
 * @param postDiv1
 * @param postDiv2
 * @param timeout
 * @return uint32_t
 */
static inline uint32_t pllSysStart(uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2, uint32_t timeout) {
  PLL_SYS->CS = PLL_SYS_CS_REFDIV(refDiv);
  PLL_SYS->FBDIV_INT = PLL_SYS_FBDIV_INT(fbDiv);
  PLL_SYS->PRIM = PLL_SYS_PRIM_POSTDIV1(postDiv1) | PLL_SYS_PRIM_POSTDIV2(postDiv2);
  PLL_SYS_CLR->PWR = PLL_SYS_PWR_VCOPD_EN | PLL_SYS_PWR_PD;

  while ((0 == (PLL_SYS->CS & PLL_SYS_CS_LOCK_MASK)) && timeout > 0) timeout--;

  PLL_SYS_CLR->PWR = PLL_SYS_PWR_POSTDIVPD_EN;
  return timeout;
}

#endif