/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Clocks peripheral definitions */
#ifndef CLOCKS_H
#define CLOCKS_H

typedef volatile struct {
  struct {
    uint32_t CTRL;
    uint32_t DIV;
    const uint32_t SELECTED;
  } CLK[10];
  uint32_t CLK_SYS_RESUS_CTRL;         /**<  */
  const uint32_t CLK_SYS_RESUS_STATUS; /**<  */
  uint32_t FC0_REF_KHZ;                /**<  */
  uint32_t FC0_MIN_KHZ;                /**<  */
  uint32_t FC0_MAX_KHZ;                /**<  */
  uint32_t FC0_DELAY;                  /**<  */
  uint32_t FC0_INTERVAL;               /**<  */
  uint32_t FC0_SRC;                    /**<  */
  const uint32_t FC0_STATUS;           /**< Frequency counter status */
  const uint32_t FC0_RESULT;           /**< Result of frequency measurement, only valid when status_done=1 */
  uint32_t WAKE_EN0;                   /**< enable clock in wake mode */
  uint32_t WAKE_EN1;                   /**< enable clock in wake mode */
  uint32_t SLEEP_EN0;                  /**< enable clock in sleep mode */
  uint32_t SLEEP_EN1;                  /**< enable clock in sleep mode */
  const uint32_t ENABLED0;             /**< indicates the state of the clock enable */
  const uint32_t ENABLED1;             /**< indicates the state of the clock enable */
  const uint32_t INTR;                 /**< Raw Interrupts */
  uint32_t INTE;                       /**< Interrupt Enable */
  uint32_t INTF;                       /**< Interrupt Force */
  const uint32_t INTS;                 /**< Interrupt status after masking & forcing */
} CLOCKS_Type;

#define CLOCKS_CLK_CTRL_RESERVED (0xFFECE21FUL)    /**< Clock generator control reserved bits */
#define CLOCKS_CLK_CTRL_SRC(src) (src << 0)        /**< Clock generator clock source, will NOT glitch */
#define CLOCKS_CLK_CTRL_AUXSRC(src) (src << 5)     /**< Clock generator auxiliary clock source, will glitch */
#define CLOCKS_CLK_CTRL_KILL_EN (1 << 10)          /**< Asynchronously kills the clock generator */
#define CLOCKS_CLK_CTRL_ENABLE (1 << 11)           /**< Starts and stops the clock generator cleanly */
#define CLOCKS_CLK_CTRL_DC50 (1 << 12)             /**< Enables duty cycle correction for odd divisors */
#define CLOCKS_CLK_CTRL_PHASE (phase)(phase << 16) /**< Delay enable signal, set before enable */
#define CLOCKS_CLK_CTRL_NUDGE (1 << 20)            /**< An edge on this bit shifts the phase by 1 input clock cycle */
#define CLOCKS_CLK_DIV_FRAC(frac) (frac << 0)      /**< Fractional component of divisor */
#define CLOCKS_CLK_DIV_INT(i) (i << 8)             /**< Integer component of divisor */

/**
 * @brief Clock generators available
 *
 */
typedef enum {
  CLK_GPOUT0 = 0, /**< Clock output GPIO 0 */
  CLK_GPOUT1 = 1, /**< Clock output GPIO 1 */
  CLK_GPOUT2 = 2, /**< Clock output GPIO 2 */
  CLK_GPOUT3 = 3, /**< Clock output GPIO 3 */
  CLK_REF = 4,    /**< Reference clock, runs from ROSC but can run from XOSC */
  CLK_SYS = 5,    /**< System clock, runs from CLK_REF but is switched to PLL */
  CLK_PERI = 6,   /**< Peripheral clock, typically runs from CLK_REF */
  CLK_USB = 7,    /**< USB reference clock, must be 48MHz */
  CLK_ADC = 8,    /**< ADC reference clock, must be 48MHz */
  CLK_RTC = 9,    /**< RTC reference clock, must be 46875Hz */
} CLOCKS_CLK_Enum;

/**
 * @brief Auxilliary Clock sources for each clock generator
 *
 */
