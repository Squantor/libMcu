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
namespace peripheral_resets_0 {
constexpr inline std::uint32_t kFlash = hardware::PRESETCTRL0::kFLASH;     /*!< FLASH peripheral reset */
constexpr inline std::uint32_t kI2c0 = hardware::PRESETCTRL0::kI2C0;       /*!< I2C0 peripheral reset */
constexpr inline std::uint32_t kGpio0 = hardware::PRESETCTRL0::kGPIO0;     /*!< GPIO0 peripheral reset */
constexpr inline std::uint32_t kSwm = hardware::PRESETCTRL0::kSWM;         /*!< SWM peripheral reset */
constexpr inline std::uint32_t kSct = hardware::PRESETCTRL0::kSCT;         /*!< SCT peripheral reset */
constexpr inline std::uint32_t kWkt = hardware::PRESETCTRL0::kWKT;         /*!< WKT peripheral reset */
constexpr inline std::uint32_t kMrt = hardware::PRESETCTRL0::kMRT;         /*!< MRT peripheral reset */
constexpr inline std::uint32_t kSpi0 = hardware::PRESETCTRL0::kSPI0;       /*!< SPI0 peripheral reset */
constexpr inline std::uint32_t kSpi1 = hardware::PRESETCTRL0::kSPI1;       /*!< SPI1 peripheral reset */
constexpr inline std::uint32_t kCrc = hardware::PRESETCTRL0::kCRC;         /*!< CRC peripheral reset */
constexpr inline std::uint32_t kUart0 = hardware::PRESETCTRL0::kUART0;     /*!< UART0 peripheral reset */
constexpr inline std::uint32_t kUart1 = hardware::PRESETCTRL0::kUART1;     /*!< UART1 peripheral reset */
constexpr inline std::uint32_t kUart2 = hardware::PRESETCTRL0::kUART2;     /*!< UART2 peripheral reset */
constexpr inline std::uint32_t kIocon = hardware::PRESETCTRL0::kIOCON;     /*!< IOCON peripheral reset */
constexpr inline std::uint32_t kAcmp = hardware::PRESETCTRL0::kACMP;       /*!< ACMP peripheral reset */
constexpr inline std::uint32_t kGpio1 = hardware::PRESETCTRL0::kGPIO1;     /*!< GPIO1 peripheral reset */
constexpr inline std::uint32_t kI2c1 = hardware::PRESETCTRL0::kI2C1;       /*!< I2C1 peripheral reset */
constexpr inline std::uint32_t kI2c2 = hardware::PRESETCTRL0::kI2C2;       /*!< I2C2 peripheral reset */
constexpr inline std::uint32_t kI2c3 = hardware::PRESETCTRL0::kI2C3;       /*!< I2C3 peripheral reset */
constexpr inline std::uint32_t kAdc = hardware::PRESETCTRL0::kADC;         /*!< ADC peripheral reset */
constexpr inline std::uint32_t kCtimer0 = hardware::PRESETCTRL0::kCTIMER0; /*!< CTIMER0 peripheral reset */
constexpr inline std::uint32_t kDac0 = hardware::PRESETCTRL0::kDAC0;       /*!< DAC0 peripheral reset */
constexpr inline std::uint32_t kGpioInt = hardware::PRESETCTRL0::kGPIOINT; /*!< GPIOINT peripheral reset */
constexpr inline std::uint32_t kDma = hardware::PRESETCTRL0::kDMA;         /*!< DMA peripheral reset */
constexpr inline std::uint32_t kUart3 = hardware::PRESETCTRL0::kUART3;     /*!< UART3 peripheral reset */
constexpr inline std::uint32_t kUart4 = hardware::PRESETCTRL0::kUART4;     /*!< UART4 peripheral reset */
}  // namespace peripheral_resets_0
/**
 * @brief Peripheral resets for second setting
 */
namespace peripheral_resets_1 {
constexpr inline std::uint32_t kCapt = hardware::PRESETCTRL1::kCAPT; /*!< CAPT peripheral reset */
constexpr inline std::uint32_t kDac1 = hardware::PRESETCTRL1::kDAC1; /*!< DAC1 peripheral reset */
constexpr inline std::uint32_t kFrg0 = hardware::PRESETCTRL1::kFRG0; /*!< FRG0 peripheral reset */
constexpr inline std::uint32_t kFrg1 = hardware::PRESETCTRL1::kFRG1; /*!< FRG1 peripheral reset */
}  // namespace peripheral_resets_1
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
  kFro = hardware::SYSPLLCLKSEL::kFRO,       /*!< FRO clock source */
  kExt = hardware::SYSPLLCLKSEL::kEXT,       /*!< External clock */
  kWdo = hardware::SYSPLLCLKSEL::kWDO,       /*!< Watchdog oscillator*/
  kFroDiv = hardware::SYSPLLCLKSEL::kFRO_DIV /*!< FRO divided clock source */
};
/**
 * @brief main clock pll sources options
 */
