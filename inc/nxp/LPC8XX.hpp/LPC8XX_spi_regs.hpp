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
constexpr inline uint32_t ENABLE = (1 << 0); /**< SPI enable */
constexpr inline uint32_t MASTER = (1 << 2); /**< master mode */
constexpr inline uint32_t SLAVE = (0 << 2);  /**< slave mode */
constexpr inline uint32_t LSBF = (1 << 3);   /**< LSB First mode enable */
constexpr inline uint32_t CPHA = (1 << 4);   /**< Clock phase select */
constexpr inline uint32_t CPOL = (1 << 5);   /**< Clock polarity select */
constexpr inline uint32_t LOOP = (1 << 7);   /**< Loopback mode enable */
constexpr inline uint32_t SPOL0 = (1 << 8);  /**< SSEL0 Polarity select */
constexpr inline uint32_t SPOL1 = (1 << 9);  /**< SSEL1 Polarity select */
constexpr inline uint32_t SPOL2 = (1 << 10); /**< SSEL2 Polarity select */
constexpr inline uint32_t SPOL3 = (1 << 11); /**< SSEL3 Polarity select */
}  // namespace CFG
namespace STAT {
constexpr inline uint32_t RXRDY = (1 << 0);       /**< Receiver Ready flag. When 1 data available  */
constexpr inline uint32_t TXRDY = (1 << 1);       /**< Transmitter Ready flag. When 1 data can be written */
constexpr inline uint32_t RXOV = (1 << 2);        /**< Receiver Overrun interrupt flag. Slave mode only */
constexpr inline uint32_t TXUR = (1 << 3);        /**< Transmitter Underrun interrupt flag. Slave mode only */
constexpr inline uint32_t SSA = (1 << 4);         /**< Slave Select Assert. Set when selected. */
constexpr inline uint32_t SSD = (1 << 5);         /**< Slave Select Deassert. Set when deselected. */
constexpr inline uint32_t STALLED = (1 << 6);     /**< Stalled status flag. */
constexpr inline uint32_t ENDTRANSFER = (1 << 7); /**< End Transfer control bit. Force end of current transaction */
constexpr inline uint32_t MSTIDLE = (1 << 8);     /**< Master idle status flag. Master is fully idle */
}  // namespace STAT
namespace RXDAT {
/**
 * @brief Format received data from RXDAT register field
 *
 * @param registerData RXDAT register data
 * @return constexpr uint16_t data in RXDAT register
 */
constexpr inline uint16_t RXDAT(uint32_t registerData) {
  return static_cast<uint16_t>(registerData & 0xFFFF);
}
constexpr inline uint32_t RXSSEL0_N = (1 << 16); /**< Slave 0 selected for receive transaction, zero is active */
constexpr inline uint32_t RXSSEL1_N = (1 << 17); /**< Slave 1 selected for receive transaction, zero is active */
constexpr inline uint32_t RXSSEL2_N = (1 << 18); /**< Slave 2 selected for receive transaction, zero is active */
constexpr inline uint32_t RXSSEL3_N = (1 << 19); /**< Slave 3 selected for receive transaction, zero is active */
constexpr inline uint32_t SOT = (1 << 20);       /**< Start of transfer flag. 1 when SSEL is asserted the first time */
}  // namespace RXDAT
namespace TXDATCTL {
/**
 * @brief Formats data to TXDATCTL register field
 *
 * @param data data to put in TXDATCTL register
 * @return constexpr uint32_t returns formatted data
 */
constexpr inline uint32_t TXDAT(uint16_t data) {
  return static_cast<uint32_t>(data);
}
constexpr inline uint32_t TXSSEL0_N = (1 << 16); /**< This field asserts SSEL0 in master mode.*/
constexpr inline uint32_t TXSSEL1_N = (1 << 17); /**< This field asserts SSEL1 in master mode.*/
constexpr inline uint32_t TXSSEL2_N = (1 << 18); /**< This field asserts SSEL2 in master mode.*/
constexpr inline uint32_t TXSSEL3_N = (1 << 19); /**< This field asserts SSEL3 in master mode.*/
constexpr inline uint32_t EOT = (1 << 20);       /**< End of Transfer. Deassert SSEL */
constexpr inline uint32_t EOF = (1 << 21);       /**< End of Frame. Insert delay between frames */
constexpr inline uint32_t RXIGNORE = (1 << 22);  /**< Receive ignore */
/**
 * @brief Format data transmit length to TXDATCTL register field
 *
 * @param length amount of data to transmit
 * @return constexpr uint32_t returns formatted data
 */
constexpr inline uint32_t LEN(uint32_t length) {
  return ((length - 1) & 0x0F) << 24;
}
}  // namespace TXDATCTL
}  // namespace spi
}  // namespace registers

#endif