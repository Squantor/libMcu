/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file Cortex M0 definitions and classes
 */
#ifndef CORTEX_M0_PLUS_HPP
#define CORTEX_M0_PLUS_HPP

namespace libMcu::hw {

// core peripheral definitions
constexpr inline libMcu::scsBaseAddress scsAddress{0xE000'E000UL};         /**< systemcontrol space base address */
constexpr inline libMcu::systickBaseAddress systickAddress{0xE000'E010UL}; /**< systick base address*/
constexpr inline libMcu::nvicBaseAddress nvicAddress{0xE000'E100UL};       /**< NVIC base address */
constexpr inline libMcu::scbBaseAddress scbAddress{0xE000'ED00UL};         /** SCB base address */
constexpr inline libMcu::mpuBaseAddress mpuAddress{0xE000'ED90UL};         /**< MPU base address */

}  // namespace libMcu::hw

#include "cortex_m_ll.hpp"

#include "systick_hw.hpp"
#include "nvic_hw.hpp"
#include "scb_hw.hpp"
#include "mpu_hw.hpp"

#include "systick_ll.hpp"
#include "nvic_ll.hpp"
#include "scb_ll.hpp"
#include "mpu_ll.hpp"

#endif