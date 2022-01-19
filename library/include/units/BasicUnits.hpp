//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_BASICUNITS_HPP
#define UNITSAPI_UNITS_BASICUNITS_HPP

#include <var/StackString.hpp>

#include "macros.hpp"

namespace units {

using NativeType = UNITS_NATIVE_TYPE;

class BasicUnit {
public:
  static constexpr NativeType unit_type_multiplier = UNITS_NATIVE_SUFFIX(1.0);

  virtual const char *unit() const = 0;
  virtual const char *symbol() const = 0;

  constexpr NativeType native_value() const { return m_native_value; }
  constexpr NativeType value() const { return m_native_value; }

  NativeType yotta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E24);
  }
  NativeType zetta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E21);
  }
  NativeType exa() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E18); }
  NativeType peta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E15);
  }
  NativeType tera() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E12);
  }
  NativeType giga() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E9); }
  NativeType mega() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E6); }
  NativeType kilo() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1000.0);
  }
  NativeType hecto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(100.0);
  }
  NativeType deka() const { return m_native_value * UNITS_NATIVE_SUFFIX(10.0); }
  NativeType deci() const { return m_native_value * UNITS_NATIVE_SUFFIX(1E-1); }
  NativeType centi() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-2);
  }
  NativeType milli() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-3);
  }
  NativeType micro() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-6);
  }
  NativeType nano() const { return m_native_value * UNITS_NATIVE_SUFFIX(1E-9); }
  NativeType pico() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-12);
  }
  NativeType femto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-15);
  }
  NativeType atto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-18);
  }
  NativeType zepto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-21);
  }
  NativeType yocto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-24);
  }

  var::NumberString to_string(const char *fmt = "%0.3f") const;

protected:
  constexpr BasicUnit() = default;
  constexpr BasicUnit(NativeType value) : m_native_value(value) {}
  NativeType m_native_value{};
};

class Unitless : public BasicUnit {
public:
  const char *unit() const override { return "unitless"; }
  const char *symbol() const override { return ""; }

  constexpr Unitless() = default;
  constexpr Unitless(NativeType value) : BasicUnit(value) {}

  Unitless operator*(Unitless a) const {
    return Unitless(m_native_value * a.m_native_value);
  }
  Unitless &operator*=(Unitless a) {
    m_native_value *= a.m_native_value;
    return *this;
  }

  Unitless operator/(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  Unitless &operator/=(Unitless a) {
    m_native_value /= a.m_native_value;
    return *this;
  }

  Unitless operator+(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  Unitless &operator+=(Unitless a) {
    m_native_value += a.m_native_value;
    return *this;
  }

  Unitless operator-(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  Unitless &operator-=(Unitless a) {
    m_native_value -= a.m_native_value;
    return *this;
  }

private:
};

template <class Derived> class BasicUnitAccess : public BasicUnit {
public:
  Derived operator+(const Derived &a) const {
    return Derived(native_value() + a.native_value());
  }

  Derived &operator+=(const Derived &a) {
    m_native_value += a.native_value();
    return static_cast<Derived &>(*this);
  }

  Derived operator-(const Derived &a) const {
    return Derived(native_value() - a.native_value());
  }

  Derived &operator-=(const Derived &a) {
    m_native_value -= a.native_value();
    return static_cast<Derived &>(*this);
  }

  Derived operator*(Unitless a) const {
    return m_native_value * a.native_value();
  }

  Derived operator/(Unitless a) const {
    return m_native_value / a.native_value();
  }

  Derived operator*=(Unitless a) const {
    m_native_value *= a.native_value();
    return static_cast<Derived &>(*this);
  }

  Derived operator/=(Unitless a) const {
    m_native_value /= a.native_value();
    return static_cast<Derived &>(*this);
  }

  Unitless operator/(Derived a) const {
    return Unitless(m_native_value / a.m_native_value);
  }

  template <class ConvertType> ConvertType convert(NativeType ratio) const {
    return ConvertType(m_native_value * ratio);
  }

protected:
  constexpr BasicUnitAccess() = default;
  constexpr BasicUnitAccess(NativeType value) : BasicUnit(value) {}
};

class OrthogonalLength : public BasicUnitAccess<OrthogonalLength> {
public:
  const char *unit() const override { return "meter"; }
  const char *symbol() const override { return "m"; }

  UNITS_BASIC_CONSTRUCT(OrthogonalLength);

private:
};

class Length : public BasicUnitAccess<Length> {
public:
  const char *unit() const override { return "meter"; }
  const char *symbol() const override { return "m"; }

  UNITS_BASIC_CONSTRUCT(Length);

  OrthogonalLength get_orthogonal_length() const {
    return OrthogonalLength(native_value());
  }
};

class Pi : public BasicUnitAccess<Pi> {
public:
  const char *unit() const override { return "radians"; }
  const char *symbol() const override { return "rad"; }

  constexpr Pi() : BasicUnitAccess<Pi>(UNITS_NATIVE_SUFFIX(3.14159265358979323846)) {}
};

class TwoPi : public BasicUnitAccess<Pi> {
public:
  const char *unit() const override { return "radians"; }
  const char *symbol() const override { return "rad"; }

  constexpr TwoPi()
    : BasicUnitAccess<Pi>(
      UNITS_NATIVE_SUFFIX(3.14159265358979323846) * UNITS_NATIVE_SUFFIX(2.0)) {}
};

UNITS_DECLARE_BASIC_UNIT(Mass, kilogram, "kg");
UNITS_DECLARE_BASIC_UNIT(Time, second, "s");
UNITS_DECLARE_BASIC_UNIT(ElectricCurrent, ampere, "A");

UNITS_DECLARE_BASIC_UNIT(ThermodynamicTemperature, kelvin, "K");
UNITS_DECLARE_BASIC_UNIT(AmountOfSubstance, mole, "mol");
UNITS_DECLARE_BASIC_UNIT(LuminousIntensity, candela, "cd");
UNITS_DECLARE_BASIC_UNIT(PlaneAngle, radian, "rad");
UNITS_DECLARE_BASIC_UNIT(SolidAngle, steradian, "sr");

UNITS_BASIC_UNIT_DEFINE_LITERAL(Unitless, number)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Length, m)

Length from_mils(NativeType input);
Length from_inches(NativeType input);
Length from_feet(NativeType input);
Length from_miles(NativeType input);

inline Mass operator"" _mg(unsigned long long int value) {
  return Mass(value * BasicUnit::unit_type_multiplier / 1000000);
}
inline Mass operator"" _g(unsigned long long int value) {
  return Mass(value * BasicUnit::unit_type_multiplier / 1000);
}
inline Mass operator"" _kg(unsigned long long int value) {
  return Mass(value * BasicUnit::unit_type_multiplier);
}

UNITS_BASIC_UNIT_DEFINE_LITERAL(Time, s)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ElectricCurrent, A)
UNITS_BASIC_UNIT_DEFINE_LITERAL(PlaneAngle, rad)
UNITS_BASIC_UNIT_DEFINE_LITERAL(SolidAngle, sr)
UNITS_BASIC_UNIT_DEFINE_LITERAL(AmountOfSubstance, mol)
UNITS_BASIC_UNIT_DEFINE_LITERAL(LuminousIntensity, cd)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ThermodynamicTemperature, K)

} // namespace units

namespace printer {
class Printer;
Printer &operator<<(Printer &printer, const units::BasicUnit &basic_unit);
} // namespace printer

#endif // UNITSAPI_UNITS_BASICUNITS_HPP
