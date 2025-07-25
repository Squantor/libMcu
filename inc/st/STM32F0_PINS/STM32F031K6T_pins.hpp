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
  Pa0,  /*!< PA0 pin */
  Pa1,  /*!< PA1 pin */
  Pa2,  /*!< PA2 pin */
  Pa3,  /*!< PA3 pin */
  Pa4,  /*!< PA4 pin */
  Pa5,  /*!< PA5 pin */
  Pa6,  /*!< PA6 pin */
  Pa7,  /*!< PA7 pin */
  Pa8,  /*!< PA8 pin */
  Pa9,  /*!< PA9 pin */
  Pa10, /*!< PA10 pin */
  Pa11, /*!< PA11 pin */
  Pa12, /*!< PA12 pin */
  Pa13, /*!< PA13 pin */
  Pa14, /*!< PA14 pin */
  Pa15, /*!< PA15 pin */
  Pb0,  /*!< PB0 pin */
  Pb1,  /*!< PB1 pin */
  Pb2,  /*!< PB2 pin */
  Pb3,  /*!< PB3 pin */
  Pb4,  /*!< PB4 pin */
  Pb5,  /*!< PB5 pin */
  Pb6,  /*!< PB6 pin */
  Pb7,  /*!< PB7 pin */
  Pf0,  /*!< PF0 pin */
  Pf1,  /*!< PF1 pin */
};

/**
 * @brief ports available on the STM32F031K6T
 */
enum class IoPorts : std::uint8_t {
  PortA, /*!< Port A */
  PortB, /*!< Port B */
  PortF, /*!< Port F */
};
/**
 * @brief STM32F031 I/O functions
 * Some of them might not be available on the microcontroller it is for
 */
enum class IoFunctions : std::uint8_t {
  Gpio,      /*!< GPIO function */
  EventOut,  /*!< EVENTOUT function */
  Mco,       /*!< MCO function */
  Swdio,     /*!< SWDIO */
  IrOut,     /*!< Infrared out */
  Swclk,     /*!< SWCLK */
  Usart1Tx,  /*!< USART1 transmit */
  Usart1Rx,  /*!< USART1 receive */
  Usart1Cts, /*!< USART1 clear to send */
  Usart1Rts, /*!< USART1 request to send */
  Usart1Ck,  /*!< USART1 clock */
  Spi1Miso,  /*!< SPI1 MISO */
  Spi1Mosi,  /*!< SPI1 MOSI */
  Spi1Sck,   /*!< SPI1 clock */
  Spi1Nss,   /*!< SPI1 NSS */
  I2s1Sd,    /*!< I2S1 SD */
  I2s1Mck,   /*!< I2S1 master clock */
  I2s1Ws,    /*!< I2S1 word select */
  I2s1Ck,    /*!< I2S1 clock */
  I2c1Scl,   /*!< I2C1 clock */
  I2c1Sda,   /*!< I2C1 data */
  I2c1Smba,  /*!< I2C1 SMBus alert */
  Tim1Bkin,  /*!< TIM1 break input */
  Tim1Ch1,   /*!< TIM1 channel 1 output */
  Tim1Ch1n,  /*!< TIM1 channel 1 complimentary output */
  Tim1Ch2,   /*!< TIM1 channel 2 output */
  Tim1Ch2n,  /*!< TIM1 channel 2 complimentary output */
  Tim1Ch3,   /*!< TIM1 channel 3 output */
  Tim1Ch3n,  /*!< TIM1 channel 3 complimentary output */
  Tim1Ch4,   /*!< TIM1 channel 4 output */
  Tim1ETR,   /*!< TIM1 external trigger */
  Tim2ChEtr, /*!< TIM2 channel external trigger */
  Tim2Ch2,   /*!< TIM2 channel 2 output */
  Tim2Ch3,   /*!< TIM2 channel 3 output */
  Tim2Ch4,   /*!< TIM2 channel 4 output */
  Tim3Ch1,   /*!< TIM3 channel 1 output */
  Tim3Ch2,   /*!< TIM3 channel 2 output */
  Tim3Ch3,   /*!< TIM3 channel 3 output */
  Tim3Ch4,   /*!< TIM3 channel 4 output */
  Tim14Ch1,  /*!< TIM14 channel 1 output */
  Tim16Ch1,  /*!< TIM16 channel 1 output */
  Tim16Ch1n, /*!< TIM16 channel 1 complimentary output */
  Tim16BkIn, /*!< TIM16 break input */
  Tim17Ch1,  /*!< TIM17 channel 1 output */
  Tim17Ch1n, /*!< TIM17 channel 1 complimentary output */
  Tim17BkIn, /*!< TIM17 break input */
};

/**
 * @brief Available pin function selects available
 */
enum class IOfunctSelects : std::uint8_t {
  Af0 = libmcuhw::gpio::AFR::AF0, /*!< Alternate function 0 */
  Af1 = libmcuhw::gpio::AFR::AF1, /*!< Alternate function 1 */
  Af2 = libmcuhw::gpio::AFR::AF2, /*!< Alternate function 2 */
  Af3 = libmcuhw::gpio::AFR::AF3, /*!< Alternate function 3 */
  Af4 = libmcuhw::gpio::AFR::AF4, /*!< Alternate function 4 */
  Af5 = libmcuhw::gpio::AFR::AF5, /*!< Alternate function 5 */
  Af6 = libmcuhw::gpio::AFR::AF6, /*!< Alternate function 6 */
  Af7 = libmcuhw::gpio::AFR::AF7, /*!< Alternate function 7 */
  None = 0xff,                    /*!< No alternate function */
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
struct Pin<IoPorts::PortA, IoPins::Pa8, IoFunctions::Gpio> : libmcu::PinBase {
  static constexpr IOfunctSelects function_select = IOfunctSelects::None;
};

/**
 * @brief Specialization for Pin 8 on Port A with MCO function
 */
template <>
struct Pin<IoPorts::PortA, IoPins::Pa8, IoFunctions::Mco> : libmcu::PinBase {
  static constexpr IOfunctSelects function_select = IOfunctSelects::Af0;
};

}  // namespace libmcuhw

#endif