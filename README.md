# LibMcuLL
This repository contains the microcontroller lowlevel library, called MCULL. It is a bit inspired by many microcontroller vendor libraries like LPCopen, STM32 LL drivers and many many more. The biggest problem is that they are locked behind various tools and instead of installing many graphical tools that download various zip files I just want to get at the register definitions.
## Usage
To use this project add the inc directory of this repository to your project and to access the register definitions define the microcontroller you intend to use, in the shape of ```MCU_DEVICECODE```, see the file ```mcu_ll.h``` for more on what devices are supported. Word of warning, that it is defined there does not mean the support is by any means complete. I tend to add register definitions/features when I need them at that moment, yes this is annoying but feel free to contribute if you are missing something.
## Adding devices
TODO
## Design documents
[Generic design documents](doc/coding_guidelines.md)
C design patterns (TODO)
C++ design patterns (TODO)

