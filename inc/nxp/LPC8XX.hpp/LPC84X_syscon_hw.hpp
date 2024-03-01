/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 system control GPIO register interface
 */
#ifndef LPC84X_SYSCON_REGS_HPP
#define LPC84X_SYSCON_REGS_HPP

namespace libMcuLL {
namespace hw {
namespace syscon {

/**
 * @brief sysctl register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t SYSMEMREMAP;    /**<  System memory remap (R/W) */
  volatile std::uint32_t PRESETCTRL;     /**<  Peripheral reset control (R/W) */
  volatile std::uint32_t SYSPLLCTRL;     /**<  System PLL control (R/W) */
  volatile std::uint32_t SYSPLLSTAT;     /**<  System PLL status (R/W ) */
  std::uint32_t RESERVED0[4];            /**< reserved */
  volatile std::uint32_t SYSOSCCTRL;     /**<  System oscillator control (R/W) */
  volatile std::uint32_t WDTOSCCTRL;     /**< Watchdog oscillator control (R/W) */
  volatile std::uint32_t RESERVED1[2];   /**< reserved */
  volatile std::uint32_t SYSRSTSTAT;     /**< System reset status Register (R/W ) */
  std::uint32_t RESERVED2[3];            /**< reserved */
  volatile std::uint32_t SYSPLLCLKSEL;   /**< System PLL clock source select (R/W) */
  volatile std::uint32_t SYSPLLCLKUEN;   /**< System PLL clock source update enable (R/W) */
  std::uint32_t RESERVED3[10];           /**< reserved */
  volatile std::uint32_t MAINCLKSEL;     /**< Main clock source select (R/W) */
  volatile std::uint32_t MAINCLKUEN;     /**< Main clock source update enable (R/W) */
  volatile std::uint32_t SYSAHBCLKDIV;   /**< System AHB clock divider (R/W) */
  std::uint32_t RESERVED4[1];            /**< reserved */
  volatile std::uint32_t SYSAHBCLKCTRL;  /**< System AHB clock control (R/W) */
  std::uint32_t RESERVED5[4];            /**< reserved */
  volatile std::uint32_t UARTCLKDIV;     /**< UART clock divider (R/W) */
  std::uint32_t RESERVED6[18];           /**< reserved */
  volatile std::uint32_t CLKOUTSEL;      /**< CLKOUT clock source select (R/W) */
  volatile std::uint32_t CLKOUTUEN;      /**< CLKOUT clock source update enable (R/W) */
  volatile std::uint32_t CLKOUTDIV;      /**< CLKOUT clock divider (R/W) */
  std::uint32_t RESERVED7;               /**< reserved */
  volatile std::uint32_t UARTFRGDIV;     /**< UART fractional divider SUB(R/W) */
  volatile std::uint32_t UARTFRGMULT;    /**< UART fractional divider ADD(R/W) */
  std::uint32_t RESERVED8[1];            /**< reserved */
  volatile std::uint32_t EXTTRACECMD;    /**< External trace buffer command register  */
  volatile std::uint32_t PIOPORCAP0;     /**< POR captured PIO status 0 (R/ ) */
  std::uint32_t RESERVED9[12];           /**< reserved */
  volatile std::uint32_t IOCONCLKDIV[7]; /**< Peripheral clock for IOCON block glitch filter */
  volatile std::uint32_t BODCTRL;        /**< BOD control (R/W) */
  volatile std::uint32_t SYSTCKCAL;      /**< System tick counter calibration (R/W) */
  std::uint32_t RESERVED10[6];           /**< reserved */
  volatile std::uint32_t IRQLATENCY;     /**< IRQ delay */
  volatile std::uint32_t NMISRC;         /**< NMI Source Control     */
  volatile std::uint32_t PINTSEL[8];     /**< GPIO Pin Interrupt Select register 0 */
  std::uint32_t RESERVED11[27];          /**< reserved */
  volatile std::uint32_t STARTERP0;      /**< Start logic signal enable Register 0 (R/W) */
  std::uint32_t RESERVED12[3];           /**< reserved */
  volatile std::uint32_t STARTERP1;      /**< Start logic signal enable Register 0 (R/W) */
  std::uint32_t RESERVED13[6];           /**< reserved */
  volatile std::uint32_t PDSLEEPCFG;     /**< Power-down states in Deep-sleep mode (R/W) */
  volatile std::uint32_t PDAWAKECFG;     /**< Power-down states after wake-up (R/W) */
  volatile std::uint32_t PDRUNCFG;       /**< Power-down configuration Register (R/W) */
  std::uint32_t RESERVED14[111];         /**< reserved */
  volatile const std::uint32_t DEVICEID; /**< Device ID (R/ ) */
};

namespace SYSMEMREMAP {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000003u; /**< register mask for allowed bits */
constexpr inline std::uint32_t MAP_BOOT = (0 << 0);         /**< Map interrupts to boot ROM */
constexpr inline std::uint32_t MAP_RAM = (1 << 0);          /**< Map interrupts to RAM */
constexpr inline std::uint32_t MAP_FLASH = (2 << 0);        /**< Map interrupts to flash */
}  // namespace SYSMEMREMAP
namespace PRESETCTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x0001FFFFu; /**< register mask for allowed bits */
constexpr inline std::uint32_t SPI0_RST_N = (1 << 0);       /**< SPI0 reset */
constexpr inline std::uint32_t SPI1_RST_N = (1 << 1);       /**< SPI1 reset */
constexpr inline std::uint32_t UARTFRG_RST_N = (1 << 2);    /**< UART FRG reset */
constexpr inline std::uint32_t UART0_RST_N = (1 << 3);      /**< UART0 reset */
constexpr inline std::uint32_t UART1_RST_N = (1 << 4);      /**< UART1 reset */
constexpr inline std::uint32_t UART2_RST_N = (1 << 5);      /**< UART2 reset */
constexpr inline std::uint32_t I2C_RST_N = (1 << 6);        /**< I2C reset */
constexpr inline std::uint32_t MRT_RST_N = (1 << 7);        /**< MRT reset */
constexpr inline std::uint32_t SCT_RST_N = (1 << 8);        /**< SCT reset */
constexpr inline std::uint32_t WKT_RST_N = (1 << 9);        /**< WKT reset */
constexpr inline std::uint32_t GPIO_RST_N = (1 << 10);      /**< GPIO reset */
constexpr inline std::uint32_t FLASH_RST_N = (1 << 11);     /**< FLASH reset */
constexpr inline std::uint32_t ACMP_RST_N = (1 << 12);      /**< ACMP reset */
}  // namespace PRESETCTRL
namespace SYSPLLCTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000007Fu; /**< register mask for allowed bits */
/**
 * @brief Format feedback divider value
 *
 * @param divider feedback divider value, 0 is division by 1 to 31 is division by 32
 * @return formatted data for SYSPLLCTRL
 */
constexpr inline std::uint32_t MSEL(std::uint32_t divider) {
  return divider << 0;
}
constexpr inline std::uint32_t PSEL_DIV2 = (0 << 5);  /**< Post divider of 2 */
constexpr inline std::uint32_t PSEL_DIV4 = (1 << 5);  /**< Post divider of 4 */
constexpr inline std::uint32_t PSEL_DIV8 = (2 << 5);  /**< Post divider of 8 */
constexpr inline std::uint32_t PSEL_DIV16 = (3 << 5); /**< Post divider of 16 */
}  // namespace SYSPLLCTRL
namespace SYSPLLSTAT {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000001u; /**< register mask for allowed bits */
constexpr inline std::uint32_t LOCK = (1 << 0);             /**< PLL lock status */
}  // namespace SYSPLLSTAT
namespace SYSOSCCTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000003u; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_BYPASS = (0 << 0);        /**< PLL input is fed by crystal oscillator */
constexpr inline std::uint32_t BYPASS = (1 << 0);           /**< PLL input is fed directly by XTALIN */
constexpr inline std::uint32_t FREQ_1_20MHz = (0 << 1);     /**< crystal range is 1 to 20MHz */
constexpr inline std::uint32_t FREQ_15_25MHz = (1 << 1);    /**< crystal range is 15 to 25MHz */
}  // namespace SYSOSCCTRL
namespace WDTOSCCTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x000001FFu; /**< register mask for allowed bits */
/**
 * @brief Format divider for Fclkana
 *
 * @param divider divider for Fclkana, 0 is 2, 1 is 4 and 31 is 64
 * @return formatted data for DIVSEL
 */