enum class mainClockPllSources : std::uint32_t {
  kPrePll = hardware::MAINCLKPLLSEL::kPRE,    /*!< Select main clock before PLL*/
  kSysPll = hardware::MAINCLKPLLSEL::kSYSPLL, /*!< select main clock PLL*/
};  // namespace mainClockSources
/**
 * @brief main clock sources options
 */
enum class mainClockSources : std::uint32_t {
  kFro = hardware::MAINCLKSEL::kFRO,        /*!< main clock source is FRO */
  kExt = hardware::MAINCLKSEL::kEXT,        /*!< main clock source is external clock */
  kWdo = hardware::MAINCLKSEL::kWDO,        /*!< main clock source is WDT oscillator */
  kFroDiv = hardware::MAINCLKSEL::kFRO_DIV, /*!< main clock source is FRO/2 */
};  // namespace mainClockSources
/**
 * @brief Peripherals to set the clock source of
 */
enum class ClockSourceSelects : std::uint32_t {
  kUart0 = hardware::FCLKSEL::kUART0, /*!< UART0 clock select */
  kUart1 = hardware::FCLKSEL::kUART1, /*!< UART1 clock select */
  kUart2 = hardware::FCLKSEL::kUART2, /*!< UART2 clock select */
  kUart3 = hardware::FCLKSEL::kUART3, /*!< UART3 clock select */
  kUart4 = hardware::FCLKSEL::kUART4, /*!< UART4 clock select */
  kI2c0 = hardware::FCLKSEL::kI2C0,   /*!< I2C0 clock select */
  kI2c1 = hardware::FCLKSEL::kI2C1,   /*!< I2C1 clock select */
  kI2c2 = hardware::FCLKSEL::kI2C2,   /*!< I2C2 clock select */
  kI2c3 = hardware::FCLKSEL::kI2C3,   /*!< I2C3 clock select */
  kSpi0 = hardware::FCLKSEL::kSPI0,   /*!< SPI0 clock select */
  kSpi1 = hardware::FCLKSEL::kSPI1,   /*!< SPI1 clock select */
};
/**
 * @brief Peripheral clock options
 */
enum class ClockSources : std::uint32_t {
  kFro = hardware::FCLKSEL::kFRO,        /*!< FRO clock source */
  kMain = hardware::FCLKSEL::kMAIN,      /*!< Main clock source */
  kFrg0 = hardware::FCLKSEL::kFRG0,      /*!< Fractional clock generator 0 */
  kFrg1 = hardware::FCLKSEL::kFRG1,      /*!< Fractional clock generator 1 */
  kFroDiv = hardware::FCLKSEL::kFRO_DIV, /*!< FRO divided by 2 clock source  */
  kNone = hardware::FCLKSEL::kNONE,      /*!< No clock source */
};
/**
 * @brief ADC clock sources
 */
enum class AdcClockSources : std::uint32_t {
  kFro = hardware::ADCCLKSEL::kFRO,       /*!< FRO clock source */
  kSysPll = hardware::ADCCLKSEL::kSYSPLL, /*!< System PLL clock source */
};
/**
 * @brief SCT clock sources
 */
enum class SctClockSources : std::uint32_t {
  kFro = hardware::SCTCLKSEL::kFRO,       /*!< FRO clock source */
  kMain = hardware::SCTCLKSEL::kMAINCLK,  /*!< Main clock source */
  kSysPll = hardware::SCTCLKSEL::kSYSPLL, /*!< System PLL clock source */
};
/**
 * @brief Peripheral clock enable/disable options section 0
 */
