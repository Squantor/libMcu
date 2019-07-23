# LibMcuLL
This repository contains the microcontroller lowlevel library, called MCULL. It is a bit inspired by many microcontroller vendor libraries like LPCopen, STM32 LL drivers and many many more. The biggest problem is that they are locked behind various tools and instead of installing many graphical tools that download various zip files I just want to get at the register definitions.
## Checking out
use ```git clone --recurse-submodules https://github.com/Squantor/$(PROJECT).git``` to clone the repository and its submodules.
## Usage
To use this project add the inc directory of this repository to your project and to access the register definitions define the microcontroller you intend to use, for a full list check the [supported microcontroller list](https://github.com/Squantor/libMcuLL/blob/master/doc/support.md). Then ```#include <mcu_ll.h>``` in your files where you intend to use the microcontroller registers.
# TODO
The following tasks are still open:
* initial design and support a few microcontrollers