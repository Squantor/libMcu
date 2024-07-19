/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 system control GPIO register interface
 */
#ifndef LPC84X_SYSCON_HW_HPP
#define LPC84X_SYSCON_HW_HPP

namespace libMcu::hw::syscon {

enum class clockSourceSelects : std::size_t {
  UART0 = 0u,
  UART1 = 1u,
  UART2 = 2u,
  UART3 = 3u,
  UART4 = 4u,
};

/**
 * @brief sysctl register definitions
 */
struct peripheral {
  volatile std::uint32_t SYSMEMREMAP;        /**< System Remap register */
  std::uint8_t RESERVED_0[4];                /**< Reserved */
  volatile std::uint32_t SYSPLLCTRL;         /**< PLL control */
  volatile const std::uint32_t SYSPLLSTAT;   /**< PLL status */
  std::uint8_t RESERVED_1[16];               /**< Reserved */
  volatile std::uint32_t SYSOSCCTRL;         /**< system oscillator control */
  volatile std::uint32_t WDTOSCCTRL;         /**< Watchdog oscillator control */
  volatile std::uint32_t FROOSCCTRL;         /**< FRO oscillator control */
  std::uint8_t RESERVED_2[4];                /**< Reserved */
  volatile std::uint32_t FRODIRECTCLKUEN;    /**< FRO direct clock source update enable register */
  std::uint8_t RESERVED_3[4];                /**< Reserved */
  volatile std::uint32_t SYSRSTSTAT;         /**< System reset status register */
  std::uint8_t RESERVED_4[4];                /**< Reserved */
  volatile std::uint32_t SYSPLLCLKSEL;       /**< System PLL clock source select register */
  volatile std::uint32_t SYSPLLCLKUEN;       /**< System PLL clock source update enable register */
  volatile std::uint32_t MAINCLKPLLSEL;      /**< Main clock source select register */
  volatile std::uint32_t MAINCLKPLLUEN;      /**< Main clock source update enable register */
  volatile std::uint32_t MAINCLKSEL;         /**< Main clock source select register */
  volatile std::uint32_t MAINCLKUEN;         /**< Main clock source update enable register */
  volatile std::uint32_t SYSAHBCLKDIV;       /**< System clock divider register */
  std::uint8_t RESERVED_5[4];                /**< Reserved */
  volatile std::uint32_t CAPTCLKSEL;         /**< CAPT clock source select register */
  volatile std::uint32_t ADCCLKSEL;          /**< ADC clock source select register */
  volatile std::uint32_t ADCCLKDIV;          /**< ADC clock divider register */
  volatile std::uint32_t SCTCLKSEL;          /**< SCT clock source select register */
  volatile std::uint32_t SCTCLKDIV;          /**< SCT clock divider register */
  volatile std::uint32_t EXTCLKSEL;          /**< external clock source select register */
  std::uint8_t RESERVED_6[8];                /**< Reserved */
  volatile std::uint32_t SYSAHBCLKCTRL0;     /**< System clock group 0 control register */
  volatile std::uint32_t SYSAHBCLKCTRL1;     /**< System clock group 1 control register */
  volatile std::uint32_t PRESETCTRL0;        /**< Peripheral reset group 0 control register */
  volatile std::uint32_t PRESETCTRL1;        /**< Peripheral reset group 1 control register */
  volatile std::uint32_t FCLKSEL[11];        /**< peripheral clock source select register */
  std::uint8_t RESERVED_7[20];               /**< Reserved */
  struct {                                   /* */
    volatile std::uint32_t FRGDIV;           /**< fractional generator N divider value register */
    volatile std::uint32_t FRGMULT;          /**< fractional generator N multiplier value register */
    volatile std::uint32_t FRGCLKSEL;        /**< FRG N clock source select register */
    std::uint8_t RESERVED_0[4];              /**< Reserved */
  } FRG[2];                                  /**< Fractional Generator array */
  volatile std::uint32_t CLKOUTSEL;          /**< CLKOUT clock source select register */
  volatile std::uint32_t CLKOUTDIV;          /**< CLKOUT clock divider registers */
  std::uint8_t RESERVED_8[4];                /**< Reserved */
  volatile std::uint32_t EXTTRACECMD;        /**< External trace buffer command register */
  volatile const std::uint32_t PIOPORCAP[2]; /**< POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs) */
  std::uint8_t RESERVED_9[44];               /**< Reserved */
  volatile std::uint32_t IOCONCLKDIV6;       /**< Peripheral clock 6 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV5;       /**< Peripheral clock 5 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV4;       /**< Peripheral clock 4 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV3;       /**< Peripheral clock 3 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV2;       /**< Peripheral clock 2 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV1;       /**< Peripheral clock 1 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t IOCONCLKDIV0;       /**< Peripheral clock 0 to the IOCON block for programmable glitch filter */
  volatile std::uint32_t BODCTRL;            /**< BOD control register */
  volatile std::uint32_t SYSTCKCAL;          /**< System tick timer calibration register */
  std::uint8_t RESERVED_10[24];              /**< Reserved */
  volatile std::uint32_t IRQLATENCY;         /**< IRQ latency register */
  volatile std::uint32_t NMISRC;             /**< NMI source selection register */
  volatile std::uint32_t PINTSEL[8];         /**< Pin interrupt select registers N, array offset */
  std::uint8_t RESERVED_11[108];             /**< Reserved */
  volatile std::uint32_t STARTERP0;          /**< Start logic 0 pin wake-up enable register 0 */
  std::uint8_t RESERVED_12[12];              /**< Reserved */
  volatile std::uint32_t STARTERP1;          /**< Start logic 0 pin wake-up enable register 1 */
  std::uint8_t RESERVED_13[24];              /**< Reserved */
  volatile std::uint32_t PDSLEEPCFG;         /**< Deep-sleep configuration register */
  volatile std::uint32_t PDAWAKECFG;         /**< Wake-up configuration register */
  volatile std::uint32_t PDRUNCFG;           /**< Power configuration register */
  std::uint8_t RESERVED_14[444];             /**< Reserved */
  volatile const std::uint32_t DEVICE_ID;    /**< Part ID register */
};
namespace SYSMEMREMAP {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MAP_BOOT{0u << 0};           /**< Map interrupts to boot ROM */
constexpr inline std::uint32_t MAP_RAM{1u << 0};            /**< Map interrupts to RAM */
constexpr inline std::uint32_t MAP_FLASH{2u << 0};          /**< Map interrupts to flash */
}  // namespace SYSMEMREMAP
namespace SYSPLLCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'007Fu}; /**< register mask for allowed bits */
/**
 * @brief Format feedback divider value
 * @param divider feedback divider value, 0 is division by 1 to 31 is division by 32
 * @return formatted data for SYSPLLCTRL
 */
constexpr inline std::uint32_t MSEL(std::uint32_t divider) {
  return divider << 0;
}
constexpr inline std::uint32_t PSEL_DIV2{0u << 5};  /**< Post divider of 2 */
constexpr inline std::uint32_t PSEL_DIV4{1u << 5};  /**< Post divider of 4 */
constexpr inline std::uint32_t PSEL_DIV8{2u << 5};  /**< Post divider of 8 */
constexpr inline std::uint32_t PSEL_DIV16{3u << 5}; /**< Post divider of 16 */
}  // namespace SYSPLLCTRL
namespace SYSPLLSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t LOCK_MASK{1u << 0};          /**< PLL lock status */
}  // namespace SYSPLLSTAT
namespace SYSOSCCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_BYPASS{0u << 0};          /**< PLL input is fed by crystal oscillator */
constexpr inline std::uint32_t BYPASS{1u << 0};             /**< PLL input is fed directly by XTALIN */
constexpr inline std::uint32_t FREQ_1_20MHz{0u << 1};       /**< crystal range is 1 to 20MHz */
constexpr inline std::uint32_t FREQ_15_25MHz{1u << 1};      /**< crystal range is 15 to 25MHz */
}  // namespace SYSOSCCTRL
namespace WDTOSCCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< register mask for allowed bits */
/**
 * @brief Format divider for Fclkana
 * @param divider divider for Fclkana, 0 is 2, 1 is 4 and 31 is 64
 * @return formatted data for DIVSEL
 */
