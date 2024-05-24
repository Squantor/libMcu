/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Power management unit functions
 */
#ifndef LPC81X_PMU_HPP
#define LPC81X_PMU_HPP

namespace libMcuLL::sw::pmu {
using namespace hw::pmu;
template <libMcuLL::pmuBaseAddress pmuAddress_>
struct pmu {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to power management unit registers
   */
  constexpr static hw::pmu::peripheral *pmuPeripheral() {
    return reinterpret_cast<hw::pmu::peripheral *>(pmuAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType pmuAddress = pmuAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::pmu
#endif