typedef enum {
  GPOUT0_AUXSRC_PLL_SYS = 0x0, /**< System PLL */
  GPOUT0_AUXSRC_GPIN0 = 0x1,   /**< GPIO clock input 0 */
  GPOUT0_AUXSRC_GPIN1 = 0x2,   /**< GPIO clock input 1 */
  GPOUT0_AUXSRC_PLL_USB = 0x3, /**< USB PLL */
  GPOUT0_AUXSRC_ROSC = 0x4,    /**< Ring oscillator */
  GPOUT0_AUXSRC_XOSC = 0x5,    /**< Crystal oscillator */
  GPOUT0_AUXSRC_CLK_SYS = 0x6, /**< System clock */
  GPOUT0_AUXSRC_CLK_USB = 0x7, /**< USB clock */
  GPOUT0_AUXSRC_CLK_ADC = 0x8, /**< ADC clock */
  GPOUT0_AUXSRC_CLK_RTC = 0x9, /**< RTC clock */
  GPOUT0_AUXSRC_CLK_REF = 0xA, /**< reference clock */

  GPOUT1_AUXSRC_PLL_SYS = 0x0, /**< System PLL */
  GPOUT1_AUXSRC_GPIN0 = 0x1,   /**< GPIO clock input 0 */
  GPOUT1_AUXSRC_GPIN1 = 0x2,   /**< GPIO clock input 1 */
  GPOUT1_AUXSRC_PLL_USB = 0x3, /**< USB PLL */
  GPOUT1_AUXSRC_ROSC = 0x4,    /**< Ring oscillator */
  GPOUT1_AUXSRC_XOSC = 0x5,    /**< Crystal oscillator */
  GPOUT1_AUXSRC_CLK_SYS = 0x6, /**< System clock */
  GPOUT1_AUXSRC_CLK_USB = 0x7, /**< USB clock */
  GPOUT1_AUXSRC_CLK_ADC = 0x8, /**< ADC clock */
  GPOUT1_AUXSRC_CLK_RTC = 0x9, /**< RTC clock */
  GPOUT1_AUXSRC_CLK_REF = 0xA, /**< reference clock */

  GPOUT2_AUXSRC_PLL_SYS = 0x0, /**< System PLL */
  GPOUT2_AUXSRC_GPIN0 = 0x1,   /**< GPIO clock input 0 */
  GPOUT2_AUXSRC_GPIN1 = 0x2,   /**< GPIO clock input 1 */
  GPOUT2_AUXSRC_PLL_USB = 0x3, /**< USB PLL */
  GPOUT2_AUXSRC_ROSC = 0x4,    /**< Ring oscillator */
  GPOUT2_AUXSRC_XOSC = 0x5,    /**< Crystal oscillator */
  GPOUT2_AUXSRC_CLK_SYS = 0x6, /**< System clock */
  GPOUT2_AUXSRC_CLK_USB = 0x7, /**< USB clock */
  GPOUT2_AUXSRC_CLK_ADC = 0x8, /**< ADC clock */
  GPOUT2_AUXSRC_CLK_RTC = 0x9, /**< RTC clock */
  GPOUT2_AUXSRC_CLK_REF = 0xA, /**< reference clock */

  GPOUT3_AUXSRC_PLL_SYS = 0x0, /**< System PLL */
  GPOUT3_AUXSRC_GPIN0 = 0x1,   /**< GPIO clock input 0 */
  GPOUT3_AUXSRC_GPIN1 = 0x2,   /**< GPIO clock input 1 */
  GPOUT3_AUXSRC_PLL_USB = 0x3, /**< USB PLL */
  GPOUT3_AUXSRC_ROSC = 0x4,    /**< Ring oscillator */
  GPOUT3_AUXSRC_XOSC = 0x5,    /**< Crystal oscillator */
  GPOUT3_AUXSRC_CLK_SYS = 0x6, /**< System clock */
  GPOUT3_AUXSRC_CLK_USB = 0x7, /**< USB clock */
  GPOUT3_AUXSRC_CLK_ADC = 0x8, /**< ADC clock */
  GPOUT3_AUXSRC_CLK_RTC = 0x9, /**< RTC clock */
  GPOUT3_AUXSRC_CLK_REF = 0xA, /**< reference clock */

  REF_AUXSRC_PLL_USB = 0x0, /**< USB PLL */
  REF_AUXSRC_GPIN0 = 0x1,   /**< GPIO clock input 0 */
  REF_AUXSRC_GPIN1 = 0x2,   /**< GPIO clock input 1 */

  SYS_AUXSRC_PLL_SYS = 0x0, /**< System PLL */
  SYS_AUXSRC_PLL_USB = 0x1, /**< USB PLL */
  SYS_AUXSRC_ROSC = 0x2,    /**< Ring oscillator */
  SYS_AUXSRC_XOSC = 0x3,    /**< Crystal oscillator */
  SYS_AUXSRC_GPIN0 = 0x4,   /**< GPIO clock input 0 */
  SYS_AUXSRC_GPIN1 = 0x5,   /**< GPIO clock input 1 */

  PERI_AUXSRC_CLK_SYS = 0x0, /**< System clock */
  PERI_AUXSRC_PLL_SYS = 0x1, /**< System PLL */
  PERI_AUXSRC_PLL_USB = 0x2, /**< USB PLL */
  PERI_AUXSRC_ROSC = 0x3,    /**< Ring oscillator */
  PERI_AUXSRC_XOSC = 0x4,    /**< Crystal oscillator */
  PERI_AUXSRC_GPIN0 = 0x5,   /**< GPIO clock input 0 */
  PERI_AUXSRC_GPIN1 = 0x6,   /**< GPIO clock input 1 */

  USB_AUXSRC_PLL_USB = 0x0, /**< USB PLL */
  USB_AUXSRC_PLL_SYS = 0x1, /**< System PLL */
  USB_AUXSRC_ROSC = 0x2,    /**< Ring oscillator */
  USB_AUXSRC_XOSC = 0x3,    /**< Crystal oscillator */
  USB_AUXSRC_GPIN0 = 0x4,   /**< GPIO clock input 0 */
  USB_AUXSRC_GPIN1 = 0x5,   /**< GPIO clock input 1 */

  ADC_AUXSRC_PLL_USB = 0x0, /**< USB PLL */
  ADC_AUXSRC_PLL_SYS = 0x1, /**< System PLL */
  ADC_AUXSRC_ROSC = 0x2,    /**< Ring oscillator */
  ADC_AUXSRC_XOSC = 0x3,    /**< Crystal oscillator */
  ADC_AUXSRC_GPIN0 = 0x4,   /**< GPIO clock input 0 */
  ADC_AUXSRC_GPIN1 = 0x5,   /**< GPIO clock input 1 */

  RTC_AUXSRC_PLL_USB = 0x0, /**< USB PLL */
  RTC_AUXSRC_PLL_SYS = 0x1, /**< System PLL */
  RTC_AUXSRC_ROSC = 0x2,    /**< Ring oscillator */
  RTC_AUXSRC_XOSC = 0x3,    /**< Crystal oscillator */
  RTC_AUXSRC_GPIN0 = 0x4,   /**< GPIO clock input 0 */
  RTC_AUXSRC_GPIN1 = 0x5,   /**< GPIO clock input 1 */

} CLOCKS_CLK_AUXSRC_Enum;

/**
 * @brief Clock sources for each clock generator
 *
 */
typedef enum {
  REF_SRC_ROSC = 0x0,               /**< Ring oscillator */
  REF_SRC_CLKSRC_CLK_REF_AUX = 0x1, /**< Clock source reference auxilliary  */
  REF_SRC_XOSC = 0x2,               /**< Crystal oscillator */

  SYS_SRC_CLK_REF = 0x0,            /**< Reference clock */
  SYS_SRC_CLKSRC_CLK_SYS_AUX = 0x1, /**< clock source sys auxilliary */

} CLOCKS_CLK_SRC_Enum;

#endif