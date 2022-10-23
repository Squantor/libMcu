# LibMcuLL Coding guidelines
# Introduction
To make sure that LibMcuLL is consistent a bunch of rules/templates are defined in how to do certain things. These are described here. Also included is some of the architecture of LibMcuLL.
# Include architecture
We strive to make this library header only so we have bit convoluted way of including files. Generally two patterns are adhered to:
* libmcull.h
    * vendor\microcontroller.h
        * vendor\family\controller_peripheral.h

If possible we try to make common definitions of some peripheral in a common peripheral definition file. This can still lead to some duplication so we try to port to a more general purpose definition of peripheral definitions below:

* libmcull.h
    * vendor\microcontroller.h
        * vendor\peripheral_variantnumber.h

The variantnumber is in the format of v001, when there are no versions of a peripheral we leave out the variantnumber.

# Code formatting
LibMcuLL uses the google code format as used by clang-format, with some minor changes.

# Naming conventions
Constants are in all capitals with underscores: ```SOME_CONSTANT```
Typedefs are in capitals postfixed with ```_Type``` Example: ```SOME_TYPEDEF_Type```
Enums are in capitals postfixed with ```_Enum``` Example: ```SOME_ENUM_Enum```
## Specific naming convention
Peripheral name is the name of the peripheral as described in the microcontroller datasheet. If we have multiple instances of one peripheral, name them accordingly, example:
```
#define SPI0 ((SPI_Type *)SPI0_BASE)
#define SPI1 ((SPI_Type *)SPI1_BASE)
```

# Doxygen style
Use the javadoc style as described here:
https://doxygen.nl/manual/docblocks.html

Example
```
/**
* @file A test class. 
* A more elaborate class description.
*/
class Javadoc_Test
{
public:
/**
* An enum.
* More detailed enum description.
*/
enum TEnum {
TVal1, /**< enum value TVal1. */
TVal2, /**< enum value TVal2. */
TVal3 /**< enum value TVal3. */
}
*enumPtr, /**< enum pointer. Details. */
enumVar; /**< enum variable. Details. */
/**
* A constructor.
* A more elaborate description of the constructor.
*/
Javadoc_Test();
/**
* A destructor.
* A more elaborate description of the destructor.
*/
~Javadoc_Test();
/**
* a normal member taking two arguments and returning an integer value.
* @param a an integer argument.
* @param s a constant character pointer.
* @see Javadoc_Test()
* @see ~Javadoc_Test()
* @see testMeToo()
* @see publicVar()
* @return The test results
*/
int testMe(int a,const char *s);
/**
* A pure virtual member.
* @see testMe()
* @param c1 the first argument.
* @param c2 the second argument.
*/
virtual void testMeToo(char c1,char c2) = 0;
/**
* a public variable.
* Details.
*/
int publicVar;
/**
* a function variable.
* Details.
*/
int (*handler)(int a,int b);
};
```
# Peripheral structure definition
Example:
```
/**
 * @brief Example peripheral
 *
 */
typedef volatile struct {
  uint32_t CTRL;       /**< Control register */
  const uint32_t STAT; /**< Status register */
  struct {
    const uint32_t INPUT; /**< Input */
    uint32_t OUTPUT;      /**< Output */
  } REGS[30];
} EXAMPLE_PERIPHERAL_Type;
```
# Peripheral accessor defines
## General
Generally, you namespace the defines by the form: ```PERIPHERAL_REGISTER_DEFINITION_NAME``` Example: ```SPI_CTRL_BAZ```
## Peripheral registers
For each peripheral register you need to specify the reserved bits in such a fashion: ```#define PERIPHERAL_REGISTER_RESERVED (0xFFFF0000)``` Reserved bits are set to 1
## Peripheral Register bits
For simple on/off bits you postfix the bits with EN/DIS for enable/disabling of bits.
```
#define PERIPHERAL_REGISTER_FUNCTION_EN (setting << position)
#define PERIPHERAL_REGISTER_FUNCTION_DIS (~setting << position)
```
For read only bits we postfix the define with ```MASK```, for example:
```
#define PERIPHERAL_REGISTER_FUNCTION_MASK (0x01 << position)
```
usage:
```
// checking multiple bits at once
if(PERIPHERAL_REGISTER_FUNCTION_SETTING0_MASK | PERIPHERAL_REGISTER_FUNCTION_SETTING1_MASK | registerValue)
```

For multiple bits/settings use this template and use an enum to bound settable values.
```
#define PERIPHERAL_REGISTER_FUNCTION_SETTING (((value) & mask) << position)
typedef enum {
    PERIPHERAL_REGISTER_SETTING_VARIANT0 = 0x0,
    PERIPHERAL_REGISTER_SETTING_VARIANT1 = 0x1,
    PERIPHERAL_REGISTER_SETTING_VARIANT2 = 0x2,
} PERIPHERAL_REGISTER_SETTING_Enum;
```
For multiple read only bits we imitate the write pattern but change it so below code works:
```
if(PERIPHERAL_REGISTER_FUNCTION_SETTING_MASK(register) == PERIPHERAL_REGISTER_SETTING_VARIANT1)
```

# Peripheral accessor functions
## general function naming pattern
Writing functions
```
/**
 * @brief peripheral register write
 *
 * @param peripheral  peripheral
 * @param settings    value to set to register
 */
static inline void peripheralRegister(PERIPHERAL_Type* const peripheral, settingType settings)
```
Reading functions
```
/**
 * @brief peripheral register write
 *
 * @param peripheral  peripheral
 * @return            value of the register
 */
static inline settingType peripheralGetRegister(PERIPHERAL_Type* const peripheral)
```
For data register where the whole register the above pattern is sufficient but for register where you often mask off bits, you can also change the accessor to also pass a AND mask to it so only relevant bits are passed to the caller.
```
/**
 * @brief peripheral register write
 *
 * @param peripheral  peripheral
 * @param mask        mask used in bitwise and on the register, used to filter unused bits
 * @return            value of the register bitwise anded with mask
 */
static inline settingType peripheralGetRegister(PERIPHERAL_Type* const peripheral, settingType mask)
```

## function naming for accessors
Some accessors are special for clearing/setting/xoring bits, sometimes there are dedicated registers or even full register spaces for setting/clearing/xoring bits in a register. We postfix these accessor functions as follows:
* register overwrites: ```peripheralRegister(const type *peripheral, registerwidth setting)``` 
* register sets: ```peripheralSetRegister(const type *peripheral, registerwidth mask)``` 
* register clears: ```peripheralClearRegister(const type *peripheral, registerwidth mask)``` 
* register toggles: ```peripheralToggleRegister(const type *peripheral, registerwidth mask)```
* register get: ```peripheralGetRegister(const type *peripheral, registerwidth mask)``` optional mask can be passed if applicable

Sometimes a register setting is very simple, like single enable bit or disable bit, it is okay then to wrap the functionality into the function like this: ```peripheralEnable(const type *peripheral, bool enable)```


