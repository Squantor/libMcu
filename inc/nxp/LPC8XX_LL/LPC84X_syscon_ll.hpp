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
constexpr inline std::uint32_t Flash = hardware::PRESETCTRL0::FLASH;     /*!< FLASH peripheral reset */
constexpr inline std::uint32_t I2c0 = hardware::PRESETCTRL0::I2C0;       /*!< I2C0 peripheral reset */
constexpr inline std::uint32_t Gpio0 = hardware::PRESETCTRL0::GPIO0;     /*!< GPIO0 peripheral reset */
constexpr inline std::uint32_t Swm = hardware::PRESETCTRL0::SWM;         /*!< SWM peripheral reset */
constexpr inline std::uint32_t Sct = hardware::PRESETCTRL0::SCT;         /*!< SCT peripheral reset */
constexpr inline std::uint32_t Wkt = hardware::PRESETCTRL0::WKT;         /*!< WKT peripheral reset */
constexpr inline std::uint32_t Mrt = hardware::PRESETCTRL0::MRT;         /*!< MRT peripheral reset */
constexpr inline std::uint32_t Spi0 = hardware::PRESETCTRL0::SPI0;       /*!< SPI0 peripheral reset */
constexpr inline std::uint32_t Spi1 = hardware::PRESETCTRL0::SPI1;       /*!< SPI1 peripheral reset */
constexpr inline std::uint32_t Crc = hardware::PRESETCTRL0::CRC;         /*!< CRC peripheral reset */
constexpr inline std::uint32_t Uart0 = hardware::PRESETCTRL0::UART0;     /*!< UART0 peripheral reset */
constexpr inline std::uint32_t Uart1 = hardware::PRESETCTRL0::UART1;     /*!< UART1 peripheral reset */
constexpr inline std::uint32_t Uart2 = hardware::PRESETCTRL0::UART2;     /*!< UART2 peripheral reset */
constexpr inline std::uint32_t Iocon = hardware::PRESETCTRL0::IOCON;     /*!< IOCON peripheral reset */
constexpr inline std::uint32_t Acmp = hardware::PRESETCTRL0::ACMP;       /*!< ACMP peripheral reset */
constexpr inline std::uint32_t Gpio1 = hardware::PRESETCTRL0::GPIO1;     /*!< GPIO1 peripheral reset */
constexpr inline std::uint32_t I2c1 = hardware::PRESETCTRL0::I2C1;       /*!< I2C1 peripheral reset */
constexpr inline std::uint32_t I2c2 = hardware::PRESETCTRL0::I2C2;       /*!< I2C2 peripheral reset */
constexpr inline std::uint32_t I2c3 = hardware::PRESETCTRL0::I2C3;       /*!< I2C3 peripheral reset */
constexpr inline std::uint32_t Adc = hardware::PRESETCTRL0::ADC;         /*!< ADC peripheral reset */
constexpr inline std::uint32_t Ctimer0 = hardware::PRESETCTRL0::CTIMER0; /*!< CTIMER0 peripheral reset */
constexpr inline std::uint32_t Dac0 = hardware::PRESETCTRL0::DAC0;       /*!< DAC0 peripheral reset */
constexpr inline std::uint32_t GpioInt = hardware::PRESETCTRL0::GPIOINT; /*!< GPIOINT peripheral reset */
constexpr inline std::uint32_t Dma = hardware::PRESETCTRL0::DMA;         /*!< DMA peripheral reset */
constexpr inline std::uint32_t Uart3 = hardware::PRESETCTRL0::UART3;     /*!< UART3 peripheral reset */
constexpr inline std::uint32_t Uart4 = hardware::PRESETCTRL0::UART4;     /*!< UART4 peripheral reset */
}  // namespace peripheral_resets_0
/**
 * @brief Peripheral resets for second setting
 */
namespace peripheral_resets_1 {
constexpr inline std::uint32_t Capt = hardware::PRESETCTRL1::CAPT; /*!< CAPT peripheral reset */
constexpr inline std::uint32_t Dac1 = hardware::PRESETCTRL1::DAC1; /*!< DAC1 peripheral reset */
constexpr inline std::uint32_t Frg0 = hardware::PRESETCTRL1::FRG0; /*!< FRG0 peripheral reset */
constexpr inline std::uint32_t Frg1 = hardware::PRESETCTRL1::FRG1; /*!< FRG1 peripheral reset */
}  // namespace peripheral_resets_1
/**
 * @brief PLL post divider options
 */
