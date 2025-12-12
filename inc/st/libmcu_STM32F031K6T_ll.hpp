/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_STM32F031K6T_ll.hpp
 * @brief LibMcu Low Low level library include for STM32F031K6T microcontroller
 */
#ifndef LIBMCU_STM32F031K6T_LL_HPP
#define LIBMCU_STM32F031K6T_LL_HPP

#include "../libmcu/libmcull.hpp"
#include "../libmcu/functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t Revision{0x0000}; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool Present{false}; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool Present{false}; /*!< presence of vector relocation */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t Variant{0}; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t PriorityMask{0x3}; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t PriorityBits{2};   /*!< NVIC priority bit count */
constexpr inline std::uint32_t VectorCount{48};   /*!< amount of interrupt vectors */
}  // namespace nvic

enum class Interrupts : std::int8_t {
  Reset = -15,
  NonMaskable = -14,
  HardFault = -13,
  SvCall = -5,
  PendSv = -2,
  Systick = -1,
  Wwdg = 0,             /*!< Window WatchDog Interrupt */
  Pvd = 1,              /*!< PVD Interrupt through EXTI Lines 16 */
  Rtc = 2,              /*!< RTC Interrupt through EXTI Lines 17, 19 and 20 */
  Flash = 3,            /*!< FLASH global Interrupt */
  Rcc = 4,              /*!< RCC global Interrupt */
  Exti0_1 = 5,          /*!< EXTI Line 0 and 1 Interrupt */
  Exti2_3 = 6,          /*!< EXTI Line 2 and 3 Interrupt */
  Exti4_5 = 7,          /*!< EXTI Line 4 to 15 Interrupt */
  Dma1_1 = 9,           /*!< DMA1 Channel 1 Interrupt */
  Dma1_2_3 = 10,        /*!< DMA1 Channel 2 and Channel 3 Interrupt */
  Dma1_4_5 = 11,        /*!< DMA1 Channel 4 and Channel 5 Interrupt */
  Adc1 = 12,            /*!< ADC1 Interrupt */
  Tim1BrkUpTrgCom = 13, /*!< TIM1 Break, Update, Trigger and Commutation Interrupt */
  Tim1_cc = 14,         /*!< TIM1 Capture Compare Interrupt */
  Tim2 = 15,            /*!< TIM2 global Interrupt */
  Tim3 = 16,            /*!< TIM3 global Interrupt */
  Tim14 = 19,           /*!< TIM14 global Interrupt */
  Tim16 = 21,           /*!< TIM16 global Interrupt */
  Tim17 = 22,           /*!< TIM17 global Interrupt */
  I2c1 = 23,            /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup) */
  Spi1 = 25,            /*!< SPI1 global Interrupt */
  Uart1 = 27            /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
};
}  // namespace libmcuhw

#include "../CortexM/cortex_m0.hpp"