constexpr inline std::uint32_t DIVSEL(std::uint32_t divider) {
  return divider << 0;
}
constexpr inline std::uint32_t FREQSEL_0_0MHZ{0u << 5};   /**< Fclkana is 0.0 MHz */
constexpr inline std::uint32_t FREQSEL_0_6MHZ{1u << 5};   /**< Fclkana is 0.6 MHz */
constexpr inline std::uint32_t FREQSEL_1_05MHZ{2u << 5};  /**< Fclkana is 1.05 MHz */
constexpr inline std::uint32_t FREQSEL_1_4MHZ{3u << 5};   /**< Fclkana is 1.4 MHz */
constexpr inline std::uint32_t FREQSEL_1_75MHZ{4u << 5};  /**< Fclkana is 1.75 MHz */
constexpr inline std::uint32_t FREQSEL_2_1MHZ{5u << 5};   /**< Fclkana is 2.1 MHz */
constexpr inline std::uint32_t FREQSEL_2_4MHZ{6u << 5};   /**< Fclkana is 2.4 MHz */
constexpr inline std::uint32_t FREQSEL_2_7MHZ{7u << 5};   /**< Fclkana is 2.7 MHz */
constexpr inline std::uint32_t FREQSEL_3_0MHZ{8u << 5};   /**< Fclkana is 3.0 MHz */
constexpr inline std::uint32_t FREQSEL_3_25MHZ{9u << 5};  /**< Fclkana is 3.25 MHz */
constexpr inline std::uint32_t FREQSEL_3_5MHZ{10u << 5};  /**< Fclkana is 3.5 MHz */
constexpr inline std::uint32_t FREQSEL_3_75MHZ{11u << 5}; /**< Fclkana is 3.75 MHz */
constexpr inline std::uint32_t FREQSEL_4_0MHZ{12u << 5};  /**< Fclkana is 4.0 MHz */
constexpr inline std::uint32_t FREQSEL_4_2MHZ{13u << 5};  /**< Fclkana is 4.2 MHz */
constexpr inline std::uint32_t FREQSEL_4_4MHZ{14u << 5};  /**< Fclkana is 4.4 MHz */
constexpr inline std::uint32_t FREQSEL_4_6MHZ{15u << 5};  /**< Fclkana is 4.6 MHz */
}  // namespace WDTOSCCTRL
namespace FROOSCCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace FRODIRECTCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace SYSRSTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'001Fu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t POR{1u << 0};                /**< POR detected */
constexpr inline std::uint32_t EXTRST{1u << 1};             /**< reset detected */
constexpr inline std::uint32_t WDT{1u << 2};                /**< WDT reset detected */
constexpr inline std::uint32_t BOD{1u << 3};                /**< BOD reset detected */
constexpr inline std::uint32_t SYSRST{1u << 4};             /**< System reset detected */
}  // namespace SYSRSTSTAT
namespace SYSPLLCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t FRO{0u << 0};                /**< PLL clock source is FRO */
constexpr inline std::uint32_t EXT{1u << 0};                /**< PLL clock source is external clock */
constexpr inline std::uint32_t WDO{2u << 0};                /**< PLL clock source is watchdog oscillator */
constexpr inline std::uint32_t FRO_DIV{3u << 0};            /**< PLL clock source is FRO divider */
}  // namespace SYSPLLCLKSEL
namespace SYSPLLCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE{0u << 0};          /**< No change of clock source */
constexpr inline std::uint32_t UPDATE{1u << 0};             /**< update clock source */
}  // namespace SYSPLLCLKUEN
namespace MAINCLKPLLSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t PRE{0 << 0};                 /**< select clock before PLL */
constexpr inline std::uint32_t SYSPLL{1 << 0};              /**< select clock after PLL */
}  // namespace MAINCLKPLLSEL
namespace MAINCLKPLLUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE{0u << 0};          /**< No change of clock source */
constexpr inline std::uint32_t UPDATE{1u << 0};             /**< update clock source */
}  // namespace MAINCLKPLLUEN
namespace MAINCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t FRO{0u << 0};                /**< main clock source is FRO */
constexpr inline std::uint32_t EXT{1u << 0};                /**< main clock source is external clock */
constexpr inline std::uint32_t WDO{2u << 0};                /**< main clock source is WDT oscillator */
constexpr inline std::uint32_t FRO_DIV{3u << 0};            /**< main clock source is FRO/2 */
}  // namespace MAINCLKSEL
namespace MAINCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE{0u << 0};          /**< No change of clock source */
constexpr inline std::uint32_t UPDATE{1u << 0};             /**< update clock source */
}  // namespace MAINCLKUEN
namespace SYSAHBCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< register mask for allowed bits */
/**
 * @brief Format system clock divider
 * @param divider 0 is system clock disabled, 1 divide by 1, 255 divide by 255
 * @return formatted data for SYSAHBCLKDIV
 */
