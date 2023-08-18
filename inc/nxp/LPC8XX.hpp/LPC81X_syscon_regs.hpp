/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 system control GPIO register interface
 */
#ifndef LPC81X_SYSCON_REGS_HPP
#define LPC81X_SYSCON_REGS_HPP

namespace registers {
namespace syscon {

/**
 * @brief sysctl register definitions
 *
 */
struct registers {
  volatile uint32_t SYSMEMREMAP;    /**<  System memory remap (R/W) */
  volatile uint32_t PRESETCTRL;     /**<  Peripheral reset control (R/W) */
  volatile uint32_t SYSPLLCTRL;     /**<  System PLL control (R/W) */
  volatile uint32_t SYSPLLSTAT;     /**<  System PLL status (R/W ) */
  uint32_t RESERVED0[4];            /**< reserved */
  volatile uint32_t SYSOSCCTRL;     /**<  System oscillator control (R/W) */
  volatile uint32_t WDTOSCCTRL;     /**< Watchdog oscillator control (R/W) */
  volatile uint32_t RESERVED1[2];   /**< reserved */
  volatile uint32_t SYSRSTSTAT;     /**< System reset status Register (R/W ) */
  uint32_t RESERVED2[3];            /**< reserved */
  volatile uint32_t SYSPLLCLKSEL;   /**< System PLL clock source select (R/W) */
  volatile uint32_t SYSPLLCLKUEN;   /**< System PLL clock source update enable (R/W) */
  uint32_t RESERVED3[10];           /**< reserved */
  volatile uint32_t MAINCLKSEL;     /**< Main clock source select (R/W) */
  volatile uint32_t MAINCLKUEN;     /**< Main clock source update enable (R/W) */
  volatile uint32_t SYSAHBCLKDIV;   /**< System AHB clock divider (R/W) */
  uint32_t RESERVED4[1];            /**< reserved */
  volatile uint32_t SYSAHBCLKCTRL;  /**< System AHB clock control (R/W) */
  uint32_t RESERVED5[4];            /**< reserved */
  volatile uint32_t UARTCLKDIV;     /**< UART clock divider (R/W) */
  uint32_t RESERVED6[18];           /**< reserved */
  volatile uint32_t CLKOUTSEL;      /**< CLKOUT clock source select (R/W) */
  volatile uint32_t CLKOUTUEN;      /**< CLKOUT clock source update enable (R/W) */
  volatile uint32_t CLKOUTDIV;      /**< CLKOUT clock divider (R/W) */
  uint32_t RESERVED7;               /**< reserved */
  volatile uint32_t UARTFRGDIV;     /**< UART fractional divider SUB(R/W) */
  volatile uint32_t UARTFRGMULT;    /**< UART fractional divider ADD(R/W) */
  uint32_t RESERVED8[1];            /**< reserved */
  volatile uint32_t EXTTRACECMD;    /**< External trace buffer command register  */
  volatile uint32_t PIOPORCAP0;     /**< POR captured PIO status 0 (R/ ) */
  uint32_t RESERVED9[12];           /**< reserved */
  volatile uint32_t IOCONCLKDIV[7]; /**< Peripheral clock for IOCON block glitch filter */
  volatile uint32_t BODCTRL;        /**< BOD control (R/W) */
  volatile uint32_t SYSTCKCAL;      /**< System tick counter calibration (R/W) */
  uint32_t RESERVED10[6];           /**< reserved */
  volatile uint32_t IRQLATENCY;     /**< IRQ delay */
  volatile uint32_t NMISRC;         /**< NMI Source Control     */
  volatile uint32_t PINTSEL[8];     /**< GPIO Pin Interrupt Select register 0 */
  uint32_t RESERVED11[27];          /**< reserved */
  volatile uint32_t STARTERP0;      /**< Start logic signal enable Register 0 (R/W) */
  uint32_t RESERVED12[3];           /**< reserved */
  volatile uint32_t STARTERP1;      /**< Start logic signal enable Register 0 (R/W) */
  uint32_t RESERVED13[6];           /**< reserved */
  volatile uint32_t PDSLEEPCFG;     /**< Power-down states in Deep-sleep mode (R/W) */
  volatile uint32_t PDAWAKECFG;     /**< Power-down states after wake-up (R/W) */
  volatile uint32_t PDRUNCFG;       /**< Power-down configuration Register (R/W) */
  uint32_t RESERVED14[111];         /**< reserved */
  volatile const uint32_t DEVICEID; /**< Device ID (R/ ) */
};

}  // namespace syscon
}  // namespace registers

#endif