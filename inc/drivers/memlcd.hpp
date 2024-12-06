/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file memlcd.hpp
 * @brief driver for the sharp memory LCD via SPI
 * @todo optimize lcd update by writing only dirty lines
 */
#ifndef DRIVER_MEMLCD_HPP
#define DRIVER_MEMLCD_HPP

#include <cstdint>
#include <array>
#include "sharp_memlcd/memlcd_config.hpp"

namespace libMcuDrv::memlcd {

constexpr inline std::uint16_t cmdDataUpdate = 0x0001; /*!< command for updating data */
constexpr inline std::uint16_t cmdVcomHigh = 0x0002;   /*!< command for setting VCOM high */
constexpr inline std::uint16_t cmdAllClear = 0x0004;   /*!< command for clearing display */

namespace spi = libMcuHal::spi;
template <typename config, spi::spiSlaveSelects slaveSelect, auto &spiHal>
struct memlcd {
  static_assert(config::maxX > 0, "display cant have zero X");
  static_assert(config::maxY > 0, "display cant have zero Y");
  // TODO static asserts if display X is not multiple of 16
  /**
   * @brief Construct a new memlcd object
   */
  memlcd() : vcom{false} {}
  constexpr void init(void) {}
  /**
   * @brief return X size of the display
   * @return X size, zero referenced
   */
  consteval std::uint32_t getXSize() {
    return config::maxX;
  }
  /**
   * @brief return Y size of the display
   * @return Y size, zero referenced
   */
  consteval std::uint32_t getYSize() {
    return config::maxY;
  }
  /**
   * @brief send Vcom command and toggle the state
   */
  constexpr void toggleVcom() {
    std::array<std::uint16_t, 1> data = {0};
    if (vcom) {
      data[0] = cmdVcomHigh;
      spiHal.write(data, 16u, slaveSelect, true, true);
    } else
      spiHal.write(data, 16u, slaveSelect, true, true);

    vcom = !vcom;
  }
  /**
   * @brief clear the display
   */
  constexpr void clear(void) {
    std::array<std::uint16_t, 1> data = {cmdAllClear};
    spiHal.write(data, 16u, slaveSelect, true, true);
  }
  /**
   * @brief Bulk transfer lines in the proper format the display expects
   * @param data lines to transfer
   */
  constexpr void transferLines(const std::span<const std::uint16_t> data) {
    spiHal.write(data, 16u, slaveSelect, true, true);
  }

  bool vcom;
};

}  // namespace libMcuDrv::memlcd

#endif