namespace libmcuhw {
/* memory map */
constexpr inline libmcu::MemoryAddress Ahb2BaseAddress{0x4800'0000u};
constexpr inline libmcu::MemoryAddress Ahb1BaseAddress{0x4002'0000u};
constexpr inline libmcu::MemoryAddress ApbBaseAddress{0x4000'0000u};
constexpr inline libmcu::MemoryAddress RamBaseAddress{0x2000'0000u};
constexpr inline libmcu::MemoryAddress OptBaseAddress{0x1FFF'F800u};
constexpr inline libmcu::MemoryAddress FlashBaseAddress{0x0800'0000u};
constexpr inline libmcu::MemoryAddress MainBaseAddress{0x0000'0000u};
/* AHB2 peripheral addresses */
constexpr inline libmcu::GpioBaseAddress GpiofAddress{0x4800'1400u}; /*!< GPIO port F */
constexpr inline libmcu::GpioBaseAddress GpioeAddress{0x4800'1000u}; /*!< GPIO port E */
constexpr inline libmcu::GpioBaseAddress GpiodAddress{0x4800'0C00u}; /*!< GPIO port D */
constexpr inline libmcu::GpioBaseAddress GpiocAddress{0x4800'0800u}; /*!< GPIO port C */
constexpr inline libmcu::GpioBaseAddress GpiobAddress{0x4800'0400u}; /*!< GPIO port B */
constexpr inline libmcu::GpioBaseAddress GpioaAddress{0x4800'0000u}; /*!< GPIO port A */
/* AHB1 peripheral addresses */
constexpr inline libmcu::stmBaseAddress TscAddress{0x4002'4000u};   /*!< TSC */
constexpr inline libmcu::CrcBaseAddress CrcAddress{0x4002'3000u};   /*!< CRC */
constexpr inline libmcu::stmBaseAddress FlashAddress{0x4002'2000u}; /*!< Flash interface */
constexpr inline libmcu::stmBaseAddress RccAddress{0x4002'1000u};   /*!< RCC */
constexpr inline libmcu::DmaBaseAddress Dma2Address{0x4002'0400u};  /*!< DMA2 */
constexpr inline libmcu::DmaBaseAddress Dma1Address{0x4002'0000u};  /*!< DMA */
/* APB peripheral addresses */
constexpr inline libmcu::stmBaseAddress DbgmcuAddress{0x4001'5800u};    /*!< DBGMCU */
constexpr inline libmcu::stmBaseAddress Tim17Address{0x4001'4800u};     /*!< TIM17 */
constexpr inline libmcu::stmBaseAddress Tim16Address{0x4001'4400u};     /*!< TIM16 */
constexpr inline libmcu::stmBaseAddress Tim15Address{0x4001'4000u};     /*!< TIM15 */
constexpr inline libmcu::UartBaseAddress Usart1Address{0x4001'3800u};   /*!< USART1 */
constexpr inline libmcu::stmBaseAddress Spi1I2s1Address{0x4001'3000u};  /*!< SPI1/I2S1 */
constexpr inline libmcu::stmBaseAddress Tim1Address{0x4001'2C00u};      /*!< TIM1 */
constexpr inline libmcu::AdcBaseAddress AdcAddress{0x4001'2400u};       /*!< ADC */
constexpr inline libmcu::UartBaseAddress Usart8Address{0x4001'1C00u};   /*!< USART8 */
constexpr inline libmcu::UartBaseAddress Usart7Address{0x4001'1800u};   /*!< USART7 */
constexpr inline libmcu::UartBaseAddress Usart6Address{0x4001'1400u};   /*!< USART6 */
constexpr inline libmcu::stmBaseAddress ExtiAddress{0x4001'0400u};      /*!< EXTI */
constexpr inline libmcu::SyscfgBaseAddress SyscfgAddress{0x4001'0000u}; /*!< SYSCFG/COMP */
constexpr inline libmcu::stmBaseAddress CecAddress{0x4000'7800u};       /*!< CEC */
constexpr inline libmcu::DacBaseAddress DacAddress{0x4000'7400u};       /*!< DAC */
constexpr inline libmcu::stmBaseAddress PwrAddress{0x4000'7000u};       /*!< PWR */
constexpr inline libmcu::stmBaseAddress CrsAddress{0x4000'6C00u};       /*!< CRS */
constexpr inline libmcu::stmBaseAddress CanAddress{0x4000'6400u};       /*!< CAN */
constexpr inline libmcu::stmBaseAddress RamUsbCanAddress{0x4000'6000u}; /*!< USB/CAN RAM */
constexpr inline libmcu::stmBaseAddress UsbAddress{0x4000'5C00u};       /*!< USB */
constexpr inline libmcu::I2cBaseAddress I2c2Address{0x4000'5800u};      /*!< I2C2 */
constexpr inline libmcu::I2cBaseAddress I2c1Address{0x4000'5400u};      /*!< I2C1 */
constexpr inline libmcu::UartBaseAddress Usart5Address{0x4000'5000u};   /*!< USART5 */
constexpr inline libmcu::UartBaseAddress Usart4Address{0x4000'4C00u};   /*!< USART4 */
constexpr inline libmcu::UartBaseAddress Usart3Address{0x4000'4800u};   /*!< USART3 */
constexpr inline libmcu::UartBaseAddress Usart2Address{0x4000'4400u};   /*!< USART2 */
constexpr inline libmcu::SpiBaseAddress Spi2Address{0x4000'3800u};      /*!< SPI2 */
constexpr inline libmcu::stmBaseAddress IwdgAddress{0x4000'3000u};      /*!< IWDG */
constexpr inline libmcu::stmBaseAddress WwdgAddress{0x4000'2C00u};      /*!< WWDG */
constexpr inline libmcu::stmBaseAddress RtcAddress{0x4000'2800u};       /*!< RTC */
constexpr inline libmcu::stmBaseAddress Tim14Address{0x4000'2000u};     /*!< timer 14 */
constexpr inline libmcu::stmBaseAddress Tim7Address{0x4000'1400u};      /*!< timer 7 */
constexpr inline libmcu::stmBaseAddress Tim6Address{0x4000'1000u};      /*!< timer 6 */
constexpr inline libmcu::stmBaseAddress Tim3Address{0x4000'0400u};      /*!< timer 3 */
constexpr inline libmcu::stmBaseAddress Tim2Address{0x4000'0000u};      /*!< Timer 2 */
}  // namespace libmcuhw

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
