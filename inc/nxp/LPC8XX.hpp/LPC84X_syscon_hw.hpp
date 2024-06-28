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

/**
 * @brief sysctl register definitions
 *
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
  volatile std::uint32_t IOCONCLKDIV5;       /**< Peripheral clock 6 to the IOCON block for programmable glitch filter */
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
namespace PRESETCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'FFFFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t SPI0_RST_N{1u << 0};         /**< SPI0 reset */
constexpr inline std::uint32_t SPI1_RST_N{1u << 1};         /**< SPI1 reset */
constexpr inline std::uint32_t UARTFRG_RST_N{1u << 2};      /**< UART FRG reset */
constexpr inline std::uint32_t UART0_RST_N{1u << 3};        /**< UART0 reset */
constexpr inline std::uint32_t UART1_RST_N{1u << 4};        /**< UART1 reset */
constexpr inline std::uint32_t UART2_RST_N{1u << 5};        /**< UART2 reset */
constexpr inline std::uint32_t I2C_RST_N{1u << 6};          /**< I2C reset */
constexpr inline std::uint32_t MRT_RST_N{1u << 7};          /**< MRT reset */
constexpr inline std::uint32_t SCT_RST_N{1u << 8};          /**< SCT reset */
constexpr inline std::uint32_t WKT_RST_N{1u << 9};          /**< WKT reset */
constexpr inline std::uint32_t GPIO_RST_N{1u << 10};        /**< GPIO reset */
constexpr inline std::uint32_t FLASH_RST_N{1u << 11};       /**< FLASH reset */
constexpr inline std::uint32_t ACMP_RST_N{1u << 12};        /**< ACMP reset */
}  // namespace PRESETCTRL
namespace SYSPLLCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'007Fu}; /**< register mask for allowed bits */
/**
 * @brief Format feedback divider value
 *
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
constexpr inline std::uint32_t LOCK{1u << 0};               /**< PLL lock status */
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
 *
 * @param divider divider for Fclkana, 0 is 2, 1 is 4 and 31 is 64
 * @return formatted data for DIVSEL
 */
constexpr inline std::uint32_t DIVSEL(std::uint32_t divider) {
  return divider << 0;
}
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
constexpr inline std::uint32_t SEL_IRC{0u << 0};            /**< PLL clock source is IRC */
constexpr inline std::uint32_t SEL_SYSOSC{1u << 0};         /**< PLL clock source is crystal oscillator */
constexpr inline std::uint32_t SEL_CLKIN{3u << 0};          /**< PLL clock source is external clock input */
}  // namespace SYSPLLCLKSEL
namespace SYSPLLCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE{0u << 0};          /**< No change of clock source */
constexpr inline std::uint32_t UPDATE{1u << 0};             /**< update clock source */
}  // namespace SYSPLLCLKUEN
namespace MAINCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t SEL_IRC{0u << 0};            /**< main clock source is IRC */
constexpr inline std::uint32_t SEL_PLL_IN{1u << 0};         /**< main clock source is PLL input */
constexpr inline std::uint32_t SEL_WDTOSC{2u << 0};         /**< main clock source is WDT oscillator */
constexpr inline std::uint32_t SEL_PLL_OUT{3u << 0};        /**< main clock source is PLL output */
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
 *
 * @param divider 0 is system clock disabled, 1 divide by 1, 255 divide by 255
 * @return formatted data for SYSAHBCLKDIV
 */
constexpr inline std::uint32_t DIV(std::uint32_t divider) {
  return divider << 0;
}
}  // namespace SYSAHBCLKDIV
namespace SYSAHBCLKCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x000F'FFFFu}; /**< register mask for allowed bits */
}  // namespace SYSAHBCLKCTRL
namespace UARTCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< register mask for allowed bits */
}
namespace CLKOUTSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace CLKOUTUEN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace CLKOUTDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace UARTFRGDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace UARTFRGMULT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace EXTTRACECMD {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
namespace PIOPORCAP0 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
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
constexpr inline std::uint32_t RESERVED_MASK{0x0000'80EFu}; /**< register mask for allowed bits */
}
namespace DEVICEID {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}
}  // namespace libMcu::hw::syscon
#endif