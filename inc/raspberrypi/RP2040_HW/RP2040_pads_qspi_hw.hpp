/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pads_qspi_hw.hpp
 * @brief Register interface for the RP2040 QSPI pads
 */
#ifndef RP2040_PADS_QSPI_HW_HPP
#define RP2040_PADS_QSPI_HW_HPP

namespace libmcuhw::padsQspi {
/**
 * @brief QSPI pads register definitions
 */
struct padsQspi {
  volatile std::uint32_t DUMMY; /*!< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /*!< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libmcuhw::padsQspi
#endif