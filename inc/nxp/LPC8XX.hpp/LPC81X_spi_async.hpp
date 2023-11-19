/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series asynchronous SPI functions
 */
#ifndef LPC81X_SPI_ASYNC_HPP
#define LPC81X_SPI_ASYNC_HPP

#include "LPC81X_spi_common.hpp"

namespace libMcuLL {
namespace sw {
namespace spi {
namespace detail {

enum class synchonousStates : std::uint8_t {
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
 * @tparam address_ Peripheral base address
 * @tparam chipEnables enum of available chip enables
 * @tparam transferType datatype to use for data transfers
 */
template <libMcuLL::SPIbaseAddress address_, typename chipEnables, typename transferType>
struct spiAsync {
  /**
   * @brief Construct a new spi Async object
   *
   * Initializes the internal state to defaults
   *
   */
  spiAsync() : transactionState{detail::synchonousStates::IDLE} {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to spi registers
   */
  static hw::spi::peripheral *regs() {
    return reinterpret_cast<hw::spi::peripheral *>(address);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  std::uint32_t initMaster(std::uint32_t bitRate) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER;
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
  std::uint32_t initMaster(std::uint32_t bitRate, waveforms waveform, slavePolaritySelects polarity) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER | static_cast<std::uint32_t>(waveform) | static_cast<std::uint32_t>(polarity);
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
  std::uint32_t setBitRate(std::uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(CLOCK_AHB / bitRate);
    regs()->DIV = DIV::DIVVAL(divider);
    return CLOCK_AHB / divider;
  }

  /**
   * @brief Claim the SPI interface
   *
   * @return IN_USE when already in use
   * @return CLAIMED when the claim has been successful
   */
  libMcuLL::results claim(void) {
    if (transactionState != detail::synchonousStates::IDLE) {
      return libMcuLL::results::IN_USE;
    }
    transactionState = detail::synchonousStates::CLAIMED;
    return libMcuLL::results::CLAIMED;
  }

  /**
   * @brief Unclaim the SPI interface
   *
   * @return ERROR when already idle or inconsistent, possible programming error!
   * @return BUSY when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  libMcuLL::results unclaim(void) {
    if (transactionState == detail::synchonousStates::IDLE) {
      return libMcuLL::results::ERROR;
    } else if (transactionState == detail::synchonousStates::TRANSACTING_RW) {
      return libMcuLL::results::BUSY;
    } else {
      transactionState = detail::synchonousStates::IDLE;
      return libMcuLL::results::UNCLAIMED;
    }
    return libMcuLL::results::ERROR;
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
   * @retval libMcuLL::results::STARTED transaction started
   */
  libMcuLL::results startReadWrite(chipEnables device, const std::span<transferType> transmitBuffer,
                                   std::span<transferType> receiveBuffer, std::uint32_t bitcount, bool lastAction) {
    if (transactionState != detail::synchonousStates::CLAIMED) {
      return libMcuLL::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0;
    transactionReadIndex = 0;
    transactionWriteData = transmitBuffer;
    transactionReadData = receiveBuffer;
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::synchonousStates::TRANSACTING_RW;
    return libMcuLL::results::STARTED;
  }

  /**
   * @brief Start a read data transaction
   *
   * @param device SPI device to use
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   *
   * @retval libMcuLL::results::STARTED transaction started
   */
  libMcuLL::results startRead(chipEnables device, std::span<transferType> receiveBuffer, std::uint32_t bitcount, bool lastAction) {
    if (transactionState != detail::synchonousStates::CLAIMED) {
      return libMcuLL::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0;
    transactionReadIndex = 0;
    transactionWriteData = std::span<transferType>();
    transactionReadData = receiveBuffer;
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::synchonousStates::TRANSACTING_R;
    return libMcuLL::results::STARTED;
  }

  /**
   * @brief Start a write data transaction
   *
   * @param device SPI device to use
   * @param transmitBuffer data to transmit
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   *
   * @retval libMcuLL::results::STARTED transaction started
   */
  libMcuLL::results startWrite(chipEnables device, const std::span<transferType> transmitBuffer, std::uint32_t bitcount,
                               bool lastAction) {
    if (transactionState != detail::synchonousStates::CLAIMED) {
      return libMcuLL::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0;
    transactionReadIndex = 0;
    transactionWriteData = transmitBuffer;
    transactionReadData = std::span<transferType>();
    transactionWriteBits = bitcount;
    transactionReadBits = bitcount;
    transactionDeviceEnable = device;
    transactionDisableDevice = lastAction;
    // TODO: Enable device
    transactionState = detail::synchonousStates::TRANSACTING_W;
    return libMcuLL::results::STARTED;
  }

  // TODO: StartWrite
  /**
   * @brief progress with current transaction
   *
   * @retval libMcuLL::results::BUSY transaction still busy
   * @retval libMcuLL::results::DONE transaction done, data available in buffers
   */
  libMcuLL::results progress(void) {
    switch (transactionState) {
      case detail::synchonousStates::TRANSACTING_RW:
        return progressReadWrite();
        break;
      case detail::synchonousStates::TRANSACTING_R:
        return progressRead();
        break;
      case detail::synchonousStates::TRANSACTING_W:
        return progressWrite();
        break;
      default:
        return libMcuLL::results::ERROR;
    }
  }

 private:
  /**
   * @brief progress with current read write transaction
   *
   * @retval libMcuLL::results::BUSY transaction still busy
   * @retval libMcuLL::results::DONE transaction done, data available in buffers
   */
  libMcuLL::results progressReadWrite(void) {
    std::uint32_t address_TransferCommand = TXDATCTL::TXSSEL(transactionDeviceEnable);
    // data read path, best to put it first as a write will generate data
    if ((regs()->STAT & STAT::RXRDY) != 0) {
      if (transactionReadBits > elementBitCnt) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(regs()->RXDAT);
        transactionReadBits -= elementBitCnt;
        transactionReadIndex++;
      } else if (transactionReadBits > 0) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(regs()->RXDAT);
        transactionState = detail::synchonousStates::CLAIMED;
        return libMcuLL::results::DONE;
      }
    }
    // data write path
    if (((regs()->STAT & STAT::TXRDY) != 0)) {
      if (transactionWriteBits > elementBitCnt) {
        regs()->TXDATCTL =
          address_TransferCommand | TXDATCTL::TXDAT(transactionWriteData[transactionWriteIndex]) | TXDATCTL::LEN(16);
        transactionWriteBits -= elementBitCnt;
        transactionWriteIndex++;
      } else if (transactionWriteBits > 0) {
        if (transactionDisableDevice)
          address_TransferCommand |= TXDATCTL::EOT;
        regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transactionWriteData[transactionWriteIndex]) |
                           TXDATCTL::LEN(transactionWriteBits);
        transactionWriteBits = 0;  // reset to zero so any further calls while TX is ready will cause no data written
      }
    }
    return libMcuLL::results::BUSY;
  }

  /**
   * @brief progress with current read transaction
   *
   * @retval libMcuLL::results::BUSY transaction still busy
   * @retval libMcuLL::results::DONE transaction done, data available in buffers
   */
  libMcuLL::results progressRead(void) {
    std::uint32_t address_TransferCommand = TXDATCTL::TXSSEL(transactionDeviceEnable);
    // data read path, best to put it first as a write will generate data
    if ((regs()->STAT & STAT::RXRDY) != 0) {
      if (transactionReadBits > 16) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(regs()->RXDAT);
        transactionReadBits -= 16;
        transactionReadIndex++;
      } else if (transactionReadBits > 0) {
        transactionReadData[transactionReadIndex] = RXDAT::RXDAT(regs()->RXDAT);
        transactionState = detail::synchonousStates::CLAIMED;
        return libMcuLL::results::DONE;
      }
    }
    // data write path
    if (((regs()->STAT & STAT::TXRDY) != 0)) {
      if (transactionWriteBits > 16) {
        regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(0x0000) | TXDATCTL::LEN(16);
        transactionWriteBits -= 16;
        transactionWriteIndex++;
      } else if (transactionWriteBits > 0) {
        if (transactionDisableDevice)
          address_TransferCommand |= TXDATCTL::EOT;
        regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(0x0000) | TXDATCTL::LEN(transactionWriteBits);
        transactionWriteBits = 0;  // reset to zero so any further calls while TX is ready will cause no data written
      }
    }
    return libMcuLL::results::BUSY;
  }

  /**
   * @brief progress with current write transaction
   *
   * @retval libMcuLL::results::BUSY transaction still busy
   * @retval libMcuLL::results::DONE transaction done, data available in buffers
   */
  libMcuLL::results progressWrite(void) {
    std::uint32_t address_TransferCommand = TXDATCTL::TXSSEL(transactionDeviceEnable) | TXDATCTL::RXIGNORE;
    // data write path
    if (((regs()->STAT & STAT::TXRDY) != 0)) {
      if (transactionWriteBits > 16) {
        regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(0x0000) | TXDATCTL::LEN(16);
        transactionWriteBits -= 16;
        transactionWriteIndex++;
      } else if (transactionWriteBits > 0) {
        if (transactionDisableDevice)
          address_TransferCommand |= TXDATCTL::EOT;
        regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(0x0000) | TXDATCTL::LEN(transactionWriteBits);
        transactionWriteBits = 0;  // reset to zero so any further calls while TX is ready will cause no data written
        return libMcuLL::results::DONE;
      }
    }
    return libMcuLL::results::BUSY;
  }

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  detail::synchonousStates transactionState;                   /**< spi transaction state */
  std::size_t transactionWriteIndex;                           /**< transaction write buffer index */
  std::size_t transactionReadIndex;                            /**< transaction read buffer index */
  std::span<transferType> transactionWriteData;                /**< data to write */
  std::span<transferType> transactionReadData;                 /**< where to put read data in */
  std::uint32_t transactionWriteBits;                          /**< Bits remaining in current transaction */
  std::uint32_t transactionReadBits;                           /**< Bits remaining in current transaction */
  chipEnables transactionDeviceEnable;                         /**< Disable chip after transaction */
  bool transactionDisableDevice;                               /**< Do we disable chip select after transaction */
  static constexpr std::uint8_t elementBitCnt =
    std::numeric_limits<transferType>::digits; /**< Amount of bits in datatransfer type */
};
}  // namespace spi
}  // namespace sw
}  // namespace libMcuLL

#endif