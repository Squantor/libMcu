/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_i2c_int_ll.hpp
 * @brief LPC84X series Interrupt driven I2C low level interface class and definitions
 */
#ifndef LPC84X_I2C_INT_LL_HPP
#define LPC84X_I2C_INT_LL_HPP

namespace libmcull::i2c {
namespace hardware = libmcuhw::i2c;
/**
 * @brief
 * @tparam i2c_address
 * @todo error handling is lacking, need a centralized error handler and additional result codes
 * @todo claim and unclaim maybe need a handle number to ensure no double unclaims
 * @todo the async calls have some master waits for the address transmission phase, this could be handled without waiting but needs
 * probably an additional state and address variable
 * @todo duplicate code in entry on multiple methods checking states, refactor
 */
template <libmcu::I2cBaseAddress i2c_address>
struct I2cInterrupt : libmcull::AsyncI2cBase {
  /**
   * @brief Get the I2C interrupt peripheral current status
   * @return current status
   */
  constexpr libmcu::Results GetStatus() {
    return static_cast<libmcu::Results>(current_state);
  }
  /**
   * @brief Initialize I2C master
   * @todo need to take into account the sampling periods of SCL SDA
   * @tparam clock_config clock configuration
   * @param bit_rate requested bit rate
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t peripheralFrequency = GetInputClockFreq<clock_config>();
    std::uint32_t divider = peripheralFrequency / (bit_rate * 20);
    GetPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    GetPeripheral()->CLKDIV = divider + 1;
    GetPeripheral()->INTENCLR = hardware::INTENCLR::RESERVED_MASK;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTARBLOSSEN | hardware::INTENSET::MSTSTSTPERREN |
                                hardware::INTENSET::EVENTTIMEOUTEN | hardware::INTENSET::SCLTIMEOUTEN;
    GetPeripheral()->CFG = hardware::CFG::MSTEN;
    current_state = libmcu::States::Idle;
    return peripheralFrequency / divider / 20;
  }
  /**
   * @brief Progress the I2C interface
   * This should be periodically called to continue operation and callback if needed
   */
  void Progress(void) {
    if (current_state == libmcu::States::BusyCallbackSingle) {
      if (transaction_callback != nullptr) {
        transaction_callback->Callback();
      }
      current_state = libmcu::States::Idle;
    } else if (current_state == libmcu::States::BusyCallbackMultiTx) {
      if (transaction_callback != nullptr) {
        transaction_callback->Callback();
      }
      current_state = libmcu::States::WaitForNextTransmit;
    } else if (current_state == libmcu::States::BusyCallbackMultiRx) {
      if (transaction_callback != nullptr) {
        transaction_callback->Callback();
      }
      current_state = libmcu::States::WaitForNextReceive;
    }
  }
  /**
   * @brief Callback method
   * Not called by anything as this is a top level driver
   */
  void Callback(void) {}
  /**
   * @brief Transmit data to I2C device
   * @param address I2C device to transmit to
   * @param buffer Data to transmit
   * @param transaction_type Transaction type
   */
  constexpr libmcu::Results Transmit(const libmcu::I2cDeviceAddress address, std::span<std::uint8_t> buffer,
                                     libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::Idle) {
      return static_cast<libmcu::Results>(current_state);
    }
    current_state = libmcu::States::BusyTransmitSingle;
    transaction_callback = callback;
    buffer_index = 0;
    transmit_buffer = buffer;
    GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Receive data from I2C device
   * @param address I2C device to receive from
   * @param receive_buffer place to put received data, needs to be at least size 1!
   */
  constexpr libmcu::Results Receive(const libmcu::I2cDeviceAddress address, std::span<std::uint8_t> buffer,
                                    libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::Idle) {
      return static_cast<libmcu::Results>(current_state);
    }
    current_state = libmcu::States::BusyReceiveSingle;
    transaction_callback = callback;
    buffer_index = 0;
    receive_buffer = buffer;
    GetPeripheral()->MSTDAT = (static_cast<std::uint32_t>(address.value) << 1) | 0x01;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }

