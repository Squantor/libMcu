/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick functions
 */
/**
 * @file systick_ll.hpp
 * @brief systick interface class and definitions
 */
#ifndef SYSTICK_LL_HPP
#define SYSTICK_LL_HPP
namespace libmcull::systick {
namespace hardware = libmcuhw::systick;
/**
 * @brief systick lowlevel interface class
 * @tparam systick_address
 */
template <libmcu::SystickBaseAddress const& systick_address>
struct Systick {
  /**
   * @brief Construct a new systick object
   */
  Systick() {}
  /**
   * @brief setup systick peripheral
   * @param interval systick interval count
   */
  constexpr void Init(std::uint32_t interval) {
    GetPeripheral()->RVR = interval;
  }
  /**
   * @brief set the reload value
   * @param interval systick interval to put in reload register
   */
  constexpr void SetReload(std::uint32_t interval) {
    GetPeripheral()->RVR = interval;
  }
  /**
   * @brief Get systick count value
   * @return current systick count
   */
  constexpr std::uint32_t GetCount() {
    return GetPeripheral()->CVR;
  }
  /**
   * @brief did the systick counter pass zero
   * @return zero if not, non zero if so
   */
  constexpr std::uint32_t GetZeroPass() {
    return GetPeripheral()->CSR & hardware::CSR::COUNTFLAG_MASK;
  }
  /**
   * @brief start the systick peripheral without any interrupts
   */
  constexpr void Start() {
    GetPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC | hardware::CSR::ENABLE;
  }
  /**
   * @brief start the systick peripheral with interrupts
   * @param lambda callback function
   */
  constexpr void Start(libmcu::IsrLambda lambda) {
    callback = lambda;
    GetPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC | hardware::CSR::ENABLE | hardware::CSR::TICKINT;
  }
  /*!< @todo start(lambda) for callbacks when interrupts, depends on NVIC */
  /**
   * @brief stop the systick peripheral
   */
  constexpr void Stop() {
    GetPeripheral()->CSR = hardware::CSR::CLKSOURCE_PROC;
  }
  /**
   * @brief call site for the systick ISR
   * let the C style ISR call this method to make sure the callbacks get called properly
   * @todo rename to InterruptHandler
   */
  constexpr void Isr() {
    callback();
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral registers
   */
  static hardware::systick* GetPeripheral() {
    return reinterpret_cast<hardware::systick*>(systickAddress);
  }
  static constexpr libmcu::HwAddressType systickAddress = systick_address; /*!< peripheral address */
  libmcu::IsrLambda callback;
};
}  // namespace libmcull::systick
#endif