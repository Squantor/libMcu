/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
LPC840 series common system control registers, defines and functions.
*/
#ifndef LPC84X_SYSCON_H
#define LPC84X_SYSCON_H

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;       /**< System Remap register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SYSPLLCTRL;        /**< PLL control, offset: 0x8 */
  __I  uint32_t SYSPLLSTAT;        /**< PLL status, offset: 0xC */
       uint8_t RESERVED_1[16];
  __IO uint32_t SYSOSCCTRL;        /**< system oscillator control, offset: 0x20 */
  __IO uint32_t WDTOSCCTRL;        /**< Watchdog oscillator control, offset: 0x24 */
  __IO uint32_t FROOSCCTRL;        /**< FRO oscillator control, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FRODIRECTCLKUEN;   /**< FRO direct clock source update enable register, offset: 0x30 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SYSRSTSTAT;        /**< System reset status register, offset: 0x38 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SYSPLLCLKSEL;      /**< System PLL clock source select register, offset: 0x40 */
  __IO uint32_t SYSPLLCLKUEN;      /**< System PLL clock source update enable register, offset: 0x44 */
  __IO uint32_t MAINCLKPLLSEL;     /**< Main clock source select register, offset: 0x48 */
  __IO uint32_t MAINCLKPLLUEN;     /**< Main clock source update enable register, offset: 0x4C */
  __IO uint32_t MAINCLKSEL;        /**< Main clock source select register, offset: 0x50 */
  __IO uint32_t MAINCLKUEN;        /**< Main clock source update enable register, offset: 0x54 */
  __IO uint32_t SYSAHBCLKDIV;      /**< System clock divider register, offset: 0x58 */
       uint8_t RESERVED_5[4];
  __IO uint32_t CAPTCLKSEL;        /**< CAPT clock source select register, offset: 0x60 */
  __IO uint32_t ADCCLKSEL;         /**< ADC clock source select register, offset: 0x64 */
  __IO uint32_t ADCCLKDIV;         /**< ADC clock divider register, offset: 0x68 */
  __IO uint32_t SCTCLKSEL;         /**< SCT clock source select register, offset: 0x6C */
  __IO uint32_t SCTCLKDIV;         /**< SCT clock divider register, offset: 0x70 */
  __IO uint32_t EXTCLKSEL;         /**< external clock source select register, offset: 0x74 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SYSAHBCLKCTRL0;    /**< System clock group 0 control register, offset: 0x80 */
  __IO uint32_t SYSAHBCLKCTRL1;    /**< System clock group 1 control register, offset: 0x84 */
  __IO uint32_t PRESETCTRL0;       /**< Peripheral reset group 0 control register, offset: 0x88 */
  __IO uint32_t PRESETCTRL1;       /**< Peripheral reset group 1 control register, offset: 0x8C */
  __IO uint32_t FCLKSEL[11];       /**< peripheral clock source select register. FCLK0SEL~FCLK4SEL are for UART0~UART4 clock source select register. FCLK5SEL~FCLK8SEL are for I2C0~I2C3 clock source select register. FCLK9SEL~FCLK10SEL are for SPI0~SPI1 clock source select register., array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_7[20];
  struct {                                         /* offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGDIV;          /**< fractional generator N divider value register, array offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGMULT;         /**< fractional generator N multiplier value register, array offset: 0xD4, array step: 0x10 */
    __IO uint32_t FRGCLKSEL;       /**< FRG N clock source select register, array offset: 0xD8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } FRG[2];
  __IO uint32_t CLKOUTSEL;         /**< CLKOUT clock source select register, offset: 0xF0 */
  __IO uint32_t CLKOUTDIV;         /**< CLKOUT clock divider registers, offset: 0xF4 */
       uint8_t RESERVED_8[4];
  __IO uint32_t EXTTRACECMD;       /**< External trace buffer command register, offset: 0xFC */
  __I  uint32_t PIOPORCAP[2];      /**< POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs), array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_9[44];
  __IO uint32_t IOCONCLKDIV6;      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x134 */
  __IO uint32_t IOCONCLKDIV5;      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x138 */
  __IO uint32_t IOCONCLKDIV4;      /**< Peripheral clock 4 to the IOCON block for programmable glitch filter, offset: 0x13C */
  __IO uint32_t IOCONCLKDIV3;      /**< Peripheral clock 3 to the IOCON block for programmable glitch filter, offset: 0x140 */
  __IO uint32_t IOCONCLKDIV2;      /**< Peripheral clock 2 to the IOCON block for programmable glitch filter, offset: 0x144 */
  __IO uint32_t IOCONCLKDIV1;      /**< Peripheral clock 1 to the IOCON block for programmable glitch filter, offset: 0x148 */
  __IO uint32_t IOCONCLKDIV0;      /**< Peripheral clock 0 to the IOCON block for programmable glitch filter, offset: 0x14C */
  __IO uint32_t BODCTRL;           /**< BOD control register, offset: 0x150 */
  __IO uint32_t SYSTCKCAL;         /**< System tick timer calibration register, offset: 0x154 */
       uint8_t RESERVED_10[24];
  __IO uint32_t IRQLATENCY;        /**< IRQ latency register, offset: 0x170 */
  __IO uint32_t NMISRC;            /**< NMI source selection register, offset: 0x174 */
  __IO uint32_t PINTSEL[8];        /**< Pin interrupt select registers N, array offset: 0x178, array step: 0x4 */
       uint8_t RESERVED_11[108];
  __IO uint32_t STARTERP0;         /**< Start logic 0 pin wake-up enable register 0, offset: 0x204 */
       uint8_t RESERVED_12[12];
  __IO uint32_t STARTERP1;         /**< Start logic 0 pin wake-up enable register 1, offset: 0x214 */
       uint8_t RESERVED_13[24];
  __IO uint32_t PDSLEEPCFG;        /**< Deep-sleep configuration register, offset: 0x230 */
  __IO uint32_t PDAWAKECFG;        /**< Wake-up configuration register, offset: 0x234 */
  __IO uint32_t PDRUNCFG;          /**< Power configuration register, offset: 0x238 */
       uint8_t RESERVED_14[444];
  __I  uint32_t DEVICE_ID;         /**< Part ID register, offset: 0x3F8 */
} SYSCON_Type;



#endif
