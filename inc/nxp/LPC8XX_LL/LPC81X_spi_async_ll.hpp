/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_spi_async_ll.hpp
 * @brief LPC810 series asynchronous SPI interface class and definitions
 * @todo depricate async polling interfaces
 */
#ifndef LPC81X_SPI_ASYNC_LL_HPP
#define LPC81X_SPI_ASYNC_LL_HPP

#include "LPC81X_spi_common_ll.hpp"

namespace libmcull::spi {
namespace hardware = ::libmcuhw::spi;

/**
 * @brief Asynchronous SPI peripheral instance
 * @tparam spi_address Peripheral base address
 * @tparam ChipEnable enum of available chip enables
 * @tparam TransferType datatype to use for data transfers
 * @todo basically remove or transform into SpiInterrupt for a proper async SPI interface
 */
template <libmcu::SpiBaseAddress spi_address, typename ChipEnable, typename TransferType>
struct SpiAsync : libmcull::PeripheralBase {
  /**
   * @brief Construct a new spi Async object
   * Initializes the internal state to defaults
   */
  SpiAsync() : transaction_state_{libmcu::AsynchronousStates::Idle} {}
  /**
   * @brief Initialise SPI peripheral as master device, LSB first mode, CPHA is 0, CPOL is 0,
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate) {
    std::uint32_t actual_bitrate = SetBitRate(bit_rate);
    GetPeripheral()->CFG = hardware::CFG::kENABLE | hardware::CFG::kMASTER;
    return actual_bitrate;
  }
  /**
   * @brief Initialise SPI peripheral as master device with custom settings
   * @param bit_rate requested bit rate
   * @param waveform SPI waveform, see Waveforms for options
   * @param polarity SPI slave select polarity, see SlavePolaritySelects for options
   * @return actual bit rate
   */
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate, Waveforms waveform, SlavePolaritySelects polarity) {
    std::uint32_t actual_bitrate = SetBitRate(bit_rate);
    GetPeripheral()->CFG =
      hardware::CFG::kENABLE | hardware::CFG::kMASTER | static_cast<std::uint32_t>(waveform) | static_cast<std::uint32_t>(polarity);
    return actual_bitrate;
  }
  /**
   * @brief Set the SPI peripheral bit rate
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t SetBitRate(std::uint32_t bit_rate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(CLOCK_AHB / bit_rate);
    GetPeripheral()->DIV = hardware::DIV::DIVVAL(divider);
    return CLOCK_AHB / divider;
  }
  /**
   * @brief Claim the SPI interface
   * @return InUse when already in use
   * @return CLAIMED when the claim has been successful
   */
  constexpr libmcu::Results Claim(void) {
    if (transaction_state_ != libmcu::AsynchronousStates::Idle) {
      return libmcu::Results::InUse;
    }
    transaction_state_ = libmcu::AsynchronousStates::Claimed;
    return libmcu::Results::Claimed;
  }
  /**
   * @brief Unclaim the SPI interface
   * @return Error when already idle or inconsistent, possible programming error!
   * @return Busy when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  constexpr libmcu::Results Unclaim(void) {
    if (transaction_state_ == libmcu::AsynchronousStates::Idle) {
      return libmcu::Results::Error;
    } else if (transaction_state_ == libmcu::AsynchronousStates::Busy) {
      return libmcu::Results::Busy;
    } else {
      transaction_state_ = libmcu::AsynchronousStates::Idle;
      return libmcu::Results::Unclaimed;
    }
    return libmcu::Results::Error;
  }
  /**
   * @brief Start a transceive operation
   * @param device SPI chipselect to use
   * @param transmit_buffer data to transmit
   * @param receive_buffer buffer to put data into
   * @param bit_count amount of bits
   * @param last_action is this the last action? This will disable the chip select
   * @retval Started transaction started
   */
  constexpr libmcu::Results Transceive(ChipEnable device, const std::span<TransferType> transmit_buffer,
                                       std::span<TransferType> receive_buffer, std::uint32_t bit_count, bool last_action) {
    if (transaction_state_ != libmcu::AsynchronousStates::Claimed) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transaction_write_index_ = 0u;
    transaction_read_index_ = 0u;
    transaction_write_data_ = transmit_buffer;
    transaction_read_data_ = receive_buffer;
    transaction_write_bits_ = bit_count;
    transaction_read_bits_ = bit_count;
    transaction_device_enable_ = device;
    transaction_disable_device_ = last_action;
    // TODO: Enable device
    transaction_state_ = libmcu::AsynchronousStates::Busy;
    return libmcu::Results::Started;
  }
  /**
   * @brief Start a receive operation
   * @param device SPI device to use
   * @param receive_buffer buffer to put data into
   * @param bit_count amount of bits
   * @param last_action is this the last action? This will disable the chip select
   * @retval Started transaction started
   */
  constexpr libmcu::Results Receive(ChipEnable device, std::span<TransferType> receive_buffer, std::uint32_t bit_count,
                                    bool last_action) {
    if (transaction_state_ != libmcu::AsynchronousStates::Claimed) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transaction_write_index_ = 0u;
    transaction_read_index_ = 0u;
    transaction_write_data_ = std::span<TransferType>();
    transaction_read_data_ = receive_buffer;
    transaction_write_bits_ = bit_count;
    transaction_read_bits_ = bit_count;
    transaction_device_enable_ = device;
    transaction_disable_device_ = last_action;
    // TODO: Enable device
    transaction_state_ = libmcu::AsynchronousStates::BusyReceive;
    return libmcu::Results::Started;
  }
  /**
   * @brief Start a transmit operation
   * @param device SPI device to use
   * @param transmit_buffer data to transmit
   * @param bit_count amount of bits
   * @param last_action is this the last action? This will disable the chip select
   * @retval Started transaction started
   */
  constexpr libmcu::Results Transmit(ChipEnable device, const std::span<TransferType> transmit_buffer, std::uint32_t bit_count,
                                     bool last_action) {
    if (transaction_state_ != libmcu::AsynchronousStates::Claimed) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transaction_write_index_ = 0u;
    transaction_read_index_ = 0u;
    transaction_write_data_ = transmit_buffer;
    transaction_read_data_ = std::span<TransferType>();
    transaction_write_bits_ = bit_count;
    transaction_read_bits_ = bit_count;
    transaction_device_enable_ = device;
    transaction_disable_device_ = last_action;
    // TODO: Enable device
    transaction_state_ = libmcu::AsynchronousStates::BusyTransmit;
    return libmcu::Results::Started;
  }
  /**
   * @brief progress with current transaction
   * @retval Busy transaction still busy
   * @retval Done transaction done, data available in buffers
   */
  constexpr libmcu::Results Progress(void) {
    switch (transaction_state_) {
      case libmcu::AsynchronousStates::Busy:
        return ProgressTransceive(transaction_write_data_[transaction_write_index_]);
        break;
      case libmcu::AsynchronousStates::BusyReceive:
        return ProgressTransceive(0u);  // we send along zero as dummy data
        break;
      case libmcu::AsynchronousStates::BusyTransmit:
        return ProgressWrite();
        break;
      default:
        return libmcu::Results::Error;
    }
  }

