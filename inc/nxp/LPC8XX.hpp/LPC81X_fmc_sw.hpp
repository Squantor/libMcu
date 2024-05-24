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

namespace libMcuLL::sw::fmc {
using namespace libMcuLL::hw::fmc;

enum class waitstates : std::uint32_t {
  WAIT_1_CLOCK = FLASHCFG::FLASHTIM_1_CLOCK, /**< 1 clock flash waitstate, use up to 20MHz clock */
  WAIT_2_CLOCK = FLASHCFG::FLASHTIM_2_CLOCK, /**< 2 clock flash waitstate, use up to 30MHz clock */
};

template <libMcuLL::fmcBaseAddress fmcAddress_>
struct fmc {
  /**
   * @brief Change flash controller wait states
   *
   * @param setting amount of waitstates to wait for accessing flash
   */
  constexpr void setFlashWaitState(waitstates setting) {
    // reserved bits need to be EXACTLY written back according to datasheet
    fmcPeripheral()->FLASHCFG = (fmcPeripheral()->FLASHCFG & ~FLASHCFG::RESERVED_MASK) | static_cast<std::uint32_t>(setting);
  }
  // TODO flash signiature generator method
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  constexpr static hw::fmc::peripheral *fmcPeripheral() {
    return reinterpret_cast<hw::fmc::peripheral *>(fmcAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType fmcAddress = fmcAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::fmc
#endif