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
template <libMcuLL::systickBaseAddress const& address_>
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
  static hw::systick::peripheral* peripheral() {
    return reinterpret_cast<hw::systick::peripheral*>(address);
  }
  /**
   * @brief setup systick peripheral
   *
   * @param interval systick interval count
   */
  constexpr void init(std::uint32_t interval) {
    peripheral()->RVR = interval;
  }

  /**
   * @brief set the reload value
   *
   * @param interval systick interval to put in reload register
   */
  constexpr void setReload(std::uint32_t interval) {
    peripheral()->RVR = interval;
  }

  /**
   * @brief Get systick count value
   *
   * @return current systick count
   */
  constexpr std::uint32_t getCount() {
    return peripheral()->CVR;
  }

  /**
   * @brief did the systick counter pass zero
   *
   * @return zero if not, non zero if so
   */
  constexpr std::uint32_t getZeroPass() {
    return peripheral()->CSR & CSR::COUNTFLAG_MASK;
  }

  /**
   * @brief start the systick peripheral without any interrupts
   */
  constexpr void start() {
    peripheral()->CSR = CSR::CLKSOURCE_PROC | CSR::ENABLE;
  }

  // TODO start(lambda) for callbacks when interrupts, depends on NVIC

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace systick
}  // namespace sw
}  // namespace libMcuLL

#endif