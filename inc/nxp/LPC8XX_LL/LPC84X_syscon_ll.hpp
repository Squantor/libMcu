/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_syscon_ll.hpp
 * @brief LPC84X series system control interface class and definitions
 */
#ifndef LPC84X_SYSCON_LL_HPP
#define LPC84X_SYSCON_LL_HPP

namespace libmcull::syscon {
namespace hardware = libmcuhw::syscon;

/**
 * @brief Peripheral reset for first setting
 */
namespace peripheralResets0 {
constexpr inline std::uint32_t FLASH = hardware::PRESETCTRL0::kFLASH;     /*!< FLASH peripheral reset */
constexpr inline std::uint32_t I2C0 = hardware::PRESETCTRL0::kI2C0;       /*!< I2C0 peripheral reset */
constexpr inline std::uint32_t GPIO0 = hardware::PRESETCTRL0::kGPIO0;     /*!< GPIO0 peripheral reset */
constexpr inline std::uint32_t SWM = hardware::PRESETCTRL0::kSWM;         /*!< SWM peripheral reset */
constexpr inline std::uint32_t SCT = hardware::PRESETCTRL0::kSCT;         /*!< SCT peripheral reset */
constexpr inline std::uint32_t WKT = hardware::PRESETCTRL0::kWKT;         /*!< WKT peripheral reset */
constexpr inline std::uint32_t MRT = hardware::PRESETCTRL0::kMRT;         /*!< MRT peripheral reset */
constexpr inline std::uint32_t SPI0 = hardware::PRESETCTRL0::kSPI0;       /*!< SPI0 peripheral reset */
constexpr inline std::uint32_t SPI1 = hardware::PRESETCTRL0::kSPI1;       /*!< SPI1 peripheral reset */
constexpr inline std::uint32_t CRC = hardware::PRESETCTRL0::kCRC;         /*!< CRC peripheral reset */
constexpr inline std::uint32_t UART0 = hardware::PRESETCTRL0::kUART0;     /*!< UART0 peripheral reset */
constexpr inline std::uint32_t UART1 = hardware::PRESETCTRL0::kUART1;     /*!< UART1 peripheral reset */
constexpr inline std::uint32_t UART2 = hardware::PRESETCTRL0::kUART2;     /*!< UART2 peripheral reset */
constexpr inline std::uint32_t IOCON = hardware::PRESETCTRL0::kIOCON;     /*!< IOCON peripheral reset */
constexpr inline std::uint32_t ACMP = hardware::PRESETCTRL0::kACMP;       /*!< ACMP peripheral reset */
constexpr inline std::uint32_t GPIO1 = hardware::PRESETCTRL0::kGPIO1;     /*!< GPIO1 peripheral reset */
constexpr inline std::uint32_t I2C1 = hardware::PRESETCTRL0::kI2C1;       /*!< I2C1 peripheral reset */
constexpr inline std::uint32_t I2C2 = hardware::PRESETCTRL0::kI2C2;       /*!< I2C2 peripheral reset */
constexpr inline std::uint32_t I2C3 = hardware::PRESETCTRL0::kI2C3;       /*!< I2C3 peripheral reset */
constexpr inline std::uint32_t ADC = hardware::PRESETCTRL0::kADC;         /*!< ADC peripheral reset */
constexpr inline std::uint32_t CTIMER0 = hardware::PRESETCTRL0::kCTIMER0; /*!< CTIMER0 peripheral reset */
constexpr inline std::uint32_t DAC0 = hardware::PRESETCTRL0::kDAC0;       /*!< DAC0 peripheral reset */
constexpr inline std::uint32_t GPIOINT = hardware::PRESETCTRL0::kGPIOINT; /*!< GPIOINT peripheral reset */
constexpr inline std::uint32_t DMA = hardware::PRESETCTRL0::kDMA;         /*!< DMA peripheral reset */
constexpr inline std::uint32_t UART3 = hardware::PRESETCTRL0::kUART3;     /*!< UART3 peripheral reset */
constexpr inline std::uint32_t UART4 = hardware::PRESETCTRL0::kUART4;     /*!< UART4 peripheral reset */
}  // namespace peripheralResets0
/**
 * @brief Peripheral resets for second setting
 */
namespace peripheralResets1 {
constexpr inline std::uint32_t CAPT = hardware::PRESETCTRL1::kCAPT; /*!< CAPT peripheral reset */
constexpr inline std::uint32_t DAC1 = hardware::PRESETCTRL1::kDAC1; /*!< DAC1 peripheral reset */
constexpr inline std::uint32_t FRG0 = hardware::PRESETCTRL1::kFRG0; /*!< FRG0 peripheral reset */
constexpr inline std::uint32_t FRG1 = hardware::PRESETCTRL1::kFRG1; /*!< FRG1 peripheral reset */
}  // namespace peripheralResets1
/**
 * @brief PLL post divider options
 */
enum class PllPostDividers : std::uint32_t {
  kDiv2 = hardware::SYSPLLCTRL::kPSEL_DIV2,   /*!< PLL post division ration of 2 */
  kDiv4 = hardware::SYSPLLCTRL::kPSEL_DIV4,   /*!< PLL post division ration of 4 */
  kDiv8 = hardware::SYSPLLCTRL::kPSEL_DIV8,   /*!< PLL post division ration of 8 */
  kDiv16 = hardware::SYSPLLCTRL::kPSEL_DIV16, /*!< PLL post division ration of 16 */
};  // namespace pllPostDivider
/**
 * @brief PLL source options
 */
enum class PllClockSources : std::uint32_t {
  FRO = hardware::SYSPLLCLKSEL::kFRO,        /*!< FRO clock source */
  EXT = hardware::SYSPLLCLKSEL::kEXT,        /*!< External clock */
  WDO = hardware::SYSPLLCLKSEL::kWDO,        /*!< Watchdog oscillator*/
  FRO_DIV = hardware::SYSPLLCLKSEL::kFRO_DIV /*!< FRO divided clock source */
};
/**
 * @brief main clock pll sources options
 */
enum class mainClockPllSources : std::uint32_t {
  PRE = hardware::MAINCLKPLLSEL::kPRE,       /*!< Select main clock before PLL*/
  SYSPLL = hardware::MAINCLKPLLSEL::kSYSPLL, /*!< select main clock PLL*/
};  // namespace mainClockSources
/**
 * @brief main clock sources options
 */
enum class mainClockSources : std::uint32_t {
  FRO = hardware::MAINCLKSEL::kFRO,         /*!< main clock source is FRO */
  EXT = hardware::MAINCLKSEL::kEXT,         /*!< main clock source is external clock */
  WDO = hardware::MAINCLKSEL::kWDO,         /*!< main clock source is WDT oscillator */
  FRO_DIV = hardware::MAINCLKSEL::kFRO_DIV, /*!< main clock source is FRO/2 */
};  // namespace mainClockSources
/**
 * @brief Peripherals to set the clock source of
 */
enum class ClockSourceSelects : std::uint32_t {
  UART0 = hardware::FCLKSEL::kUART0, /*!< UART0 clock select */
  UART1 = hardware::FCLKSEL::kUART1, /*!< UART1 clock select */
  UART2 = hardware::FCLKSEL::kUART2, /*!< UART2 clock select */
  UART3 = hardware::FCLKSEL::kUART3, /*!< UART3 clock select */
  UART4 = hardware::FCLKSEL::kUART4, /*!< UART4 clock select */
  I2C0 = hardware::FCLKSEL::kI2C0,   /*!< I2C0 clock select */
  I2C1 = hardware::FCLKSEL::kI2C1,   /*!< I2C1 clock select */
  I2C2 = hardware::FCLKSEL::kI2C2,   /*!< I2C2 clock select */
  I2C3 = hardware::FCLKSEL::kI2C3,   /*!< I2C3 clock select */
  SPI0 = hardware::FCLKSEL::kSPI0,   /*!< SPI0 clock select */
  SPI1 = hardware::FCLKSEL::kSPI1,   /*!< SPI1 clock select */
};
/**
 * @brief Peripheral clock options
 */
enum class clockSources : std::uint32_t {
  FRO = hardware::FCLKSEL::kFRO,         /*!< FRO clock source */
  MAIN = hardware::FCLKSEL::kMAIN,       /*!< Main clock source */
  FRG0 = hardware::FCLKSEL::kFRG0,       /*!< Fractional clock generator 0 */
  FRG1 = hardware::FCLKSEL::kFRG1,       /*!< Fractional clock generator 1 */
  FRO_DIV = hardware::FCLKSEL::kFRO_DIV, /*!< FRO divided by 2 clock source  */
  NONE = hardware::FCLKSEL::kNONE,       /*!< No clock source */
};

/**
 * @brief ADC clock sources
 */
enum class adcClockSources : std::uint32_t {
  FRO = hardware::ADCCLKSEL::kFRO,       /*!< FRO clock source */
  SYSPLL = hardware::ADCCLKSEL::kSYSPLL, /*!< System PLL clock source */
};
/**
 * @brief SCT clock sources
 */
enum class sctClockSources : std::uint32_t {
  FRO = hardware::SCTCLKSEL::kFRO,       /*!< FRO clock source */
  MAIN = hardware::SCTCLKSEL::kMAINCLK,  /*!< Main clock source */
  SYSPLL = hardware::SCTCLKSEL::kSYSPLL, /*!< System PLL clock source */
};

/**
 * @brief Peripheral clock enable/disable options section 0
 */
namespace peripheralClocks0 {
constexpr inline std::uint32_t ROM = hardware::SYSAHBCLKCTRL0::kROM;           /*!< ROM clock enable */
constexpr inline std::uint32_t RAM = hardware::SYSAHBCLKCTRL0::kRAM0_1;        /*!< RAM clock enable */
constexpr inline std::uint32_t FLASH = hardware::SYSAHBCLKCTRL0::kFLASH;       /*!< Flash clock enable */
constexpr inline std::uint32_t I2C0 = hardware::SYSAHBCLKCTRL0::kI2C0;         /*!< I2C0 clock enable */
constexpr inline std::uint32_t GPIO0 = hardware::SYSAHBCLKCTRL0::kGPIO0;       /*!< GPIO0 clock enable */
constexpr inline std::uint32_t SWM = hardware::SYSAHBCLKCTRL0::kSWM;           /*!< SWM clock enable */
constexpr inline std::uint32_t SCT = hardware::SYSAHBCLKCTRL0::kSCT;           /*!< SCT clock enable */
constexpr inline std::uint32_t WKT = hardware::SYSAHBCLKCTRL0::kWKT;           /*!< WKT clock enable */
constexpr inline std::uint32_t MRT = hardware::SYSAHBCLKCTRL0::kMRT;           /*!< MRT clock enable */
constexpr inline std::uint32_t SPI0 = hardware::SYSAHBCLKCTRL0::kSPI0;         /*!< SPI0 clock enable */
constexpr inline std::uint32_t SPI1 = hardware::SYSAHBCLKCTRL0::kSPI1;         /*!< SPI1 clock enable */
constexpr inline std::uint32_t CRC = hardware::SYSAHBCLKCTRL0::kCRC;           /*!< CRC clock enable */
constexpr inline std::uint32_t UART0 = hardware::SYSAHBCLKCTRL0::kUART0;       /*!< UART0 clock enable */
constexpr inline std::uint32_t UART1 = hardware::SYSAHBCLKCTRL0::kUART1;       /*!< UART1 clock enable */
constexpr inline std::uint32_t UART2 = hardware::SYSAHBCLKCTRL0::kUART2;       /*!< UART2 clock enable */
constexpr inline std::uint32_t WWDT = hardware::SYSAHBCLKCTRL0::kWWDT;         /*!< WWDT clock enable */
constexpr inline std::uint32_t IOCON = hardware::SYSAHBCLKCTRL0::kIOCON;       /*!< IOCON clock enable */
constexpr inline std::uint32_t ACMP = hardware::SYSAHBCLKCTRL0::kACMP;         /*!< ACMP clock enable */
constexpr inline std::uint32_t GPIO1 = hardware::SYSAHBCLKCTRL0::kGPIO1;       /*!< GPIO1 clock enable */
constexpr inline std::uint32_t I2C1 = hardware::SYSAHBCLKCTRL0::kI2C1;         /*!< I2C1 clock enable */
constexpr inline std::uint32_t I2C2 = hardware::SYSAHBCLKCTRL0::kI2C2;         /*!< I2C2 clock enable */
constexpr inline std::uint32_t I2C3 = hardware::SYSAHBCLKCTRL0::kI2C3;         /*!< I2C3 clock enable */
constexpr inline std::uint32_t ADC = hardware::SYSAHBCLKCTRL0::kADC;           /*!< ADC clock enable */
constexpr inline std::uint32_t CTIMER0 = hardware::SYSAHBCLKCTRL0::kCTIMER0;   /*!< CTIMER0 clock enable */
constexpr inline std::uint32_t MTB = hardware::SYSAHBCLKCTRL0::kMTB;           /*!< MTB clock enable */
constexpr inline std::uint32_t DAC0 = hardware::SYSAHBCLKCTRL0::kDAC0;         /*!< DAC0 clock enable */
constexpr inline std::uint32_t GPIO_INT = hardware::SYSAHBCLKCTRL0::kGPIO_INT; /*!< GPIO_INT clock enable */
constexpr inline std::uint32_t DMA = hardware::SYSAHBCLKCTRL0::kDMA;           /*!< DMA clock enable */
constexpr inline std::uint32_t UART3 = hardware::SYSAHBCLKCTRL0::kUART3;       /*!< UART3 clock enable */
constexpr inline std::uint32_t UART4 = hardware::SYSAHBCLKCTRL0::kUART4;       /*!< UART4 clock enable */
}  // namespace peripheralClocks0
/**
 * @brief Peripheral clock enable/disable options section 1
 */
namespace peripheralClocks1 {
constexpr inline std::uint32_t CAPT = hardware::SYSAHBCLKCTRL1::kCAPT; /*!< CAPT clock enable */
constexpr inline std::uint32_t DAC1 = hardware::SYSAHBCLKCTRL1::kDAC1; /*!< DAC1 clock enable */
}  // namespace peripheralClocks1
/**
 * @brief Peripheral power up/down options
 */
namespace powerOptions {
constexpr inline std::uint32_t FROOUT = hardware::PDRUNCFG::kFROOUT; /*!< FRO oscillator output power */
constexpr inline std::uint32_t FRO = hardware::PDRUNCFG::kFRO;       /*!< FRO oscillator power */
constexpr inline std::uint32_t FLASH = hardware::PDRUNCFG::kFLASH;   /*!< Flash power */
constexpr inline std::uint32_t BOD = hardware::PDRUNCFG::kBOD;       /*!< BOD power */
constexpr inline std::uint32_t ADC = hardware::PDRUNCFG::kADC;       /*!< ADC power */
constexpr inline std::uint32_t SYSOSC = hardware::PDRUNCFG::kSYSOSC; /*!< Crystal oscillator power */
constexpr inline std::uint32_t WDTOSC = hardware::PDRUNCFG::kWDTOSC; /*!< Watchdog oscillator power */
constexpr inline std::uint32_t SYSPLL = hardware::PDRUNCFG::kSYSPLL; /*!< System PLL oscillator power */
constexpr inline std::uint32_t DAC0 = hardware::PDRUNCFG::kDAC0;     /*!< DAC0 power */
constexpr inline std::uint32_t DAC1 = hardware::PDRUNCFG::kDAC1;     /*!< DAC1 power */
constexpr inline std::uint32_t ACMP = hardware::PDRUNCFG::kACMP;     /*!< ACMP power */
}  // namespace powerOptions
/**
 * @brief Clock output sources
 */
enum class clockOutSources : std::uint32_t {
  FRO = hardware::CLKOUTSEL::kFRO,           /*!< FRO clock source */
  MAIN = hardware::CLKOUTSEL::kMAIN,         /*!< Main clock source */
  SYSPLL = hardware::CLKOUTSEL::kSYSPLL,     /*!< System PLL clock source */
  EXTERNAL = hardware::CLKOUTSEL::kEXTERNAL, /*!< External clock source */
  WATCHDOG = hardware::CLKOUTSEL::kWATCHDOG, /*!< Watchdog oscillator clock source */
};

template <libmcu::SysconBaseAddress syscon_address>
struct Syscon : libmcu::PeripheralBase {
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
  constexpr void selectPllClock(PllClockSources setting) {
    GetPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kNO_CHANGE;
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kUPDATE;
  }
  /**
   * @brief Select main clock PLL source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void selectMainPllClock(mainClockPllSources setting) {
    GetPeripheral()->MAINCLKPLLSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::kNO_CHANGE;
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::kUPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void selectMainClock(mainClockSources setting) {
    GetPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kNO_CHANGE;
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kUPDATE;
  }
  /**
   * @brief Set the AHB system clock Divider
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  constexpr void setMainClockDivider(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKDIV = hardware::SYSAHBCLKDIV::DIV(setting);
  }
  /**
   * @brief Setup ADC clock
   * @param source clock source for the ADC
   * @param divisor clock pre divider for the ADC, zero disables the clock
   */
  constexpr void setupAdcClock(adcClockSources source, std::uint32_t divisor) {
    GetPeripheral()->ADCCLKDIV = divisor;
    GetPeripheral()->ADCCLKSEL = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief Setup SCT clock
   * @param source clock source for the SCT
   * @param divisor clock pre divider for the SCT, zero disables the clock
   */
  constexpr void setupSctClock(sctClockSources source, std::uint32_t divisor) {
    GetPeripheral()->SCTCLKDIV = divisor;
    GetPeripheral()->SCTCLKSEL = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief enable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void enablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    GetPeripheral()->SYSAHBCLKCTRL0 = GetPeripheral()->SYSAHBCLKCTRL0 | setting0;
    GetPeripheral()->SYSAHBCLKCTRL1 = GetPeripheral()->SYSAHBCLKCTRL1 | setting1;
  }
  /**
   * @brief disable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void disablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    GetPeripheral()->SYSAHBCLKCTRL0 = GetPeripheral()->SYSAHBCLKCTRL0 & ~setting0;
    GetPeripheral()->SYSAHBCLKCTRL1 = GetPeripheral()->SYSAHBCLKCTRL1 & ~setting1;
  }
  /**
   * @brief reset a peripheral
   * @param setting0 bit setting from peripheralResets enum
   * @param setting1 bit setting from peripheralResets enum
   */
  constexpr void resetPeripherals(std::uint32_t setting0, std::uint32_t setting1) {
    GetPeripheral()->PRESETCTRL0 = GetPeripheral()->PRESETCTRL0 & ~setting0;
    GetPeripheral()->PRESETCTRL1 = GetPeripheral()->PRESETCTRL1 & ~setting1;
    GetPeripheral()->PRESETCTRL0 = GetPeripheral()->PRESETCTRL0 | setting0;
    GetPeripheral()->PRESETCTRL1 = GetPeripheral()->PRESETCTRL1 | setting1;
  }
  /**
   * @brief Set the peripheral clock to a specific clock
   * @param peripheral peripheral to set the clock input of
   * @param clock clock to connect to the peripheral
   */
  constexpr void peripheralClockSource(ClockSourceSelects peripheral, clockSources clock) {
    size_t index = static_cast<size_t>(peripheral);
    GetPeripheral()->FCLKSEL[index] = static_cast<std::uint32_t>(clock);
  }
  /**
   * @brief configure the clock output
   * @param source clock source to output
   * @param divisor divisor of the clock output
   */
  constexpr void setClockOutput(clockOutSources source, std::uint32_t divisor) {
    // disable clock to prevent overspeed
    GetPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(0);
    GetPeripheral()->CLKOUTSEL = static_cast<std::uint32_t>(source);
    GetPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(divisor);
  }
  /**
   * @brief Power up a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void powerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = (GetPeripheral()->PDRUNCFG & ~setting) | hardware::PDRUNCFG::kRESERVED_BITS;
  }
  /**
   * @brief Power down a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void depowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG | setting;
  }
  /**
   * @brief Configure microcontroller clocks with mcuConfiguration settings
   * @tparam &config current configuration settings
   */
  template <const libmcuhw::clock::mcuClockConfig &config = libmcuhw::clock::defaultClocks>
  constexpr void configureMcuClocks() {
    // check if the wanted config is possible at all?
    static_assert(libmcuhw::clock::FindClockFrequency(config.getSourceFreq(), config.getSystemFreq()) != 0,
                  "Unable to find a clock configuration solution");
    // setup clock source
    if constexpr (config.source == libmcuhw::clock::clockInputSources::FRO) {
      // TODO support 24MHz FRO frequency
      // support romfunction FRO and get valid list of FRO frequency
      if constexpr (config.getSourceFreq() == libmcuhw::clock::froDefaultClockFreq)
        selectMainClock(mainClockSources::FRO);
      else
        static_assert(false, "Unsupported FRO frequency!");
    } else if constexpr (config.source == libmcuhw::clock::clockInputSources::XTAL) {
      if constexpr (config.getSourceFreq() > 15'000'000) {
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::kNO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::kFREQ_15_25MHz);
      } else
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::kNO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::kFREQ_1_20MHz);
      powerPeripherals(libmcull::syscon::powerOptions::SYSOSC);
      libmcu::Delay(3000);
      selectMainClock(mainClockSources::EXT);
    }
    // TODO: handle WDT clock source
    // TODO: some peripherals can only use the PLL out as a clock source
    selectMainPllClock(mainClockPllSources::PRE);
    // can we achieve the frequency we need without using the PLL?
    if constexpr (config.getMainFreq() == config.getSourceFreq()) {
      setMainClockDivider(config.getMainFreq() / config.getSystemFreq());
    } else {
      if constexpr (config.source == libmcuhw::clock::clockInputSources::FRO) {
        selectPllClock(libmcull::syscon::PllClockSources::FRO);
      } else if constexpr (config.source == libmcuhw::clock::clockInputSources::XTAL) {
        selectPllClock(libmcull::syscon::PllClockSources::EXT);
      }
      depowerPeripherals(libmcull::syscon::powerOptions::SYSPLL);
      SetSystemPllControl(libmcuhw::clock::FindSystemPllMsel(config.getSourceFreq(), config.getMainFreq()),
                          static_cast<libmcull::syscon::PllPostDividers>(libmcuhw::clock::FindSystemPllPsel(config.getMainFreq())));
      powerPeripherals(libmcull::syscon::powerOptions::SYSPLL);
      while (GetSystemPllStatus() == 0)
        ;
      setMainClockDivider(config.getMainFreq() / config.getSystemFreq());
      selectMainPllClock(libmcull::syscon::mainClockPllSources::SYSPLL);
    }
  }
  /**
   * @brief Configure peripheral clock with configuration settings
   * @tparam &config configuration for this peripheral
   */
  template <const libmcuhw::clock::periClockConfig &config>
  constexpr void configurePeripheralClock() {
    if constexpr (config.peripheral == libmcuhw::clock::periSelect::UART0) {
      if constexpr (config.source == libmcuhw::clock::periSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kFRO;
      else if constexpr (config.source == libmcuhw::clock::periSource::MAIN)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kMAIN;
      else
        static_assert(false, "Unsupported clock source for UART0!");
    } else if constexpr (config.peripheral == libmcuhw::clock::periSelect::UART1) {
      if constexpr (config.source == libmcuhw::clock::periSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kFRO;
      else if constexpr (config.source == libmcuhw::clock::periSource::MAIN)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kMAIN;
      else
        static_assert(false, "Unsupported clock source for UART1!");
    } else
      static_assert(false, "Unknown or unsupported peripheral!");
  }

  /**
   * @brief Get the DEVICE ID
   * @return chip id value
   * @return 0x00008100 is returned for LPC840M021FN8
   * @return 0x00008110 is returned for LPC841M001JDH16
   * @return 0x00008120 is returned for LPC842M101JDH16
   * @return 0x00008121 is returned for LPC842M101JD20
   * @return 0x00008122 is returned for LPC842M101JDH20
   * @return 0x00008122 is returned for LPC842M101JTB16
   */
  constexpr std::uint32_t getChipId(void) {
    return GetPeripheral()->DEVICE_ID;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to syscon registers
   */
  constexpr static hardware::Syscon *GetPeripheral() {
    return reinterpret_cast<hardware::Syscon *>(syscon_address_);
  }

 private:
  constexpr static libmcu::HwAddressType syscon_address_ = syscon_address; /*!< peripheral address */
};
}  // namespace libmcull::syscon
#endif