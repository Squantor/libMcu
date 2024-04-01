/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file PLL peripheral definitions */
#ifndef PLL_H
#define PLL_H

/**
 * @brief PLL peripheral registers
 *
 */
typedef volatile struct {
  uint32_t CS;        /**< Control and Status */
  uint32_t PWR;       /**< Controls the PLL power modes */
  uint32_t FBDIV_INT; /**< Feedback divisor */
  uint32_t PRIM;      /**< Controls the PLL post dividers for the primary output*/
} PLL_Type;

#define PLL_CS_LOCK_MASK (1 << 31)                         /**< PLL is locked */
#define PLL_CS_BYPASS (1 << 8)                             /**< Pass reference clock to output instead of divided VCO */
#define PLL_CS_REFDIV(divisor) ((divisor & 0x3F) << 0)     /**< Divides the PLL reference clock, zero undefined! */
#define PLL_PWR_VCOPD_EN (1 << 5)                          /**< PLL VCO powerdown */
#define PLL_PWR_POSTDIVPD_EN (1 << 3)                      /**< PLL post divider powerdown */
#define PLL_PWR_PD (1 << 0)                                /**< PLL powerdown */
#define PLL_FBDIV_INT(divisor) ((divisor & 0xFFF) << 0)    /**< Feedback divider */
#define PLL_PRIM_POSTDIV1(divisor) ((divisor & 0x7) << 16) /**< Post divider 1 */
#define PLL_PRIM_POSTDIV2(divisor) ((divisor & 0x7) << 12) /**< Post divider 2 */

/**
 * @brief
 *
 * @param pll
 * @param pllClear
 * @param refDiv
 * @param fbDiv
 * @param postDiv1
 * @param postDiv2
 * @param timeout
 * @return uint32_t
 */
static inline uint32_t pllStart(PLL_Type* pll, uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2,
                                uint32_t timeout) {
  PLL_Type* pllClear = (PLL_Type*)((volatile char*)pll + OFFSET_CLR);
  pll->CS = PLL_CS_REFDIV(refDiv);
  pll->FBDIV_INT = PLL_FBDIV_INT(fbDiv);
  pll->PRIM = PLL_PRIM_POSTDIV1(postDiv1) | PLL_PRIM_POSTDIV2(postDiv2);
  pllClear->PWR = PLL_PWR_VCOPD_EN | PLL_PWR_PD;

  while ((0 == (pll->CS & PLL_CS_LOCK_MASK)) && timeout > 0) timeout--;

  pllClear->PWR = PLL_PWR_POSTDIVPD_EN;
  return timeout;
}

#endif