 private:
  /**
   * @brief Partially progress a SPI read
   * Fills a single data element in the read transaction buffer if the interface is ready. This peripheral
   * depends on SPI writes for the read buffer to be filled, the SPI write initiates clocking.
   * @retval Done when the last data is read
   * @retval Busy when interface is busy or still some data to be read remains
   */
  constexpr libmcu::Results ProgressPartialRead(void) {
    if ((GetPeripheral()->STAT & hardware::STAT::kRXRDY) != 0u) {
      if (transaction_read_bits_ > element_bit_count_) {
        transaction_read_data_[transaction_read_index_] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
        transaction_read_bits_ -= element_bit_count_;
        transaction_read_index_++;
      } else if (transaction_read_bits_ > 0u) {
        transaction_read_data_[transaction_read_index_] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
        transaction_state_ = libmcu::AsynchronousStates::Claimed;
        transaction_read_bits_ = 0u;
        return libmcu::Results::Done;
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief Partially progress a SPI write
   * @param transfer_command SPI write command pattern to use for this SPI write
   * @param data SPI data to write for this SPI write
   * @retval Done when the last data element is written
   * @retval Busy when interface is busy or still some data remains
   */
  constexpr libmcu::Results ProgressPartialWrite(std::uint32_t transfer_command, TransferType data) {
    if (((GetPeripheral()->STAT & hardware::STAT::kTXRDY) != 0u)) {
      if (transaction_write_bits_ > element_bit_count_) {
        GetPeripheral()->TXDATCTL =
          transfer_command | hardware::TXDATCTL::TXDAT(static_cast<uint16_t>(data)) | hardware::TXDATCTL::LEN(element_bit_count_);
        transaction_write_bits_ -= element_bit_count_;
        transaction_write_index_++;
      } else if (transaction_write_bits_ > 0u) {
        if (transaction_disable_device_)
          transfer_command |= hardware::TXDATCTL::kEOT;
        GetPeripheral()->TXDATCTL = transfer_command | hardware::TXDATCTL::TXDAT(static_cast<uint16_t>(data)) |
                                    hardware::TXDATCTL::LEN(transaction_write_bits_);
        transaction_write_bits_ = 0u;  // reset to zero so any further calls while TX is ready will cause no data written
        return libmcu::Results::Done;
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief progress with current read write transaction
   * @param data SPI data to write for this SPI read/write
   * @retval Busy transaction still busy
   * @retval Done transaction done, data available in buffers
   */
  constexpr libmcu::Results ProgressTransceive(TransferType data) {
    libmcu::Results readResult = ProgressPartialRead();
    if (readResult == libmcu::Results::Done)
      return libmcu::Results::Done;
    ProgressPartialWrite(hardware::TXDATCTL::TXSSEL(static_cast<std::uint32_t>(transaction_device_enable_)), data);
    return libmcu::Results::Busy;
  }
  /**
   * @brief progress with current write transaction
   * @retval Busy transaction still busy
   * @retval Done transaction done, data available in buffers
   */
  constexpr libmcu::Results ProgressWrite(void) {
    libmcu::Results writeResult = ProgressPartialWrite(
      hardware::TXDATCTL::TXSSEL(static_cast<std::uint32_t>(transaction_device_enable_)) | hardware::TXDATCTL::kRXIGNORE,
      transaction_write_data_[transaction_write_index_]);
    if (writeResult == libmcu::Results::Done) {
      transaction_state_ = libmcu::AsynchronousStates::Claimed;
      return libmcu::Results::Done;
    } else
      return writeResult;
  }

  /**
   * @brief get registers from peripheral
   * @return return pointer to spi registers
   */
  static hardware::Spi *GetPeripheral() {
    return reinterpret_cast<hardware::Spi *>(spi_address_);
  }

  libmcu::AsynchronousStates transaction_state_;   /*!< spi transaction state */
  std::size_t transaction_write_index_;            /*!< transaction write buffer index */
  std::size_t transaction_read_index_;             /*!< transaction read buffer index */
  std::span<TransferType> transaction_write_data_; /*!< data to write */
  std::span<TransferType> transaction_read_data_;  /*!< where to put read data in */
  std::uint32_t transaction_write_bits_;           /*!< Bits remaining in current transaction */
  std::uint32_t transaction_read_bits_;            /*!< Bits remaining in current transaction */
  ChipEnable transaction_device_enable_;           /*!< Disable chip after transaction */
  bool transaction_disable_device_;                /*!< Do we disable chip select after transaction */
  static constexpr std::uint8_t element_bit_count_ =
    std::numeric_limits<TransferType>::digits;                       /*!< Amount of bits in datatransfer type */
  static constexpr libmcu::HwAddressType spi_address_ = spi_address; /*!< peripheral address */
};
}  // namespace libmcull::spi
#endif