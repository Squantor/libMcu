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

namespace libMcuLL {
namespace sw {
namespace syscon {
using namespace hw::syscon;

/**
 * @brief Peripheral reset options
 *
 * TODO: change name after all C dependencies are gone so you can use
 * proper name like SPI0 instead of SPI0_reset
 *
 */
enum peripheralResets : std::uint32_t {
  RESET_SPI0 = PRESETCTRL::SPI0_RST_N,       /**< SPI0 reset control */
  RESET_SPI1 = PRESETCTRL::SPI1_RST_N,       /**< SPI1 reset control */
  RESET_UARTFRG = PRESETCTRL::UARTFRG_RST_N, /**< UART fractional baud rate generator reset control */
  RESET_UART0 = PRESETCTRL::UART0_RST_N,     /**< UART0 reset control */
  RESET_UART1 = PRESETCTRL::UART1_RST_N,     /**< UART1 reset control */
  RESET_UART2 = PRESETCTRL::UART2_RST_N,     /**< UART2 reset control */
  RESET_I2C = PRESETCTRL::I2C_RST_N,         /**< I2C reset control */
  RESET_MRT = PRESETCTRL::MRT_RST_N,         /**< MRT reset control */
  RESET_SCT = PRESETCTRL::SCT_RST_N,         /**< SCT reset control */
  RESET_WKT = PRESETCTRL::WKT_RST_N,         /**< WKT reset control */
  RESET_GPIO = PRESETCTRL::GPIO_RST_N,       /**< GPIO reset control */
  RESET_FLASH = PRESETCTRL::FLASH_RST_N,     /**< Flash reset control */
  RESET_ACMP = PRESETCTRL::ACMP_RST_N,       /**< ACMP reset control */
};

/**
 * @brief PLL post divider options
 */
enum pllPostDivider : std::uint32_t {
  PLLPOSTDIV_2 = SYSPLLCTRL::PSEL_DIV2,   /**< PLL post division ration of 2 */
  PLLPOSTDIV_4 = SYSPLLCTRL::PSEL_DIV4,   /**< PLL post division ration of 4 */
  PLLPOSTDIV_8 = SYSPLLCTRL::PSEL_DIV8,   /**< PLL post division ration of 8 */
  PLLPOSTDIV_16 = SYSPLLCTRL::PSEL_DIV16, /**< PLL post division ration of 16 */
};

/**
 * @brief PLL source options
 */
enum pllClockSources : std::uint32_t {
  PLLCLK_IRC = SYSPLLCLKSEL::SEL_IRC,       /**< IRC oscillator */
  PLLCLK_SYSOSC = SYSPLLCLKSEL::SEL_SYSOSC, /**< crystal oscillator */
  PLLCLK_CLKIN = SYSPLLCLKSEL::SEL_CLKIN,   /**< External clock input */
};

/**
 * @brief main clock sources
 */
enum mainClockSources : std::uint32_t {
  MAINCLK_IRC = 0,     /**< IRC oscillator */
  MAINCLK_PLL_IN = 1,  /**< PLL input */
  MAINCLK_WDOSC = 2,   /**< Watchdog oscillator */
  MAINCLK_PLL_OUT = 3, /**< PLL output */
};

/**
 * @brief Peripheral clock enable options
 *
 * TODO: change name after all C dependencies are gone so you can use the proper names like
 * IRCOUT instead of POWER_IRCOUT_PD.
 *
 */
enum peripheralClocks : std::uint32_t {
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
 * TODO: change name after all C dependencies are gone so you can use the proper names like
 * IRCOUT instead of POWER_IRCOUT.
 *
 */
enum peripheralPowers : std::uint32_t {
  POWER_IRCOUT = (1 << 0), /**< IRC oscillator output */
  POWER_IRC = (1 << 1),    /**< IRC oscillator*/
  POWER_FLASH = (1 << 2),  /**< Flash*/
  POWER_BOD = (1 << 3),    /**< BOD*/
  POWER_SYSOSC = (1 << 5), /**< Crystal oscillator*/
  POWER_WDTOSC = (1 << 6), /**< Watchdog oscillator*/
  POWER_SYSPLL = (1 << 7), /**< System PLL*/
  POWER_ACMP = (1 << 15),  /**< Analog comparator*/
};

template <libMcuLL::SYSCONbaseAddress sysconAddress_>
struct syscon {
  static constexpr libMcuLL::hwAddressType sysconAddress = sysconAddress_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  static hw::syscon::peripheral *sysconPeripheral() {
    return reinterpret_cast<hw::syscon::peripheral *>(sysconAddress);
  }

