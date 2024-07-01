/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series system control low level functions
 */
#ifndef LPC84X_SYSCON_LL_HPP
#define LPC84X_SYSCON_LL_HPP

namespace libMcu::ll::syscon {
namespace hardware = libMcu::hw::syscon;

/**
 * @brief Peripheral reset for first setting
 */
enum peripheralResets0 : std::uint32_t {
  FLASH_RESET = hardware::PRESETCTRL0::FLASH,     /**< FLASH peripheral reset */
  I2C0_RESET = hardware::PRESETCTRL0::I2C0,       /**< I2C0 peripheral reset */
  GPIO0_RESET = hardware::PRESETCTRL0::GPIO0,     /**< GPIO0 peripheral reset */
  SWM_RESET = hardware::PRESETCTRL0::SWM,         /**< SWM peripheral reset */
  SCT_RESET = hardware::PRESETCTRL0::SCT,         /**< SCT peripheral reset */
  WKT_RESET = hardware::PRESETCTRL0::WKT,         /**< WKT peripheral reset */
  MRT_RESET = hardware::PRESETCTRL0::MRT,         /**< MRT peripheral reset */
  SPI0_RESET = hardware::PRESETCTRL0::SPI0,       /**< SPI0 peripheral reset */
  SPI1_RESET = hardware::PRESETCTRL0::SPI1,       /**< SPI1 peripheral reset */
  CRC_RESET = hardware::PRESETCTRL0::CRC,         /**< CRC peripheral reset */
  UART0_RESET = hardware::PRESETCTRL0::UART0,     /**< UART0 peripheral reset */
  UART1_RESET = hardware::PRESETCTRL0::UART1,     /**< UART1 peripheral reset */
  UART2_RESET = hardware::PRESETCTRL0::UART2,     /**< UART2 peripheral reset */
  IOCON_RESET = hardware::PRESETCTRL0::IOCON,     /**< IOCON peripheral reset */
  ACMP_RESET = hardware::PRESETCTRL0::ACMP,       /**< ACMP peripheral reset */
  GPIO1_RESET = hardware::PRESETCTRL0::GPIO1,     /**< GPIO1 peripheral reset */
  I2C1_RESET = hardware::PRESETCTRL0::I2C1,       /**< I2C1 peripheral reset */
  I2C2_RESET = hardware::PRESETCTRL0::I2C2,       /**< I2C2 peripheral reset */
  I2C3_RESET = hardware::PRESETCTRL0::I2C3,       /**< I2C3 peripheral reset */
  ADC_RESET = hardware::PRESETCTRL0::ADC,         /**< ADC peripheral reset */
  CTIMER0_RESET = hardware::PRESETCTRL0::CTIMER0, /**< CTIMER0 peripheral reset */
  DAC0_RESET = hardware::PRESETCTRL0::DAC0,       /**< DAC0 peripheral reset */
  GPIOINT_RESET = hardware::PRESETCTRL0::GPIOINT, /**< GPIOINT peripheral reset */
  DMA_RESET = hardware::PRESETCTRL0::DMA,         /**< DMA peripheral reset */
  UART3_RESET = hardware::PRESETCTRL0::UART3,     /**< UART3 peripheral reset */
  UART4_RESET = hardware::PRESETCTRL0::UART4,     /**< UART4 peripheral reset */
};
/**
 * @brief Peripheral resets for second setting
 */
enum peripheralResets1 : std::uint32_t {
  CAPT_RESET = hardware::PRESETCTRL1::CAPT, /**< CAPT peripheral reset */
  DAC1_RESET = hardware::PRESETCTRL1::DAC1, /**< DAC1 peripheral reset */
  FRG0_RESET = hardware::PRESETCTRL1::FRG0, /**< FRG0 peripheral reset */
  FRG1_RESET = hardware::PRESETCTRL1::FRG1, /**< FRG1 peripheral reset */
};
/**
 * @brief PLL post divider options
 */
enum pllPostDivider : std::uint32_t {
  DIV_2 = hardware::SYSPLLCTRL::PSEL_DIV2,   /**< PLL post division ration of 2 */
  DIV_4 = hardware::SYSPLLCTRL::PSEL_DIV4,   /**< PLL post division ration of 4 */
  DIV_8 = hardware::SYSPLLCTRL::PSEL_DIV8,   /**< PLL post division ration of 8 */
  DIV_16 = hardware::SYSPLLCTRL::PSEL_DIV16, /**< PLL post division ration of 16 */
};
/**
 * @brief PLL source options
 */
enum pllClockSources : std::uint32_t {
};
/**
 * @brief main clock sources
 */
enum mainClockSources : std::uint32_t {
};
/**
 * @brief Peripherals to set the clock source of
 */
enum class peripheralClockSelects : std::uint32_t {
  UART0 = hardware::FCLKSEL::UART0, /**< UART0 clock select */
  UART1 = hardware::FCLKSEL::UART1, /**< UART1 clock select */
  UART2 = hardware::FCLKSEL::UART2, /**< UART2 clock select */
  UART3 = hardware::FCLKSEL::UART3, /**< UART3 clock select */
  UART4 = hardware::FCLKSEL::UART4, /**< UART4 clock select */
  I2C0 = hardware::FCLKSEL::I2C0,   /**< I2C0 clock select */
  I2C1 = hardware::FCLKSEL::I2C1,   /**< I2C1 clock select */
  I2C2 = hardware::FCLKSEL::I2C2,   /**< I2C2 clock select */
  I2C3 = hardware::FCLKSEL::I2C3,   /**< I2C3 clock select */
  SPI0 = hardware::FCLKSEL::SPI0,   /**< SPI0 clock select */
  SPI1 = hardware::FCLKSEL::SPI1,   /**< SPI1 clock select */
};
/**
 * @brief Peripheral clock options
 */
enum class peripheralClocks : std::uint32_t {
  FRO = hardware::FCLKSEL::FRO,         /**< FRO clock source */
  MAIN = hardware::FCLKSEL::MAIN,       /**< Main clock source */
  FRG0 = hardware::FCLKSEL::FRG0,       /**< Fractional clock generator 0 */
  FRG1 = hardware::FCLKSEL::FRG1,       /**< Fractional clock generator 1 */
  FRO_DIV = hardware::FCLKSEL::FRO_DIV, /**< FRO divided by 2 clock source  */
  NONE = hardware::FCLKSEL::NONE,       /**< No clock source */
};
/**
 * @brief Peripheral clock enable options section 0
 */
enum peripheralClocks0 : std::uint32_t {
  ROM_CLOCK = hardware::SYSAHBCLKCTRL0::ROM,     /**< ROM clock enable */
  RAM_CLOCK = hardware::SYSAHBCLKCTRL0::RAM0_1,  /**< RAM clock enable */
  FLASH_CLOCK = hardware::SYSAHBCLKCTRL0::FLASH, /**< Flash clock enable */
};
/**
 * @brief Peripheral clock enable options section 1
 */
enum peripheralClocks1 : std::uint32_t {
  CAPT_CLOCK = hardware::SYSAHBCLKCTRL1::CAPT, /**< CAPT clock enable */
  DAC1_CLOCK = hardware::SYSAHBCLKCTRL1::DAC1, /**< DAC1 clock enable */
};
/**
 * @brief Peripheral power down reset options
 */
enum peripheralPowers : std::uint32_t {
};

template <libMcuLL::sysconBaseAddress sysconAddress_>
struct syscon : libMcuLL::peripheralBase {
  /**
   * @brief Set the System PLL Control
   *
   * @param msel Feedback divider ratio, 0 divides by 1, 31 divides by 32
   * @param psel Post divider ratio, acceptable values in pllPostDivider enum
   */
  constexpr void setSystemPllControl(std::uint32_t msel, pllPostDivider psel) {
    sysconPeripheral()->SYSPLLCTRL = hardware::SYSPLLCTRL::MSEL(msel) | static_cast<std::uint32_t>(psel);
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
   * @param   source      Clock source of the PLL
   */
  constexpr void selectPllClock(pllClockSources setting) {
    sysconPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::NO_CHANGE;
    sysconPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::UPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void selectMainClock(mainClockSources setting) {
    sysconPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::NO_CHANGE;
    sysconPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::UPDATE;
  }
  /**
   * @brief Set the System Clock Divider
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  constexpr void setSystemClockDivider(std::uint32_t setting) {
    sysconPeripheral()->SYSAHBCLKDIV = hardware::SYSAHBCLKDIV::DIV(setting);
  }
  /**
   * @brief enable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void enablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    sysconPeripheral()->SYSAHBCLKCTRL0 = sysconPeripheral()->SYSAHBCLKCTRL0 | setting0;
    sysconPeripheral()->SYSAHBCLKCTRL1 = sysconPeripheral()->SYSAHBCLKCTRL1 | setting1;
  }
  /**
   * @brief disable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void disablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    sysconPeripheral()->SYSAHBCLKCTRL0 = sysconPeripheral()->SYSAHBCLKCTRL0 & ~setting0;
    sysconPeripheral()->SYSAHBCLKCTRL1 = sysconPeripheral()->SYSAHBCLKCTRL1 & ~setting1;
  }
  /**
   * @brief reset a peripheral
   * @param setting0 bit setting from peripheralResets enum
   * @param setting1 bit setting from peripheralResets enum
   */
  constexpr void resetPeripherals(std::uint32_t setting0, std::uint32_t setting1) {
    sysconPeripheral()->PRESETCTRL0 = sysconPeripheral()->PRESETCTRL0 & ~setting0;
    sysconPeripheral()->PRESETCTRL0 = sysconPeripheral()->PRESETCTRL0 | setting0;
    sysconPeripheral()->PRESETCTRL1 = sysconPeripheral()->PRESETCTRL1 & ~setting1;
    sysconPeripheral()->PRESETCTRL1 = sysconPeripheral()->PRESETCTRL1 | setting1;
  }
  /**
   * @brief Set the peripheral clock to a specific clock
   * @param peripheral peripheral to set the clock input of
   * @param clock clock to connect to the peripheral
   */
  constexpr void peripheralClockSource(peripheralClockSelects peripheral, peripheralClocks clock) {
    size_t index = static_cast<size_t>(peripheral);
    sysconPeripheral()->FCLKSEL[index] = static_cast<std::uint32_t>(clock);
  }
  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  constexpr void powerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG | setting;
  }
  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  constexpr void depowerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = (sysconPeripheral()->PDRUNCFG & ~setting) | hardware::PDRUNCFG::RESERVED_BITS;
  }
  /**
   * @brief Get the DEVICE ID
   *
   * @return chip id value
   * @return 0x00008100 is returned for LPC840M021FN8
   * @return 0x00008110 is returned for LPC841M001JDH16
   * @return 0x00008120 is returned for LPC842M101JDH16
   * @return 0x00008121 is returned for LPC842M101JD20
   * @return 0x00008122 is returned for LPC842M101JDH20
   * @return 0x00008122 is returned for LPC842M101JTB16
   */
  constexpr std::uint32_t getChipId(void) {
    return sysconPeripheral()->DEVICE_ID;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  constexpr static hw::syscon::peripheral *sysconPeripheral() {
    return reinterpret_cast<hw::syscon::peripheral *>(sysconAddress);
  }

 private:
  constexpr static libMcuLL::hwAddressType sysconAddress = sysconAddress_; /**< peripheral address */
};
}  // namespace libMcu::ll::syscon
#endif