namespace peripheral_clocks_0 {
constexpr inline std::uint32_t kRom = hardware::SYSAHBCLKCTRL0::kROM;          /*!< ROM clock enable */
constexpr inline std::uint32_t kRam = hardware::SYSAHBCLKCTRL0::kRAM0_1;       /*!< RAM clock enable */
constexpr inline std::uint32_t kFlash = hardware::SYSAHBCLKCTRL0::kFLASH;      /*!< Flash clock enable */
constexpr inline std::uint32_t kI2c0 = hardware::SYSAHBCLKCTRL0::kI2C0;        /*!< I2C0 clock enable */
constexpr inline std::uint32_t kGpio0 = hardware::SYSAHBCLKCTRL0::kGPIO0;      /*!< GPIO0 clock enable */
constexpr inline std::uint32_t kSwm = hardware::SYSAHBCLKCTRL0::kSWM;          /*!< SWM clock enable */
constexpr inline std::uint32_t kSct = hardware::SYSAHBCLKCTRL0::kSCT;          /*!< SCT clock enable */
constexpr inline std::uint32_t kWkt = hardware::SYSAHBCLKCTRL0::kWKT;          /*!< WKT clock enable */
constexpr inline std::uint32_t kMrt = hardware::SYSAHBCLKCTRL0::kMRT;          /*!< MRT clock enable */
constexpr inline std::uint32_t kSpi0 = hardware::SYSAHBCLKCTRL0::kSPI0;        /*!< SPI0 clock enable */
constexpr inline std::uint32_t kSpi1 = hardware::SYSAHBCLKCTRL0::kSPI1;        /*!< SPI1 clock enable */
constexpr inline std::uint32_t kCrc = hardware::SYSAHBCLKCTRL0::kCRC;          /*!< CRC clock enable */
constexpr inline std::uint32_t kUart0 = hardware::SYSAHBCLKCTRL0::kUART0;      /*!< UART0 clock enable */
constexpr inline std::uint32_t kUart1 = hardware::SYSAHBCLKCTRL0::kUART1;      /*!< UART1 clock enable */
constexpr inline std::uint32_t kUart2 = hardware::SYSAHBCLKCTRL0::kUART2;      /*!< UART2 clock enable */
constexpr inline std::uint32_t kWwdt = hardware::SYSAHBCLKCTRL0::kWWDT;        /*!< WWDT clock enable */
constexpr inline std::uint32_t kIocon = hardware::SYSAHBCLKCTRL0::kIOCON;      /*!< IOCON clock enable */
constexpr inline std::uint32_t kAcmp = hardware::SYSAHBCLKCTRL0::kACMP;        /*!< ACMP clock enable */
constexpr inline std::uint32_t kGpio1 = hardware::SYSAHBCLKCTRL0::kGPIO1;      /*!< GPIO1 clock enable */
constexpr inline std::uint32_t kI2c1 = hardware::SYSAHBCLKCTRL0::kI2C1;        /*!< I2C1 clock enable */
constexpr inline std::uint32_t kI2c2 = hardware::SYSAHBCLKCTRL0::kI2C2;        /*!< I2C2 clock enable */
constexpr inline std::uint32_t kI2c3 = hardware::SYSAHBCLKCTRL0::kI2C3;        /*!< I2C3 clock enable */
constexpr inline std::uint32_t kAdc = hardware::SYSAHBCLKCTRL0::kADC;          /*!< ADC clock enable */
constexpr inline std::uint32_t kCtimer0 = hardware::SYSAHBCLKCTRL0::kCTIMER0;  /*!< CTIMER0 clock enable */
constexpr inline std::uint32_t kMtb = hardware::SYSAHBCLKCTRL0::kMTB;          /*!< MTB clock enable */
constexpr inline std::uint32_t kDac0 = hardware::SYSAHBCLKCTRL0::kDAC0;        /*!< DAC0 clock enable */
constexpr inline std::uint32_t kGpioInt = hardware::SYSAHBCLKCTRL0::kGPIO_INT; /*!< GPIO_INT clock enable */
constexpr inline std::uint32_t kDma = hardware::SYSAHBCLKCTRL0::kDMA;          /*!< DMA clock enable */
constexpr inline std::uint32_t kUart3 = hardware::SYSAHBCLKCTRL0::kUART3;      /*!< UART3 clock enable */
constexpr inline std::uint32_t kUart4 = hardware::SYSAHBCLKCTRL0::kUART4;      /*!< UART4 clock enable */
}  // namespace peripheral_clocks_0
/**
 * @brief Peripheral clock enable/disable options section 1
 */
namespace peripheral_clocks_1 {
constexpr inline std::uint32_t kCapt = hardware::SYSAHBCLKCTRL1::kCAPT; /*!< CAPT clock enable */
constexpr inline std::uint32_t kDac1 = hardware::SYSAHBCLKCTRL1::kDAC1; /*!< DAC1 clock enable */
}  // namespace peripheral_clocks_1
/**
 * @brief Peripheral power up/down options
 */
