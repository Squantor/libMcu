/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X series SPI functions
 */
#ifndef LPC84X_SPI_HPP
#define LPC84X_SPI_HPP

namespace instances {
namespace spi {

/**
 * @brief SPI hardware chip enables
 *
 */
enum class spiChipEnables : uint16_t {
  SSEL0 = 0, /**< Hardware chip enable 0 */
  SSEL1 = 1, /**< Hardware chip enable 1 */
  SSEL2 = 2, /**< Hardware chip enable 2 */
  SSEL3 = 3, /**< Hardware chip enable 3 */
};

template <uint32_t base, typename chipEnables>
struct spi {
  static auto regs() {
    return reinterpret_cast<registers::spi::registers*>(base);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  uint32_t init(uint32_t bitRate) {
    uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = registers::spi::CFG::ENABLE | registers::spi::CFG::MASTER;
    return actualBitRate;
  }

  /**
   * @brief Set the SPI peripheral bit rate
   *
   * Uses defined CLOCK_AHB to compute the actual bit rate
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  uint32_t setBitRate(uint32_t bitRate) {
    // compute divider
    uint32_t divider = CLOCK_AHB / bitRate;
    regs()->DIV = divider - 1; /**< Divider value is -1 encoded as per datasheet */
    return CLOCK_AHB / divider;
  }
  // void transmit(chipEnables chipEnable, const uint16_t* txData, uint32_t bitCount, bool lastTransaction){};
  // void receive(chipEnables chipEnable, uint16_t* rxData, uint32_t bitCount, bool lastTransaction){};
  // void transceive(chipEnables chipEnable, const uint16_t* txData, uint16_t* rxData, uint32_t bitCount, bool lastTransaction){};
};
}  // namespace spi
}  // namespace instances

#endif