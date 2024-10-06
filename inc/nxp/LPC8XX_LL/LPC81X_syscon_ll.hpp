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

namespace libMcuLL::sw::syscon {
using namespace hw::syscon;

/**
 * @brief Peripheral reset options
 */
enum class peripheralResets : std::uint32_t {
  SPI0 = PRESETCTRL::SPI0_RST_N,       /**< SPI0 reset control */
  SPI1 = PRESETCTRL::SPI1_RST_N,       /**< SPI1 reset control */
  UARTFRG = PRESETCTRL::UARTFRG_RST_N, /**< UART fractional baud rate generator reset control */
  UART0 = PRESETCTRL::UART0_RST_N,     /**< UART0 reset control */
  UART1 = PRESETCTRL::UART1_RST_N,     /**< UART1 reset control */
  UART2 = PRESETCTRL::UART2_RST_N,     /**< UART2 reset control */
  I2C = PRESETCTRL::I2C_RST_N,         /**< I2C reset control */
  MRT = PRESETCTRL::MRT_RST_N,         /**< MRT reset control */
  SCT = PRESETCTRL::SCT_RST_N,         /**< SCT reset control */
  WKT = PRESETCTRL::WKT_RST_N,         /**< WKT reset control */
  GPIO = PRESETCTRL::GPIO_RST_N,       /**< GPIO reset control */
  FLASH = PRESETCTRL::FLASH_RST_N,     /**< Flash reset control */
  ACMP = PRESETCTRL::ACMP_RST_N,       /**< ACMP reset control */
};

/**
 * @brief operator | for peripheralResets
 *
 * @param a peripheral reset
 * @param b peripheral reset
 * @return Ored valued of a and b
 */
constexpr peripheralResets operator|(const peripheralResets a, const peripheralResets b) {
  return static_cast<peripheralResets>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

/**
 * @brief PLL post divider options
 */
enum class pllPostDivider : std::uint32_t {
  DIV_2 = SYSPLLCTRL::PSEL_DIV2,   /**< PLL post division ration of 2 */
  DIV_4 = SYSPLLCTRL::PSEL_DIV4,   /**< PLL post division ration of 4 */
  DIV_8 = SYSPLLCTRL::PSEL_DIV8,   /**< PLL post division ration of 8 */
  DIV_16 = SYSPLLCTRL::PSEL_DIV16, /**< PLL post division ration of 16 */
};

/**
 * @brief PLL source options
 */
enum class pllClockSources : std::uint32_t {
  IRC = SYSPLLCLKSEL::SEL_IRC,       /**< IRC oscillator */
  SYSOSC = SYSPLLCLKSEL::SEL_SYSOSC, /**< crystal oscillator */
  CLKIN = SYSPLLCLKSEL::SEL_CLKIN,   /**< External clock input */
};

/**
 * @brief main clock sources
 */
enum class mainClockSources : std::uint32_t {
  IRC = 0,     /**< IRC oscillator */
  PLL_IN = 1,  /**< PLL input */
  WDOSC = 2,   /**< Watchdog oscillator */
  PLL_OUT = 3, /**< PLL output */
};

/**
 * @brief Peripheral clock enable options
 */
enum class peripheralClocks : std::uint32_t {
  SYS = (1 << 0),      /**< AHB bus, APB bridge and the processor core */
  ROM = (1 << 1),      /**< ROM */
  RAM = (1 << 2),      /**< RAM */
  FLASHREG = (1 << 3), /**< Flash register interface */
  FLASH = (1 << 4),    /**< Flash */
  I2C = (1 << 5),      /**< I2C */
  GPIO = (1 << 6),     /**< GPIO */
  SWM = (1 << 7),      /**< Switch Matrix */
  SCT = (1 << 8),      /**< State configurable timer */
  WKT = (1 << 9),      /**< self wake-up timer */
  MRT = (1 << 10),     /**< multi-rate timer */
  SPI0 = (1 << 11),    /**< SPI0 */
  SPI1 = (1 << 12),    /**< SPI1 */
  CRC = (1 << 13),     /**< CRC */
  UART0 = (1 << 14),   /**< UART0 */
  UART1 = (1 << 15),   /**< UART1 */
  UART2 = (1 << 16),   /**< UART2 */
  WWDT = (1 << 17),    /**< WWDT */
  IOCON = (1 << 18),   /**< IOCON */
  ACMP = (1 << 19),    /**< analog comparator */
};

/**
 * @brief operator | for peripheralClocks
 *
 * @param a peripheral clock
 * @param b peripheral clock
 * @return ored value of peripheral clock
 */
constexpr peripheralClocks operator|(const peripheralClocks a, const peripheralClocks b) {
  return static_cast<peripheralClocks>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

/**
 * @brief Peripheral power down reset options
 */
enum peripheralPowers : std::uint32_t {
  IRCOUT = (1 << 0), /**< IRC oscillator output */
  IRC = (1 << 1),    /**< IRC oscillator*/
  FLASH = (1 << 2),  /**< Flash*/
  BOD = (1 << 3),    /**< BOD*/
  SYSOSC = (1 << 5), /**< Crystal oscillator*/
  WDTOSC = (1 << 6), /**< Watchdog oscillator*/
  SYSPLL = (1 << 7), /**< System PLL*/
  ACMP = (1 << 15),  /**< Analog comparator*/
};

/**
 * @brief operator | for peripheralPowers
 *
 * @param a peripheral power setting
 * @param b peripheral power setting
 * @return ored value of peripheral power
 */
constexpr peripheralPowers operator|(const peripheralPowers a, const peripheralPowers b) {
  return static_cast<peripheralPowers>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

template <libMcu::sysconBaseAddress sysconAddress_>
struct syscon : libMcu::peripheralBase {
  /**
   * @brief reset a peripheral
   *
   * @param setting bit setting from peripheralResets enum
   */
  constexpr void resetPeripherals(peripheralResets setting) {
    std::uint32_t resets = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->PRESETCTRL = sysconPeripheral()->PRESETCTRL & ~resets;
    sysconPeripheral()->PRESETCTRL = sysconPeripheral()->PRESETCTRL | resets;
  }
  /**
   * @brief Set the System PLL Control
   *
   * @param msel Feedback divider ratio, 0 divides by 1, 31 divides by 32
   * @param psel Post divider ratio, acceptable values in pllPostDivider enum
   */
  constexpr void setSystemPllControl(std::uint32_t msel, pllPostDivider psel) {
    sysconPeripheral()->SYSPLLCTRL = SYSPLLCTRL::MSEL(msel) | static_cast<std::uint32_t>(psel);
  }
  /**
   * @brief Get the System Pll Status
   *
   * @return 0 PLL not locked, 1 PLL locked
   */
  constexpr std::uint32_t getSystemPllStatus(void) {
    return sysconPeripheral()->SYSPLLSTAT;
  }
  /**
   * @brief set system oscillator control
   *
   * @param setting set register see registers::syscon::SYSOSCCTRL
   */
  constexpr void setSysOscControl(std::uint32_t setting) {
    sysconPeripheral()->SYSOSCCTRL = setting;
  }
  /**
   * @brief   Select PLL clock source
   *
   * @param   source      Clock source of the PLL
   */
  constexpr void selectPllClock(pllClockSources setting) {
    sysconPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->SYSPLLCLKUEN = SYSPLLCLKUEN::NO_CHANGE;
    sysconPeripheral()->SYSPLLCLKUEN = SYSPLLCLKUEN::UPDATE;
  }
  /**
   * @brief Select main clock source
   *
   * @param setting clock source from mainClockSources enum
   */
  constexpr void selectMainClock(mainClockSources setting) {
    sysconPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->MAINCLKUEN = MAINCLKUEN::NO_CHANGE;
    sysconPeripheral()->MAINCLKUEN = MAINCLKUEN::UPDATE;
  }
  /**
   * @brief Set the System Clock Divider
   *
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  constexpr void setSystemClockDivider(std::uint32_t setting) {
    sysconPeripheral()->SYSAHBCLKDIV = SYSAHBCLKDIV::DIV(setting);
  }
  /**
   * @brief enable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  constexpr void enablePeripheralClocks(peripheralClocks setting) {
    sysconPeripheral()->SYSAHBCLKCTRL =
      sysconPeripheral()->SYSAHBCLKCTRL | (SYSAHBCLKCTRL::RESERVED_MASK & static_cast<std::uint32_t>(setting));
  }
  /**
   * @brief disable peripheral clocks
   *
   * @param setting bit setting from peripheralClocks
   */
  constexpr void disablePeripheralClocks(peripheralClocks setting) {
    sysconPeripheral()->SYSAHBCLKCTRL =
      sysconPeripheral()->SYSAHBCLKCTRL & ~(SYSAHBCLKCTRL::RESERVED_MASK & static_cast<std::uint32_t>(setting));
  }
  /**
   * @brief Set the Usart Clock Divider
   *
   * @param setting clock divisor
   */
  constexpr void setUsartClockDivider(std::uint32_t setting) {
    sysconPeripheral()->UARTCLKDIV = setting;
  }
  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  constexpr void powerPeripherals(peripheralPowers setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG & ~(PDRUNCFG::RESERVED_MASK & static_cast<std::uint32_t>(setting));
  }
  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  constexpr void depowerPeripherals(peripheralPowers setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG | (PDRUNCFG::RESERVED_MASK & static_cast<std::uint32_t>(setting));
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
  constexpr std::uint32_t getChipId(void) {
    return sysconPeripheral()->DEVICEID;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  constexpr static hw::syscon::syscon *sysconPeripheral() {
    return reinterpret_cast<hw::syscon::syscon *>(sysconAddress);
  }

 private:
  constexpr static libMcu::hwAddressType sysconAddress = sysconAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::syscon
#endif