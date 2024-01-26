/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Flash memory control functions
 */
#ifndef LPC81X_FMC_HPP
#define LPC81X_FMC_HPP

namespace libMcuLL {
namespace sw {
namespace fmc {
using namespace libMcuLL::hw::fmc;

enum class waitstates : std::uint32_t {
  WAIT_1_CLOCK = FLASHCFG::FLASHTIM_1_CLOCK, /**< 1 clock flash waitstate */
  WAIT_2_CLOCK = FLASHCFG::FLASHTIM_2_CLOCK, /**< 2 clock flash waitstate */
};

template <libMcuLL::FMCbaseAddress address_>
struct fmc {
  /**
   * @brief Construct a new fmc object
   *
   */
  fmc() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static hw::fmc::peripheral *peripheral() {
    return reinterpret_cast<hw::fmc::peripheral *>(address_);
  }

  /**
   * @brief Change flash controller wait states
   *
   *
   *
   * @param setting amount of waitstates to wait for accessing flash
   */
  constexpr void setFlashWaitState(waitstates setting) {
    // reserved bits need to be EXACTLY written back according to datasheet
    peripheral()->FLASHCFG = (peripheral()->FLASHCFG & ~FLASHCFG::RESERVED_MASK) | static_cast<std::uint32_t>(setting);
  }

  // TODO flash signiature generator

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace fmc
}  // namespace sw
}  // namespace libMcuLL

#endif