# Include paths
LibMcuLL uses multiple levels of includes to reduce the file clutter.

* ```inc\ ``` include directory top level, ```mcu_ll.h``` and ```mcu_ll.hpp``` headers reside here
  * ```CMSIS\ ``` ARM CMSIS provided files, these provide CortexM definitions
  * ```generic\ ``` generic microcontroller definitions, these are controllers with only their on core peripherals and can be used as a basis for your own definitions
  * ```libmcull\ ``` LibMcuLL specific headers for types and enums
  * ```nxp\ ``` NXP device headers, here the device specific headers reside
    * ```LPC8XX\ ``` LPC800 series C style headers
    * ```LPC8XX.hpp\ ``` LPC800 series peripheral C++ style headers

There are many more vendor header directories but they are not described here for brevity but do follow the general shape:

* ```VENDOR\ ``` Vendor header file directory
  * ```DEVICE_FAMILIY\ ``` Device family C style header directory
  * ```DEVICE_FAMILTY.hpp\ ``` Device family C++ style header directory

## including files
We generally use ```#include "current_path/include.h"``` to minimise the compiler needing to search for our include.
# include file naming conventions
Device headers usually fully include the device name, also all the size variants. For example the LPC812 in TSSOP 20 package is described in the header ```LPC812M101DH20.hpp``` in the ```nxp``` vendor directory.
Peripheral headers are usually prefixed as with the device family and the peripheral name in the general shape of ```DEVICEFAMILIY_PERIPHERAL_suffixes```. The ```_hw``` suffix is used for hardware related definitions like registers, bit names, formatting functions and more. We drop package/geometry/temperature related letters/numbers if they are at the end of the device part number or we replace them with a X character. 
For example, the LPC812 SPI register definitions has the name ```LPC81X_spi_hw.hpp```, we drop the 2 number in LPC812 as it describes the flash/ram size in that family. 

For the includes that contain the peripheral control classes we suffix them with ```_sw```. Some peripherals have multiple API's for control with various methods. The spi peripheral is usually controlled in a synchronous (blocking), asynchronous (nonblocking), asynchronous interrupt or asynchronous DMA methods. Peripheral control functions with these API's are suffixed by the following pattern:

* for synchronous API's the headers are suffixed by ```_sw__sync```
* for asynchronous API's the headers are suffixed by ```_sw_async```
* for asynchronous API's using interrupts are suffixed by ```_sw_interrupt```
* for asynchronous API's using DMA are suffixed by ```_sw_dma```

If there is just one API, still use the proper suffixes.

Peripherals that have multiple ways of controlling the peripheral often share definitions for their API's. This is put in a common peripheral header with the suffix ```_sw_common``` to make it clear that it is software/API related common definitions.

Some device family share common definitions, for example the LPC81, LPC82 and LPC83 series share some common bits or even full peripherals. Share these headers among the device and change the name to not refer to a specific device family but one level higher. So this would be a header prefixed with ```LPC8XX``` to signify it is common for the whole LPC800 series family.

# conditional compilation
The header ```mcu_ll.h``` and ```mcu_ll.hpp``` contain the selection logic for selecting the right microcontroller device header but using a long ```#ifndef``` chain. In general specifity is greatest at bottom level and gradually becomes less specific the futher you go deeper in the include hierarchy. The device specific header contains the most specific values for that device. The device specific headers less detail like package type, memory sizes, it is often not relevant. These even might be shared among multiple devices.
# inclusion anatomy of a device header
```
// Processor specific defines/constexprs for setting up processor specific header

#include "core_definitions.hpp" // device processor definitions

// device specific defines/constexprs for things like pins/ports etcetera

constexpr inline libMcuLL::peripheralBaseAddress peripheral0{0x4000'0000u};     /**< Peripheral base address */

#include "device_peripheral_regs.hpp" // peripheral register definitions

#include "device_peripheral.hpp" // peripheral class definitions
```
## CortexM
TODO give a generic example of a device header.

