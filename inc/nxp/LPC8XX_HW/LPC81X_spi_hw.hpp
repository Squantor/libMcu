/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_spi_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series SPI
 */
#ifndef LPC81X_SPI_HW_HPP
#define LPC81X_SPI_HW_HPP

namespace libmcuhw::spi {

/**
 * @brief SPI register definitions
 */
struct Spi {
  volatile std::uint32_t CFG;           /*!< Configuration register */
  volatile std::uint32_t DLY;           /*!< Delay register */
  volatile std::uint32_t STAT;          /*!< Status register */
  volatile std::uint32_t INTENSET;      /*!< Interrupt Enable Set register */
  volatile std::uint32_t INTENCLR;      /*!< Interrupt Enable Clear register */
  volatile const std::uint32_t RXDAT;   /*!< Receive Data register */
  volatile std::uint32_t TXDATCTL;      /*!< Transmit Data with Control register */
  volatile std::uint32_t TXDAT;         /*!< Transmit Data register */
  volatile std::uint32_t TXCTL;         /*!< Transmit Control register */
  volatile std::uint32_t DIV;           /*!< clock Divider register */
  volatile const std::uint32_t INTSTAT; /*!< Interrupt Status register */
};
namespace CFG {
constexpr inline std::uint32_t kRESERVED_MASK{0x1BDu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kENABLE{1u << 0};       /*!< SPI enable */
constexpr inline std::uint32_t kMASTER{1u << 2};       /*!< master mode */
constexpr inline std::uint32_t kSLAVE{0u << 2};        /*!< slave mode */
constexpr inline std::uint32_t kLSBF{1u << 3};         /*!< LSB First mode enable */
constexpr inline std::uint32_t kCPHA{1u << 4};         /*!< Clock phase select */
constexpr inline std::uint32_t kCPOL{1u << 5};         /*!< Clock polarity select */
constexpr inline std::uint32_t kLOOP{1u << 7};         /*!< Loopback mode enable */
constexpr inline std::uint32_t kSPOL{1u << 8};         /*!< SSEL0 Polarity select */
}  // namespace CFG
namespace DLY {
constexpr inline std::uint32_t RESERVED_MASK{0x0000FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format pre delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t PRE_DELAY(std::uint32_t data) {
  return static_cast<std::uint32_t>(data) << 0;
}
/**
 * @brief Format post delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t POST_DELAY(std::uint32_t data) {
  return static_cast<std::uint32_t>(data) << 4;
}
/**
 * @brief Format frame delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t FRAME_DELAY(std::uint32_t data) {
  return static_cast<std::uint32_t>(data) << 8;
}
/**
 * @brief Format transfer delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t TRANSFER_DELAY(std::uint32_t data) {
  return static_cast<std::uint32_t>(data) << 12;
}
}  // namespace DLY
namespace STAT {
constexpr inline std::uint32_t kRESERVED_MASK{0x000001FFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kRXRDY{1u << 0};             /*!< Receiver Ready flag. When 1 data available  */
constexpr inline std::uint32_t kTXRDY{1u << 1};             /*!< Transmitter Ready flag. When 1 data can be written */
constexpr inline std::uint32_t kRXOV{1u << 2};              /*!< Receiver Overrun interrupt flag. Slave mode only */
constexpr inline std::uint32_t kTXUR{1u << 3};              /*!< Transmitter Underrun interrupt flag. Slave mode only */
constexpr inline std::uint32_t kSSA{1u << 4};               /*!< Slave Select Assert. Set when selected. */
constexpr inline std::uint32_t kSSD{1u << 5};               /*!< Slave Select Deassert. Set when deselected. */
constexpr inline std::uint32_t kSTALLED{1u << 6};           /*!< Stalled status flag. */
constexpr inline std::uint32_t kENDTRANSFER{1u << 7};       /*!< End Transfer control bit. Force end of current transaction */
constexpr inline std::uint32_t kMSTIDLE{1u << 8};           /*!< Master idle status flag. Master is fully idle */
}  // namespace STAT
namespace INTENSET {
constexpr inline std::uint32_t kRESERVED_MASK{0x0000003Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kRXRDYEN{1u << 0};           /*!< enable received data available interrupt */
constexpr inline std::uint32_t kTXRDYEN{1u << 1};           /*!< enable write to transmit register interrupt */
constexpr inline std::uint32_t kRXOVEN{1u << 2};            /*!< enable receiver overrun interrupt */
constexpr inline std::uint32_t kTXUREN{1u << 3};            /*!< enable transmitter underrun interrupt */
constexpr inline std::uint32_t kSSAEN{1u << 4};             /*!< enable slave selected interrupt */
constexpr inline std::uint32_t kSSDEN{1u << 5};             /*!< enable slave deselected interrupt */
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t kRESERVED_MASK{0x0000003Fu}; /*!< register mask for allowed bits */
// TODO register definitions
}  // namespace INTENCLR
namespace RXDAT {
constexpr inline std::uint32_t kRESERVED_MASK{0x0011FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format received data from RXDAT register field
 * @param registerData RXDAT register data
 * @return constexpr std::uint16_t data in RXDAT register
 */
constexpr inline std::uint16_t RXDAT(std::uint32_t registerData) {
  return static_cast<std::uint16_t>(registerData & 0xFFFFu);
}
constexpr inline std::uint32_t kRXSSEL_N{1u << 16}; /*!< Slave 0 selected for receive transaction, zero is active */
constexpr inline std::uint32_t kSOT{1u << 20};      /*!< Start of transfer flag. 1 when SSEL is asserted the first time */
}  // namespace RXDAT
namespace TXDATCTL {
constexpr inline std::uint32_t kRESERVED_MASK{0x0F71FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Formats data to TXDATCTL register field
 * @param data data to put in TXDATCTL register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t TXDAT(std::uint16_t data) {
  return static_cast<std::uint32_t>(data);
}
constexpr inline std::uint32_t kTXSSEL_N{1u << 16}; /*!< This field asserts SSEL0 in master mode.*/
/**
 * @brief Formats chipselects to TXSSEL register field
 * @param chipselects chipselects to use
 * @return constexpr std::uint32_t properly formatted chipselects to be put in register
 */
constexpr inline std::uint32_t TXSSEL(std::uint32_t chipselects) {
  return (chipselects ^ kTXSSEL_N) & kTXSSEL_N;
}
constexpr inline std::uint32_t kEOT{1u << 20};      /*!< End of Transfer. Deassert SSEL */
constexpr inline std::uint32_t kEOF{1u << 21};      /*!< End of Frame. Insert delay between frames */
constexpr inline std::uint32_t kRXIGNORE{1u << 22}; /*!< Receive ignore */
/**
 * @brief Format data transmit length to TXDATCTL register field
 *
 * @param length amount of data to transmit
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t LEN(std::uint32_t length) {
  return ((length - 1) & 0x0Fu) << 24;
}
}  // namespace TXDATCTL
namespace TXDAT {
constexpr inline std::uint32_t kRESERVED_MASK{0x0000FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Formats data to TXDATCTL register field
 *
 * @param data data to put in TXDATCTL register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t TXDAT(std::uint16_t data) {
  return static_cast<std::uint32_t>(data);
}
}  // namespace TXDAT
namespace TXCTL {
constexpr inline std::uint32_t kRESERVED_MASK{0x0F710000u}; /*!< register mask for allowed bits */
/**
 * @brief Format data transmit length to TXDATCTL register field
 *
 * @param length amount of data to transmit
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t LEN(std::uint32_t length) {
  return ((length - 1) & 0x0Fu) << 24;
}
}  // namespace TXCTL
namespace DIV {
constexpr inline std::uint32_t kRESERVED_MASK{0x0000FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Formats divider value to DIVVAL register field
 *
 * @param divider clock divider value
 * @return constexpr std::uint32_t properly formatted divider to be put in register
 */
constexpr inline std::uint32_t DIVVAL(std::uint16_t divider) {
  return divider - 1;  // subtract one according to datasheet
}
}  // namespace DIV
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000003Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t RXRDY{1u << 0};             /*!< Receiver ready interrupt flag */
constexpr inline std::uint32_t TXRDY{1u << 1};             /*!< Transmitter ready interrupt flag */
constexpr inline std::uint32_t RXOV{1u << 2};              /*!< Receiver overrun interrupt flag*/
constexpr inline std::uint32_t TXUR{1u << 3};              /*!< Transmitter underrun interrupt flag */
constexpr inline std::uint32_t SSA{1u << 4};               /*!< Slave Select Assert */
constexpr inline std::uint32_t SSD{1u << 5};               /*!< Slave Select Deassert */
}  // namespace INTSTAT
}  // namespace libmcuhw::spi
#endif