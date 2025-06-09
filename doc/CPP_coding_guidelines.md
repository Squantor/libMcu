# C++ LibMcuLL Coding guidelines
# Introduction
This document contains the naming conventions and programming idioms used by C++ LibMcuLL. Some architecture things might be defined here but they will be split off in their own design documents.
## Initialization
We prefer brace initialization as much as possible.
## Naming things
We follow the [google standard naming convention](https://google.github.io/styleguide/cppguide.html#General_Naming_Rules)
# Peripheral hardware
Peripheral hardware is defined in their own header files related to a specific microcontroller.
First the proper namespaces are defined for the peripheral:
```
namespace libmcuhw::device {
```
Then a structure definition is made where each of the fields map to a hardware register:

```
struct Device {
  volatile std::uint32_t CTRL; /*!< Control register */
  volatile std::uint32_t STAT; /*!< Status register */
  volatile std::uint32_t DAT;  /*!< Data register */
  union {
    union {                     /*!< Some composite register structure */
      volatile std::uint32_t U; /*!<  Unified register */
      struct {
        volatile std::uint16_t L; /*!<  VALUE[i].L  Access to L value */
        volatile std::uint16_t H; /*!<  VALUE[i].H  Access to H value */
      };
    } VALUE[sizeIndicator];

    const union {
      volatile std::uint32_t U; /*!<  Unified register */
      struct {
        volatile std::uint16_t L; /*!<  SHADOW[i].L  Access to L value */
        volatile std::uint16_t H; /*!<  SHADOW[i].H  Access to H value */
      };
    } SHADOW[sizeIndicator];
  };
};
```
Next up are the register namespaces, each namespace holds all the settings to one register and if needed some formatting functions. We use the standard k prefix for constants but we do deviate from the capitalisation to match the microcontroller datasheet.
```
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000FFF}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kBIT_A{1u << 0};            /*!< Bit A */
constexpr inline std::uint32_t kBIT_B{1u << 1};            /*!< Bit B */
constexpr inline std::uint32_t kBIT_C{1 << 2};             /*!< Bit C */
constexpr inline std::uint32_t kFIELD_A_MASK{0xF << 3};    /*!< Bit field A */
/**
 * @brief Format A field
 * @param Some value
 * @return formatted data for FIELD_A
 */
constexpr inline std::uint32_t FIELD_A(std::uint32_t prescale) {
  return prescale << 3;
}
constexpr inline std::uint32_t kFIELD_B_MASK{0xF << 7};   /*!< Bit field B */
/**
 * @brief Format B field
 *
 * @param Some value
 * @return formatted data for FIELD_B
 */
constexpr inline std::uint32_t FIELD_B(std::uint32_t prescale) {
  return prescale << 7;
}
} //namespace CTRL
namespace STAT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000FFF}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t STATUS_A_MASK{1u << 0};    /*!< status A mask */
constexpr inline std::uint32_t STATUS_B_MASK{1u << 1};    /*!< status B mask */
} // namespace STAT
```


# Peripheral software