namespace power_options {
constexpr inline std::uint32_t kFroOut = hardware::PDRUNCFG::kFROOUT; /*!< FRO oscillator output power */
constexpr inline std::uint32_t kFro = hardware::PDRUNCFG::kFRO;       /*!< FRO oscillator power */
constexpr inline std::uint32_t kFlash = hardware::PDRUNCFG::kFLASH;   /*!< Flash power */
constexpr inline std::uint32_t kBod = hardware::PDRUNCFG::kBOD;       /*!< BOD power */
constexpr inline std::uint32_t kAdc = hardware::PDRUNCFG::kADC;       /*!< ADC power */
constexpr inline std::uint32_t kSysOsc = hardware::PDRUNCFG::kSYSOSC; /*!< Crystal oscillator power */
constexpr inline std::uint32_t kWdtOsc = hardware::PDRUNCFG::kWDTOSC; /*!< Watchdog oscillator power */
constexpr inline std::uint32_t kSysPll = hardware::PDRUNCFG::kSYSPLL; /*!< System PLL oscillator power */
constexpr inline std::uint32_t kDac0 = hardware::PDRUNCFG::kDAC0;     /*!< DAC0 power */
constexpr inline std::uint32_t kDac1 = hardware::PDRUNCFG::kDAC1;     /*!< DAC1 power */
constexpr inline std::uint32_t kAcmp = hardware::PDRUNCFG::kACMP;     /*!< ACMP power */
}  // namespace power_options
/**
 * @brief Clock output sources
 */
enum class ClockOutSources : std::uint32_t {
  kFro = hardware::CLKOUTSEL::kFRO,           /*!< FRO clock source */
  kMain = hardware::CLKOUTSEL::kMAIN,         /*!< Main clock source */
  kSysPll = hardware::CLKOUTSEL::kSYSPLL,     /*!< System PLL clock source */
  kExternal = hardware::CLKOUTSEL::kEXTERNAL, /*!< External clock source */
  kWatchdog = hardware::CLKOUTSEL::kWATCHDOG, /*!< Watchdog oscillator clock source */
};

