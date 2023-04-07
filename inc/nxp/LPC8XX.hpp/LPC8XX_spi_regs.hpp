/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC800 series SPI register interface
 */
#ifndef LPC8XX_SPI_REGS_HPP
#define LPC8XX_SPI_REGS_HPP

namespace registers {
namespace spi {
/**
 * @brief   SPI register definitions
 *
 */
struct registers {
  volatile uint32_t CFG;           /**< SPI Configuration register */
  volatile uint32_t DLY;           /**< SPI Delay register */
  volatile uint32_t STAT;          /**< SPI Status register */
  volatile uint32_t INTENSET;      /**< SPI Interrupt Enable Set register */
  volatile uint32_t INTENCLR;      /**< SPI Interrupt Enable Clear register */
  volatile const uint32_t RXDAT;   /**< SPI Receive Data register */
  volatile uint32_t TXDATCTL;      /**< SPI Transmit Data with Control register */
  volatile uint32_t TXDAT;         /**< SPI Transmit Data register */
  volatile uint32_t TXCRL;         /**< SPI Transmit Control register */
  volatile uint32_t DIV;           /**< SPI clock Divider register */
  volatile const uint32_t INTSTAT; /**< SPI Interrupt Status register */
};
namespace CFG {
constexpr inline uint32_t ENABLE = (1 << 0); /*!< SPI enable */
constexpr inline uint32_t MASTER = (1 << 2); /*!< master mode */
constexpr inline uint32_t SLAVE = (0 << 2);  /*!< slave mode */
constexpr inline uint32_t LSBF = (1 << 3);   /*!< LSB First mode enable */
constexpr inline uint32_t CPHA = (1 << 4);   /*!< Clock phase select */
constexpr inline uint32_t CPOL = (1 << 5);   /*!< Clock polarity select */
constexpr inline uint32_t LOOP = (1 << 7);   /*!< Loopback mode enable */
constexpr inline uint32_t SPOL0 = (1 << 8);  /*!< SSEL0 Polarity select */
constexpr inline uint32_t SPOL1 = (1 << 9);  /*!< SSEL1 Polarity select */
constexpr inline uint32_t SPOL2 = (1 << 10); /*!< SSEL2 Polarity select */
constexpr inline uint32_t SPOL3 = (1 << 11); /*!< SSEL3 Polarity select */
}  // namespace CFG
}  // namespace spi
}  // namespace registers

#endif