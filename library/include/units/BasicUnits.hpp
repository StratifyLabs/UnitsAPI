//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_BASICUNITS_HPP
#define UNITSAPI_UNITS_BASICUNITS_HPP

#include <var/StackString.hpp>

#include "macros.hpp"

namespace units {

using NativeType = UNITS_NATIVE_TYPE;
using NativeIntegerType = UNITS_NATIVE_INTEGER_TYPE;

class BasicUnit {
public:
  static constexpr NativeType unit_type_multiplier = UNITS_NATIVE_SUFFIX(1.0);

  API_MAYBE_UNUSED API_NO_DISCARD constexpr NativeType value() const {
    return m_native_value;
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeType absolute_value() const;

  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType yotta() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E24));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType zetta() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E21));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType exa() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E18));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType peta() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E15));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType tera() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E12));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType giga() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E9));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType mega() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10E6));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType kilo() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1000.0));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType hecto() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(100.0));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType deka() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(10.0));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType deci() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-1));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType centi() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-2));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType milli() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-3));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType micro() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-6));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType nano() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-9));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType pico() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-12));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType femto() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-15));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType atto() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-18));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType zepto() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-21));
  }
  API_MAYBE_UNUSED API_NO_DISCARD NativeIntegerType yocto() const {
    return NativeIntegerType(m_native_value * UNITS_NATIVE_SUFFIX(1E-24));
  }

  API_MAYBE_UNUSED API_NO_DISCARD var::NumberString
  to_string(const char *fmt = "%0.3e") const;

  static const char *get_unit(const BasicUnit &a);
  static const char *get_symbol(const BasicUnit &a);

protected:
  // Normally enum class values would be snake-case
  // but to have compatibility with the classes
  // and aid the use of macros, these names
  // match the class names
  enum class Type : unsigned {
    Unitless,
    Mass,
    Time,
    ElectricCurrent,
    ThermodynamicTemperature,
    AmountOfSubstance,
    LuminousIntensity,
    PlaneAngle,
    SolidAngle,
    Length,
    OrthogonalLength,
    Pi,
    TwoPi,
    Frequency,
    Area,
    Volume,
    Velocity,
    Acceleration,
    Force,
    Pressure,
    Energy,
    Power,
    ElectricCharge,
    ElectricPotential,
    Capacitance,
    ElectricResistance,
    ElectricConductance,
    MagneticFlux,
    MagneticFluxDensity,
    Inductance,
    Temperature,
    LuminousFlux,
    Illuminance,
    DynamicViscosity,
    MomentOfForce,
    AngularVelocity,
    AngularAcceleration,
    SurfaceTension,
    HeatFluxDensity,
    HeatCapacity,
    SpecificHeatCapacity,
    SpecificEnergy,
    ThermalConductivity,
    EnergyDensity,
    ElectricFieldStrength,
    ElectricChargeDensity,
    ElectricFluxDensity,
    Permittivity,
    Permeability,
    MolarEnergy,
    MolarHeatCapacity,
    Radiance,
    Momentum,
    MassDensity,
    MassThermodynamicTemperature,
    LengthThermodynamicTemperature,
    AmountOfSubstanceThermodynamicTemperature,
    AreaSolidAngle,
    PerAmountOfSubstance,
    EnergyPerFrequency
  };

  constexpr BasicUnit() = default;
  constexpr explicit BasicUnit(NativeType value) : m_native_value(value) {}
  constexpr BasicUnit(NativeType value, Type type)
    : m_native_value(value), m_type(type) {}

  NativeType m_native_value{};
  Type m_type = Type::Unitless;
  static bool is_equal(NativeType a, NativeType b);
};

class Unitless : public BasicUnit {
public:
  static constexpr const char *unit() { return "unitless"; }
  static constexpr const char *symbol() { return ""; }

  constexpr Unitless() = default;
  constexpr explicit Unitless(NativeType value) : BasicUnit(value) {}

  auto operator*(Unitless a) const {
    return Unitless(m_native_value * a.m_native_value);
  }
  auto &operator*=(Unitless a) {
    m_native_value *= a.m_native_value;
    return *this;
  }

