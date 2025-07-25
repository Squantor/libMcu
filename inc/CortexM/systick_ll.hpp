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
 * @brief
 * @tparam systick_address
 * @todo Rename methods to conform to standard
 */
template <libmcu::SystickBaseAddress const& systick_address>
struct Systick {
  /**
   * @brief Construct a new systick object
   *
   */
  Systick() {}

  /**
   * @brief setup systick peripheral
   *
   * @param interval systick interval count
   */
  constexpr void init(std::uint32_t interval) {
    GetPeripheral()->RVR = interval;
  }

  /**
   * @brief set the reload value
   *
   * @param interval systick interval to put in reload register
   */
  constexpr void setReload(std::uint32_t interval) {
    GetPeripheral()->RVR = interval;
  }

  /**
   * @brief Get systick count value
   *
   * @return current systick count
   */
  constexpr std::uint32_t getCount() {
    return GetPeripheral()->CVR;
  }

  /**
   * @brief did the systick counter pass zero
   *
   * @return zero if not, non zero if so
   */
  constexpr std::uint32_t getZeroPass() {
    return GetPeripheral()->CSR & hardware::CSR::kCOUNTFLAG_MASK;
  }

  /**
   * @brief start the systick peripheral without any interrupts
   */
  constexpr void start() {
    GetPeripheral()->CSR = hardware::CSR::kCLKSOURCE_PROC | hardware::CSR::kENABLE;
  }

  constexpr void start(libmcu::IsrLambda lambda) {
    callback = lambda;
    GetPeripheral()->CSR = hardware::CSR::kCLKSOURCE_PROC | hardware::CSR::kENABLE | hardware::CSR::kTICKINT;
  }

  // TODO start(lambda) for callbacks when interrupts, depends on NVIC

  /**
   * @brief stop the systick peripheral
   *
   */
  constexpr void stop() {
    GetPeripheral()->CSR = hardware::CSR::kCLKSOURCE_PROC;
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