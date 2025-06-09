/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_spi_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series SPI
 */
#ifndef LPC84X_SPI_HW_HPP
#define LPC84X_SPI_HW_HPP

namespace libmcuhw::spi {
/**
 * @brief SPI register definitions
 */
struct Spi {
  volatile std::uint32_t CFG;           /*!< SPI Configuration register */
  volatile std::uint32_t DLY;           /*!< SPI Delay register */
  volatile std::uint32_t STAT;          /*!< SPI Status */
  volatile std::uint32_t INTENSET;      /*!< SPI Interrupt Enable read and Set */
  volatile std::uint32_t INTENCLR;      /*!< SPI Interrupt Enable Clear */
  volatile const std::uint32_t RXDAT;   /*!< SPI Receive Data */
  volatile std::uint32_t TXDATCTL;      /*!< SPI Transmit Data with Control */
  volatile std::uint32_t TXDAT;         /*!< SPI Transmit Data */
  volatile std::uint32_t TXCTL;         /*!< SPI Transmit Control */
  volatile std::uint32_t DIV;           /*!< SPI clock Divider */
  volatile const std::uint32_t INTSTAT; /*!< SPI Interrupt Status */
};
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0xFBDu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kENABLE{1u << 0};      /*!< SPI enable */
constexpr inline std::uint32_t kMASTER{1u << 2};      /*!< master mode */
constexpr inline std::uint32_t kSLAVE{0u << 2};       /*!< slave mode */
constexpr inline std::uint32_t kLSBF{1u << 3};        /*!< LSB First mode enable */
constexpr inline std::uint32_t kCPHA{1u << 4};        /*!< Clock phase select */
constexpr inline std::uint32_t kCPOL{1u << 5};        /*!< Clock polarity select */
constexpr inline std::uint32_t kLOOP{1u << 7};        /*!< Loopback mode enable */
constexpr inline std::uint32_t kSPOL0{1u << 8};       /*!< SSEL0 Polarity select */
constexpr inline std::uint32_t kSPOL1{1u << 9};       /*!< SSEL1 Polarity select */
constexpr inline std::uint32_t kSPOL2{1u << 10};      /*!< SSEL2 Polarity select */
constexpr inline std::uint32_t kSPOL3{1u << 11};      /*!< SSEL3 Polarity select */
/**
 * @brief Selects polarity for SSEL0, SSEL1, SSEL2, SSEL3
 * @param selects bit pattern of selects
 * @return register setting
 */
constexpr inline std::uint32_t SPOL(std::uint32_t selects) {
  return selects << 8;
}
}  // namespace CFG
namespace DLY {
constexpr inline std::uint32_t RESERVED_MASK{0x0000FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format pre delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t PRE_DELAY(std::uint32_t data) {
  return data << 0;
}
/**
 * @brief Format post delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t POST_DELAY(std::uint32_t data) {
  return data << 4;
}
/**
 * @brief Format frame delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t FRAME_DELAY(std::uint32_t data) {
  return data << 8;
}
/**
 * @brief Format transfer delay data for DLY register
 * @param data SPI clocks to insert
 * @return formatted data to be put in DLY register
 */
constexpr inline std::uint32_t TRANSFER_DELAY(std::uint32_t data) {
  return data << 12;
}
}  // namespace DLY
namespace STAT {
constexpr inline std::uint32_t RESERVED_MASK{0x000001FFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kRXRDY{1 << 0};             /*!< Receiver Ready flag. When 1 data available  */
constexpr inline std::uint32_t kTXRDY{1 << 1};             /*!< Transmitter Ready flag. When 1 data can be written */
constexpr inline std::uint32_t kRXOV{1 << 2};              /*!< Receiver Overrun interrupt flag. Slave mode only */
constexpr inline std::uint32_t kTXUR{1 << 3};              /*!< Transmitter Underrun interrupt flag. Slave mode only */
constexpr inline std::uint32_t kSSA{1 << 4};               /*!< Slave Select Assert. Set when selected. */
constexpr inline std::uint32_t kSSD{1 << 5};               /*!< Slave Select Deassert. Set when deselected. */
constexpr inline std::uint32_t kSTALLED{1 << 6};           /*!< Stalled status flag. */
constexpr inline std::uint32_t kENDTRANSFER{1 << 7};       /*!< End Transfer control bit. Force end of current transaction */
constexpr inline std::uint32_t kMSTIDLE{1 << 8};           /*!< Master idle status flag. Master is fully idle */
}  // namespace STAT
namespace INTENSET {
constexpr inline std::uint32_t RESERVED_MASK{0x0000003Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kRXRDYEN{1 << 0};           /*!< enable received data available interrupt */
constexpr inline std::uint32_t kTXRDYEN{1 << 1};           /*!< enable write to transmit register interrupt */
constexpr inline std::uint32_t kRXOVEN{1 << 2};            /*!< enable receiver overrun interrupt */
constexpr inline std::uint32_t kTXUREN{1 << 3};            /*!< enable transmitter underrun interrupt */
constexpr inline std::uint32_t kSSAEN{1 << 4};             /*!< enable slave selected interrupt */
constexpr inline std::uint32_t kSSDEN{1 << 5};             /*!< enable slave deselected interrupt */
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000003Fu; /*!< register mask for allowed bits */
// TODO register definitions
}  // namespace INTENCLR
namespace RXDAT {
constexpr inline std::uint32_t RESERVED_MASK = 0x001FFFFFu; /*!< register mask for allowed bits */
/**
 * @brief Format received data from RXDAT register field
 * @param registerData RXDAT register data
 * @return constexpr std::uint16_t data in RXDAT register
 */
constexpr inline std::uint16_t RXDAT(std::uint32_t registerData) {
  return static_cast<std::uint16_t>(registerData & 0xFFFFu);
}
constexpr inline std::uint32_t kRXSSEL_N{1 << 16}; /*!< Slave 0 selected for receive transaction, zero is active */
constexpr inline std::uint32_t kSOT{1 << 20};      /*!< Start of transfer flag. 1 when SSEL is asserted the first time */
}  // namespace RXDAT
namespace TXDATCTL {
constexpr inline std::uint32_t RESERVED_MASK = 0x0F7FFFFFu; /*!< register mask for allowed bits */
/**
 * @brief Formats data to TXDATCTL register field
 * @param data data to put in TXDATCTL register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t TXDAT(std::uint16_t data) {
  return static_cast<std::uint32_t>(data);
}
constexpr inline std::uint32_t kTXSSEL0_N{1u << 16}; /*!< This field asserts SSEL0 in master mode.*/
constexpr inline std::uint32_t kTXSSEL1_N{1u << 17}; /*!< This field asserts SSEL1 in master mode.*/
constexpr inline std::uint32_t kTXSSEL2_N{1u << 18}; /*!< This field asserts SSEL2 in master mode.*/
constexpr inline std::uint32_t kTXSSEL3_N{1u << 19}; /*!< This field asserts SSEL3 in master mode.*/
constexpr inline std::uint32_t kEOT{1u << 20};       /*!< End of Transfer. Deassert SSEL */
constexpr inline std::uint32_t kEOF{1u << 21};       /*!< End of Frame. Insert delay between frames */
constexpr inline std::uint32_t kRXIGNORE{1u << 22};  /*!< Receive ignore */
/**
 * @brief Format data transmit length to TXDATCTL register field
 *
 * @param length amount of data to transmit
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t LEN(std::uint32_t length) {
  return (length - 1) << 24;
}
}  // namespace TXDATCTL
namespace TXDAT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000FFFFu; /*!< register mask for allowed bits */
/**
 * @brief Formats data to TXDATCTL register field
 * @param data data to put in TXDATCTL register
 * @return formatted data
 */
constexpr inline std::uint32_t TXDAT(std::uint16_t data) {
  return static_cast<std::uint32_t>(data);
}
}  // namespace TXDAT
namespace TXCTL {
constexpr inline std::uint32_t RESERVED_MASK{0x0F710000u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kTXSSEL0_N{1u << 16};       /*!< This field asserts SSEL0 in master mode.*/
constexpr inline std::uint32_t kTXSSEL1_N{1u << 17};       /*!< This field asserts SSEL1 in master mode.*/
constexpr inline std::uint32_t kTXSSEL2_N{1u << 18};       /*!< This field asserts SSEL2 in master mode.*/
constexpr inline std::uint32_t kTXSSEL3_N{1u << 19};       /*!< This field asserts SSEL3 in master mode.*/
constexpr inline std::uint32_t kEOT{1u << 20};             /*!< End of Transfer. Deassert SSEL */
constexpr inline std::uint32_t kEOF{1u << 21};             /*!< End of Frame. Insert delay between frames */
constexpr inline std::uint32_t kRXIGNORE{1u << 22};        /*!< Receive ignore */
/**
 * @brief Format data transmit length to TXDATCTL register field
 * @param length amount of data to transmit
 * @return formatted data
 */
constexpr inline std::uint32_t LEN(std::uint32_t length) {
  return (length - 1) << 24;
}
}  // namespace TXCTL
namespace DIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000FFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Formats divider value to DIVVAL register field
 * @param divider clock divider value
 * @return constexpr std::uint32_t properly formatted divider to be put in register
 */
constexpr inline std::uint32_t DIVVAL(std::uint32_t divider) {
  return divider - 1;  // subtract one according to datasheet
}
}  // namespace DIV
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000003Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kRXRDY{1u << 0};            /*!< Receiver ready interrupt flag */
constexpr inline std::uint32_t kTXRDY{1u << 1};            /*!< Transmitter ready interrupt flag */
constexpr inline std::uint32_t kRXOV{1u << 2};             /*!< Receiver overrun interrupt flag*/
constexpr inline std::uint32_t kTXUR{1u << 3};             /*!< Transmitter underrun interrupt flag */
constexpr inline std::uint32_t kSSA{1u << 4};              /*!< Slave Select Assert */
constexpr inline std::uint32_t kSSD{1u << 5};              /*!< Slave Select Deassert */
}  // namespace INTSTAT
}  // namespace libmcuhw::spi
#endif