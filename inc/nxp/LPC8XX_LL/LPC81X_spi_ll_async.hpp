/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series asynchronous SPI functions
 */
#ifndef LPC81X_SPI_LL_ASYNC_HPP
#define LPC81X_SPI_LL_ASYNC_HPP

#include "LPC81X_spi_ll_common.hpp"

namespace libMcuLL::sw::spi {
namespace detail {

// TODO need to remove and make use of libmcu::return
enum class asynchronousStates : std::uint8_t {
  IDLE,           /**< Interface is idle, ready to be claimed */
  CLAIMED,        /**< Interface is claimed, ready to transact */
  TRANSACTING_RW, /**< Interface is busy with a read write transaction */
  TRANSACTING_R,  /**< Interface is busy with a read write transaction */
  TRANSACTING_W,  /**< Interface is busy with a read write transaction */
};

}  // namespace detail

using namespace hw::spi;

/**
 * @brief Asynchronous SPI peripheral instance
 *
 * @tparam spiAddress_ Peripheral base address
 * @tparam chipEnables enum of available chip enables
 * @tparam transferType datatype to use for data transfers
 */
template <libMcu::spiBaseAddress spiAddress_, typename chipEnables, typename transferType>
struct spiAsync : libMcu::peripheralBase {
  /**
   * @brief Construct a new spi Async object
   *
   * Initializes the internal state to defaults
   *
   */
  spiAsync() : transactionState{detail::asynchronousStates::IDLE} {}
  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t initMaster(std::uint32_t bitRate) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER;
    return actualBitRate;
  }
  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @param waveform SPI waveform, see waveforms for options
   * @param polarity SPI slave select polarity
   * @return actual bit rate
   */
  constexpr std::uint32_t initMaster(std::uint32_t bitRate, waveforms waveform, slavePolaritySelects polarity) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER | static_cast<std::uint32_t>(waveform) | static_cast<std::uint32_t>(polarity);
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
  constexpr std::uint32_t setBitRate(std::uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(CLOCK_AHB / bitRate);
    spiPeripheral()->DIV = DIV::DIVVAL(divider);
    return CLOCK_AHB / divider;
  }
  /**
   * @brief Claim the SPI interface
   *
   * @return IN_USE when already in use
   * @return CLAIMED when the claim has been successful
   */
  constexpr libMcu::results claim(void) {
    if (transactionState != detail::asynchronousStates::IDLE) {
      return libMcu::results::IN_USE;
    }
    transactionState = detail::asynchronousStates::CLAIMED;
    return libMcu::results::CLAIMED;
  }
  /**
   * @brief Unclaim the SPI interface
   *
   * @return ERROR when already idle or inconsistent, possible programming error!
   * @return BUSY when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  constexpr libMcu::results unclaim(void) {
    if (transactionState == detail::asynchronousStates::IDLE) {
      return libMcu::results::ERROR;
    } else if (transactionState == detail::asynchronousStates::TRANSACTING_RW) {
      return libMcu::results::BUSY;
    } else {
      transactionState = detail::asynchronousStates::IDLE;
      return libMcu::results::UNCLAIMED;
    }
    return libMcu::results::ERROR;
  }
  /**
   * @brief Start a read and write data transaction
   *
   * @param device SPI device to use
   * @param transmitBuffer data to transmit
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   *
   * @retval STARTED transaction started
   */
  constexpr libMcu::results startReadWrite(chipEnables device, const std::span<transferType> transmitBuffer,
                                           std::span<transferType> receiveBuffer, std::uint32_t bitcount, bool lastAction) {
    if (transactionState != detail::asynchronousStates::CLAIMED) {
      return libMcu::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionReadIndex = 0u;
    transactionWriteData = transmitBuffer;
    transactionReadData = receiveBuffer;
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::asynchronousStates::TRANSACTING_RW;
    return libMcu::results::STARTED;
  }
  /**
   * @brief Start a read data transaction
   *
   * @param device SPI device to use
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   *
   * @retval STARTED transaction started
   */
  constexpr libMcu::results startRead(chipEnables device, std::span<transferType> receiveBuffer, std::uint32_t bitcount,
                                      bool lastAction) {
    if (transactionState != detail::asynchronousStates::CLAIMED) {
      return libMcu::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionReadIndex = 0u;
    transactionWriteData = std::span<transferType>();
    transactionReadData = receiveBuffer;
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::asynchronousStates::TRANSACTING_R;
    return libMcu::results::STARTED;
  }
  /**
   * @brief Start a write data transaction
   *
   * @param device SPI device to use
   * @param transmitBuffer data to transmit
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   *
   * @retval STARTED transaction started
   */
  constexpr libMcu::results startWrite(chipEnables device, const std::span<transferType> transmitBuffer, std::uint32_t bitcount,
                                       bool lastAction) {
    if (transactionState != detail::asynchronousStates::CLAIMED) {
      return libMcu::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionReadIndex = 0u;
    transactionWriteData = transmitBuffer;
    transactionReadData = std::span<transferType>();
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::asynchronousStates::TRANSACTING_W;
    return libMcu::results::STARTED;
  }
  // TODO: StartWrite
  /**
   * @brief progress with current transaction
   *
   * @retval BUSY transaction still busy
   * @retval DONE transaction done, data available in buffers
   */
  constexpr libMcu::results progress(void) {
    switch (transactionState) {
      case detail::asynchronousStates::TRANSACTING_RW:
        return progressReadWrite(transactionWriteData[transactionWriteIndex]);
        break;
      case detail::asynchronousStates::TRANSACTING_R:
        return progressReadWrite(0u);  // we send along zero as dummy data
        break;
      case detail::asynchronousStates::TRANSACTING_W:
        return progressWrite();
        break;
      default:
        return libMcu::results::ERROR;
    }
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to spi registers
   */
  static hw::spi::spi *spiPeripheral() {
    return reinterpret_cast<hw::spi::spi *>(spiAddress);
  }

 private:
  /**
   * @brief Partially progress a SPI read
   *
   * Fills a single data element in the read transaction buffer if the interface is ready. This peripheral
   * depends on SPI writes for the read buffer to be filled, the SPI write initiates clocking.
   *
   * @retval DONE when the last data is read
   * @retval BUSY when interface is busy or still some data to be read remains
   */
  constexpr libMcu::results progressPartialRead(void) {
    if ((spiPeripheral()->STAT & STAT::RXRDY) != 0u) {
      if (transactionReadBits > elementBitCnt) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
        transactionReadBits -= elementBitCnt;
        transactionReadIndex++;
      } else if (transactionReadBits > 0u) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
        transactionState = detail::asynchronousStates::CLAIMED;
        transactionReadBits = 0u;
        return libMcu::results::DONE;
      }
    }
    return libMcu::results::BUSY;
  }
  /**
   * @brief Partially progress a SPI write
   *
   * @param transferCommand SPI write command pattern to use for this SPI write
   * @param data SPI data to write for this SPI write
   * @retval DONE when the last data element is written
   * @retval BUSY when interface is busy or still some data remains
   */
  constexpr libMcu::results progressPartialWrite(std::uint32_t transferCommand, transferType data) {
    if (((spiPeripheral()->STAT & STAT::TXRDY) != 0u)) {
      if (transactionWriteBits > elementBitCnt) {
        spiPeripheral()->TXDATCTL = transferCommand | TXDATCTL::TXDAT(static_cast<uint16_t>(data)) | TXDATCTL::LEN(elementBitCnt);
        transactionWriteBits -= elementBitCnt;
        transactionWriteIndex++;
      } else if (transactionWriteBits > 0u) {
        if (transactionDisableDevice)
          transferCommand |= TXDATCTL::EOT;
        spiPeripheral()->TXDATCTL =
          transferCommand | TXDATCTL::TXDAT(static_cast<uint16_t>(data)) | TXDATCTL::LEN(transactionWriteBits);
        transactionWriteBits = 0u;  // reset to zero so any further calls while TX is ready will cause no data written
        return libMcu::results::DONE;
      }
    }
    return libMcu::results::BUSY;
  }
  /**
   * @brief progress with current read write transaction
   *
   * @param data SPI data to write for this SPI read/write
   * @retval BUSY transaction still busy
   * @retval DONE transaction done, data available in buffers
   */
  constexpr libMcu::results progressReadWrite(transferType data) {
    libMcu::results readResult = progressPartialRead();
    if (readResult == libMcu::results::DONE)
      return libMcu::results::DONE;
    progressPartialWrite(TXDATCTL::TXSSEL(static_cast<std::uint32_t>(transactionDeviceEnable)), data);
    return libMcu::results::BUSY;
  }
  /**
   * @brief progress with current write transaction
   *
   * @retval BUSY transaction still busy
   * @retval DONE transaction done, data available in buffers
   */
  constexpr libMcu::results progressWrite(void) {
    libMcu::results writeResult =
      progressPartialWrite(TXDATCTL::TXSSEL(static_cast<std::uint32_t>(transactionDeviceEnable)) | TXDATCTL::RXIGNORE,
                           transactionWriteData[transactionWriteIndex]);
    if (writeResult == libMcu::results::DONE) {
      transactionState = detail::asynchronousStates::CLAIMED;
      return libMcu::results::DONE;
    } else
      return writeResult;
  }

  detail::asynchronousStates transactionState;  /**< spi transaction state */
  std::size_t transactionWriteIndex;            /**< transaction write buffer index */
  std::size_t transactionReadIndex;             /**< transaction read buffer index */
  std::span<transferType> transactionWriteData; /**< data to write */
  std::span<transferType> transactionReadData;  /**< where to put read data in */
  std::uint32_t transactionWriteBits;           /**< Bits remaining in current transaction */
  std::uint32_t transactionReadBits;            /**< Bits remaining in current transaction */
  chipEnables transactionDeviceEnable;          /**< Disable chip after transaction */
  bool transactionDisableDevice;                /**< Do we disable chip select after transaction */
  static constexpr std::uint8_t elementBitCnt =
    std::numeric_limits<transferType>::digits;                     /**< Amount of bits in datatransfer type */
  static constexpr libMcu::hwAddressType spiAddress = spiAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::spi
#endif