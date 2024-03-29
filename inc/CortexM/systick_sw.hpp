/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick functions
 */
#ifndef SYSTICK_SW_HPP
#define SYSTICK_SW_HPP
namespace libMcuLL {
namespace sw {
namespace systick {
using namespace hw::systick;
template <libMcuLL::systickBaseAddress const& nvicAddress_>
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
  static hw::systick::peripheral* nvicPeripheral() {
    return reinterpret_cast<hw::systick::peripheral*>(nvicAddress);
  }
  /**
   * @brief setup systick peripheral
   *
   * @param interval systick interval count
   */
  constexpr void init(std::uint32_t interval) {
    nvicPeripheral()->RVR = interval;
  }

  /**
   * @brief set the reload value
   *
   * @param interval systick interval to put in reload register
   */
  constexpr void setReload(std::uint32_t interval) {
    nvicPeripheral()->RVR = interval;
  }

  /**
   * @brief Get systick count value
   *
   * @return current systick count
   */
  constexpr std::uint32_t getCount() {
    return nvicPeripheral()->CVR;
  }

  /**
   * @brief did the systick counter pass zero
   *
   * @return zero if not, non zero if so
   */
  constexpr std::uint32_t getZeroPass() {
    return nvicPeripheral()->CSR & CSR::COUNTFLAG_MASK;
  }

  /**
   * @brief start the systick peripheral without any interrupts
   */
  constexpr void start() {
    nvicPeripheral()->CSR = CSR::CLKSOURCE_PROC | CSR::ENABLE;
  }

  constexpr void start(isrLambda lambda) {
    callback = lambda;
    nvicPeripheral()->CSR = CSR::CLKSOURCE_PROC | CSR::ENABLE | CSR::TICKINT;
  }

  // TODO start(lambda) for callbacks when interrupts, depends on NVIC

  /**
   * @brief stop the systick peripheral
   *
   */
  constexpr void stop() {
    nvicPeripheral()->CSR = CSR::CLKSOURCE_PROC;
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

  static constexpr libMcuLL::hwAddressType nvicAddress = nvicAddress_; /**< peripheral address */
  isrLambda callback;
};
}  // namespace systick
}  // namespace sw
}  // namespace libMcuLL

#endif