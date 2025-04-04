/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_acmp_ll.hpp
 * @brief LPC810 series analog comparator interface class and definitions
 */
#ifndef LPC81X_ACMP_HPP
#define LPC81X_ACMP_HPP

namespace libmcull::sw::acmp {
namespace hardware = libmcuhw::acmp;

/**
 * @brief possible inputs for plus comparator input
 */
enum class inputPositiveSettings : std::uint32_t {
  LADDER = hardware::CTRL::kCOMP_VP_SEL_LAD,    /*!< Positive input connected to voltage ladder */
  IN1 = hardware::CTRL::kCOMP_VP_SEL_ACMP_I1,   /*!< Positive input connected to IN1 */
  IN2 = hardware::CTRL::kCOMP_VP_SEL_ACMP_I2,   /*!< Positive input connected to IN2 */
  REF = hardware::CTRL::kCOMP_VP_SEL_ACMP_VREF, /*!< Positive input connected to reference */
};
/**
 * @brief possible inputs for min comparator input
 */
enum class inputNegativeSettings : std::uint32_t {
  LADDER = hardware::CTRL::kCOMP_VM_SEL_LAD,    /*!< Negative input connected to voltage ladder */
  IN1 = hardware::CTRL::kCOMP_VM_SEL_ACMP_I1,   /*!< Negative input connected to IN1 */
  IN2 = hardware::CTRL::kCOMP_VM_SEL_ACMP_I2,   /*!< Negative input connected to IN2 */
  REF = hardware::CTRL::kCOMP_VM_SEL_ACMP_VREF, /*!< Negative input connected to reference */
};
/**
 * @brief possible options for comparator edge detector
 */
enum class edgeDetectSettings : std::uint32_t {
  FALLING = hardware::CTRL::kEDGESEL_FALLING, /*!< edge detector detects falling edges */
  RISING = hardware::CTRL::kEDGESEL_RISING,   /*!< edge detector detects rising edges */
  BOTH = hardware::CTRL::kEDGESEL_BOTH,       /*!< edge detector detects both edges */
};
/**
 * @brief possible options for comparator output synchronization
 */
enum class outputControlSettings : std::uint32_t {
  DIRECT = hardware::CTRL::kCOMPSA_DIR,  /*!< comparator output used directly */
  SYNCED = hardware::CTRL::kCOMPSA_SYNC, /*!< comparator output is synchronized to main clock */
};
/**
 * @brief possible options for comparator hysteresis
 */
enum class hysteresisSettings : std::uint32_t {
  NONE = hardware::CTRL::kHYS_NONE,     /*!< No hysteresis */
  HYS_5MV = hardware::CTRL::kHYS_5MV,   /*!< 5mV hysteresis */
  HYS_10MV = hardware::CTRL::kHYS_10MV, /*!< 10mV hysteresis */
  HYS_20MV = hardware::CTRL::kHYS_20MV, /*!< 20mV hysteresis */
};
/**
 * @brief possible options for voltage ladder reference
 */
enum class ladderReferenceSetting : std::uint32_t {
  VDD = hardware::LAD::kLADREF_VDD,       /*!< ladder reference is VDD pin */
  VDDCMP = hardware::LAD::kLADREF_VDDCMP, /*!< ladder reference is VDDCMP pin */
};
/**
 * @brief
 * @tparam acmpAddress_
 */
template <libmcu::acmpBaseAddress const& acmpAddress_>
struct acmp : libmcu::PeripheralBase {
  /**
   * @brief Setup analog comparator
   * @param inPlus positive input connection
   * @param inNeg negative input connection
   * @param edges edge detector setting
   * @param output comparator output setting
   * @param hysteresis comparator hysteresis
   */
  constexpr void init(inputPositiveSettings inPlus, inputNegativeSettings inNeg, edgeDetectSettings edges,
                      outputControlSettings output, hysteresisSettings hysteresis) {
    acmpPeripheral()->CTRL = static_cast<std::uint32_t>(inPlus) | static_cast<std::uint32_t>(inNeg) |
                             static_cast<std::uint32_t>(output) | static_cast<std::uint32_t>(edges) |
                             static_cast<std::uint32_t>(hysteresis);
    clearEdgeDetector();
  }
  /**
   * @brief Setup analog comparator and voltage ladder
   * @param inPlus positive input connection
   * @param inNeg negative input connection
   * @param edges edge detector setting
   * @param output comparator output setting
   * @param hysteresis comparator hysteresis
   * @param ladderReference voltage ladder reference connection
   */
  constexpr void init(inputPositiveSettings inPlus, inputNegativeSettings inNeg, edgeDetectSettings edges,
                      outputControlSettings output, hysteresisSettings hysteresis, ladderReferenceSetting ladderReference) {
    acmpPeripheral()->CTRL = static_cast<std::uint32_t>(inPlus) | static_cast<std::uint32_t>(inNeg) |
                             static_cast<std::uint32_t>(output) | static_cast<std::uint32_t>(edges) |
                             static_cast<std::uint32_t>(hysteresis);
    acmpPeripheral()->LAD = hardware::LAD::kLADEN | static_cast<std::uint32_t>(ladderReference);
    clearEdgeDetector();
  }
  /**
   * @brief comparator output status
   * @return zero for low, non zero for high
   */
  constexpr std::uint32_t comparatorOutput() {
    return acmpPeripheral()->CTRL & hardware::CTRL::kCOMPSTAT_MASK;
  }
  /**
   * @brief comparator edge detector status
   * @return zero for no edges detected, non zero for edge detector edges detected
   */
  constexpr std::uint32_t edgeOutput() {
    std::uint32_t status = acmpPeripheral()->CTRL & hardware::CTRL::kCOMPEDGE_MASK;
    if (status == 0u)
      return status;
    clearEdgeDetector();
    return status;
  }
  /**
   * @brief set resistor ladder value
   * @param value resistor ladder setting
   */
  constexpr void setLadder(std::uint32_t value) {
    acmpPeripheral()->LAD = (acmpPeripheral()->LAD & ~hardware::LAD::kLADSEL_MASK) | hardware::LAD::LADSEL(value);
  }
  /**
   * @brief reset edge detector
   */
  constexpr void clearEdgeDetector() {
    acmpPeripheral()->CTRL = acmpPeripheral()->CTRL | hardware::CTRL::kEDGECLR;
    acmpPeripheral()->CTRL = acmpPeripheral()->CTRL & ~hardware::CTRL::kEDGECLR;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to analog comparator registers
   */
  static libmcuhw::acmp::Acmp* acmpPeripheral() {
    return reinterpret_cast<libmcuhw::acmp::Acmp*>(acmpAddress);
  }

 private:
  static constexpr libmcu::hwAddressType acmpAddress{acmpAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::sw::acmp
#endif