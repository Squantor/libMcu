/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_fmc_ll.hpp
 * @brief LPC810 series Flash memory control class and definitions
 */
#ifndef LPC81X_FMC_HPP
#define LPC81X_FMC_HPP

namespace libmcull::fmc {
namespace hardware = libmcuhw::fmc;

enum class WaitStates : std::uint32_t {
  WAIT_1_CLOCK = hardware::FLASHCFG::kFLASHTIM_1_CLOCK, /*!< 1 clock flash waitstate, use up to 20MHz clock */
  WAIT_2_CLOCK = hardware::FLASHCFG::kFLASHTIM_2_CLOCK, /*!< 2 clock flash waitstate, use up to 30MHz clock */
};

template <libmcu::FmcBaseAddress fmc_address>
struct Fmc {
  /**
   * @brief Change flash controller wait states
   *
   * @param setting amount of waitstates to wait for accessing flash
   */
  constexpr void setFlashWaitState(WaitStates setting) {
    // reserved bits need to be EXACTLY written back according to datasheet
    fmcPeripheral()->FLASHCFG =
      (fmcPeripheral()->FLASHCFG & ~hardware::FLASHCFG::RESERVED_MASK) | static_cast<std::uint32_t>(setting);
  }
  // TODO flash signiature generator method
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  constexpr static libmcuhw::fmc::Fmc *fmcPeripheral() {
    return reinterpret_cast<libmcuhw::fmc::Fmc *>(fmc_address_);
  }

 private:
  static constexpr libmcu::HwAddressType fmc_address_ = fmc_address; /*!< peripheral address */
};
}  // namespace libmcull::fmc
#endif