enum class PllPostDividers : std::uint32_t {
  Div2 = hardware::SYSPLLCTRL::PSEL_DIV2,   /*!< PLL post division ration of 2 */
  Div4 = hardware::SYSPLLCTRL::PSEL_DIV4,   /*!< PLL post division ration of 4 */
  Div8 = hardware::SYSPLLCTRL::PSEL_DIV8,   /*!< PLL post division ration of 8 */
  Div16 = hardware::SYSPLLCTRL::PSEL_DIV16, /*!< PLL post division ration of 16 */
};  // namespace pllPostDivider
/**
 * @brief PLL source options
 */
enum class PllClockSources : std::uint32_t {
  Fro = hardware::SYSPLLCLKSEL::FRO,       /*!< FRO clock source */
  Ext = hardware::SYSPLLCLKSEL::EXT,       /*!< External clock */
  Wdo = hardware::SYSPLLCLKSEL::WDO,       /*!< Watchdog oscillator*/
  FroDiv = hardware::SYSPLLCLKSEL::FRO_DIV /*!< FRO divided clock source */
};
/**
 * @brief main clock pll sources options
 */
enum class mainClockPllSources : std::uint32_t {
  PrePll = hardware::MAINCLKPLLSEL::PRE,    /*!< Select main clock before PLL*/
  SysPll = hardware::MAINCLKPLLSEL::SYSPLL, /*!< select main clock PLL*/
};  // namespace mainClockSources
/**
 * @brief main clock sources options
 */
enum class mainClockSources : std::uint32_t {
  Fro = hardware::MAINCLKSEL::FRO,        /*!< main clock source is FRO */
  Ext = hardware::MAINCLKSEL::EXT,        /*!< main clock source is external clock */
  Wdo = hardware::MAINCLKSEL::WDO,        /*!< main clock source is WDT oscillator */
  FroDiv = hardware::MAINCLKSEL::FRO_DIV, /*!< main clock source is FRO/2 */
};  // namespace mainClockSources
/**
 * @brief Peripherals to set the clock source of
 */
enum class ClockSourceSelects : std::uint32_t {
  Uart0 = hardware::FCLKSEL::UART0, /*!< UART0 clock select */
  Uart1 = hardware::FCLKSEL::UART1, /*!< UART1 clock select */
  Uart2 = hardware::FCLKSEL::UART2, /*!< UART2 clock select */
  Uart3 = hardware::FCLKSEL::UART3, /*!< UART3 clock select */
  Uart4 = hardware::FCLKSEL::UART4, /*!< UART4 clock select */
  I2c0 = hardware::FCLKSEL::I2C0,   /*!< I2C0 clock select */
  I2c1 = hardware::FCLKSEL::I2C1,   /*!< I2C1 clock select */
  I2c2 = hardware::FCLKSEL::I2C2,   /*!< I2C2 clock select */
  I2c3 = hardware::FCLKSEL::I2C3,   /*!< I2C3 clock select */
  Spi0 = hardware::FCLKSEL::SPI0,   /*!< SPI0 clock select */
  Spi1 = hardware::FCLKSEL::SPI1,   /*!< SPI1 clock select */
};
/**
 * @brief Peripheral clock options
 */
enum class ClockSources : std::uint32_t {
  Fro = hardware::FCLKSEL::FRO,        /*!< FRO clock source */
  Main = hardware::FCLKSEL::MAIN,      /*!< Main clock source */
  Frg0 = hardware::FCLKSEL::FRG0,      /*!< Fractional clock generator 0 */
  Frg1 = hardware::FCLKSEL::FRG1,      /*!< Fractional clock generator 1 */
  FroDiv = hardware::FCLKSEL::FRO_DIV, /*!< FRO divided by 2 clock source  */
  None = hardware::FCLKSEL::NONE,      /*!< No clock source */
};
/**
 * @brief ADC clock sources
 */
enum class AdcClockSources : std::uint32_t {
  Fro = hardware::ADCCLKSEL::FRO,       /*!< FRO clock source */
  SysPll = hardware::ADCCLKSEL::SYSPLL, /*!< System PLL clock source */
};
/**
 * @brief SCT clock sources
 */
enum class SctClockSources : std::uint32_t {
  Fro = hardware::SCTCLKSEL::FRO,       /*!< FRO clock source */
  Main = hardware::SCTCLKSEL::MAINCLK,  /*!< Main clock source */
  SysPll = hardware::SCTCLKSEL::SYSPLL, /*!< System PLL clock source */
};
/**
 * @brief Interrupt pins indices
 */
