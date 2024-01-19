/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series analog comparator functions
 */
#ifndef LPC81X_ACMP_HPP
#define LPC81X_ACMP_HPP
namespace libMcuLL {
namespace sw {
namespace acmp {
using namespace hw::acmp;

/**
 * @brief possible inputs for plus comparator input
 *
 */
enum class inputPositiveSettings : std::uint32_t {
  LADDER = CTRL::COMP_VP_SEL_LAD,    /**< Positive input connected to voltage ladder */
  IN1 = CTRL::COMP_VP_SEL_ACMP_I1,   /**< Positive input connected to IN1 */
  IN2 = CTRL::COMP_VP_SEL_ACMP_I2,   /**< Positive input connected to IN2 */
  REF = CTRL::COMP_VP_SEL_ACMP_VREF, /**< Positive input connected to reference */
};

/**
 * @brief possible inputs for min comparator input
 *
 */
enum class inputNegativeSettings : std::uint32_t {
  LADDER = CTRL::COMP_VM_SEL_LAD,    /**< Negative input connected to voltage ladder */
  IN1 = CTRL::COMP_VM_SEL_ACMP_I1,   /**< Negative input connected to IN1 */
  IN2 = CTRL::COMP_VM_SEL_ACMP_I2,   /**< Negative input connected to IN2 */
  REF = CTRL::COMP_VM_SEL_ACMP_VREF, /**< Negative input connected to reference */
};

/**
 * @brief possible options for comparator edge detector
 *
 */
enum class edgeDetectSettings : std::uint32_t {
  FALLING = CTRL::EDGESEL_FALLING, /**< edge detector detects falling edges */
  RISING = CTRL::EDGESEL_RISING,   /**< edge detector detects rising edges */
  BOTH = CTRL::EDGESEL_BOTH,       /**< edge detector detects both edges */
};

/**
 * @brief possible options for comparator output synchronization
 *
 */
enum class outputControlSettings : std::uint32_t {
  DIRECT = CTRL::COMPSA_DIR,  /**< comparator output used directly */
  SYNCED = CTRL::COMPSA_SYNC, /**< comparator output is synchronized to main clock */
};

/**
 * @brief possible options for comparator hysteresis
 *
 */
enum class hysteresisSettings : std::uint32_t {
  NONE = CTRL::HYS_NONE,     /**< No hysteresis */
  HYS_5MV = CTRL::HYS_5MV,   /**< 5mV hysteresis */
  HYS_10MV = CTRL::HYS_10MV, /**< 10mV hysteresis */
  HYS_20MV = CTRL::HYS_20MV, /**< 20mV hysteresis */
};

/**
 * @brief possible options for voltage ladder reference
 *
 */
enum class ladderReferenceSetting : std::uint32_t {
  VDD = LAD::LADREF_VDD,       /**< ladder reference is VDD pin */
  VDDCMP = LAD::LADREF_VDDCMP, /**< ladder reference is VDDCMP pin */
};

template <libMcuLL::ACMPbaseAddress const& address_>
struct acmp {
  /**
   * @brief Construct a new acmp object
   *
   */
  acmp() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hw::acmp::peripheral* peripheral() {
    return reinterpret_cast<hw::acmp::peripheral*>(address);
  }
  /**
   * @brief Setup analog comparator
   *
   * @param inPlus positive input connection
   * @param inNeg negative input connection
   * @param edges edge detector setting
   * @param output comparator output setting
   * @param hysteresis comparator hysteresis
   */
  constexpr void init(inputPositiveSettings inPlus, inputNegativeSettings inNeg, edgeDetectSettings edges,
                      outputControlSettings output, hysteresisSettings hysteresis) {
    peripheral()->CTRL = static_cast<std::uint32_t>(inPlus) | static_cast<std::uint32_t>(inNeg) |
                         static_cast<std::uint32_t>(output) | static_cast<std::uint32_t>(edges) |
                         static_cast<std::uint32_t>(hysteresis);
    // clear edge detector status
    peripheral()->CTRL = peripheral()->CTRL | CTRL::EDGECLR;
    peripheral()->CTRL = peripheral()->CTRL & ~CTRL::EDGECLR;
  }

  /**
   * @brief Setup analog comparator and voltage ladder
   *
   * @param inPlus positive input connection
   * @param inNeg negative input connection
   * @param edges edge detector setting
   * @param output comparator output setting
   * @param hysteresis comparator hysteresis
   * @param ladderReference voltage ladder reference connection
   */
  constexpr void init(inputPositiveSettings inPlus, inputNegativeSettings inNeg, edgeDetectSettings edges,
                      outputControlSettings output, hysteresisSettings hysteresis, ladderReferenceSetting ladderReference) {
    peripheral()->CTRL = static_cast<std::uint32_t>(inPlus) | static_cast<std::uint32_t>(inNeg) |
                         static_cast<std::uint32_t>(output) | static_cast<std::uint32_t>(edges) |
                         static_cast<std::uint32_t>(hysteresis);
    peripheral()->LAD = LAD::LADEN | static_cast<std::uint32_t>(ladderReference);
    // clear edge detector status
    peripheral()->CTRL = peripheral()->CTRL | CTRL::EDGECLR;
    peripheral()->CTRL = peripheral()->CTRL & ~CTRL::EDGECLR;
  }

  // get comparator status
  // get edge detector status
  // set voltage ladder

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace acmp
}  // namespace sw
}  // namespace libMcuLL

#endif