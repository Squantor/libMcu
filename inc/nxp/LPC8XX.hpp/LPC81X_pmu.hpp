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

namespace libMcuLL {
namespace sw {
namespace pmu {
using namespace hw::pmu;
template <libMcuLL::PMUaddress address_>
struct pmu {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to power management unit registers
   */
  static hw::pmu::peripheral *peripheral() {
    return reinterpret_cast<hw::pmu::peripheral *>(address_);
  }
};
}  // namespace pmu
}  // namespace sw
}  // namespace libMcuLL

#endif