enum class InterruptPins : std::size_t {
  PintSel0 = hardware::PINTSEL::PINTSEL0, /*!< PINTSEL0 */
  PintSel1 = hardware::PINTSEL::PINTSEL1, /*!< PINTSEL1 */
  PintSel2 = hardware::PINTSEL::PINTSEL2, /*!< PINTSEL2 */
  PintSel3 = hardware::PINTSEL::PINTSEL3, /*!< PINTSEL3 */
  PintSel4 = hardware::PINTSEL::PINTSEL4, /*!< PINTSEL4 */
  PintSel5 = hardware::PINTSEL::PINTSEL5, /*!< PINTSEL5 */
  PintSel6 = hardware::PINTSEL::PINTSEL6, /*!< PINTSEL6 */
  PintSel7 = hardware::PINTSEL::PINTSEL7, /*!< PINTSEL7 */
};
/**
 * @brief Iocon glitch filter indices
 */
enum class IoconGlitchFilters : std::uint32_t {
  Filter0 = 6, /*!< Iocon glitch filter 0 */
  Filter1 = 5, /*!< Iocon glitch filter 1 */
  Filter2 = 4, /*!< Iocon glitch filter 2 */
  Filter3 = 3, /*!< Iocon glitch filter 3 */
  Filter4 = 2, /*!< Iocon glitch filter 4 */
  Filter5 = 1, /*!< Iocon glitch filter 5 */
  Filter6 = 0, /*!< Iocon glitch filter 6 */
};

/**
 * @brief Peripheral clock enable/disable options section 0
 */
namespace peripheral_clocks_0 {
constexpr inline std::uint32_t Rom = hardware::SYSAHBCLKCTRL0::ROM;          /*!< ROM clock enable */
constexpr inline std::uint32_t Ram = hardware::SYSAHBCLKCTRL0::RAM0_1;       /*!< RAM clock enable */
constexpr inline std::uint32_t Flash = hardware::SYSAHBCLKCTRL0::FLASH;      /*!< Flash clock enable */
constexpr inline std::uint32_t I2c0 = hardware::SYSAHBCLKCTRL0::I2C0;        /*!< I2C0 clock enable */
constexpr inline std::uint32_t Gpio0 = hardware::SYSAHBCLKCTRL0::GPIO0;      /*!< GPIO0 clock enable */
constexpr inline std::uint32_t Swm = hardware::SYSAHBCLKCTRL0::SWM;          /*!< SWM clock enable */
constexpr inline std::uint32_t Sct = hardware::SYSAHBCLKCTRL0::SCT;          /*!< SCT clock enable */
constexpr inline std::uint32_t Wkt = hardware::SYSAHBCLKCTRL0::WKT;          /*!< WKT clock enable */
constexpr inline std::uint32_t Mrt = hardware::SYSAHBCLKCTRL0::MRT;          /*!< MRT clock enable */
constexpr inline std::uint32_t Spi0 = hardware::SYSAHBCLKCTRL0::SPI0;        /*!< SPI0 clock enable */
constexpr inline std::uint32_t Spi1 = hardware::SYSAHBCLKCTRL0::SPI1;        /*!< SPI1 clock enable */
constexpr inline std::uint32_t Crc = hardware::SYSAHBCLKCTRL0::CRC;          /*!< CRC clock enable */
constexpr inline std::uint32_t Uart0 = hardware::SYSAHBCLKCTRL0::UART0;      /*!< UART0 clock enable */
constexpr inline std::uint32_t Uart1 = hardware::SYSAHBCLKCTRL0::UART1;      /*!< UART1 clock enable */
constexpr inline std::uint32_t Uart2 = hardware::SYSAHBCLKCTRL0::UART2;      /*!< UART2 clock enable */
constexpr inline std::uint32_t Wwdt = hardware::SYSAHBCLKCTRL0::WWDT;        /*!< WWDT clock enable */
constexpr inline std::uint32_t Iocon = hardware::SYSAHBCLKCTRL0::IOCON;      /*!< IOCON clock enable */
constexpr inline std::uint32_t Acmp = hardware::SYSAHBCLKCTRL0::ACMP;        /*!< ACMP clock enable */
constexpr inline std::uint32_t Gpio1 = hardware::SYSAHBCLKCTRL0::GPIO1;      /*!< GPIO1 clock enable */
constexpr inline std::uint32_t I2c1 = hardware::SYSAHBCLKCTRL0::I2C1;        /*!< I2C1 clock enable */
constexpr inline std::uint32_t I2c2 = hardware::SYSAHBCLKCTRL0::I2C2;        /*!< I2C2 clock enable */
constexpr inline std::uint32_t I2c3 = hardware::SYSAHBCLKCTRL0::I2C3;        /*!< I2C3 clock enable */
constexpr inline std::uint32_t Adc = hardware::SYSAHBCLKCTRL0::ADC;          /*!< ADC clock enable */
constexpr inline std::uint32_t Ctimer0 = hardware::SYSAHBCLKCTRL0::CTIMER0;  /*!< CTIMER0 clock enable */
constexpr inline std::uint32_t Mtb = hardware::SYSAHBCLKCTRL0::MTB;          /*!< MTB clock enable */
constexpr inline std::uint32_t Dac0 = hardware::SYSAHBCLKCTRL0::DAC0;        /*!< DAC0 clock enable */
constexpr inline std::uint32_t GpioInt = hardware::SYSAHBCLKCTRL0::GPIO_INT; /*!< GPIO_INT clock enable */
constexpr inline std::uint32_t Dma = hardware::SYSAHBCLKCTRL0::DMA;          /*!< DMA clock enable */
constexpr inline std::uint32_t Uart3 = hardware::SYSAHBCLKCTRL0::UART3;      /*!< UART3 clock enable */
constexpr inline std::uint32_t Uart4 = hardware::SYSAHBCLKCTRL0::UART4;      /*!< UART4 clock enable */
}  // namespace peripheral_clocks_0
/**
 * @brief Peripheral clock enable/disable options section 1
 */
