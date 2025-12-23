/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file cortex_m0plus.hpp
 * \brief Main entry point for Cortex M0+ support
 */
#ifndef CORTEX_M0PLUS_HPP
#define CORTEX_M0PLUS_HPP

namespace libmcuhw {

// core peripheral definitions
constexpr inline libmcu::ScsBaseAddress ScsAddress{0xE000'E000UL};         /*!< systemcontrol space base address */
constexpr inline libmcu::SystickBaseAddress SystickAddress{0xE000'E010UL}; /*!< systick base address*/
constexpr inline libmcu::NvicBaseAddress NvicAddress{0xE000'E100UL};       /*!< NVIC base address */
constexpr inline libmcu::ScbBaseAddress ScbAddress{0xE000'ED00UL};         /*!< SCB base address */
constexpr inline libmcu::MpuBaseAddress MpuAddress{0xE000'ED90UL};         /*!< MPU base address */

}  // namespace libmcuhw

#include "cortex_m_ll.hpp"
#include "cm_assert.hpp"

#include "systick_hw.hpp"
#include "nvic_hw.hpp"
#include "cm0p_scb_hw.hpp"
#include "mpu_hw.hpp"

#include "systick_ll.hpp"
#include "nvic_ll.hpp"
#include "scb_ll.hpp"
#include "mpu_ll.hpp"

#endif