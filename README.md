# LibMcuLL
This repository contains the microcontroller lowlevel library, called libMcuLL. It is a inspired by many microcontroller vendor libraries like LPCopen, STM32 LL drivers and many many more. The biggest problem is that they are locked behind various tools and instead of installing many graphical tools that download various zip files I just want to get at the register definitions. Next to that, these libraries are sometimes bloated and a bit inefficient, so lets reinvent the wheel ;-).
# Usage
To use this project add the inc directory of this repository to your project and to access the register definitions define the microcontroller with a preprocessor define in the shape of ```MCU_DEVICECODE```. See the appropriate header for supported controller. Word of warning, that it is defined there does not mean the support is by any means complete. I tend to add register definitions/features when I need them at that moment, yes this is annoying but feel free to contribute if you are missing something.
## Minimal usage example in C
```
// TODO add your configuration options here
#include <mcu_ll.h>
```
## Minimal usage example in C++
```
// TODO add your configuration options here
#include <mcu_ll.hpp>
```
## Design documents
* How to add a microcontroller (TODO)
* Hardware in the loop tests (TODO)
* [include architecture](doc/includes.md)
* [C Coding guidelines](doc/C_coding_guidelines.md)
* [C++ Coding guidelines](doc/CPP_coding_guidelines.md)
* [C++ namespacing](doc/CPP_namespaces.md)
* C++ anatomy of a peripheral hardware definition (TODO)
* C++ anatomy of a peripheral software definition (TODO)
# Goals
For version 0.1 I intend to support the all the LPC812 peripherals with some functionality to make some applications. Not all features will be supported on all peripherals.
