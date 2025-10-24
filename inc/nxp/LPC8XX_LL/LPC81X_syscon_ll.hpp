/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_syscon_ll.hpp
 * @brief LPC810 series System control interface class and definitions
 */
#ifndef LPC81X_SYSCON_HPP
#define LPC81X_SYSCON_HPP

namespace libmcull::syscon {
namespace hardware = libmcuhw::syscon;
/**
 * @brief Peripheral reset options
 */
enum PeripheralResets : std::uint32_t {
  ResetSpi0 = hardware::PRESETCTRL::SPI0_RST_N,       /*!< SPI0 reset control */
  ResetSpi1 = hardware::PRESETCTRL::SPI1_RST_N,       /*!< SPI1 reset control */
  ResetUartFrg = hardware::PRESETCTRL::UARTFRG_RST_N, /*!< UART fractional baud rate generator reset control */
  ResetUart0 = hardware::PRESETCTRL::UART0_RST_N,     /*!< UART0 reset control */
  ResetUart1 = hardware::PRESETCTRL::UART1_RST_N,     /*!< UART1 reset control */
  ResetUart2 = hardware::PRESETCTRL::UART2_RST_N,     /*!< UART2 reset control */
  ResetI2c = hardware::PRESETCTRL::I2C_RST_N,         /*!< I2C reset control */
  ResetMrt = hardware::PRESETCTRL::MRT_RST_N,         /*!< MRT reset control */
  ResetSct = hardware::PRESETCTRL::SCT_RST_N,         /*!< SCT reset control */
  ResetWkt = hardware::PRESETCTRL::WKT_RST_N,         /*!< WKT reset control */
  ResetGpio = hardware::PRESETCTRL::GPIO_RST_N,       /*!< GPIO reset control */
  ResetFlash = hardware::PRESETCTRL::FLASH_RST_N,     /*!< Flash reset control */
  ResetAcmp = hardware::PRESETCTRL::ACMP_RST_N,       /*!< ACMP reset control */
};
/**
 * @brief PLL post divider options
 */
enum class PllPostDividers : std::uint32_t {
  Div2 = hardware::SYSPLLCTRL::PSEL_DIV2,   /*!< PLL post division ration of 2 */
  Div4 = hardware::SYSPLLCTRL::PSEL_DIV4,   /*!< PLL post division ration of 4 */
  Div8 = hardware::SYSPLLCTRL::PSEL_DIV8,   /*!< PLL post division ration of 8 */
  Div16 = hardware::SYSPLLCTRL::PSEL_DIV16, /*!< PLL post division ration of 16 */
};
/**
 * @brief PLL source options
 */
enum class PllClockSources : std::uint32_t {
  Irc = hardware::SYSPLLCLKSEL::SEL_IRC,       /*!< IRC oscillator */
  SysOsc = hardware::SYSPLLCLKSEL::SEL_SYSOSC, /*!< crystal oscillator */
  ClkIn = hardware::SYSPLLCLKSEL::SEL_CLKIN,   /*!< External clock input */
};
/**
 * @brief main clock sources
 * @todo refer to bit definitions
 */
enum class MainClockSources : std::uint32_t {
  Irc = 0,    /*!< IRC oscillator */
  PllIn = 1,  /*!< PLL input */
  WdOsc = 2,  /*!< Watchdog oscillator */
  PllOut = 3, /*!< PLL output */
};

/**
 * @brief Peripheral clock enable options
 */
enum PeripheralClocks : std::uint32_t {
  ClockSys = hardware::SYSAHBCLKCTRL::SYS,           /*!< AHB bus, APB bridge and the processor core */
  ClockRom = hardware::SYSAHBCLKCTRL::ROM,           /*!< ROM */
  ClockRam = hardware::SYSAHBCLKCTRL::RAM,           /*!< RAM */
  ClockFlashReg = hardware::SYSAHBCLKCTRL::FLASHREG, /*!< Flash register interface */
  ClockFlash = hardware::SYSAHBCLKCTRL::FLASH,       /*!< Flash */
  ClockI2c = hardware::SYSAHBCLKCTRL::I2C,           /*!< I2C */
  ClockGpio = hardware::SYSAHBCLKCTRL::GPIO,         /*!< GPIO */
  ClockSwm = hardware::SYSAHBCLKCTRL::SWM,           /*!< Switch Matrix */
  ClockSct = hardware::SYSAHBCLKCTRL::SCT,           /*!< State configurable timer */
  ClockWkt = hardware::SYSAHBCLKCTRL::WKT,           /*!< self wake-up timer */
  ClockMrt = hardware::SYSAHBCLKCTRL::MRT,           /*!< multi-rate timer */
  ClockSpi0 = hardware::SYSAHBCLKCTRL::SPI0,         /*!< SPI0 */
  ClockSpi1 = hardware::SYSAHBCLKCTRL::SPI1,         /*!< SPI1 */
  ClockCrc = hardware::SYSAHBCLKCTRL::CRC,           /*!< CRC */
  ClockUart0 = hardware::SYSAHBCLKCTRL::UART0,       /*!< UART0 */
  ClockUart1 = hardware::SYSAHBCLKCTRL::UART1,       /*!< UART1 */
  ClockUart2 = hardware::SYSAHBCLKCTRL::UART2,       /*!< UART2 */
  ClockWwdt = hardware::SYSAHBCLKCTRL::WWDT,         /*!< WWDT */
  ClockIocon = hardware::SYSAHBCLKCTRL::IOCON,       /*!< IOCON */
  ClockAcmp = hardware::SYSAHBCLKCTRL::ACMP,         /*!< analog comparator */
};

/**
 * @brief Peripheral power down reset options
 * @todo refer to bit definitions
 */
enum PeripheralPowers : std::uint32_t {
  PowerIrcOutput = (1 << 0), /*!< IRC oscillator output */
  PowerIrc = (1 << 1),       /*!< IRC oscillator*/
  PowerFlash = (1 << 2),     /*!< Flash*/
  PowerBod = (1 << 3),       /*!< BOD*/
  PowerSysOsc = (1 << 5),    /*!< Crystal oscillator*/
  PowerWdOsc = (1 << 6),     /*!< Watchdog oscillator*/
  PowerSysPll = (1 << 7),    /*!< System PLL*/
  PowerAcmp = (1 << 15),     /*!< Analog comparator*/
};

template <libmcu::SysconBaseAddress syscon_address>
struct Syscon : libmcull::LowLevelBase {
  /**
   * @brief reset a peripheral
   * @param setting bit setting from peripheralResets enum
   */
  constexpr void ResetPeripherals(std::uint32_t setting) {
    GetPeripheral()->PRESETCTRL = GetPeripheral()->PRESETCTRL & ~setting;
    GetPeripheral()->PRESETCTRL = GetPeripheral()->PRESETCTRL | setting;
  }
  /**
   * @brief Set the System PLL Control
   * @param msel Feedback divider ratio, 0 divides by 1, 31 divides by 32
   * @param psel Post divider ratio, acceptable values in pllPostDivider enum
   */
  constexpr void SetSystemPllControl(std::uint32_t msel, PllPostDividers psel) {
    GetPeripheral()->SYSPLLCTRL = hardware::SYSPLLCTRL::MSEL(msel) | static_cast<std::uint32_t>(psel);
  }
  /**
   * @brief Get the System Pll Status
   * @return 0 PLL not locked, 1 PLL locked
   */
  constexpr std::uint32_t GetSystemPllStatus(void) {
    return GetPeripheral()->SYSPLLSTAT;
  }
  /**
   * @brief set system oscillator control
   * @param setting set register see registers::syscon::SYSOSCCTRL
   */
  constexpr void SetSysOscControl(std::uint32_t setting) {
    GetPeripheral()->SYSOSCCTRL = setting;
  }
  /**
   * @brief   Select PLL clock source
   * @param   source      Clock source of the PLL
   */
  constexpr void SelectPllClockSource(PllClockSources setting) {
    GetPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::NO_CHANGE;
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::UPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from MainClockSources enum
   */
  constexpr void SelectMainClockSource(MainClockSources setting) {
    GetPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::NO_CHANGE;
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::UPDATE;
  }
  /**
   * @brief Set the System Clock Divider
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  constexpr void SetSystemClockDivider(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKDIV = hardware::SYSAHBCLKDIV::DIV(setting);
  }
  /**
   * @brief enable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void EnablePeripheralClocks(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKCTRL = GetPeripheral()->SYSAHBCLKCTRL | (hardware::SYSAHBCLKCTRL::RESERVED_MASK & setting);
  }
  /**
   * @brief disable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void DisablePeripheralClocks(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKCTRL = GetPeripheral()->SYSAHBCLKCTRL & ~(hardware::SYSAHBCLKCTRL::RESERVED_MASK & setting);
  }
  /**
   * @brief Set the Usart Clock Divider
   * @param setting clock divisor
   */
  constexpr void SetUsartClockDivider(std::uint32_t setting) {
    GetPeripheral()->UARTCLKDIV = setting;
  }
  /**
   * @brief Power up peripherals
   * @param setting bit setting from PeripheralPowers enum
   */
  constexpr void PowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG & ~(hardware::PDRUNCFG::RESERVED_MASK & setting);
  }
  /**
   * @brief Power down peripherals
   * @param setting bit setting from PeripheralPowers enum
   */
  constexpr void DepowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG | (hardware::PDRUNCFG::RESERVED_MASK & setting);
  }
  /**
   * @brief Get the DEVICE ID
   * @return chip id value
   * @return 0x00008100 is returned for LPC810M021FN8
   * @return 0x00008110 is returned for LPC811M001JDH16
   * @return 0x00008120 is returned for LPC812M101JDH16
   * @return 0x00008121 is returned for LPC812M101JD20
   * @return 0x00008122 is returned for LPC812M101JDH20
   * @return 0x00008122 is returned for LPC812M101JTB16
   */
  constexpr std::uint32_t GetChipId(void) {
    return GetPeripheral()->DEVICEID;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to syscon registers
   */
  constexpr static libmcuhw::syscon::Syscon *GetPeripheral() {
    return reinterpret_cast<libmcuhw::syscon::Syscon *>(syscon_address_);
  }

 private:
  constexpr static libmcu::HwAddressType syscon_address_ = syscon_address; /*!< peripheral address */
};
}  // namespace libmcull::syscon
#endif