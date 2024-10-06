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
  USBCTRL = libMcuHw::resets::RESET::USBCTRL,       /**< USB controller reset bit */
  UART1 = libMcuHw::resets::RESET::UART1,           /**< UART 1 reset bit */
  UART0 = libMcuHw::resets::RESET::UART0,           /**< UART 0 reset bit */
  TIMER = libMcuHw::resets::RESET::TIMER,           /**< Timer reset bit */
  TBMAN = libMcuHw::resets::RESET::TBMAN,           /**< Test Bench manager reset bit */
  SYSINFO = libMcuHw::resets::RESET::SYSINFO,       /**< System information reset bit */
  SYSCFG = libMcuHw::resets::RESET::SYSCFG,         /**< System configuration reset bit */
  SPI1 = libMcuHw::resets::RESET::SPI1,             /**< SPI 1 reset bit */
  SPI0 = libMcuHw::resets::RESET::SPI0,             /**< SPI 0 reset bit */
  RTC = libMcuHw::resets::RESET::RTC,               /**< RTC reset bit */
  PWM = libMcuHw::resets::RESET::PWM,               /**< PWM reset bit */
  PLL_USB = libMcuHw::resets::RESET::PLL_USB,       /**< USB PLL reset bit */
  PLL_SYS = libMcuHw::resets::RESET::PLL_SYS,       /**< System PLL reset bit */
  PIO1 = libMcuHw::resets::RESET::PIO1,             /**< PIO1 reset bit */
  PIO0 = libMcuHw::resets::RESET::PIO0,             /**< PIO0 reset bit */
  PADS_QSPI = libMcuHw::resets::RESET::PADS_QSPI,   /**< Pads QSPI reset bit */
  PADS_BANK0 = libMcuHw::resets::RESET::PADS_BANK0, /**< Pads Bank0 reset bit */
  JTAG = libMcuHw::resets::RESET::JTAG,             /**< JTAG reset bit */
  IO_QSPI = libMcuHw::resets::RESET::IO_QSPI,       /**< IO QSPI reset bit */
  IO_BANK0 = libMcuHw::resets::RESET::IO_BANK0,     /**< IO BANK0 reset bit */
  I2C1 = libMcuHw::resets::RESET::I2C1,             /**< I2C 1 reset bit */
  I2C0 = libMcuHw::resets::RESET::I2C0,             /**< I2C 0 reset bit */
  DMA = libMcuHw::resets::RESET::DMA,               /**< DMA reset bit */
  BUSCTRL = libMcuHw::resets::RESET::BUSCTRL,       /**< Buscontrol reset bit */
  ADC = libMcuHw::resets::RESET::ADC,               /**< ADC reset bit */
};
/**
 * @brief resets peripheral
 * @tparam resetsAddress_  base resets peripheral address
 */
template <libMcu::resetsBaseAddress const& resetsAddress_>
struct resets : libMcu::peripheralBase {
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
  static libMcuHw::resets::peripheral* resetsPeripheral() {
    return reinterpret_cast<libMcuHw::resets::peripheral*>(resetsAddress + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static libMcuHw::resets::peripheral* resetsPeripheralSet() {
    return reinterpret_cast<libMcuHw::resets::peripheral*>(resetsAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static libMcuHw::resets::peripheral* resetsPeripheralClear() {
    return reinterpret_cast<libMcuHw::resets::peripheral*>(resetsAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static libMcuHw::resets::peripheral* resetsPeripheralXor() {
    return reinterpret_cast<libMcuHw::resets::peripheral*>(resetsAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType resetsAddress{resetsAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::resets
#endif