/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Resets software interface
 */
#ifndef RP2040_RESETS_SW_HPP
#define RP2040_RESETS_SW_HPP

namespace libMcuLL::sw::resets {
enum peripheralResets : std::uint32_t {
  USBCTRL = hw::resets::RESET::USBCTRL,       /**< USB controller reset bit */
  UART1 = hw::resets::RESET::UART1,           /**< UART 1 reset bit */
  UART0 = hw::resets::RESET::UART0,           /**< UART 0 reset bit */
  TIMER = hw::resets::RESET::TIMER,           /**< Timer reset bit */
  TBMAN = hw::resets::RESET::TBMAN,           /**< Test Bench manager reset bit */
  SYSINFO = hw::resets::RESET::SYSINFO,       /**< System information reset bit */
  SYSCFG = hw::resets::RESET::SYSCFG,         /**< System configuration reset bit */
  SPI1 = hw::resets::RESET::SPI1,             /**< SPI 1 reset bit */
  SPI0 = hw::resets::RESET::SPI0,             /**< SPI 0 reset bit */
  RTC = hw::resets::RESET::RTC,               /**< RTC reset bit */
  PWM = hw::resets::RESET::PWM,               /**< PWM reset bit */
  PLL_USB = hw::resets::RESET::PLL_USB,       /**< USB PLL reset bit */
  PLL_SYS = hw::resets::RESET::PLL_SYS,       /**< System PLL reset bit */
  PIO1 = hw::resets::RESET::PIO1,             /**< PIO1 reset bit */
  PIO0 = hw::resets::RESET::PIO0,             /**< PIO0 reset bit */
  PADS_QSPI = hw::resets::RESET::PADS_QSPI,   /**< Pads QSPI reset bit */
  PADS_BANK0 = hw::resets::RESET::PADS_BANK0, /**< Pads Bank0 reset bit */
  JTAG = hw::resets::RESET::JTAG,             /**< JTAG reset bit */
  IO_QSPI = hw::resets::RESET::IO_QSPI,       /**< IO QSPI reset bit */
  IO_BANK0 = hw::resets::RESET::IO_BANK0,     /**< IO BANK0 reset bit */
  I2C1 = hw::resets::RESET::I2C1,             /**< I2C 1 reset bit */
  I2C0 = hw::resets::RESET::I2C0,             /**< I2C 0 reset bit */
  DMA = hw::resets::RESET::DMA,               /**< DMA reset bit */
  BUSCTRL = hw::resets::RESET::BUSCTRL,       /**< Buscontrol reset bit */
  ADC = hw::resets::RESET::ADC,               /**< ADC reset bit */
};
/**
 * @brief resets peripheral
 * @tparam resetsAddress_  base resets peripheral address
 */
template <libMcuLL::resetsBaseAddress const& resetsAddress_>
struct resets : libMcuLL::peripheralBase {
  /**
   * @brief Resets peripherals and waits until they have been reset
   * @param peripheralBits     bit set of peripherals to reset, see RESETS_RESET_Enum for peripherals
   * @param timeout     how many times to check if the status set
   * @return         returns zero when timed out or nonzero when resets are executed
   */
  constexpr inline std::uint32_t reset(uint32_t peripheralBits, uint32_t timeout) {
    resetsPeripheralSet()->RESET = peripheralBits;
    resetsPeripheralClear()->RESET = peripheralBits;
    // wait until resets have arrived
    while ((~resetsPeripheral()->RESET_DONE & peripheralBits) && (timeout > 0)) {
      timeout--;
    }
    return timeout;
  }
  /**
   * @brief get registers from peripheral for normal access
   * @return return pointer to peripheral
   */
  static hw::resets::peripheral* resetsPeripheral() {
    return reinterpret_cast<hw::resets::peripheral*>(resetsAddress + hw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::resets::peripheral* resetsPeripheralSet() {
    return reinterpret_cast<hw::resets::peripheral*>(resetsAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::resets::peripheral* resetsPeripheralClear() {
    return reinterpret_cast<hw::resets::peripheral*>(resetsAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::resets::peripheral* resetsPeripheralXor() {
    return reinterpret_cast<hw::resets::peripheral*>(resetsAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType resetsAddress{resetsAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::resets
#endif