constexpr inline std::uint32_t DIV(std::uint32_t divider) {
  return divider << 0;
}
}  // namespace SYSAHBCLKDIV
namespace CAPTCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace ADCCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace ADCCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace SCTCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace SCTCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace EXTCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace SYSAHBCLKCTRL0 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFF7u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t SYS{1u << 0};                /**< core clock enable, read only */
constexpr inline std::uint32_t ROM{1u << 1};                /**< ROM clock enable */
constexpr inline std::uint32_t RAM0_1{1u << 2};             /**< SRAM clock enable */
constexpr inline std::uint32_t FLASH{1u << 4};              /**< FLASH clock enable */
constexpr inline std::uint32_t I2C0{1u << 5};               /**< I2C0 clock enable */
constexpr inline std::uint32_t GPIO0{1u << 6};              /**< GPIO0 clock enable */
constexpr inline std::uint32_t SWM{1u << 7};                /**< SWM clock enable */
constexpr inline std::uint32_t SCT{1u << 8};                /**< SCT clock enable */
constexpr inline std::uint32_t WKT{1u << 9};                /**< WKT clock enable */
constexpr inline std::uint32_t MRT{1u << 10};               /**< MRT clock enable */
constexpr inline std::uint32_t SPI0{1u << 11};              /**< SPI0 clock enable */
constexpr inline std::uint32_t SPI1{1u << 12};              /**< SPI1 clock enable */
constexpr inline std::uint32_t CRC{1u << 13};               /**< CRC clock enable */
constexpr inline std::uint32_t UART0{1u << 14};             /**< UART0 clock enable */
constexpr inline std::uint32_t UART1{1u << 15};             /**< UART1 clock enable */
constexpr inline std::uint32_t UART2{1u << 16};             /**< UART2 clock enable */
constexpr inline std::uint32_t WWDT{1u << 17};              /**< WWDT clock enable */
constexpr inline std::uint32_t IOCON{1u << 18};             /**< IOCON clock enable */
constexpr inline std::uint32_t ACMP{1u << 19};              /**< ACMP clock enable */
constexpr inline std::uint32_t GPIO1{1u << 20};             /**< GPIO1 clock enable */
constexpr inline std::uint32_t I2C1{1u << 21};              /**< I2C1 clock enable */
constexpr inline std::uint32_t I2C2{1u << 22};              /**< I2C2 clock enable */
constexpr inline std::uint32_t I2C3{1u << 23};              /**< I2C3 clock enable */
constexpr inline std::uint32_t ADC{1u << 24};               /**< ADC clock enable */
constexpr inline std::uint32_t CTIMER0{1u << 25};           /**< CTIMER0 clock enable */
constexpr inline std::uint32_t MTB{1u << 26};               /**< MTB clock enable */
constexpr inline std::uint32_t DAC0{1u << 27};              /**< DAC0 clock enable */
constexpr inline std::uint32_t GPIO_INT{1u << 28};          /**< GPIO_INT clock enable */
constexpr inline std::uint32_t DMA{1u << 29};               /**< DMA clock enable */
constexpr inline std::uint32_t UART3{1u << 30};             /**< UART3 clock enable */
constexpr inline std::uint32_t UART4{1u << 31};             /**< UART4 clock enable */
}  // namespace SYSAHBCLKCTRL0
namespace SYSAHBCLKCTRL1 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t CAPT{1u << 0};               /**< CAPT clock enable, read only */
constexpr inline std::uint32_t DAC1{1u << 1};               /**< DAC1 clock enable */
}  // namespace SYSAHBCLKCTRL1
namespace PRESETCTRL0 {
constexpr inline std::uint32_t RESERVED_MASK{0xFBFD'FFF0u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t FLASH{1u << 4};              /**< FLASH reset control */
constexpr inline std::uint32_t I2C0{1u << 5};               /**< I2C0 reset control */
constexpr inline std::uint32_t GPIO0{1u << 6};              /**< GPIO0 reset control */
constexpr inline std::uint32_t SWM{1u << 7};                /**< SWM reset control */
constexpr inline std::uint32_t SCT{1u << 8};                /**< SCT reset control */
constexpr inline std::uint32_t WKT{1u << 9};                /**< WKT reset control */
constexpr inline std::uint32_t MRT{1u << 10};               /**< MRT reset control */
constexpr inline std::uint32_t SPI0{1u << 11};              /**< SPI0 reset control */
constexpr inline std::uint32_t SPI1{1u << 12};              /**< SPI1 reset control */
constexpr inline std::uint32_t CRC{1u << 13};               /**< CRC reset control */
constexpr inline std::uint32_t UART0{1u << 14};             /**< UART0 reset control */
constexpr inline std::uint32_t UART1{1u << 15};             /**< UART1 reset control */
constexpr inline std::uint32_t UART2{1u << 16};             /**< UART2 reset control */
constexpr inline std::uint32_t IOCON{1u << 18};             /**< IOCON reset control */
constexpr inline std::uint32_t ACMP{1u << 19};              /**< ACMP reset control */
constexpr inline std::uint32_t GPIO1{1u << 20};             /**< GPIO1 reset control */
constexpr inline std::uint32_t I2C1{1u << 21};              /**< I2C1 reset control */
constexpr inline std::uint32_t I2C2{1u << 22};              /**< I2C2 reset control */
constexpr inline std::uint32_t I2C3{1u << 23};              /**< I2C3 reset control */
constexpr inline std::uint32_t ADC{1u << 24};               /**< ADC reset control */
constexpr inline std::uint32_t CTIMER0{1u << 25};           /**< CTIMER0 reset control */
constexpr inline std::uint32_t DAC0{1u << 27};              /**< DAC0 reset control */
constexpr inline std::uint32_t GPIOINT{1u << 28};           /**< GPIOINT reset control */
constexpr inline std::uint32_t DMA{1u << 29};               /**< DMA reset control */
constexpr inline std::uint32_t UART3{1u << 30};             /**< UART3 reset control */
constexpr inline std::uint32_t UART4{1u << 31};             /**< UART4 reset control */
}  // namespace PRESETCTRL0
namespace PRESETCTRL1 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t CAPT{1u << 0};               /**< CAPT reset control */
constexpr inline std::uint32_t DAC1{1u << 1};               /**< DAC1 reset control */
constexpr inline std::uint32_t FRG0{1u << 3};               /**< Fractional baud rate generator 0 reset control */
constexpr inline std::uint32_t FRG1{1u << 4};               /**< Fractional baud rate generator 1 reset control */
}  // namespace PRESETCTRL1
namespace FCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0007u}; /**< register mask for allowed bits */
constexpr inline std::size_t UART0{0u};                     /**< UART0 clock select index */
constexpr inline std::size_t UART1{1u};                     /**< UART1 clock select index */
constexpr inline std::size_t UART2{2u};                     /**< UART2 clock select index */
constexpr inline std::size_t UART3{3u};                     /**< UART3 clock select index */
constexpr inline std::size_t UART4{4u};                     /**< UART4 clock select index */
constexpr inline std::size_t I2C0{5u};                      /**< I2C0 clock select index */
constexpr inline std::size_t I2C1{6u};                      /**< I2C1 clock select index */
constexpr inline std::size_t I2C2{7u};                      /**< I2C2 clock select index */
constexpr inline std::size_t I2C3{8u};                      /**< I2C3 clock select index */
constexpr inline std::size_t SPI0{9u};                      /**< SPI0 clock select index */
constexpr inline std::size_t SPI1{10u};                     /**< SPI1 clock select index */
constexpr inline std::uint32_t FRO{0u << 0};                /**< FRO clock select */
constexpr inline std::uint32_t MAIN{1u << 0};               /**< Main clock select */
constexpr inline std::uint32_t FRG0{2u << 0};               /**< Fractional generator 0 clock select */
constexpr inline std::uint32_t FRG1{3u << 0};               /**< Fractional generator 1 clock select */
constexpr inline std::uint32_t FRO_DIV{4u << 0};            /**< FRO divided by 2 clock select */
constexpr inline std::uint32_t NONE{7u << 0};               /**< No clock selected */
}  // namespace FCLKSEL
namespace FRGDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace FRGMULT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace FRGCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace CLKOUTSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0007u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t FRO{0u << 0};                /**< FRO */
constexpr inline std::uint32_t MAIN{1u << 0};               /**< Main clock */
constexpr inline std::uint32_t SYS_PLL{2u << 0};            /**< System PLL */
constexpr inline std::uint32_t EXTERNAL{3u << 0};           /**< External clock */
constexpr inline std::uint32_t WATCHDOG{4u << 0};           /**< Watchdog oscillator */
}  // namespace CLKOUTSEL
namespace CLKOUTDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< register mask for allowed bits */