template <libmcu::SysconBaseAddress syscon_address>
struct Syscon : libmcull::PeripheralBase {
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
  constexpr void SelectPllClock(PllClockSources setting) {
    GetPeripheral()->SYSPLLCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kNO_CHANGE;
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::kUPDATE;
  }
  /**
   * @brief Select main clock PLL source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void SelectMainPllClock(mainClockPllSources setting) {
    GetPeripheral()->MAINCLKPLLSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::kNO_CHANGE;
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::kUPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void SelectMainClock(mainClockSources setting) {
    GetPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kNO_CHANGE;
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::kUPDATE;
  }
  /**
   * @brief Set the AHB system clock Divider
   * @param setting divison factor, 0 is disable, 1 is 1, the maximum is 255
   */
  constexpr void SetMainClockDivider(std::uint32_t setting) {
    GetPeripheral()->SYSAHBCLKDIV = hardware::SYSAHBCLKDIV::DIV(setting);
  }
  /**
   * @brief Setup ADC clock
   * @param source clock source for the ADC
   * @param divisor clock pre divider for the ADC, zero disables the clock
   */
  constexpr void SetupAdcClock(AdcClockSources source, std::uint32_t divisor) {
    GetPeripheral()->ADCCLKDIV = divisor;
    GetPeripheral()->ADCCLKSEL = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief Setup SCT clock
   * @param source clock source for the SCT
   * @param divisor clock pre divider for the SCT, zero disables the clock
   */
  constexpr void SetupSctClock(SctClockSources source, std::uint32_t divisor) {
    GetPeripheral()->SCTCLKDIV = divisor;
    GetPeripheral()->SCTCLKSEL = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief enable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void EnablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    GetPeripheral()->SYSAHBCLKCTRL0 = GetPeripheral()->SYSAHBCLKCTRL0 | setting0;
    GetPeripheral()->SYSAHBCLKCTRL1 = GetPeripheral()->SYSAHBCLKCTRL1 | setting1;
  }
  /**
   * @brief disable peripheral clocks
   * @param setting bit setting from peripheralClocks
   */
  constexpr void DisablePeripheralClocks(std::uint32_t setting0, std::uint32_t setting1) {
    GetPeripheral()->SYSAHBCLKCTRL0 = GetPeripheral()->SYSAHBCLKCTRL0 & ~setting0;
    GetPeripheral()->SYSAHBCLKCTRL1 = GetPeripheral()->SYSAHBCLKCTRL1 & ~setting1;
  }
  /**
   * @brief reset a peripheral
   * @param setting0 bit setting from peripheralResets enum
   * @param setting1 bit setting from peripheralResets enum
   */
  constexpr void ResetPeripherals(std::uint32_t setting0, std::uint32_t setting1) {
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
  constexpr void PeripheralClockSource(ClockSourceSelects peripheral, ClockSources clock) {
    size_t index = static_cast<size_t>(peripheral);
    GetPeripheral()->FCLKSEL[index] = static_cast<std::uint32_t>(clock);
  }
  /**
   * @brief configure the clock output
   * @param source clock source to output
   * @param divisor divisor of the clock output
   */
  constexpr void SetClockOutput(ClockOutSources source, std::uint32_t divisor) {
    // disable clock to prevent overspeed
    GetPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(0);
    GetPeripheral()->CLKOUTSEL = static_cast<std::uint32_t>(source);
    GetPeripheral()->CLKOUTDIV = hardware::CLKOUTDIV::DIV(divisor);
  }
  /**
   * @brief Power up a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void PowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = (GetPeripheral()->PDRUNCFG & ~setting) | hardware::PDRUNCFG::kRESERVED_BITS;
  }
  /**
   * @brief Power down a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void DepowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG | setting;
  }
  /**
   * @brief Configure microcontroller clocks with mcuConfiguration settings
   * @tparam &config current configuration settings
   */
  template <const libmcuhw::clock::McuClockConfig &config = libmcuhw::clock::default_clock_config>
  constexpr void ConfigureMcuClocks() {
    // check if the wanted config is possible at all?
    static_assert(libmcuhw::clock::FindClockFrequency(config.GetSourceFreq(), config.GetSystemFreq()) != 0,
                  "Unable to find a clock configuration solution");
    // setup clock source
    if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::FRO) {
      //! @todo support 24MHz FRO frequency
      //! support romfunction FRO and get valid list of FRO frequency
      if constexpr (config.GetSourceFreq() == libmcuhw::clock::kFroDefaultClockFreq)
        SelectMainClock(mainClockSources::kFro);
      else
        static_assert(false, "Unsupported FRO frequency!");
    } else if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::XTAL) {
      if constexpr (config.GetSourceFreq() > 15'000'000) {
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::kNO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::kFREQ_15_25MHz);
      } else
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::kNO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::kFREQ_1_20MHz);
      PowerPeripherals(libmcull::syscon::power_options::kSysOsc);
      libmcu::Delay(3000);
      SelectMainClock(mainClockSources::kExt);
    }
    //! @todo handle WDT clock source
    //! @todo some peripherals can only use the PLL out as a clock source
    SelectMainPllClock(mainClockPllSources::kPrePll);
    // can we achieve the frequency we need without using the PLL?
    if constexpr (config.GetMainFreq() == config.GetSourceFreq()) {
      SetMainClockDivider(config.GetMainFreq() / config.GetSystemFreq());
    } else {
      if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::FRO) {
        SelectPllClock(libmcull::syscon::PllClockSources::kFro);
      } else if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::XTAL) {
        SelectPllClock(libmcull::syscon::PllClockSources::kExt);
      }
      DepowerPeripherals(libmcull::syscon::power_options::kSysPll);
      SetSystemPllControl(libmcuhw::clock::FindSystemPllMsel(config.GetSourceFreq(), config.GetMainFreq()),
                          static_cast<libmcull::syscon::PllPostDividers>(libmcuhw::clock::FindSystemPllPsel(config.GetMainFreq())));
      PowerPeripherals(libmcull::syscon::power_options::kSysPll);
      while (GetSystemPllStatus() == 0)
        ;
      SetMainClockDivider(config.GetMainFreq() / config.GetSystemFreq());
      SelectMainPllClock(libmcull::syscon::mainClockPllSources::kSysPll);
    }
  }
  /**
   * @brief Configure peripheral clock with configuration settings
   * @tparam &config configuration for this peripheral
   * @todo add more peripherals
   */
  template <const libmcuhw::clock::PeriClockConfig &config>
  constexpr void ConfigurePeripheralClock() {
    if constexpr (config.peripheral == libmcuhw::clock::PeriSelect::UART0) {
      if constexpr (config.source == libmcuhw::clock::PeriSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kFRO;
      else if constexpr (config.source == libmcuhw::clock::PeriSource::MAIN)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kMAIN;
      else
        static_assert(false, "Unsupported clock source for UART0!");
    } else if constexpr (config.peripheral == libmcuhw::clock::PeriSelect::UART1) {
      if constexpr (config.source == libmcuhw::clock::PeriSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::kUART0] = hardware::FCLKSEL::kFRO;
      else if constexpr (config.source == libmcuhw::clock::PeriSource::MAIN)
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
  constexpr std::uint32_t GetChipId(void) {
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