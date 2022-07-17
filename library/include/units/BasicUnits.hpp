//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_BASICUNITS_HPP
#define UNITSAPI_UNITS_BASICUNITS_HPP

#include <var/StackString.hpp>

#include "macros.hpp"

namespace units {

using NativeType = UNITS_NATIVE_TYPE;
using NativeIntegerType = s32;


class BasicUnit {
public:
  static constexpr NativeType unit_type_multiplier = UNITS_NATIVE_SUFFIX(1.0);

  constexpr NativeType value() const { return m_native_value; }
  NativeType absolute_value() const;

  NativeIntegerType yotta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E24);
  }
  NativeIntegerType zetta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E21);
  }
  NativeIntegerType exa() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E18); }
  NativeIntegerType peta() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E15);
  }
  NativeIntegerType tera() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(10E12);
  }
  NativeIntegerType giga() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E9); }
  NativeIntegerType mega() const { return m_native_value * UNITS_NATIVE_SUFFIX(10E6); }
  NativeIntegerType kilo() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1000.0);
  }
  NativeIntegerType hecto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(100.0);
  }
  NativeIntegerType deka() const { return m_native_value * UNITS_NATIVE_SUFFIX(10.0); }
  NativeIntegerType deci() const { return m_native_value * UNITS_NATIVE_SUFFIX(1E-1); }
  NativeIntegerType centi() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-2);
  }
  NativeIntegerType milli() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-3);
  }
  NativeIntegerType micro() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-6);
  }
  NativeIntegerType nano() const { return m_native_value * UNITS_NATIVE_SUFFIX(1E-9); }
  NativeIntegerType pico() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-12);
  }
  NativeIntegerType femto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-15);
  }
  NativeIntegerType atto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-18);
  }
  NativeIntegerType zepto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-21);
  }
  NativeIntegerType yocto() const {
    return m_native_value * UNITS_NATIVE_SUFFIX(1E-24);
  }

  var::NumberString to_string(const char *fmt = "%0.3f") const;

  static const char *get_unit(const BasicUnit &a);
  static const char *get_symbol(const BasicUnit &a);


protected:
  //Normally enum class values would be snake-case
  //but to have compatibility with the classes
  //and aid the use of macros, these names
  //match the class names
  enum class Type : u32 {
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
    MassDensity
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

  Derived operator*(Unitless a) const {
    return m_native_value * a.value();
  }

  Derived operator/(Unitless a) const {
    return m_native_value / a.value();
  }

  Derived& operator*=(Unitless a) {
    m_native_value *= a.value();
    return static_cast<Derived &>(*this);
  }

  Derived& operator/=(Unitless a) {
    m_native_value /= a.value();
    return static_cast<Derived &>(*this);
  }

  Unitless operator/(Derived a) const {
    return Unitless(m_native_value / a.m_native_value);
  }

  bool operator == (const Derived & a) const {
    return is_equal(value(), a.value());
  }

  bool operator != (const Derived & a) const {
    return !is_equal(value(), a.value());
  }

  bool operator < (const Derived & a) const {
    return value() < a.value();
  }

  bool operator > (const Derived & a) const {
    return value() > a.value();
  }

  bool operator <= (const Derived & a) const {
    return value() < a.value() || is_equal(value(), a.value());
  }

  bool operator >= (const Derived & a) const {
    return value() > a.value() || is_equal(value(), a.value());
  }


  template <class ConvertType> ConvertType convert(NativeType ratio) const {
    return ConvertType(m_native_value * ratio);
  }

protected:
  friend class BasicUnit;
  constexpr BasicUnitAccess() = default;
  constexpr BasicUnitAccess(NativeType value, Type type) : BasicUnit(value, type) {}

  constexpr static void magic_function() {}
  constexpr static void *magic_number() { return (void *)magic_function; }
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
    : BasicUnitAccess<Pi>(UNITS_NATIVE_SUFFIX(3.14159265358979323846), Type::Pi) {}
};

class TwoPi : public BasicUnitAccess<TwoPi> {
public:
  static constexpr const char *unit() { return "radians"; }
  static constexpr const char *symbol() { return "rad"; }

  constexpr TwoPi()
    : BasicUnitAccess<TwoPi>(
      UNITS_NATIVE_SUFFIX(3.14159265358979323846) * UNITS_NATIVE_SUFFIX(2.0), Type::TwoPi) {}
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

NativeType to_mils(Length input);
NativeType to_inches(Length input);
NativeType to_feet(Length input);
NativeType to_miles(Length input);

PlaneAngle from_degrees(NativeType input);
NativeType to_degrees(PlaneAngle input);



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
