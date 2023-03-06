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

/**
 * @brief
 *
 * @tparam base
 * @tparam TODO chipEnables
 */
template <uint32_t base>
struct spi {
  static auto regs() {
    return reinterpret_cast<LPC845M301BD48::registers::spi*>(base);
  }
  void init(void) {
    regs()->CFG = 0;
  }
  // void transmit(chipEnables chipEnable, const uint16_t* txData, uint32_t bitCount, bool lastTransaction){};
  // void receive(chipEnables chipEnable, uint16_t* rxData, uint32_t bitCount, bool lastTransaction){};
  // void transceive(chipEnables chipEnable, const uint16_t* txData, uint16_t* rxData, uint32_t bitCount, bool lastTransaction){};
};

}  // namespace instances

#endif