# LibMcuLL Coding guidelines
This document in short describes some coding guidelines for libMcuLL.
# Include chain
Explaining how inclusions work in libMcuLl
# function naming
Naming functions is always annoying. Function names are in CamelCase with the first letter capitalized.
Generally the following format is adhered to:
```
PeripheralnameOperationtypeRegister
```
Peripheral name is the name of the peripheral as described in the microcontroller datasheet. Some examples:
* Usb
* Timer
* Gpio
* Swm
Operation is meant to signify what it does. Possible options:
* no operation, e.g: PeripheralConfig: Blindly sets the config register of the peripheral
* Set: Sets bits (to 1) while not modifying the rest, usually implemented as a Read OR Write operation.
* Clear: Clears bits (to 0) while not modifying the rest, usually implemented as a Read AND Write operation.
Example:
```
static inline void SctSetConfig(LPC_SCT_T *sct, const uint32_t value)
{
    uint32_t temp = sct->CONFIG;
    sct->CONFIG = value | temp;
}
```
Sets bits in Config register of the SCT peripheral.
# C programming patterns

## Functions
Where possible create static inline functions in the headers.

# C++ programming patterns
