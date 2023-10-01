# C++ LibMcuLL namespaces
C++ LibMcuLL uses namespaces to group various definitions.
* ```libMcuLL``` is the top level namespace that contains LibMcuLL types and helper classes
  * ```hw``` contains hardware definitions like the peripheral addresses
    * ```peripheral``` contains the defintions for this peripheral
      * ```REGISTER``` contains the defintions for this peripheral register
  * ```sw``` contains software definitions like classes, enums used as method arguments
