/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_pmu_ll.hpp
 * @brief LPC810 series Power management unit interface class and definitions
 */
#ifndef LPC81X_PMU_HPP
#define LPC81X_PMU_HPP

namespace libmcull::sw::pmu {
namespace hardware = libmcuhw::pmu;
/**
 * @brief pmu peripheral low level interface
 * @tparam pmu_address peripheral address
 */
template <libmcu::pmuBaseAddress pmu_address>
struct Pmu {
  /**
   * @brief get registers from peripheral
   * @return return pointer to power management unit registers
   */
  constexpr static libmcuhw::pmu::Pmu *GetPeripheral() {
    return reinterpret_cast<libmcuhw::pmu::Pmu *>(pmu_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pmu_address_ = pmu_address; /*!< peripheral address */
};
}  // namespace libmcull::sw::pmu
#endif