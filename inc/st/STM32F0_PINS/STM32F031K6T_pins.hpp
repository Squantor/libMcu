/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F031K6T_pins.hpp
 * @brief pin definitions for the STM32F031K6T microcontroller
 */
#ifndef STM32F031K6T_PINS_HPP
#define STM32F031K6T_PINS_HPP
namespace libmcuhw {
namespace hardware = libmcuhw::gpio;

/**
 * @brief pins available on the STM32F031K6T
 */
enum class IoPins : std::uint8_t {
  kPa0,  /*!< PA0 pin */
  kPa1,  /*!< PA1 pin */
  kPa2,  /*!< PA2 pin */
  kPa3,  /*!< PA3 pin */
  kPa4,  /*!< PA4 pin */
  kPa5,  /*!< PA5 pin */
  kPa6,  /*!< PA6 pin */
  kPa7,  /*!< PA7 pin */
  kPa8,  /*!< PA8 pin */
  kPa9,  /*!< PA9 pin */
  kPa10, /*!< PA10 pin */
  kPa11, /*!< PA11 pin */
  kPa12, /*!< PA12 pin */
  kPa13, /*!< PA13 pin */
  kPa14, /*!< PA14 pin */
  kPa15, /*!< PA15 pin */
  kPb0,  /*!< PB0 pin */
  kPb1,  /*!< PB1 pin */
  kPb2,  /*!< PB2 pin */
  kPb3,  /*!< PB3 pin */
  kPb4,  /*!< PB4 pin */
  kPb5,  /*!< PB5 pin */
  kPb6,  /*!< PB6 pin */
  kPb7,  /*!< PB7 pin */
  kPf0,  /*!< PF0 pin */
  kPf1,  /*!< PF1 pin */
};

/**
 * @brief ports available on the STM32F031K6T
 */
enum class IoPorts : std::uint8_t {
  kPortA, /*!< Port A */
  kPortB, /*!< Port B */
  kPortF, /*!< Port F */
};
/**
 * @brief STM32F031 I/O functions
 * Some of them might not be available on the microcontroller it is for
 */
enum class IoFunctions : std::uint8_t {
  kGpio,      /*!< GPIO function */
  kEventOut,  /*!< EVENTOUT function */
  kMco,       /*!< MCO function */
  kSwdio,     /*!< SWDIO */
  kIrOut,     /*!< Infrared out */
  kSwclk,     /*!< SWCLK */
  kUsart1Tx,  /*!< USART1 transmit */
  kUsart1Rx,  /*!< USART1 receive */
  kUsart1Cts, /*!< USART1 clear to send */
  kUsart1Rts, /*!< USART1 request to send */
  kUsart1Ck,  /*!< USART1 clock */
  kSpi1Miso,  /*!< SPI1 MISO */
  kSpi1Mosi,  /*!< SPI1 MOSI */
  kSpi1Sck,   /*!< SPI1 clock */
  kSpi1Nss,   /*!< SPI1 NSS */
  kI2s1Sd,    /*!< I2S1 SD */
  kI2s1Mck,   /*!< I2S1 master clock */
  kI2s1Ws,    /*!< I2S1 word select */
  kI2s1Ck,    /*!< I2S1 clock */
  kI2c1Scl,   /*!< I2C1 clock */
  kI2c1Sda,   /*!< I2C1 data */
  kI2c1Smba,  /*!< I2C1 SMBus alert */
  kTim1Bkin,  /*!< TIM1 break input */
  kTim1Ch1,   /*!< TIM1 channel 1 output */
  kTim1Ch1n,  /*!< TIM1 channel 1 complimentary output */
  kTim1Ch2,   /*!< TIM1 channel 2 output */
  kTim1Ch2n,  /*!< TIM1 channel 2 complimentary output */
  kTim1Ch3,   /*!< TIM1 channel 3 output */
  kTim1Ch3n,  /*!< TIM1 channel 3 complimentary output */
  kTim1Ch4,   /*!< TIM1 channel 4 output */
  kTim1ETR,   /*!< TIM1 external trigger */
  kTim2ChEtr, /*!< TIM2 channel external trigger */
  kTim2Ch2,   /*!< TIM2 channel 2 output */
  kTim2Ch3,   /*!< TIM2 channel 3 output */
  kTim2Ch4,   /*!< TIM2 channel 4 output */
  kTim3Ch1,   /*!< TIM3 channel 1 output */
  kTim3Ch2,   /*!< TIM3 channel 2 output */
  kTim3Ch3,   /*!< TIM3 channel 3 output */
  kTim3Ch4,   /*!< TIM3 channel 4 output */
  kTim14Ch1,  /*!< TIM14 channel 1 output */
  kTim16Ch1,  /*!< TIM16 channel 1 output */
  kTim16Ch1n, /*!< TIM16 channel 1 complimentary output */
  kTim16BkIn, /*!< TIM16 break input */
  kTim17Ch1,  /*!< TIM17 channel 1 output */
  kTim17Ch1n, /*!< TIM17 channel 1 complimentary output */
  kTim17BkIn, /*!< TIM17 break input */
};

/**
 * @brief Available pin function selects available
 */
enum class IOfunctSelects : std::uint8_t {
  kAf0 = libmcuhw::gpio::AFR::AF0, /*!< Alternate function 0 */
  kAf1 = libmcuhw::gpio::AFR::AF1, /*!< Alternate function 1 */
  kAf2 = libmcuhw::gpio::AFR::AF2, /*!< Alternate function 2 */
  kAf3 = libmcuhw::gpio::AFR::AF3, /*!< Alternate function 3 */
  kAf4 = libmcuhw::gpio::AFR::AF4, /*!< Alternate function 4 */
  kAf5 = libmcuhw::gpio::AFR::AF5, /*!< Alternate function 5 */
  kAf6 = libmcuhw::gpio::AFR::AF6, /*!< Alternate function 6 */
  kAf7 = libmcuhw::gpio::AFR::AF7, /*!< Alternate function 7 */
  kNone = 0xff,                    /*!< No alternate function */
};

/**
 * @brief base I/O pin template
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IoPorts port, IoPins pin, IoFunctions function, bool dummy = false>
struct Pin : libmcu::PinBase {
  static_assert(dummy, "This I/O pin configuration is invalid!");
};

/**
 * @brief Specialization for Pin 8 on Port A with MCO function
 */
template <>
struct Pin<IoPorts::kPortA, IoPins::kPa8, IoFunctions::kGpio> : libmcu::PinBase {
  static constexpr IOfunctSelects function_select = IOfunctSelects::kNone;
};

/**
 * @brief Specialization for Pin 8 on Port A with MCO function
 */
template <>
struct Pin<IoPorts::kPortA, IoPins::kPa8, IoFunctions::kMco> : libmcu::PinBase {
  static constexpr IOfunctSelects function_select = IOfunctSelects::kAf0;
};

}  // namespace libmcuhw

#endif