  auto operator/(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  auto &operator/=(Unitless a) {
    m_native_value /= a.m_native_value;
    return *this;
  }

  auto operator+(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  auto &operator+=(Unitless a) {
    m_native_value += a.m_native_value;
    return *this;
  }

  auto operator-(Unitless a) const {
    return Unitless(m_native_value + a.m_native_value);
  }
  auto &operator-=(Unitless a) {
    m_native_value -= a.m_native_value;
    return *this;
  }

private:
};

template <class Derived> class BasicUnitAccess : public BasicUnit {
public:
  Derived operator+(const Derived &a) const {
    return Derived(value() + a.value());
  }

  Derived &operator+=(const Derived &a) {
    m_native_value += a.value();
    return static_cast<Derived &>(*this);
  }

  Derived operator-(const Derived &a) const {
    return Derived(value() - a.value());
  }

  Derived &operator-=(const Derived &a) {
    m_native_value -= a.value();
    return static_cast<Derived &>(*this);
  }

  Derived operator*(Unitless a) const { return m_native_value * a.value(); }

  Derived operator/(Unitless a) const { return m_native_value / a.value(); }

  Derived &operator*=(Unitless a) {
    m_native_value *= a.value();
    return static_cast<Derived &>(*this);
  }

  Derived &operator/=(Unitless a) {
    m_native_value /= a.value();
    return static_cast<Derived &>(*this);
  }

  Unitless operator/(Derived a) const {
    return Unitless(m_native_value / a.m_native_value);
  }

  bool operator==(const Derived &a) const {
    return is_equal(value(), a.value());
  }

  bool operator!=(const Derived &a) const {
    return !is_equal(value(), a.value());
  }

  bool operator<(const Derived &a) const { return value() < a.value(); }

  bool operator>(const Derived &a) const { return value() > a.value(); }

  bool operator<=(const Derived &a) const {
    return value() < a.value() || is_equal(value(), a.value());
  }

  bool operator>=(const Derived &a) const {
    return value() > a.value() || is_equal(value(), a.value());
  }

  template <class ConvertType>
  ConvertType convert(Derived numerator, ConvertType denominator) const {
    return ConvertType(
      m_native_value * (numerator.value() / denominator.value()));
  }

protected:
  friend class BasicUnit;
  constexpr BasicUnitAccess() = default;
  constexpr BasicUnitAccess(NativeType value, Type type)
    : BasicUnit(value, type) {}
};

class OrthogonalLength : public BasicUnitAccess<OrthogonalLength> {
public:
  static constexpr const char *unit() { return "meter"; }
  static constexpr const char *symbol() { return "m"; }

  UNITS_BASIC_CONSTRUCT(OrthogonalLength);

private:
};

class Length : public BasicUnitAccess<Length> {
public:
  static constexpr const char *unit() { return "meter"; }
  static constexpr const char *symbol() { return "m"; }

  UNITS_BASIC_CONSTRUCT(Length);

  OrthogonalLength get_orthogonal_length() const {
    return OrthogonalLength(value());
  }
};

class Pi : public BasicUnitAccess<Pi> {
public:
  static constexpr const char *unit() { return "radians"; }
  static constexpr const char *symbol() { return "rad"; }

  constexpr Pi()
    : BasicUnitAccess<Pi>(
      UNITS_NATIVE_SUFFIX(3.14159265358979323846),
      Type::Pi) {}
};

class TwoPi : public BasicUnitAccess<TwoPi> {
public:
  static constexpr const char *unit() { return "radians"; }
  static constexpr const char *symbol() { return "rad"; }

  constexpr TwoPi()
    : BasicUnitAccess<TwoPi>(
      UNITS_NATIVE_SUFFIX(3.14159265358979323846) * UNITS_NATIVE_SUFFIX(2.0),
      Type::TwoPi) {}
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

API_MAYBE_UNUSED Length from_mils(NativeType input);
API_MAYBE_UNUSED Length from_inches(NativeType input);
API_MAYBE_UNUSED Length from_feet(NativeType input);
API_MAYBE_UNUSED Length from_miles(NativeType input);

API_MAYBE_UNUSED NativeType to_mils(Length input);
API_MAYBE_UNUSED NativeType to_inches(Length input);
API_MAYBE_UNUSED NativeType to_feet(Length input);
API_MAYBE_UNUSED NativeType to_miles(Length input);

API_MAYBE_UNUSED PlaneAngle from_degrees(NativeType input);
API_MAYBE_UNUSED NativeType to_degrees(PlaneAngle input);

inline Mass operator"" _ug(unsigned long long int value) {
  return Mass(
    NativeType(value) * BasicUnit::unit_type_multiplier / 1'000'000'000);
}
inline Mass operator"" _mg(unsigned long long int value) {
  return Mass(NativeType(value) * BasicUnit::unit_type_multiplier / 1'000'000);
}
inline Mass operator"" _g(unsigned long long int value) {
  return Mass(NativeType(value) * BasicUnit::unit_type_multiplier / 1'000);
}
inline Mass operator"" _kg(unsigned long long int value) {
  return Mass(NativeType(value) * BasicUnit::unit_type_multiplier);
}
inline Mass operator"" _Mg(unsigned long long int value) {
  return Mass(NativeType(value) * BasicUnit::unit_type_multiplier * 1'000);
}
inline Mass operator"" _Gg(unsigned long long int value) {
  return Mass(NativeType(value) * BasicUnit::unit_type_multiplier * 1'000'000);
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