namespace peripheral_clocks_1 {
constexpr inline std::uint32_t Capt = hardware::SYSAHBCLKCTRL1::CAPT; /*!< CAPT clock enable */
constexpr inline std::uint32_t Dac1 = hardware::SYSAHBCLKCTRL1::DAC1; /*!< DAC1 clock enable */
}  // namespace peripheral_clocks_1
/**
 * @brief Peripheral power up/down options
 */
namespace power_options {
constexpr inline std::uint32_t FroOut = hardware::PDRUNCFG::FROOUT; /*!< FRO oscillator output power */
constexpr inline std::uint32_t Fro = hardware::PDRUNCFG::FRO;       /*!< FRO oscillator power */
constexpr inline std::uint32_t Flash = hardware::PDRUNCFG::FLASH;   /*!< Flash power */
constexpr inline std::uint32_t Bod = hardware::PDRUNCFG::BOD;       /*!< BOD power */
constexpr inline std::uint32_t Adc = hardware::PDRUNCFG::ADC;       /*!< ADC power */
constexpr inline std::uint32_t SysOsc = hardware::PDRUNCFG::SYSOSC; /*!< Crystal oscillator power */
constexpr inline std::uint32_t WdtOsc = hardware::PDRUNCFG::WDTOSC; /*!< Watchdog oscillator power */
constexpr inline std::uint32_t SysPll = hardware::PDRUNCFG::SYSPLL; /*!< System PLL oscillator power */
constexpr inline std::uint32_t Dac0 = hardware::PDRUNCFG::DAC0;     /*!< DAC0 power */
constexpr inline std::uint32_t Dac1 = hardware::PDRUNCFG::DAC1;     /*!< DAC1 power */
constexpr inline std::uint32_t Acmp = hardware::PDRUNCFG::ACMP;     /*!< ACMP power */
}  // namespace power_options
/**
 * @brief Clock output sources
 */
enum class ClockOutSources : std::uint32_t {
  Fro = hardware::CLKOUTSEL::FRO,           /*!< FRO clock source */
  Main = hardware::CLKOUTSEL::MAIN,         /*!< Main clock source */
  SysPll = hardware::CLKOUTSEL::SYSPLL,     /*!< System PLL clock source */
  External = hardware::CLKOUTSEL::EXTERNAL, /*!< External clock source */
  Watchdog = hardware::CLKOUTSEL::WATCHDOG, /*!< Watchdog oscillator clock source */
};

