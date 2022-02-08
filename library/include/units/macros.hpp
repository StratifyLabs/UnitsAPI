//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_MACROS_HPP
#define UNITSAPI_UNITS_MACROS_HPP

#include <sdk/types.h>

#define UNITS_BASIC_CONSTRUCT(NAME)                                            \
  constexpr NAME(NativeType value)                                             \
      : BasicUnitAccess<NAME>(value, Type::NAME) {}                            \
  constexpr NAME() = default

#define UNITS_DECLARE_BASIC_UNIT(NAME, UNIT, SYMBOL)                           \
  class NAME : public BasicUnitAccess<NAME> {                                  \
  public:                                                                      \
    static constexpr const char *unit() { return MCU_STRINGIFY(UNIT); }        \
    static constexpr const char *symbol() { return SYMBOL; }                   \
    UNITS_BASIC_CONSTRUCT(NAME);                                               \
  };                                                                           \
  inline NAME operator*(Unitless lhs, NAME rhs) {                              \
    return NAME(lhs.value() * rhs.value());                                    \
  }

#define UNITS_DECLARE_DERIVED_UNIT(NAME, UNIT, SYMBOL)                         \
  UNITS_DECLARE_BASIC_UNIT(NAME, UNIT, SYMBOL)

#define UNITS_DECLARE_MULTIPLY(RESULT, LHS, RHS)                               \
  RESULT operator*(const LHS &lhs, const RHS &rhs);                            \
  RESULT operator*(const RHS &lhs, const LHS &rhs);                            \
  LHS operator/(const RESULT &lhs, const RHS &rhs);                            \
  RHS operator/(const RESULT &lhs, const LHS &rhs)

#define UNITS_DECLARE_MULTIPLY_SAME(RESULT, LHS)                               \
  RESULT operator*(const LHS &lhs, const LHS &rhs);                            \
  LHS operator/(const RESULT &lhs, const LHS &rhs)

#define UNITS_DECLARE_DIVIDE(RESULT, LHS, RHS)                                 \
  RESULT operator/(const LHS &lhs, const RHS &rhs);                            \
  RHS operator/(const LHS &lhs, const RESULT &rhs);                            \
  LHS operator*(const RESULT &lhs, const RHS &rhs);                            \
  LHS operator*(const RHS &lhs, const RESULT &rhs)

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


#if UNITS_API_IS_DOUBLE
#define UNITS_NATIVE_SUFFIX(x) (x)
#define UNITS_NATIVE_TYPE double
#define UNITS_NATIVE_INTEGER_TYPE s64
#define UNITS_PRECISION 0.0000000000000001
#else
#define UNITS_NATIVE_SUFFIX(x) (x##f)
#define UNITS_NATIVE_TYPE float
#define UNITS_NATIVE_INTEGER_TYPE s32
#define UNITS_PRECISION 0.000001f
#endif

#endif // UNITSAPI_UNITS_MACROS_HPP
