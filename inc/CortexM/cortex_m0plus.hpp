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

namespace libMcuLL {
namespace hw {

// core peripheral definitions
constexpr inline libMcuLL::scsBaseAddress scsAddress{0xE000'E000u};        /**< systemcontrol space base address */
constexpr inline libMcuLL::systickBaseAddress systickAddress{0xE000'E010}; /**< systick base address*/
constexpr inline libMcuLL::nvicBaseAddress nvicAddress{0xE000'E100};       /**< NVIC base address */
constexpr inline libMcuLL::scbBaseAddress scbAddress{0xE000'ED00};         /** SCB base address */
constexpr inline libMcuLL::mpuBaseAddress mpuAddress{0xE000'ED90};         /**< MPU base address */

}  // namespace hw
}  // namespace libMcuLL

#include "cortex_m_sw.hpp"

#include "systick_hw.hpp"
#include "nvic_hw.hpp"
#include "scb_hw.hpp"
#include "mpu_hw.hpp"

#include "systick_sw.hpp"
#include "nvic_sw.hpp"
#include "scb_sw.hpp"
#include "mpu_sw.hpp"

#endif