/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 USB dual port memory register interface
 */
#ifndef RP2040_USBCTRL_DPRAM_HW_HPP
#define RP2040_USBCTRL_DPRAM_HW_HPP

namespace libMcuHw::usbCtrlDpRam {
/**
 * @brief USB dual port memory register definitions
 */
struct usbCtrlDpRam {
  volatile std::uint32_t DUMMY; /**< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libMcuHw::usbCtrlDpRam
#endif