template <libmcu::SysconBaseAddress syscon_address>
struct Syscon : libmcull::LowLevelBase {
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
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::NO_CHANGE;
    GetPeripheral()->SYSPLLCLKUEN = hardware::SYSPLLCLKUEN::UPDATE;
  }
  /**
   * @brief Select main clock PLL source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void SelectMainPllClock(mainClockPllSources setting) {
    GetPeripheral()->MAINCLKPLLSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::NO_CHANGE;
    GetPeripheral()->MAINCLKPLLUEN = hardware::MAINCLKPLLUEN::UPDATE;
  }
  /**
   * @brief Select main clock source
   * @param setting clock source from mainClockSources enum
   */
  constexpr void SelectMainClock(mainClockSources setting) {
    GetPeripheral()->MAINCLKSEL = static_cast<std::uint32_t>(setting);
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::NO_CHANGE;
    GetPeripheral()->MAINCLKUEN = hardware::MAINCLKUEN::UPDATE;
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
   * @brief Set the Iocon glitch filter divider
   * @param filter Iocon filter to configure
   * @param setting divisor setting from 0 (disabled) to 255
   */
  constexpr void SetIoconGlitchFiltDivider(IoconGlitchFilters filter, std::uint32_t setting) {
    GetPeripheral()->IOCONCLKDIV[static_cast<size_t>(filter)] = setting;
  }
  /**
   * @brief Set the Pin instance to the interrupt pin channel
   * @tparam Pin gpio pin instance type
   * @param pin gpio pin instance
   * @param channel interrupt pin channel to use
   */
  template <typename Pin>
  constexpr void SetInterruptPin(Pin &pin, InterruptPins channel) {
    GetPeripheral()->PINTSEL[static_cast<size_t>(channel)] = static_cast<std::uint32_t>(pin.interrupt_index);
  }
  /**
   * @brief Power up a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void PowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = (GetPeripheral()->PDRUNCFG & ~setting) | hardware::PDRUNCFG::RESERVED_BITS;
  }
  /**
   * @brief Power down a peripheral
   * @param setting bit setting from powerEnables enum
   */
  constexpr void DepowerPeripherals(std::uint32_t setting) {
    GetPeripheral()->PDRUNCFG = GetPeripheral()->PDRUNCFG | setting;
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
      if constexpr (config.GetSourceFreq() == libmcuhw::clock::FroDefaultClockFreq)
        SelectMainClock(mainClockSources::Fro);
      else
        static_assert(false, "Unsupported FRO frequency!");
    } else if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::XTAL) {
      if constexpr (config.GetSourceFreq() > 15'000'000) {
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::NO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::FREQ_15_25MHz);
      } else
        SetSysOscControl(libmcuhw::syscon::SYSOSCCTRL::NO_BYPASS | libmcuhw::syscon::SYSOSCCTRL::FREQ_1_20MHz);
      PowerPeripherals(libmcull::syscon::power_options::SysOsc);
      libmcu::Delay(3000);
      SelectMainClock(mainClockSources::Ext);
    }
    //! @todo handle WDT clock source
    //! @todo some peripherals can only use the PLL out as a clock source
    SelectMainPllClock(mainClockPllSources::PrePll);
    // can we achieve the frequency we need without using the PLL?
    if constexpr (config.GetMainFreq() == config.GetSourceFreq()) {
      SetMainClockDivider(config.GetMainFreq() / config.GetSystemFreq());
    } else {
      if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::FRO) {
        SelectPllClock(libmcull::syscon::PllClockSources::Fro);
      } else if constexpr (config.source_ == libmcuhw::clock::ClockInputSources::XTAL) {
        SelectPllClock(libmcull::syscon::PllClockSources::Ext);
      }
      DepowerPeripherals(libmcull::syscon::power_options::SysPll);
      SetSystemPllControl(libmcuhw::clock::FindSystemPllMsel(config.GetSourceFreq(), config.GetMainFreq()),
                          static_cast<libmcull::syscon::PllPostDividers>(libmcuhw::clock::FindSystemPllPsel(config.GetMainFreq())));
      PowerPeripherals(libmcull::syscon::power_options::SysPll);
      while (GetSystemPllStatus() == 0)
        ;
      SetMainClockDivider(config.GetMainFreq() / config.GetSystemFreq());
      SelectMainPllClock(libmcull::syscon::mainClockPllSources::SysPll);
    }
  }
  /**
   * @brief Configure peripheral clock with configuration settings
   * @tparam &config configuration for this peripheral
   * @todo add more peripherals
   */
  template <const auto &config>
  constexpr void ConfigurePeripheralClock() {
    if constexpr (config.peripheral == libmcuhw::clock::PeriSelect::UART0) {
      if constexpr (config.source == libmcuhw::clock::PeriSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::UART0] = hardware::FCLKSEL::FRO;
      else if constexpr (config.source == libmcuhw::clock::PeriSource::MAIN)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::UART0] = hardware::FCLKSEL::MAIN;
      else
        static_assert(false, "Unsupported clock source for UART0!");
    } else if constexpr (config.peripheral == libmcuhw::clock::PeriSelect::UART1) {
      if constexpr (config.source == libmcuhw::clock::PeriSource::FRO)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::UART0] = hardware::FCLKSEL::FRO;
      else if constexpr (config.source == libmcuhw::clock::PeriSource::MAIN)
        GetPeripheral()->FCLKSEL[hardware::FCLKSEL::UART0] = hardware::FCLKSEL::MAIN;
      else
        static_assert(false, "Unsupported clock source for UART1!");
    } else
      static_assert(false, "Unknown or unsupported peripheral!");
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