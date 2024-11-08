/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file libmcu_STM32F031K6T_ll.hpp
 * \brief LibMcu Low Low level library include for STM32F031K6T microcontroller
 */
#ifndef LIBMCU_STM32F031K6T_LL_HPP
#define LIBMCU_STM32F031K6T_LL_HPP

#include "../libmcu/libmcu.hpp"

namespace libMcuHw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t revision{0x0000}; /**< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool present{false}; /**< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool present{false}; /**< presence of vector relocation */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t variant{0}; /**< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t priorityMask{0x3}; /**< NVIC priority bit mask */
constexpr inline std::uint32_t priorityBits{2};   /**< NVIC priority bit count */
constexpr inline std::uint32_t vectorCount{48};   /**< amount of interrupt vectors */
}  // namespace nvic

enum class interrupts : std::int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
  wwdg = 0,                 /*!< Window WatchDog Interrupt */
  pvd = 1,                  /*!< PVD Interrupt through EXTI Lines 16 */
  rtc = 2,                  /*!< RTC Interrupt through EXTI Lines 17, 19 and 20 */
  flash = 3,                /*!< FLASH global Interrupt */
  rcc = 4,                  /*!< RCC global Interrupt */
  exti0_1 = 5,              /*!< EXTI Line 0 and 1 Interrupt */
  exti2_3 = 6,              /*!< EXTI Line 2 and 3 Interrupt */
  exti4_5 = 7,              /*!< EXTI Line 4 to 15 Interrupt */
  dma1_1 = 9,               /*!< DMA1 Channel 1 Interrupt */
  dma1_2_3 = 10,            /*!< DMA1 Channel 2 and Channel 3 Interrupt */
  dma1_4_5 = 11,            /*!< DMA1 Channel 4 and Channel 5 Interrupt */
  adc1 = 12,                /*!< ADC1 Interrupt */
  tim1_brk_up_trg_com = 13, /*!< TIM1 Break, Update, Trigger and Commutation Interrupt */
  tim1_cc = 14,             /*!< TIM1 Capture Compare Interrupt */
  tim2 = 15,                /*!< TIM2 global Interrupt */
  tim3 = 16,                /*!< TIM3 global Interrupt */
  tim14 = 19,               /*!< TIM14 global Interrupt */
  tim16 = 21,               /*!< TIM16 global Interrupt */
  tim17 = 22,               /*!< TIM17 global Interrupt */
  i2c1 = 23,                /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup) */
  spi1 = 25,                /*!< SPI1 global Interrupt */
  uart1 = 27                /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
};
}  // namespace libMcuHw

#include "../CortexM/cortex_m0.hpp"

