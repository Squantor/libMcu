/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_pmu_hw.hpp
 * @brief LPC840 series Power management unit register interface and definitions
 */
#ifndef LPC84X_PMU_HW_HPP
#define LPC84X_PMU_HW_HPP

namespace libmcuhw::pmu {
/**
 * @brief PMU register definitions
 */
struct pmu {
  volatile std::uint32_t PCON;     /*!< Power control register */
  volatile std::uint32_t GPREG[4]; /*!< General purpose register N */
  volatile std::uint32_t DPDCTRL;  /*!< Deep power-down control register */
};
}  // namespace libmcuhw::pmu
#endif