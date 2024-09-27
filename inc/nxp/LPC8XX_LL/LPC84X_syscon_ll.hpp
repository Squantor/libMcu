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

namespace libMcuLL::syscon {
namespace hardware = libMcuHw::syscon;

/**
 * @brief Peripheral reset for first setting
 */
namespace peripheralResets0 {
constexpr inline std::uint32_t FLASH = hardware::PRESETCTRL0::FLASH;     /**< FLASH peripheral reset */
constexpr inline std::uint32_t I2C0 = hardware::PRESETCTRL0::I2C0;       /**< I2C0 peripheral reset */
constexpr inline std::uint32_t GPIO0 = hardware::PRESETCTRL0::GPIO0;     /**< GPIO0 peripheral reset */
constexpr inline std::uint32_t SWM = hardware::PRESETCTRL0::SWM;         /**< SWM peripheral reset */
constexpr inline std::uint32_t SCT = hardware::PRESETCTRL0::SCT;         /**< SCT peripheral reset */
constexpr inline std::uint32_t WKT = hardware::PRESETCTRL0::WKT;         /**< WKT peripheral reset */
constexpr inline std::uint32_t MRT = hardware::PRESETCTRL0::MRT;         /**< MRT peripheral reset */
constexpr inline std::uint32_t SPI0 = hardware::PRESETCTRL0::SPI0;       /**< SPI0 peripheral reset */
constexpr inline std::uint32_t SPI1 = hardware::PRESETCTRL0::SPI1;       /**< SPI1 peripheral reset */
constexpr inline std::uint32_t CRC = hardware::PRESETCTRL0::CRC;         /**< CRC peripheral reset */
constexpr inline std::uint32_t UART0 = hardware::PRESETCTRL0::UART0;     /**< UART0 peripheral reset */
constexpr inline std::uint32_t UART1 = hardware::PRESETCTRL0::UART1;     /**< UART1 peripheral reset */
constexpr inline std::uint32_t UART2 = hardware::PRESETCTRL0::UART2;     /**< UART2 peripheral reset */
constexpr inline std::uint32_t IOCON = hardware::PRESETCTRL0::IOCON;     /**< IOCON peripheral reset */
constexpr inline std::uint32_t ACMP = hardware::PRESETCTRL0::ACMP;       /**< ACMP peripheral reset */
constexpr inline std::uint32_t GPIO1 = hardware::PRESETCTRL0::GPIO1;     /**< GPIO1 peripheral reset */
constexpr inline std::uint32_t I2C1 = hardware::PRESETCTRL0::I2C1;       /**< I2C1 peripheral reset */
constexpr inline std::uint32_t I2C2 = hardware::PRESETCTRL0::I2C2;       /**< I2C2 peripheral reset */
constexpr inline std::uint32_t I2C3 = hardware::PRESETCTRL0::I2C3;       /**< I2C3 peripheral reset */
constexpr inline std::uint32_t ADC = hardware::PRESETCTRL0::ADC;         /**< ADC peripheral reset */
constexpr inline std::uint32_t CTIMER0 = hardware::PRESETCTRL0::CTIMER0; /**< CTIMER0 peripheral reset */
constexpr inline std::uint32_t DAC0 = hardware::PRESETCTRL0::DAC0;       /**< DAC0 peripheral reset */
constexpr inline std::uint32_t GPIOINT = hardware::PRESETCTRL0::GPIOINT; /**< GPIOINT peripheral reset */
constexpr inline std::uint32_t DMA = hardware::PRESETCTRL0::DMA;         /**< DMA peripheral reset */
constexpr inline std::uint32_t UART3 = hardware::PRESETCTRL0::UART3;     /**< UART3 peripheral reset */
constexpr inline std::uint32_t UART4 = hardware::PRESETCTRL0::UART4;     /**< UART4 peripheral reset */
}  // namespace peripheralResets0
/**
 * @brief Peripheral resets for second setting
 */
namespace peripheralResets1 {
constexpr inline std::uint32_t CAPT = hardware::PRESETCTRL1::CAPT; /**< CAPT peripheral reset */
constexpr inline std::uint32_t DAC1 = hardware::PRESETCTRL1::DAC1; /**< DAC1 peripheral reset */
constexpr inline std::uint32_t FRG0 = hardware::PRESETCTRL1::FRG0; /**< FRG0 peripheral reset */
constexpr inline std::uint32_t FRG1 = hardware::PRESETCTRL1::FRG1; /**< FRG1 peripheral reset */
}  // namespace peripheralResets1
/**
 * @brief PLL post divider options
 */
enum class pllPostDivider : std::uint32_t {
  DIV_2 = hardware::SYSPLLCTRL::PSEL_DIV2,   /**< PLL post division ration of 2 */
  DIV_4 = hardware::SYSPLLCTRL::PSEL_DIV4,   /**< PLL post division ration of 4 */
  DIV_8 = hardware::SYSPLLCTRL::PSEL_DIV8,   /**< PLL post division ration of 8 */
  DIV_16 = hardware::SYSPLLCTRL::PSEL_DIV16, /**< PLL post division ration of 16 */
};  // namespace pllPostDivider
/**
 * @brief PLL source options
 */
enum class pllClockSources : std::uint32_t {
  FRO = hardware::SYSPLLCLKSEL::FRO,        /**< FRO clock source */
  EXT = hardware::SYSPLLCLKSEL::EXT,        /**< External clock */
  WDO = hardware::SYSPLLCLKSEL::WDO,        /**< Watchdog oscillator*/
  FRO_DIV = hardware::SYSPLLCLKSEL::FRO_DIV /**< FRO divided clock source */
};
/**
 * @brief main clock pll sources options
 */
enum class mainClockPllSources : std::uint32_t {
  PRE = hardware::MAINCLKPLLSEL::PRE,       /**< Select main clock before PLL*/
  SYSPLL = hardware::MAINCLKPLLSEL::SYSPLL, /**< select main clock PLL*/
};  // namespace mainClockSources
/**
 * @brief main clock sources options
 */
enum class mainClockSources : std::uint32_t {
  FRO = hardware::MAINCLKSEL::FRO,         /**< main clock source is FRO */
  EXT = hardware::MAINCLKSEL::EXT,         /**< main clock source is external clock */
  WDO = hardware::MAINCLKSEL::WDO,         /**< main clock source is WDT oscillator */
  FRO_DIV = hardware::MAINCLKSEL::FRO_DIV, /**< main clock source is FRO/2 */
};  // namespace mainClockSources
/**
 * @brief Peripherals to set the clock source of
 */
enum class clockSourceSelects : std::uint32_t {
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
enum class clockSources : std::uint32_t {
  FRO = hardware::FCLKSEL::FRO,         /**< FRO clock source */
  MAIN = hardware::FCLKSEL::MAIN,       /**< Main clock source */
  FRG0 = hardware::FCLKSEL::FRG0,       /**< Fractional clock generator 0 */
  FRG1 = hardware::FCLKSEL::FRG1,       /**< Fractional clock generator 1 */
  FRO_DIV = hardware::FCLKSEL::FRO_DIV, /**< FRO divided by 2 clock source  */
  NONE = hardware::FCLKSEL::NONE,       /**< No clock source */
};
/**
 * @brief Peripheral clock enable/disable options section 0
 */
namespace peripheralClocks0 {
constexpr inline std::uint32_t ROM = hardware::SYSAHBCLKCTRL0::ROM;           /**< ROM clock enable */
constexpr inline std::uint32_t RAM = hardware::SYSAHBCLKCTRL0::RAM0_1;        /**< RAM clock enable */
constexpr inline std::uint32_t FLASH = hardware::SYSAHBCLKCTRL0::FLASH;       /**< Flash clock enable */
constexpr inline std::uint32_t I2C0 = hardware::SYSAHBCLKCTRL0::I2C0;         /**< I2C0 clock enable */
constexpr inline std::uint32_t GPIO0 = hardware::SYSAHBCLKCTRL0::GPIO0;       /**< GPIO0 clock enable */
constexpr inline std::uint32_t SWM = hardware::SYSAHBCLKCTRL0::SWM;           /**< SWM clock enable */
constexpr inline std::uint32_t SCT = hardware::SYSAHBCLKCTRL0::SCT;           /**< SCT clock enable */
constexpr inline std::uint32_t WKT = hardware::SYSAHBCLKCTRL0::WKT;           /**< WKT clock enable */
constexpr inline std::uint32_t MRT = hardware::SYSAHBCLKCTRL0::MRT;           /**< MRT clock enable */
constexpr inline std::uint32_t SPI0 = hardware::SYSAHBCLKCTRL0::SPI0;         /**< SPI0 clock enable */
constexpr inline std::uint32_t SPI1 = hardware::SYSAHBCLKCTRL0::SPI1;         /**< SPI1 clock enable */
constexpr inline std::uint32_t CRC = hardware::SYSAHBCLKCTRL0::CRC;           /**< CRC clock enable */
constexpr inline std::uint32_t UART0 = hardware::SYSAHBCLKCTRL0::UART0;       /**< UART0 clock enable */
constexpr inline std::uint32_t UART1 = hardware::SYSAHBCLKCTRL0::UART1;       /**< UART1 clock enable */
constexpr inline std::uint32_t UART2 = hardware::SYSAHBCLKCTRL0::UART2;       /**< UART2 clock enable */
constexpr inline std::uint32_t WWDT = hardware::SYSAHBCLKCTRL0::WWDT;         /**< WWDT clock enable */
constexpr inline std::uint32_t IOCON = hardware::SYSAHBCLKCTRL0::IOCON;       /**< IOCON clock enable */
constexpr inline std::uint32_t ACMP = hardware::SYSAHBCLKCTRL0::ACMP;         /**< ACMP clock enable */
constexpr inline std::uint32_t GPIO1 = hardware::SYSAHBCLKCTRL0::GPIO1;       /**< GPIO1 clock enable */
constexpr inline std::uint32_t I2C1 = hardware::SYSAHBCLKCTRL0::I2C1;         /**< I2C1 clock enable */
constexpr inline std::uint32_t I2C2 = hardware::SYSAHBCLKCTRL0::I2C2;         /**< I2C2 clock enable */
constexpr inline std::uint32_t I2C3 = hardware::SYSAHBCLKCTRL0::I2C3;         /**< I2C3 clock enable */
constexpr inline std::uint32_t ADC = hardware::SYSAHBCLKCTRL0::ADC;           /**< ADC clock enable */
constexpr inline std::uint32_t CTIMER0 = hardware::SYSAHBCLKCTRL0::CTIMER0;   /**< CTIMER0 clock enable */
constexpr inline std::uint32_t MTB = hardware::SYSAHBCLKCTRL0::MTB;           /**< MTB clock enable */
constexpr inline std::uint32_t DAC0 = hardware::SYSAHBCLKCTRL0::DAC0;         /**< DAC0 clock enable */
constexpr inline std::uint32_t GPIO_INT = hardware::SYSAHBCLKCTRL0::GPIO_INT; /**< GPIO_INT clock enable */
constexpr inline std::uint32_t DMA = hardware::SYSAHBCLKCTRL0::DMA;           /**< DMA clock enable */
constexpr inline std::uint32_t UART3 = hardware::SYSAHBCLKCTRL0::UART3;       /**< UART3 clock enable */
constexpr inline std::uint32_t UART4 = hardware::SYSAHBCLKCTRL0::UART4;       /**< UART4 clock enable */
}  // namespace peripheralClocks0
/**
 * @brief Peripheral clock enable/disable options section 1
 */
namespace peripheralClocks1 {
constexpr inline std::uint32_t CAPT = hardware::SYSAHBCLKCTRL1::CAPT; /**< CAPT clock enable */
constexpr inline std::uint32_t DAC1 = hardware::SYSAHBCLKCTRL1::DAC1; /**< DAC1 clock enable */
}  // namespace peripheralClocks1
/**
 * @brief Peripheral power up/down options
 */
namespace powerOptions {
constexpr inline std::uint32_t FROOUT = hardware::PDRUNCFG::FROOUT; /**< FRO oscillator output power */
constexpr inline std::uint32_t FRO = hardware::PDRUNCFG::FRO;       /**< FRO oscillator power */
constexpr inline std::uint32_t FLASH = hardware::PDRUNCFG::FLASH;   /**< Flash power */
constexpr inline std::uint32_t BOD = hardware::PDRUNCFG::BOD;       /**< BOD power */
constexpr inline std::uint32_t ADC = hardware::PDRUNCFG::ADC;       /**< ADC power */
constexpr inline std::uint32_t SYSOSC = hardware::PDRUNCFG::SYSOSC; /**< Crystal oscillator power */
constexpr inline std::uint32_t WDTOSC = hardware::PDRUNCFG::WDTOSC; /**< Watchdog oscillator power */
constexpr inline std::uint32_t SYSPLL = hardware::PDRUNCFG::SYSPLL; /**< System PLL oscillator power */
constexpr inline std::uint32_t DAC0 = hardware::PDRUNCFG::DAC0;     /**< DAC0 power */
constexpr inline std::uint32_t DAC1 = hardware::PDRUNCFG::DAC1;     /**< DAC1 power */
constexpr inline std::uint32_t ACMP = hardware::PDRUNCFG::ACMP;     /**< ACMP power */
}  // namespace powerOptions
/**
 * @brief Clock output sources
 */
enum class clockOutSources : std::uint32_t {
  FRO = hardware::CLKOUTSEL::FRO,           /**< FRO clock source */
  MAIN = hardware::CLKOUTSEL::MAIN,         /**< Main clock source */
  SYS_PLL = hardware::CLKOUTSEL::SYS_PLL,   /**< System PLL clock source */
  EXTERNAL = hardware::CLKOUTSEL::EXTERNAL, /**< External clock source */
  WATCHDOG = hardware::CLKOUTSEL::WATCHDOG, /**< Watchdog oscillator clock source */
};

template <libMcu::sysconBaseAddress sysconAddress_>
struct syscon : libMcu::peripheralBase {
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
   * @brief Select main clock PLL source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void selectMainPllClock(mainClockPllSources setting) {
    sysconPeripheral()->MAINCLKPLLSEL = static_cast<std::uint32_t>(setting);
    sysconPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::NO_CHANGE;
    sysconPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::UPDATE;
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
  constexpr void peripheralClockSource(clockSourceSelects peripheral, clockSources clock) {
    size_t index = static_cast<size_t>(peripheral);
    sysconPeripheral()->FCLKSEL[index] = static_cast<std::uint32_t>(clock);
  }

  constexpr void setClockOutput(clockOutSources source, std::uint32_t divisor) {
    // disable clock to prevent overspeed
    sysconPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(0);
    sysconPeripheral()->CLKOUTSEL = static_cast<std::uint32_t>(source);
    sysconPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(divisor);
  }
  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from powerEnables enum
   */
  constexpr void powerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = (sysconPeripheral()->PDRUNCFG & ~setting) | hardware::PDRUNCFG::RESERVED_BITS;
  }
  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from powerEnables enum
   */
  constexpr void depowerPeripherals(std::uint32_t setting) {
    sysconPeripheral()->PDRUNCFG = sysconPeripheral()->PDRUNCFG | setting;
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
  constexpr static hardware::syscon *sysconPeripheral() {
    return reinterpret_cast<hardware::syscon *>(sysconAddress);
  }

 private:
  constexpr static libMcu::hwAddressType sysconAddress = sysconAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::syscon
#endif