  /**
   * @brief Starts a transmit operation and transmits a block of data
   * Leaves the I2C bus open
   * @param address I2C address
   * @param transmit_buffer Buffer of data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcu::I2cDeviceAddress address, const std::span<const std::uint8_t> buffer,
                                                libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::Idle) {
      return static_cast<libmcu::Results>(current_state);
    }
    buffer_index = 0;
    transmit_buffer = buffer;
    return StartMasterTransmit(address, callback);
  }
  /**
   * @brief Starts a transmit operation and writes a single byte
   * Leaves the I2C bus open
   * @param address I2C address
   * @param data Byte to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcu::I2cDeviceAddress address, const std::uint8_t data,
                                                libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::Idle) {
      return static_cast<libmcu::Results>(current_state);
    }
    buffer_index = 0;
    single_byte_transmit_buffer[0] = data;
    transmit_buffer = single_byte_transmit_buffer;
    return StartMasterTransmit(address, callback);
  }
  /**
   * @brief Starts transmitting I2C data to a closed I2C bus
   * Leaves the I2C bus open
   * @param address Address data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(libmcu::I2cDeviceAddress address, libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::Idle) {
      return static_cast<libmcu::Results>(current_state);
    }
    current_state = libmcu::States::BusyTransmitMulti;
    transaction_callback = callback;
    GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Starts receiving I2C data to a closed I2C bus
   * Leaves the I2C bus open
   * @param address Address data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterReceive(libmcu::I2cDeviceAddress address, std::span<std::uint8_t> buffer,
                                               libmcu::AsyncInterface *callback = nullptr) {
    buffer_index = 0;
    receive_buffer = buffer;
    return StartMasterReceive(address, callback);
  }
  /**
   * @brief Starts receiving I2C data to a closed I2C bus
   * Leaves the I2C bus open
   * @param address Address data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterReceive(libmcu::I2cDeviceAddress address, libmcu::AsyncInterface *callback = nullptr) {
    current_state = libmcu::States::BusyReceiveMulti;
    transaction_callback = callback;
    GetPeripheral()->MSTDAT = (static_cast<std::uint32_t>(address.value) << 1) | 0x01;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param transmit_buffer Data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(const std::span<const std::uint8_t> buffer,
                                                   libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextTransmit) {
      return static_cast<libmcu::Results>(current_state);
    }
    transmit_buffer = buffer;
    return ContinueMasterTransmit(callback);
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param data Data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(const std::uint8_t data, libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextTransmit) {
      return static_cast<libmcu::Results>(current_state);
    }
    single_byte_transmit_buffer[0] = data;
    transmit_buffer = single_byte_transmit_buffer;
    return ContinueMasterTransmit(callback);
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param callback Callback when completed
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextTransmit) {
      return static_cast<libmcu::Results>(current_state);
    }
    buffer_index = 0;
    current_state = libmcu::States::BusyTransmitMulti;
    transaction_callback = callback;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param transmit_buffer Data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterReceive(std::span<std::uint8_t> buffer, libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextReceive) {
      return static_cast<libmcu::Results>(current_state);
    }
    buffer_index = 0;
    receive_buffer = buffer;
    return ContinueMasterReceive(callback);
  }
  /**
   * @brief Receives more I2C data
   * Leaves the I2C bus open
   * @param callback Callback when completed
   * @return
   */
  constexpr libmcu::Results ContinueMasterReceive(libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextReceive) {
      return static_cast<libmcu::Results>(current_state);
    }
    current_state = libmcu::States::BusyReceiveMulti;
    transaction_callback = callback;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Stops I2C master
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StopMaster(libmcu::AsyncInterface *callback = nullptr) {
    if (current_state != libmcu::States::WaitForNextTransmit && current_state != libmcu::States::WaitForNextReceive) {
      return static_cast<libmcu::Results>(current_state);
    }
    transaction_callback = callback;
    current_state = libmcu::States::Busy;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
    return libmcu::Results::NoError;
  }
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void MasterWait() {
    // @todo add timeout
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Interrupt handler for this I2C peripheral
   * @todo separate handling for reception/transmission depending on state?
   * @todo there might be contention issue on current_state, better to have a separate state variable?
   * We do not check if we are in transmit/read state as the i2c statemachine will have the correct states
   */
  constexpr void InterruptHandler() {
    std::uint32_t status = GetPeripheral()->STAT & hardware::STAT::RESERVED_MASK;
    if (status & hardware::STAT::MSTPENDING) {
      std::uint32_t status_state = status & hardware::STAT::MSTSTATE_MASK;

      if (status_state == hardware::STAT::MSTSTATE_IDLE) {
        // we are idle, disable interrupts
        GetPeripheral()->INTENCLR = hardware::INTENCLR::MSTPENDINGCLR;
        current_state = libmcu::States::BusyCallbackSingle;  // we are done, callback if needed
      } else if (status_state == hardware::STAT::MSTSTATE_RXRDY) {
        receive_buffer[buffer_index++] = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
        if (buffer_index < receive_buffer.size()) {
          GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
        } else {
          if (current_state == libmcu::States::BusyReceiveSingle) {
            // no more future transfers, send stop
            GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
          } else if (current_state == libmcu::States::BusyReceiveMulti) {
            // we have future transfers, disable master pending interrupt and go to callback state
            GetPeripheral()->INTENCLR = hardware::INTENCLR::MSTPENDINGCLR;
            current_state = libmcu::States::BusyCallbackMultiRx;
          }
        }
      } else if (status_state == hardware::STAT::MSTSTATE_TXRDY) {
        if (buffer_index < transmit_buffer.size()) {
          GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(transmit_buffer[buffer_index++]);
          GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
        } else {
          if (current_state == libmcu::States::BusyTransmitSingle) {
            // no more future transfers, send stop
            GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
          } else if (current_state == libmcu::States::BusyTransmitMulti) {
            // we have future transfers, disable master pending interrupt and go to callback state
            GetPeripheral()->INTENCLR = hardware::INTENCLR::MSTPENDINGCLR;
            current_state = libmcu::States::BusyCallbackMultiTx;
          }
        }
      } else if (status_state == hardware::STAT::MSTSTATE_NACK_ADDR) {
        //! @todo handle Address NACK
      } else if (status_state == hardware::STAT::MSTSTATE_NACK_DATA) {
        //! @todo handle data NACK
      }
    }
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((i2c_address_ == libmcuhw::I2c0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C0))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::I2c1Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C1))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::I2c2Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C2))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::I2c3Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C3))
      return clock_config.GetFrequency();
    else
      static_assert(false, "Clock config and peripherals unknown or not matching!");
    return 0;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to i2c registers
   */
  constexpr static hardware::I2c *GetPeripheral() {
    return reinterpret_cast<hardware::I2c *>(i2c_address_);
  }

 private:
  static constexpr libmcu::HwAddressType i2c_address_ = i2c_address; /*!< peripheral address */
  volatile libmcu::States current_state;                             /*!< current state */
  std::span<std::uint8_t> receive_buffer;                            /*!< Receive buffer */
  std::span<const std::uint8_t> transmit_buffer;                     /*!< transmit buffer */
  std::size_t buffer_index;                                          /*!< current buffer index */
  libmcu::AsyncInterface *transaction_callback;                      /*!< Pointer to class with async callback */
  std::array<std::uint8_t, 1> single_byte_transmit_buffer;           /*!< Buffer for single byte transmits */
};
}  // namespace libmcull::i2c
#endif