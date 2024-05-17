# LibMcu
This repository contains a set of libraries for usage on various microcontrollers. It is inspired by many microcontroller vendor libraries like LPCopen, STM32 LL drivers and many many more. The biggest problem is that they are locked behind various tools and instead of installing graphical tools that download various zip files I just want to get at the register definitions. Next to that, these libraries are can be big and inefficient, so lets reinvent the wheel ;-).
All of these libraries are written in C++20.
This library encompasses three separate libraries:
* LibMcuLL: Contains low level routines that expose as much as the microcontroller functionality with a specific API
* LibMcuHal: Contains low level routines that expose some of the microcontroller functionality but with a common interface that should be the same across all supported microcontrollers
* LibMcuDriver: Contains drivers using the LibMcuHal classes so are usable across all microcontroller families.
# Usage
To use this project add the inc directory of this repository to your project and to access the register definitions define the microcontroller with a preprocessor define in the shape of ```MCU_DEVICECODE```. See the appropriate header for supported controller. Word of warning, that it is defined there does not mean the support is by any means complete. I tend to add register definitions/features when I need them at that moment, yes this is annoying but feel free to contribute if you are missing something.
## Uusage example in C++
Just include the microcontroller specific library with the proper postfix notation for HAL or LL library. For example including the RP2040 LL library:
```
// Before inclusion add your clocking configuration in #defines, this will change in the future by using a proper configuration structure
#include <libmcuRP2040ll.hpp>
```
If you want to use the HAL library:
```
// Before inclusion add your clocking configuration in #defines, this will change in the future by using a proper configuration structure
#include <libmcuRP2040hal.hpp>
```
The drivers are located in the ```drivers``` 
## Design documents
* How to add a microcontroller (TODO)
* Hardware in the loop tests (TODO)
* [include architecture](doc/includes.md)
* [C++ Coding guidelines](doc/CPP_coding_guidelines.md)
* [namespacing](doc/CPP_namespaces.md)
* design of a low level peripheral hardware definition (TODO)
* design of a low level peripheral software definition (TODO)
* design of a HAL peripheral definition (TODO)
* design of a driver (TODO)
# Goals
Support is based on the microcontrollers I use the most, support is spotty as this library is still in development. Peripheral support is based on a first use basis.
* NXP LPC8 series like the LPC81X, LPC82X, LPC80X, LPC84X, LPC11XX
* STM32F0 STM32G0 STM32C0 STM32F4 STM32F7
* RP2040
I add support for peripherals on a project by project need basis. I use this library mostly as a learning vehicle for using modern C++. If you have a need, feel free to submit a pullrequest.