  /**
   * @brief reset a peripheral
   *
   * @param setting bit setting from peripheralResets enum
   */
  void resetPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PRESETCTRL = sysconPeripheral()->PRESETCTRL & ~setting;
    sysconPeripheral()->PRESETCTRL = sysconPeripheral()->PRESETCTRL | setting;
  }

  /**
   * @brief Set the System PLL Control
   *
   * @param msel Feedback divider ratio, 0 divides by 1, 31 divides by 32
   * @param psel Post divider ratio, acceptable values in pllPostDivider enum
   */
  void setSystemPllControl(std::uint32_t msel, pllPostDivider psel) {
    sysconPeripheral()->SYSPLLCTRL = SYSPLLCTRL::MSEL(msel) | static_cast<std::uint32_t>(psel);
  }

  /**
   * @brief Get the System Pll Status
   *
   * @return 0 PLL not locked, 1 PLL locked
   */
  std::uint32_t getSystemPllStatus(void) {
    return sysconPeripheral()->SYSPLLSTAT;
  }

  /**
   * @brief set system oscillator control
   *
   * @param setting set register see registers::syscon::SYSOSCCTRL
   */
  void setSysOscControl(std::uint32_t setting) {
    sysconPeripheral()->SYSOSCCTRL = setting;
  }

  /**
   * @brief   Select PLL clock source
   *
   * @param   source      Clock source of the PLL
   */
  void selectPllClock(pllClockSources setting) {
    sysconPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->SYSPLLCLKUEN = SYSPLLCLKUEN::NO_CHANGE;
    sysconPeripheral()->SYSPLLCLKUEN = SYSPLLCLKUEN::UPDATE;
  }

  /**
   * @brief Select main clock source
   *
   * @param setting clock source from mainClockSources enum
   */
  void selectMainClock(mainClockSources setting) {
    sysconPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->MAINCLKUEN = MAINCLKUEN::NO_CHANGE;
    sysconPeripheral()->MAINCLKUEN = MAINCLKUEN::UPDATE;
  }
  /**
   * @brief Set the System Clock Divider
   *
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  void setSystemClockDivider(std::uint32_t setting) {
    sysconPeripheral()->SYSAHBCLKDIV = SYSAHBCLKDIV::DIV(setting);
  }

  /**
   * @brief enable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  void enablePeripheralClocks(std::uint32_t setting) {
    sysconPeripheral()->SYSAHBCLKCTRL = sysconPeripheral()->SYSAHBCLKCTRL | (SYSAHBCLKCTRL::RESERVED_MASK & setting);
  }

  /**
   * @brief disable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  void disablePeripheralClocks(std::uint32_t setting) {
    sysconPeripheral()->SYSAHBCLKCTRL = sysconPeripheral()->SYSAHBCLKCTRL & ~(SYSAHBCLKCTRL::RESERVED_MASK & setting);
  }

  void setUsartClockDivider(std::uint32_t setting) {
    sysconPeripheral()->UARTCLKDIV = UARTCLKDIV::RESERVED_MASK & setting;
  }

  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void powerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG & ~(PDRUNCFG::RESERVED_MASK & setting);
  }

  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void depowerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG | (PDRUNCFG::RESERVED_MASK & setting);
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
  std::uint32_t getChipId(void) {
    return sysconPeripheral()->DEVICEID;
  }
};
}  // namespace syscon
}  // namespace sw
}  // namespace libMcuLL

#endif