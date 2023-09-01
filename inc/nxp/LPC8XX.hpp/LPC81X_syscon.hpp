/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series system control functions
 */
#ifndef LPC81X_SYSCON_HPP
#define LPC81X_SYSCON_HPP

namespace instances {
namespace syscon {
using namespace registers::syscon;

/**
 * @brief Peripheral reset options
 *
 * TODO, change name after all C dependencies are gone so you can use
 * proper name like SPI0 instead of SPI0_reset
 *
 */
enum peripheralResets : uint32_t {
  RESET_SPI0 = (1 << 0),    /**< SPI0 reset control */
  RESET_SPI1 = (1 << 1),    /**< SPI1 reset control */
  RESET_UARTFRG = (1 << 2), /**< UART fractional baud rate generator reset control */
  RESET_UART0 = (1 << 3),   /**< UART0 reset control */
  RESET_UART1 = (1 << 4),   /**< UART1 reset control */
  RESET_UART2 = (1 << 5),   /**< UART2 reset control */
  RESET_I2C = (1 << 6),     /**< I2C reset control */
  RESET_MRT = (1 << 7),     /**< MRT reset control */
  RESET_SCT = (1 << 8),     /**< SCT reset control */
  RESET_WKT = (1 << 9),     /**< WKT reset control */
  RESET_GPIO = (1 << 10),   /**< GPIO reset control */
  RESET_FLASH = (1 << 11),  /**< Flash reset control */
  RESET_ACMP = (1 << 12),   /**< ACMP reset control */
};

/**
 * @brief Peripheral power down reset options
 *
 * TODO, change name after all C dependencies are gone so you can use the proper names like
 * IRCOUT instead of POWER_IRCOUT_PD.
 *
 */
enum peripheralPowers : uint32_t {
  POWER_IRCOUT_PD = (1 << 0), /**< IRC oscillator output power */
  POWER_IRC_PD = (1 << 1),    /**< IRC oscillator power down */
  POWER_FLASH_PD = (1 << 2),  /**< Flash power down */
  POWER_BOD_PD = (1 << 3),    /**< BOD power down */
  POWER_SYSOSC_PD = (1 << 5), /**< Crystal oscillator powerdown */
  POWER_WDTOSC_PD = (1 << 6), /**< Watchdog oscillator powerdown */
  POWER_SYSPLL_PD = (1 << 7), /**< System PLL power down */
  POWER_ACMP_PD = (1 << 15),  /**< Analog comparator power down */
};

template <uint32_t base>
struct syscon {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  static registers::syscon::registers *regs() {
    return reinterpret_cast<registers::syscon::registers *>(base);
  }

  /**
   * @brief
   *
   * @param setting
   */
  void resetPeripherals(uint32_t setting) {
    regs()->PRESETCTRL = regs()->PRESETCTRL & ~setting;
    regs()->PRESETCTRL = regs()->PRESETCTRL | setting;
  }

  /**
   * @brief Power up a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void powerPeripherals(uint32_t setting) {
    regs()->PDRUNCFG = regs()->PDRUNCFG & ~(PDRUNCFG::MASK & setting);
  }

  /**
   * @brief Power down a peripheral
   *
   * @param setting bit setting from peripheralPowers enum
   */
  void depowerPeripherals(uint32_t setting) {
    regs()->PDRUNCFG = regs()->PDRUNCFG | (PDRUNCFG::MASK & setting);
  }

  /**
   * @brief Get the DEVICE ID
   *
   * @return chip id value
   * @return 0x00008100 is returned for LPC810M021FN8
   * @return 0x00008110 is returned for LPC811M001JDH16
   * @return 0x00008120 is returned for LPC812M101JDH16
   * @return 0x00008121 is returned for LPC812M101JD20
   * @return 0x00008122 is returned for LPC812M101JDH20
   * @return 0x00008122 is returned for LPC812M101JTB16
   */
  uint32_t getChipId(void) {
    return regs()->DEVICEID;
  }
};
}  // namespace syscon
}  // namespace instances

#endif