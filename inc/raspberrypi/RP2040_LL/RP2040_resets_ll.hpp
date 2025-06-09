/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_resets_ll.hpp
 * @brief low level interface for the RP2040 resets
 */
#ifndef RP2040_RESETS_LL_HPP
#define RP2040_RESETS_LL_HPP

namespace libmcull::resets {
namespace hardware = libmcuhw::resets;
/**
 * @brief
 */
enum PeripheralResets : std::uint32_t {
  kUsbCtrl = hardware::RESET::USBCTRL,      /*!< USB controller reset bit */
  kUart1 = hardware::RESET::UART1,          /*!< UART 1 reset bit */
  kUart0 = hardware::RESET::UART0,          /*!< UART 0 reset bit */
  kTimer = hardware::RESET::TIMER,          /*!< Timer reset bit */
  kTbman = hardware::RESET::TBMAN,          /*!< Test Bench manager reset bit */
  kSysinfo = hardware::RESET::SYSINFO,      /*!< System information reset bit */
  kSyscfg = hardware::RESET::SYSCFG,        /*!< System configuration reset bit */
  kSpi1 = hardware::RESET::SPI1,            /*!< SPI 1 reset bit */
  kSpi0 = hardware::RESET::SPI0,            /*!< SPI 0 reset bit */
  kRtc = hardware::RESET::RTC,              /*!< RTC reset bit */
  kPwm = hardware::RESET::PWM,              /*!< PWM reset bit */
  kPllUsb = hardware::RESET::PLL_USB,       /*!< USB PLL reset bit */
  kPllSys = hardware::RESET::PLL_SYS,       /*!< System PLL reset bit */
  kPio1 = hardware::RESET::PIO1,            /*!< PIO1 reset bit */
  kPio0 = hardware::RESET::PIO0,            /*!< PIO0 reset bit */
  kPadsQspi = hardware::RESET::PADS_QSPI,   /*!< Pads QSPI reset bit */
  kPadsBank0 = hardware::RESET::PADS_BANK0, /*!< Pads Bank0 reset bit */
  kJtag = hardware::RESET::JTAG,            /*!< JTAG reset bit */
  kIoQspi = hardware::RESET::IO_QSPI,       /*!< IO QSPI reset bit */
  kIoBank0 = hardware::RESET::IO_BANK0,     /*!< IO BANK0 reset bit */
  kI2c1 = hardware::RESET::I2C1,            /*!< I2C 1 reset bit */
  kI2c0 = hardware::RESET::I2C0,            /*!< I2C 0 reset bit */
  kDma = hardware::RESET::DMA,              /*!< DMA reset bit */
  kBusctrl = hardware::RESET::BUSCTRL,      /*!< Buscontrol reset bit */
  kAdc = hardware::RESET::ADC,              /*!< ADC reset bit */
};
/**
 * @brief resets peripheral
 * @tparam resets_address  base resets peripheral address
 */
template <libmcu::ResetsBaseAddress const& resets_address>
struct Resets : libmcull::PeripheralBase {
  /**
   * @brief Resets peripherals and waits until they have been reset
   * @param peripheralBits bit set of peripherals to reset, see RESETS_RESET_Enum for peripherals
   * @param timeout how many times to check if the status set
   * @return returns zero when timed out or nonzero when resets are executed
   */
  constexpr inline std::uint32_t Reset(uint32_t peripheralBits, uint32_t timeout) {
    GetPeripheralSet()->RESET = peripheralBits;
    GetPeripheralClear()->RESET = peripheralBits;
    // wait until resets have arrived
    while ((~GetPeripheral()->RESET_kDone & peripheralBits) && (timeout > 0)) {
      timeout--;
    }
    return timeout;
  }
  /**
   * @brief get registers from peripheral for normal access
   * @return return pointer to peripheral
   */
  static hardware::Resets* GetPeripheral() {
    return reinterpret_cast<hardware::Resets*>(resets_address_ + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Resets* GetPeripheralSet() {
    return reinterpret_cast<hardware::Resets*>(resets_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Resets* GetPeripheralClear() {
    return reinterpret_cast<hardware::Resets*>(resets_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Resets* GetPeripheralXor() {
    return reinterpret_cast<hardware::Resets*>(resets_address_ + libmcuhw::kPeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType resets_address_{resets_address}; /*!< peripheral address */
};
}  // namespace libmcull::resets
#endif