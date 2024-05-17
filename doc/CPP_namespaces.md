# C++ libMcu namespaces
C++ libMcu uses namespaces to group various definitions.
* ```libMcu``` contains types, definitions and helper classe used libMcu wide
* ```libMcuLL``` is the top level namespace that contains libMcuLL types and helper classes
  * ```hw``` contains hardware definitions like the peripheral addresses
    * ```peripheral``` contains the defintions for this peripheral
      * ```REGISTER``` contains the defintions for this peripheral register
  * ```sw``` contains software definitions like peripheral control classes, enums used as method arguments
 * ```libMcuHal``` is the top level namespace that contains libMcuHal types and helper classes
   * ```peripheral``` contains the HAL control class for this peripheral. The class name is the same as the namespace name
 * ```libMcuDriver``` is the top level namespace that contain libMcuDriver types and helper classes
   * ```driver``` contains the driver control class. The class name is the same as the namespace name
   