constexpr inline std::uint32_t DIVSEL(std::uint32_t divider) {
  return divider << 0;
}
constexpr inline std::uint32_t FREQSEL_0_6MHZ = (1 << 5);   /**< Fclkana is 0.6 MHz */
constexpr inline std::uint32_t FREQSEL_1_05MHZ = (2 << 5);  /**< Fclkana is 1.05 MHz */
constexpr inline std::uint32_t FREQSEL_1_4MHZ = (3 << 5);   /**< Fclkana is 1.4 MHz */
constexpr inline std::uint32_t FREQSEL_1_75MHZ = (4 << 5);  /**< Fclkana is 1.75 MHz */
constexpr inline std::uint32_t FREQSEL_2_1MHZ = (5 << 5);   /**< Fclkana is 2.1 MHz */
constexpr inline std::uint32_t FREQSEL_2_4MHZ = (6 << 5);   /**< Fclkana is 2.4 MHz */
constexpr inline std::uint32_t FREQSEL_2_7MHZ = (7 << 5);   /**< Fclkana is 2.7 MHz */
constexpr inline std::uint32_t FREQSEL_3_0MHZ = (8 << 5);   /**< Fclkana is 3.0 MHz */
constexpr inline std::uint32_t FREQSEL_3_25MHZ = (9 << 5);  /**< Fclkana is 3.25 MHz */
constexpr inline std::uint32_t FREQSEL_3_5MHZ = (10 << 5);  /**< Fclkana is 3.5 MHz */
constexpr inline std::uint32_t FREQSEL_3_75MHZ = (11 << 5); /**< Fclkana is 3.75 MHz */
constexpr inline std::uint32_t FREQSEL_4_0MHZ = (12 << 5);  /**< Fclkana is 4.0 MHz */
constexpr inline std::uint32_t FREQSEL_4_2MHZ = (13 << 5);  /**< Fclkana is 4.2 MHz */
constexpr inline std::uint32_t FREQSEL_4_4MHZ = (14 << 5);  /**< Fclkana is 4.4 MHz */
constexpr inline std::uint32_t FREQSEL_4_6MHZ = (15 << 5);  /**< Fclkana is 4.6 MHz */
}  // namespace WDTOSCCTRL
namespace SYSRSTSTAT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000001Fu; /**< register mask for allowed bits */
constexpr inline std::uint32_t POR = (1 << 0);              /**< POR detected */
constexpr inline std::uint32_t EXTRST = (1 << 1);           /**< reset detected */
constexpr inline std::uint32_t WDT = (1 << 2);              /**< WDT reset detected */
constexpr inline std::uint32_t BOD = (1 << 3);              /**< BOD reset detected */
constexpr inline std::uint32_t SYSRST = (1 << 4);           /**< System reset detected */
}  // namespace SYSRSTSTAT
namespace SYSPLLCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000003u; /**< register mask for allowed bits */
constexpr inline std::uint32_t SEL_IRC = (0 << 0);          /**< PLL clock source is IRC */
constexpr inline std::uint32_t SEL_SYSOSC = (1 << 0);       /**< PLL clock source is crystal oscillator */
constexpr inline std::uint32_t SEL_CLKIN = (3 << 0);        /**< PLL clock source is external clock input */
}  // namespace SYSPLLCLKSEL
namespace SYSPLLCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000001u; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE = (0 << 0);        /**< No change of clock source */
constexpr inline std::uint32_t UPDATE = (1 << 0);           /**< update clock source */
}  // namespace SYSPLLCLKUEN
namespace MAINCLKSEL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000003u; /**< register mask for allowed bits */
constexpr inline std::uint32_t SEL_IRC = (0 << 0);          /**< main clock source is IRC */
constexpr inline std::uint32_t SEL_PLL_IN = (1 << 0);       /**< main clock source is PLL input */
constexpr inline std::uint32_t SEL_WDTOSC = (2 << 0);       /**< main clock source is WDT oscillator */
constexpr inline std::uint32_t SEL_PLL_OUT = (3 << 0);      /**< main clock source is PLL output */
}  // namespace MAINCLKSEL
namespace MAINCLKUEN {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000001u; /**< register mask for allowed bits */
constexpr inline std::uint32_t NO_CHANGE = (0 << 0);        /**< No change of clock source */
constexpr inline std::uint32_t UPDATE = (1 << 0);           /**< update clock source */
}  // namespace MAINCLKUEN
namespace SYSAHBCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x000000FFu; /**< register mask for allowed bits */
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
constexpr inline std::uint32_t RESERVED_MASK = 0x000FFFFFu; /**< register mask for allowed bits */
}  // namespace SYSAHBCLKCTRL
namespace UARTCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x000000FFu; /**< register mask for allowed bits */
}
namespace CLKOUTSEL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace CLKOUTUEN {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace CLKOUTDIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace UARTFRGDIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace UARTFRGMULT {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace EXTTRACECMD {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace PIOPORCAP0 {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace IOCONCLKDIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace BODCTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace SYSTCKCAL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace IRQLATENCY {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace NMISRC {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace PINTSEL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace STARTERP0 {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace STARTERP1 {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace PDSLEEPCFG {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace PDAWAKECFG {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}
namespace PDRUNCFG {
constexpr inline std::uint32_t RESERVED_MASK = 0x000080EFu; /**< register mask for allowed bits */
}
namespace DEVICEID {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000u; /**< register mask for allowed bits */
}

}  // namespace syscon
}  // namespace hw
}  // namespace libMcuLL

#endif