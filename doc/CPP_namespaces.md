# C++ libMcu namespaces
C++ libMcu uses namespaces to group various definitions. We use a few example peripheral names here.
* ```libMcu``` Contains types, definitions and helper classe used by libMcu.
* ```libMcuHw``` Is the top level namespace for hardware definitions, contains subnamespaces per peripheral. Also contains the configuration settings of the microcontroller like peripheral addresses, available pins and other microcontroller specific settings.
  * ```gpio``` Contains the defintions for the gpio peripheral. The name is taken from the datasheet but not with capital letters.
    * ```CFG``` Contains the defintions for the gpio peripheral CFG register. The name is taken from the datasheet, usually capitalized in most datasheets.
      * ```BIT``` Contains the definition of the CFG register BIT field. The name is taken from the datasheet, usually capitalized in most datasheets.
  * ```uart``` contains the definitions for the uart peripheral. The name is taken from the datasheet but not with capital letters.
    * ```STAT``` Contains the definitions for the uart peripheral STAT register.  The name is taken from the datasheet, usually capitalized in most datasheets.
* ```libMcuLL``` is the top level namespace that contains libMcuLL types and helper classes
  * ```gpio``` contains definitions for the gpio class like enums used as method arguments
 * ```libMcuHal``` is the top level namespace that contains libMcuHal types and helper classes
   * ```gpio``` contains the HAL control class for the gpio peripheral.
   * ```uart``` contains the HAL control classes for the uart peripheral. For some peripherals there are a few HAL control class variants.
 * ```libMcuDriver``` is the top level namespace that contain libMcuDriver types and helper classes
   * ```driver``` contains the driver control class. The class name is the same as the namespace name
   