/**
 * @brief Format clock output divider value
 * @param divisor divisor value for clock output
 * @return formatted divider value for CLKOUTDIV
 */
constexpr inline std::uint32_t DIV(std::uint32_t divisor) {
  return divisor << 0;
}
}  // namespace CLKOUTDIV
namespace EXTTRACECMD {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PIOPORCAP {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace IOCONCLKDIV6 {}
namespace IOCONCLKDIV5 {}
namespace IOCONCLKDIV4 {}
namespace IOCONCLKDIV3 {}
namespace IOCONCLKDIV2 {}
namespace IOCONCLKDIV1 {}
namespace IOCONCLKDIV0 {}
namespace IOCONCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace BODCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace SYSTCKCAL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace IRQLATENCY {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace NMISRC {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PINTSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace STARTERP0 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace STARTERP1 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PDSLEEPCFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PDAWAKECFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PDRUNCFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'E0FFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t RESERVED_BITS{0x0000'0D00u}; /**< Bits that need to always be set */
constexpr inline std::uint32_t FROOUT{1 << 0};              /**< FRO oscillator output power */
constexpr inline std::uint32_t FRO{1 << 1};                 /**< FRO oscillator power */
constexpr inline std::uint32_t FLASH{1 << 2};               /**< Flash power */
constexpr inline std::uint32_t BOD{1 << 3};                 /**< BOD power */
constexpr inline std::uint32_t ADC{1 << 4};                 /**< ADC power */
constexpr inline std::uint32_t SYSOSC{1 << 5};              /**< Crystal oscillator power */
constexpr inline std::uint32_t WDTOSC{1 << 6};              /**< Watchdog oscillator power */
constexpr inline std::uint32_t SYSPLL{1 << 7};              /**< System PLL oscillator power */
constexpr inline std::uint32_t DAC0{1 << 13};               /**< DAC0 power */
constexpr inline std::uint32_t DAC1{1 << 14};               /**< DAC1 power */
constexpr inline std::uint32_t ACMP{1 << 15};               /**< ACMP power */
}  // namespace PDRUNCFG
namespace DEVICEID {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace DEVICEID
}  // namespace libMcu::hw::syscon
#endif