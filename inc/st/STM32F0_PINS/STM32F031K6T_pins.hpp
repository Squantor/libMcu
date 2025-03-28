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
enum class IOpins : std::uint8_t {
  PA0,  /*!< PA0 pin */
  PA1,  /*!< PA1 pin */
  PA2,  /*!< PA2 pin */
  PA3,  /*!< PA3 pin */
  PA4,  /*!< PA4 pin */
  PA5,  /*!< PA5 pin */
  PA6,  /*!< PA6 pin */
  PA7,  /*!< PA7 pin */
  PA8,  /*!< PA8 pin */
  PA9,  /*!< PA9 pin */
  PA10, /*!< PA10 pin */
  PA11, /*!< PA11 pin */
  PA12, /*!< PA12 pin */
  PA13, /*!< PA13 pin */
  PA14, /*!< PA14 pin */
  PA15, /*!< PA15 pin */
  PB0,  /*!< PB0 pin */
  PB1,  /*!< PB1 pin */
  PB2,  /*!< PB2 pin */
  PB3,  /*!< PB3 pin */
  PB4,  /*!< PB4 pin */
  PB5,  /*!< PB5 pin */
  PB6,  /*!< PB6 pin */
  PB7,  /*!< PB7 pin */
  PF0,  /*!< PF0 pin */
  PF1,  /*!< PF1 pin */
};

/**
 * @brief ports available on the STM32F031K6T
 */
enum class IOports : std::uint8_t {
  PORTA, /*!< Port A */
  PORTB, /*!< Port B */
  PORTF, /*!< Port F */
};
/**
 * @brief STM32F031 I/O functions
 * Some of them might not be available on the microcontroller it is for
 */
enum class IOfuncts : std::uint8_t {
  GPIO,        /*!< GPIO function */
  EVENTOUT,    /*!< EVENTOUT function */
  MCO,         /*!< MCO function */
  SWDIO,       /*!< SWDIO */
  IR_OUT,      /*!< Infrared out */
  SWCLK,       /*!< SWCLK */
  USART1_TX,   /*!< USART1 transmit */
  USART1_RX,   /*!< USART1 receive */
  USART1_CTS,  /*!< USART1 clear to send */
  USART1_RTS,  /*!< USART1 request to send */
  USART1_CK,   /*!< USART1 clock */
  SPI1_MISO,   /*!< SPI1 MISO */
  SPI1_MOSI,   /*!< SPI1 MOSI */
  SPI1_SCK,    /*!< SPI1 clock */
  SPI1_NSS,    /*!< SPI1 NSS */
  I2S1_SD,     /*!< I2S1 SD */
  I2S1_MCK,    /*!< I2S1 master clock */
  I2S1_WS,     /*!< I2S1 word select */
  I2S1_CK,     /*!< I2S1 clock */
  I2C1_SCL,    /*!< I2C1 clock */
  I2C1_SDA,    /*!< I2C1 data */
  I2C1_SMBA,   /*!< I2C1 SMBus alert */
  TIM1_BKIN,   /*!< TIM1 break input */
  TIM1_CH1,    /*!< TIM1 channel 1 output */
  TIM1_CH1N,   /*!< TIM1 channel 1 complimentary output */
  TIM1_CH2,    /*!< TIM1 channel 2 output */
  TIM1_CH2N,   /*!< TIM1 channel 2 complimentary output */
  TIM1_CH3,    /*!< TIM1 channel 3 output */
  TIM1_CH3N,   /*!< TIM1 channel 3 complimentary output */
  TIM1_CH4,    /*!< TIM1 channel 4 output */
  TIM1_ETR,    /*!< TIM1 external trigger */
  TIM2_CH_ETR, /*!< TIM2 channel external trigger */
  TIM2_CH2,    /*!< TIM2 channel 2 output */
  TIM2_CH3,    /*!< TIM2 channel 3 output */
  TIM2_CH4,    /*!< TIM2 channel 4 output */
  TIM3_CH1,    /*!< TIM3 channel 1 output */
  TIM3_CH2,    /*!< TIM3 channel 2 output */
  TIM3_CH3,    /*!< TIM3 channel 3 output */
  TIM3_CH4,    /*!< TIM3 channel 4 output */
  TIM14_CH1,   /*!< TIM14 channel 1 output */
  TIM16_CH1,   /*!< TIM16 channel 1 output */
  TIM16_CH1N,  /*!< TIM16 channel 1 complimentary output */
  TIM16_BKIN,  /*!< TIM16 break input */
  TIM17_CH1,   /*!< TIM17 channel 1 output */
  TIM17_CH1N,  /*!< TIM17 channel 1 complimentary output */
  TIM17_BKIN,  /*!< TIM17 break input */
};

/**
 * @brief Available pin function selects available
 */
enum class IOfunctSelects : std::uint8_t {
  AF0 = libmcuhw::gpio::AFR::AF0, /*!< Alternate function 0 */
  AF1 = libmcuhw::gpio::AFR::AF1, /*!< Alternate function 1 */
  AF2 = libmcuhw::gpio::AFR::AF2, /*!< Alternate function 2 */
  AF3 = libmcuhw::gpio::AFR::AF3, /*!< Alternate function 3 */
  AF4 = libmcuhw::gpio::AFR::AF4, /*!< Alternate function 4 */
  AF5 = libmcuhw::gpio::AFR::AF5, /*!< Alternate function 5 */
  AF6 = libmcuhw::gpio::AFR::AF6, /*!< Alternate function 6 */
  AF7 = libmcuhw::gpio::AFR::AF7, /*!< Alternate function 7 */
  NONE = 0xff,                    /*!< No alternate function */
};

/**
 * @brief base I/O pin template
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IOports T_PORT, IOpins T_PIN, IOfuncts T_FUNCT, bool DUMMY = false>
struct pin : libmcu::PinBase {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};

/**
 * @brief Specialization for Pin 8 on Port A with MCO function
 */
template <>
struct pin<IOports::PORTA, IOpins::PA8, IOfuncts::GPIO> : libmcu::PinBase {
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::NONE;
};

/**
 * @brief Specialization for Pin 8 on Port A with MCO function
 */
template <>
struct pin<IOports::PORTA, IOpins::PA8, IOfuncts::MCO> : libmcu::PinBase {
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::AF0;
};

}  // namespace libmcuhw

#endif