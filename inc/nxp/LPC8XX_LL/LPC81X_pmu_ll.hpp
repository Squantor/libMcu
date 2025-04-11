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
using namespace libmcuhw::pmu;
template <libmcu::pmuBaseAddress pmuAddress_>
struct pmu {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to power management unit registers
   */
  constexpr static libmcuhw::pmu::Pmu *pmuPeripheral() {
    return reinterpret_cast<libmcuhw::pmu::Pmu *>(pmuAddress);
  }

 private:
  static constexpr libmcu::hwAddressType pmuAddress = pmuAddress_; /*!< peripheral address */
};
}  // namespace libmcull::sw::pmu
#endif