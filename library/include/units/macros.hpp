//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_MACROS_HPP
#define UNITSAPI_UNITS_MACROS_HPP

#include <sdk/types.h>

#define UNITS_BASIC_CONSTRUCT(NAME)                                            \
  constexpr NAME(NativeType value) : BasicUnitAccess<NAME>(value) {}           \
  constexpr NAME() = default

#define UNITS_DECLARE_BASIC_UNIT(NAME, UNIT, SYMBOL)                           \
  class NAME : public BasicUnitAccess<NAME> {                                  \
  public:                                                                      \
    const char *unit() const override { return MCU_STRINGIFY(UNIT); }          \
    const char *symbol() const override { return SYMBOL; }                     \
    UNITS_BASIC_CONSTRUCT(NAME);                                               \
  };                                                                           \
  inline NAME operator*(Unitless lhs, NAME rhs) {                              \
    return NAME(lhs.native_value() * rhs.native_value());                      \
  }

#define UNITS_DECLARE_DERIVED_UNIT(NAME, UNIT, SYMBOL)                         \
  UNITS_DECLARE_BASIC_UNIT(NAME, UNIT, SYMBOL)

#define UNITS_DECLARE_MULTIPLY(RESULT, LHS, RHS)                               \
  RESULT operator*(LHS lhs, RHS rhs);                                          \
  RESULT operator*(RHS lhs, LHS rhs);                                          \
  LHS operator/(RESULT lhs, RHS rhs);                                          \
  RHS operator/(RESULT lhs, LHS rhs)

#define UNITS_DECLARE_MULTIPLY_SAME(RESULT, LHS)                               \
  RESULT operator*(LHS lhs, LHS rhs);                                          \
  LHS operator/(RESULT lhs, LHS rhs);

#define UNITS_DECLARE_DIVIDE(RESULT, LHS, RHS)                                 \
  RESULT operator/(LHS lhs, RHS rhs);                                          \
  RHS operator/(LHS lhs, RESULT rhs);                                          \
  LHS operator*(RESULT lhs, RHS rhs);                                          \
  LHS operator*(RHS lhs, RESULT rhs)

#define UNITS_BASIC_UNIT_DEFINE_LITERAL(NAME, SYMBOL)                          \
  inline NAME operator"" _p##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier / 1'000'000'000'000);  \
  }                                                                            \
  inline NAME operator"" _n##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier / 1'000'000'000);      \
  }                                                                            \
  inline NAME operator"" _u##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier / 1'000'000);          \
  }                                                                            \
  inline NAME operator"" _m##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier / 1000);               \
  }                                                                            \
  inline NAME operator"" _c##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier / 100);                \
  }                                                                            \
  inline NAME operator"" _##SYMBOL(unsigned long long int value) {             \
    return NAME(value * BasicUnit::unit_type_multiplier);                      \
  }                                                                            \
  inline NAME operator"" _k##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier * 1000);               \
  }                                                                            \
  inline NAME operator"" _M##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier * 1'000'000);          \
  }                                                                            \
  inline NAME operator"" _G##SYMBOL(unsigned long long int value) {            \
    return NAME(value * BasicUnit::unit_type_multiplier * 1'000'000'000);      \
  }

#if !defined __link
#define UNITS_NATIVE_SUFFIX(x) (x##f)
#define UNITS_NATIVE_TYPE float
#else
#define UNITS_NATIVE_SUFFIX(x) (x)
#define UNITS_NATIVE_TYPE double
#endif

#endif // UNITSAPI_UNITS_MACROS_HPP