namespace libMcuHw {
/* memory map */
constexpr inline libMcu::memoryAddress ahb2BaseAddress{0x4800'0000u};
constexpr inline libMcu::memoryAddress ahb1BaseAddress{0x4002'0000u};
constexpr inline libMcu::memoryAddress apbBaseAddress{0x4000'0000u};
constexpr inline libMcu::memoryAddress ramBaseAddress{0x2000'0000u};
constexpr inline libMcu::memoryAddress optBaseAddress{0x1FFF'F800u};
constexpr inline libMcu::memoryAddress flashBaseAddress{0x0800'0000u};
constexpr inline libMcu::memoryAddress mainBaseAddress{0x0000'0000u};
/* AHB2 peripheral addresses */
constexpr inline libMcu::gpioBaseAddress gpiofAddress{0x4800'1400u}; /*!< GPIO port F */
constexpr inline libMcu::gpioBaseAddress gpioeAddress{0x4800'1000u}; /*!< GPIO port E */
constexpr inline libMcu::gpioBaseAddress gpiodAddress{0x4800'0C00u}; /*!< GPIO port D */
constexpr inline libMcu::gpioBaseAddress gpiocAddress{0x4800'0800u}; /*!< GPIO port C */
constexpr inline libMcu::gpioBaseAddress gpiobAddress{0x4800'0400u}; /*!< GPIO port B */
constexpr inline libMcu::gpioBaseAddress gpioaAddress{0x4800'0000u}; /*!< GPIO port A */
/* AHB1 peripheral addresses */
constexpr inline libMcu::stmBaseAddress tscAddress{0x4002'4000u};   /*!< TSC */
constexpr inline libMcu::crcBaseAddress crcAddress{0x4002'3000u};   /*!< CRC */
constexpr inline libMcu::stmBaseAddress flashAddress{0x4002'2000u}; /*!< Flash interface */
constexpr inline libMcu::stmBaseAddress rccAddress{0x4002'1000u};   /*!< RCC */
constexpr inline libMcu::dmaBaseAddress dma2Address{0x4002'0400u};  /*!< DMA2 */
constexpr inline libMcu::dmaBaseAddress dma1Address{0x4002'0000u};  /*!< DMA */
/* APB peripheral addresses */
constexpr inline libMcu::stmBaseAddress dbgmcuAddress{0x4001'5800u};    /*!< DBGMCU */
constexpr inline libMcu::stmBaseAddress tim17Address{0x4001'4800u};     /*!< TIM17 */
constexpr inline libMcu::stmBaseAddress tim16Address{0x4001'4400u};     /*!< TIM16 */
constexpr inline libMcu::stmBaseAddress tim15Address{0x4001'4000u};     /*!< TIM15 */
constexpr inline libMcu::uartBaseAddress usart1Address{0x4001'3800u};   /*!< USART1 */
constexpr inline libMcu::stmBaseAddress spi1I2s1Address{0x4001'3000u};  /*!< SPI1/I2S1 */
constexpr inline libMcu::stmBaseAddress tim1Address{0x4001'2C00u};      /*!< TIM1 */
constexpr inline libMcu::adcBaseAddress adcAddress{0x4001'2400u};       /*!< ADC */
constexpr inline libMcu::uartBaseAddress usart8Address{0x4001'1C00u};   /*!< USART8 */
constexpr inline libMcu::uartBaseAddress usart7Address{0x4001'1800u};   /*!< USART7 */
constexpr inline libMcu::uartBaseAddress usart6Address{0x4001'1400u};   /*!< USART6 */
constexpr inline libMcu::stmBaseAddress extiAddress{0x4001'0400u};      /*!< EXTI */
constexpr inline libMcu::syscfgBaseAddress syscfgAddress{0x4001'0000u}; /*!< SYSCFG/COMP */
constexpr inline libMcu::stmBaseAddress cecAddress{0x4000'7800u};       /*!< CEC */
constexpr inline libMcu::dacBaseAddress dacAddress{0x4000'7400u};       /*!< DAC */
constexpr inline libMcu::stmBaseAddress pwrAddress{0x4000'7000u};       /*!< PWR */
constexpr inline libMcu::stmBaseAddress crsAddress{0x4000'6C00u};       /*!< CRS */
constexpr inline libMcu::stmBaseAddress canAddress{0x4000'6400u};       /*!< CAN */
constexpr inline libMcu::stmBaseAddress ramUsbCanAddress{0x4000'6000u}; /*!< USB/CAN RAM */
constexpr inline libMcu::stmBaseAddress usbAddress{0x4000'5C00u};       /*!< USB */
constexpr inline libMcu::i2cBaseAddress i2c2Address{0x4000'5800u};      /*!< I2C2 */
constexpr inline libMcu::i2cBaseAddress i2c1Address{0x4000'5400u};      /*!< I2C1 */
constexpr inline libMcu::uartBaseAddress usart5Address{0x4000'5000u};   /*!< USART5 */
constexpr inline libMcu::uartBaseAddress usart4Address{0x4000'4C00u};   /*!< USART4 */
constexpr inline libMcu::uartBaseAddress usart3Address{0x4000'4800u};   /*!< USART3 */
constexpr inline libMcu::uartBaseAddress usart2Address{0x4000'4400u};   /*!< USART2 */
constexpr inline libMcu::spiBaseAddress spi2Address{0x4000'3800u};      /*!< SPI2 */
constexpr inline libMcu::stmBaseAddress iwdgAddress{0x4000'3000u};      /*!< IWDG */
constexpr inline libMcu::stmBaseAddress wwdgAddress{0x4000'2C00u};      /*!< WWDG */
constexpr inline libMcu::stmBaseAddress rtcAddress{0x4000'2800u};       /*!< RTC */
constexpr inline libMcu::stmBaseAddress tim14Address{0x4000'2000u};     /*!< timer 14 */
constexpr inline libMcu::stmBaseAddress tim7Address{0x4000'1400u};      /*!< timer 7 */
constexpr inline libMcu::stmBaseAddress tim6Address{0x4000'1000u};      /*!< timer 6 */
constexpr inline libMcu::stmBaseAddress tim3Address{0x4000'0400u};      /*!< timer 3 */
constexpr inline libMcu::stmBaseAddress tim2Address{0x4000'0000u};      /*!< Timer 2 */
}  // namespace libMcuHw

// includes that define the registers namespace go here.
#include "STM32F0_HW/STM32F0_syscfg_hw.hpp"
#include "STM32F0_HW/STM32F0_rcc_hw.hpp"
#include "STM32F0_HW/STM32F0_gpio_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "STM32F0_CLOCK/STM32F0_clock_hw.hpp"

// pin definitions
#include "STM32F0_PINS/STM32F031K6T_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "STM32F0_LL/STM32F0_syscfg_ll.hpp"
#include "STM32F0_LL/STM32F0_rcc_ll.hpp"

// clock information as last
#include "STM32F0_CLOCK/STM32F0_clock.hpp"

#endif
