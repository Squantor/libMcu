/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series system control functions
 */
#ifndef LPC81X_SYSCON_HPP
#define LPC81X_SYSCON_HPP

namespace instances {
namespace syscon {
using namespace registers::syscon;

/**
 * @brief Peripheral reset options
 *
 * TODO, change name after all C dependencies are gone so you can use
 * proper name like SPI0 instead of SPI0_reset
 *
 */
enum peripheralResets : uint32_t {
  RESET_SPI0 = (1 << 0),    /**< SPI0 reset control */
  RESET_SPI1 = (1 << 1),    /**< SPI1 reset control */
  RESET_UARTFRG = (1 << 2), /**< UART fractional baud rate generator reset control */
  RESET_UART0 = (1 << 3),   /**< UART0 reset control */
  RESET_UART1 = (1 << 4),   /**< UART1 reset control */
  RESET_UART2 = (1 << 5),   /**< UART2 reset control */
  RESET_I2C = (1 << 6),     /**< I2C reset control */
  RESET_MRT = (1 << 7),     /**< MRT reset control */
  RESET_SCT = (1 << 8),     /**< SCT reset control */
  RESET_WKT = (1 << 9),     /**< WKT reset control */
  RESET_GPIO = (1 << 10),   /**< GPIO reset control */
  RESET_FLASH = (1 << 11),  /**< Flash reset control */
  RESET_ACMP = (1 << 12),   /**< ACMP reset control */
};

/**
 * @brief main clock sources
 */
enum mainClockSources : uint32_t {
  MAINCLK_IRC = (0 << 0),     /**< IRC oscillator */
  MAINCLK_PLL_IN = (1 << 0),  /**< PLL input */
  MAINCLK_WDOSC = (1 << 1),   /**< Watchdog oscillator */
  MAINCLK_PLL_OUT = (1 << 2), /**< PLL output */
};

/**
 * @brief Peripheral clock enable options
 *
 * TODO, change name after all C dependencies are gone so you can use the proper names like
 * IRCOUT instead of POWER_IRCOUT_PD.
 *
 */
enum peripheralClocks : uint32_t {
  CLOCK_SYS = (1 << 0),      /**< AHB bus, APB bridge and the processor core */
  CLOCK_ROM = (1 << 1),      /**< ROM */
  CLOCK_RAM = (1 << 2),      /**< RAM */
  CLOCK_FLASHREG = (1 << 3), /**< Flash register interface */
  CLOCK_FLASH = (1 << 4),    /**< Flash */
  CLOCK_I2C = (1 << 5),      /**< I2C */
  CLOCK_GPIO = (1 << 6),     /**< GPIO */
  CLOCK_SWM = (1 << 7),      /**< Switch Matrix */
  CLOCK_SCT = (1 << 8),      /**< State configurable timer */
  CLOCK_WKT = (1 << 9),      /**< self wake-up timer */
  CLOCK_MRT = (1 << 10),     /**< multi-rate timer */
  CLOCK_SPI0 = (1 << 11),    /**< SPI0 */
  CLOCK_SPI1 = (1 << 12),    /**< SPI1 */
  CLOCK_CRC = (1 << 13),     /**< CRC */
  CLOCK_UART0 = (1 << 14),   /**< UART0 */
  CLOCK_UART1 = (1 << 15),   /**< UART1 */
  CLOCK_UART2 = (1 << 16),   /**< UART2 */
  CLOCK_WWDT = (1 << 17),    /**< WWDT */
  CLOCK_IOCON = (1 << 18),   /**< IOCON */
  CLOCK_ACMP = (1 << 19),    /**< analog comparator */
};

/**
 * @brief Peripheral power down reset options
 *
 * TODO, change name after all C dependencies are gone so you can use the proper names like
 * IRCOUT instead of POWER_IRCOUT.
 *
 */
enum peripheralPowers : uint32_t {
  POWER_IRCOUT = (1 << 0), /**< IRC oscillator output */
  POWER_IRC = (1 << 1),    /**< IRC oscillator*/
  POWER_FLASH = (1 << 2),  /**< Flash*/
  POWER_BOD = (1 << 3),    /**< BOD*/
  POWER_SYSOSC = (1 << 5), /**< Crystal oscillator*/
  POWER_WDTOSC = (1 << 6), /**< Watchdog oscillator*/
  POWER_SYSPLL = (1 << 7), /**< System PLL*/
  POWER_ACMP = (1 << 15),  /**< Analog comparator*/
};

template <uint32_t base>
struct syscon {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  static registers::syscon::registers *regs() {
    return reinterpret_cast<registers::syscon::registers *>(base);
  }

  /**
   * @brief reset a peripheral
   *
   * @param setting bit setting from peripheralResets enum
   */
  void resetPeripherals(uint32_t setting) {
    regs()->PRESETCTRL = regs()->PRESETCTRL & ~setting;
    regs()->PRESETCTRL = regs()->PRESETCTRL | setting;
  }

  /**
   * @brief Select main clock source
   *
   * @param setting clock source from mainClockSources enum
   */
  void selectMainClock(mainClockSources setting) {
    regs()->MAINCLKSEL = static_cast<uint32_t>(setting);
    regs()->MAINCLKUEN = MAINCLKUEN::NO_CHANGE;
    regs()->MAINCLKUEN = MAINCLKUEN::UPDATE;
  }

  /**
   * @brief enable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  void enablePeripheralClocks(uint32_t setting) {
    regs()->SYSAHBCLKCTRL = regs()->SYSAHBCLKCTRL | (SYSAHBCLKCTRL::MASK & setting);
  }

  /**
   * @brief disable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  void disablePeripheralClocks(uint32_t setting) {
    regs()->SYSAHBCLKCTRL = regs()->SYSAHBCLKCTRL & ~(SYSAHBCLKCTRL::MASK & setting);
  }

  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void powerPeripherals(uint32_t setting) {
    regs()->PDRUNCFG = regs()->PDRUNCFG & ~(PDRUNCFG::MASK & setting);
  }

  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void depowerPeripherals(uint32_t setting) {
    regs()->PDRUNCFG = regs()->PDRUNCFG | (PDRUNCFG::MASK & setting);
  }

  /**
   * @brief Get the DEVICE ID
   *
   * @return chip id value
   * @return 0x00008100 is returned for LPC810M021FN8
   * @return 0x00008110 is returned for LPC811M001JDH16
   * @return 0x00008120 is returned for LPC812M101JDH16
   * @return 0x00008121 is returned for LPC812M101JD20
   * @return 0x00008122 is returned for LPC812M101JDH20
   * @return 0x00008122 is returned for LPC812M101JTB16
   */
  uint32_t getChipId(void) {
    return regs()->DEVICEID;
  }
};
}  // namespace syscon
}  // namespace instances

#endif