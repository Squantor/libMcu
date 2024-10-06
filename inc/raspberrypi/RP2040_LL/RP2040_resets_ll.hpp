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

namespace libMcuLL::resets {
namespace hardware = libMcuHw::resets;
/**
 * @brief
 */
enum peripheralResets : std::uint32_t {
  USBCTRL = hardware::RESET::USBCTRL,       /**< USB controller reset bit */
  UART1 = hardware::RESET::UART1,           /**< UART 1 reset bit */
  UART0 = hardware::RESET::UART0,           /**< UART 0 reset bit */
  TIMER = hardware::RESET::TIMER,           /**< Timer reset bit */
  TBMAN = hardware::RESET::TBMAN,           /**< Test Bench manager reset bit */
  SYSINFO = hardware::RESET::SYSINFO,       /**< System information reset bit */
  SYSCFG = hardware::RESET::SYSCFG,         /**< System configuration reset bit */
  SPI1 = hardware::RESET::SPI1,             /**< SPI 1 reset bit */
  SPI0 = hardware::RESET::SPI0,             /**< SPI 0 reset bit */
  RTC = hardware::RESET::RTC,               /**< RTC reset bit */
  PWM = hardware::RESET::PWM,               /**< PWM reset bit */
  PLL_USB = hardware::RESET::PLL_USB,       /**< USB PLL reset bit */
  PLL_SYS = hardware::RESET::PLL_SYS,       /**< System PLL reset bit */
  PIO1 = hardware::RESET::PIO1,             /**< PIO1 reset bit */
  PIO0 = hardware::RESET::PIO0,             /**< PIO0 reset bit */
  PADS_QSPI = hardware::RESET::PADS_QSPI,   /**< Pads QSPI reset bit */
  PADS_BANK0 = hardware::RESET::PADS_BANK0, /**< Pads Bank0 reset bit */
  JTAG = hardware::RESET::JTAG,             /**< JTAG reset bit */
  IO_QSPI = hardware::RESET::IO_QSPI,       /**< IO QSPI reset bit */
  IO_BANK0 = hardware::RESET::IO_BANK0,     /**< IO BANK0 reset bit */
  I2C1 = hardware::RESET::I2C1,             /**< I2C 1 reset bit */
  I2C0 = hardware::RESET::I2C0,             /**< I2C 0 reset bit */
  DMA = hardware::RESET::DMA,               /**< DMA reset bit */
  BUSCTRL = hardware::RESET::BUSCTRL,       /**< Buscontrol reset bit */
  ADC = hardware::RESET::ADC,               /**< ADC reset bit */
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
  static hardware::resets* resetsPeripheral() {
    return reinterpret_cast<hardware::resets*>(resetsAddress + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::resets* resetsPeripheralSet() {
    return reinterpret_cast<hardware::resets*>(resetsAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::resets* resetsPeripheralClear() {
    return reinterpret_cast<hardware::resets*>(resetsAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::resets* resetsPeripheralXor() {
    return reinterpret_cast<hardware::resets*>(resetsAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType resetsAddress{resetsAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::resets
#endif