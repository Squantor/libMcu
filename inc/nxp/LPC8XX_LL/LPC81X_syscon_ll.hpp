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
  kResetSpi0 = hardware::PRESETCTRL::kSPI0_RST_N,       /*!< SPI0 reset control */
  kResetSpi1 = hardware::PRESETCTRL::kSPI1_RST_N,       /*!< SPI1 reset control */
  kResetUartFrg = hardware::PRESETCTRL::kUARTFRG_RST_N, /*!< UART fractional baud rate generator reset control */
  kResetUart0 = hardware::PRESETCTRL::kUART0_RST_N,     /*!< UART0 reset control */
  kResetUart1 = hardware::PRESETCTRL::kUART1_RST_N,     /*!< UART1 reset control */
  kResetUart2 = hardware::PRESETCTRL::kUART2_RST_N,     /*!< UART2 reset control */
  kResetI2c = hardware::PRESETCTRL::kI2C_RST_N,         /*!< I2C reset control */
  kResetMrt = hardware::PRESETCTRL::kMRT_RST_N,         /*!< MRT reset control */
  kResetSct = hardware::PRESETCTRL::kSCT_RST_N,         /*!< SCT reset control */
  kResetWkt = hardware::PRESETCTRL::kWKT_RST_N,         /*!< WKT reset control */
  kResetGpio = hardware::PRESETCTRL::kGPIO_RST_N,       /*!< GPIO reset control */
  kResetFlash = hardware::PRESETCTRL::kFLASH_RST_N,     /*!< Flash reset control */
  kResetAcmp = hardware::PRESETCTRL::kACMP_RST_N,       /*!< ACMP reset control */
};
/**
 * @brief PLL post divider options
 */
enum class PllPostDividers : std::uint32_t {
  kDiv2 = hardware::SYSPLLCTRL::kPSEL_DIV2,   /*!< PLL post division ration of 2 */
  kDiv4 = hardware::SYSPLLCTRL::kPSEL_DIV4,   /*!< PLL post division ration of 4 */
  kDiv8 = hardware::SYSPLLCTRL::kPSEL_DIV8,   /*!< PLL post division ration of 8 */
  kDiv16 = hardware::SYSPLLCTRL::kPSEL_DIV16, /*!< PLL post division ration of 16 */
};
/**
 * @brief PLL source options
 */
enum class PllClockSources : std::uint32_t {
  kIrc = hardware::SYSPLLCLKSEL::kSEL_IRC,       /*!< IRC oscillator */
  kSysOsc = hardware::SYSPLLCLKSEL::kSEL_SYSOSC, /*!< crystal oscillator */
  kClkIn = hardware::SYSPLLCLKSEL::kSEL_CLKIN,   /*!< External clock input */
};
/**
 * @brief main clock sources
 * @todo refer to bit definitions
 */
enum class MainClockSources : std::uint32_t {
  kIrc = 0,    /*!< IRC oscillator */
  kPllIn = 1,  /*!< PLL input */
  kWdOsc = 2,  /*!< Watchdog oscillator */
  kPllOut = 3, /*!< PLL output */
};

/**
 * @brief Peripheral clock enable options
 */
enum PeripheralClocks : std::uint32_t {
  kClockSys = hardware::SYSAHBCLKCTRL::kSYS,           /*!< AHB bus, APB bridge and the processor core */
  kClockRom = hardware::SYSAHBCLKCTRL::kROM,           /*!< ROM */
  kClockRam = hardware::SYSAHBCLKCTRL::kRAM,           /*!< RAM */
  kClockFlashReg = hardware::SYSAHBCLKCTRL::kFLASHREG, /*!< Flash register interface */
  kClockFlash = hardware::SYSAHBCLKCTRL::kFLASH,       /*!< Flash */
  kClockI2c = hardware::SYSAHBCLKCTRL::kI2C,           /*!< I2C */
  kClockGpio = hardware::SYSAHBCLKCTRL::kGPIO,         /*!< GPIO */
  kClockSwm = hardware::SYSAHBCLKCTRL::kSWM,           /*!< Switch Matrix */
  kClockSct = hardware::SYSAHBCLKCTRL::kSCT,           /*!< State configurable timer */
  kClockWkt = hardware::SYSAHBCLKCTRL::kWKT,           /*!< self wake-up timer */
  kClockMrt = hardware::SYSAHBCLKCTRL::kMRT,           /*!< multi-rate timer */
  kClockSpi0 = hardware::SYSAHBCLKCTRL::kSPI0,         /*!< SPI0 */
  kClockSpi1 = hardware::SYSAHBCLKCTRL::kSPI1,         /*!< SPI1 */
  kClockCrc = hardware::SYSAHBCLKCTRL::kCRC,           /*!< CRC */
  kClockUart0 = hardware::SYSAHBCLKCTRL::kUART0,       /*!< UART0 */
  kClockUart1 = hardware::SYSAHBCLKCTRL::kUART1,       /*!< UART1 */
  kClockUart2 = hardware::SYSAHBCLKCTRL::kUART2,       /*!< UART2 */
  kClockWwdt = hardware::SYSAHBCLKCTRL::kWWDT,         /*!< WWDT */
  kClockIocon = hardware::SYSAHBCLKCTRL::kIOCON,       /*!< IOCON */
  kClockAcmp = hardware::SYSAHBCLKCTRL::kACMP,         /*!< analog comparator */
};

/**
 * @brief Peripheral power down reset options
 * @todo refer to bit definitions
 */
enum PeripheralPowers : std::uint32_t {
  kPowerIrcOutput = (1 << 0), /*!< IRC oscillator output */
  kPowerIrc = (1 << 1),       /*!< IRC oscillator*/
  kPowerFlash = (1 << 2),     /*!< Flash*/
  kPowerBod = (1 << 3),       /*!< BOD*/
  kPowerSysOsc = (1 << 5),    /*!< Crystal oscillator*/
  kPowerWdOsc = (1 << 6),     /*!< Watchdog oscillator*/
  kPowerSysPll = (1 << 7),    /*!< System PLL*/
  kPowerAcmp = (1 << 15),     /*!< Analog comparator*/
};

template <libmcu::SysconBaseAddress syscon_address>
struct Syscon : libmcu::PeripheralBase {
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
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kNO_CHANGE;
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kUPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from MainClockSources enum
   */
  constexpr void SelectMainClockSource(MainClockSources setting) {
    GetPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kNO_CHANGE;
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kUPDATE;
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
    GetPeripheral()->SYSAHBCLKCTRL = GetPeripheral()->SYSAHBCLKCTRL | (hardware::SYSAHBCLKCTRL::kRESERVED_MASK & setting);
  }
  /**
   * @brief disable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void DisablePeripheralClocks(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKCTRL = GetPeripheral()->SYSAHBCLKCTRL & ~(hardware::SYSAHBCLKCTRL::kRESERVED_MASK & setting);
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
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG & ~(hardware::PDRUNCFG::kRESERVED_MASK & setting);
  }
  /**
   * @brief Power down peripherals
   * @param setting bit setting from PeripheralPowers enum
   */
  constexpr void DepowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG | (hardware::PDRUNCFG::kRESERVED_MASK & setting);
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