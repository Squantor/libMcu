/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick functions
 */
#ifndef SYSTICK_LL_HPP
#define SYSTICK_LL_HPP
namespace libMcu::ll::systick {
namespace hardware = libMcu::hw::systick;
template <libMcu::systickBaseAddress const& systickAddress_>
struct systick {
  /**
   * @brief Construct a new systick object
   *
   */
  systick() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hardware::peripheral* systickPeripheral() {
    return reinterpret_cast<hardware::peripheral*>(systickAddress);
  }
  /**
   * @brief setup systick peripheral
   *
   * @param interval systick interval count
   */
  constexpr void init(std::uint32_t interval) {
    systickPeripheral()->RVR = interval;
  }

  /**
   * @brief set the reload value
   *
   * @param interval systick interval to put in reload register
   */
  constexpr void setReload(std::uint32_t interval) {
    systickPeripheral()->RVR = interval;
  }

  /**
   * @brief Get systick count value
   *
   * @return current systick count
   */
  constexpr std::uint32_t getCount() {
    return systickPeripheral()->CVR;
  }

  /**
   * @brief did the systick counter pass zero
   *
   * @return zero if not, non zero if so
   */
  constexpr std::uint32_t getZeroPass() {
    return systickPeripheral()->CSR & hardware::CSR::COUNTFLAG_MASK;
  }

  /**
   * @brief start the systick peripheral without any interrupts
   */
  constexpr void start() {
    systickPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC | hardware::CSR::ENABLE;
  }

  constexpr void start(isrLambda lambda) {
    callback = lambda;
    systickPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC | hardware::CSR::ENABLE | hardware::CSR::TICKINT;
  }

  // TODO start(lambda) for callbacks when interrupts, depends on NVIC

  /**
   * @brief stop the systick peripheral
   *
   */
  constexpr void stop() {
    systickPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC;
  }

  /**
   * @brief call site for the systick ISR
   *
   * let the C style ISR call this method to make sure the callbacks get called properly
   *
   */
  constexpr void isr() {
    callback();
  }

  static constexpr libMcu::hwAddressType systickAddress = systickAddress_; /**< peripheral address */
  isrLambda callback;
};
}  // namespace libMcu::ll::systick
#endif