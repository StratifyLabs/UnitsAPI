//
// Created by Tyler Gilbert on 1/18/22.
//

#include "units/DerivedUnits.hpp"

#define DEFINE_MULTIPLY(RESULT, LHS, RHS)                                      \
  RESULT operator*(const LHS &lhs, const RHS &rhs) {                           \
    return RESULT(lhs.value() * rhs.value());                                  \
  }                                                                            \
  RESULT operator*(const RHS &lhs, const LHS &rhs) {                           \
    return RESULT(lhs.value() * rhs.value());                                  \
  }                                                                            \
  LHS operator/(const RESULT &lhs, const RHS &rhs) {                           \
    return LHS(lhs.value() / rhs.value());                                     \
  }                                                                            \
  RHS operator/(const RESULT &lhs, const LHS &rhs) {                           \
    return RHS(lhs.value() / rhs.value());                                     \
  }

#define DEFINE_MULTIPLY_SAME(RESULT, LHS)                                      \
  RESULT operator*(const LHS &lhs, const LHS &rhs) {                           \
    return RESULT(lhs.value() * rhs.value());                                  \
  }                                                                            \
  LHS operator/(const RESULT &lhs, const LHS &rhs) {                           \
    return LHS(lhs.value() / rhs.value());                                     \
  }

#define DEFINE_DIVIDE(RESULT, LHS, RHS)                                        \
  RESULT operator/(const LHS &lhs, const RHS &rhs) {                           \
    return RESULT(lhs.value() / rhs.value());                                  \
  }                                                                            \
  RHS operator/(const LHS &lhs, const RESULT &rhs) {                           \
    return RHS(lhs.value() / rhs.value());                                     \
  }                                                                            \
  LHS operator*(const RESULT &lhs, const RHS &rhs) {                           \
    return LHS(lhs.value() * rhs.value());                                     \
  }                                                                            \
  LHS operator*(const RHS &lhs, const RESULT &rhs) {                           \
    return LHS(lhs.value() * rhs.value());                                     \
  }

namespace {
constexpr units::NativeType kelvin_celcius_delta = UNITS_NATIVE_SUFFIX(273.15);
constexpr units::NativeType fahrenheit_to_celcius_ratio
  = UNITS_NATIVE_SUFFIX(1.8);
constexpr units::NativeType fahrenheit_to_celcius_offset
  = UNITS_NATIVE_SUFFIX(32.0);
} // namespace

namespace units {

DEFINE_MULTIPLY(Volume, Area, Length);
DEFINE_MULTIPLY_SAME(Area, Length);
DEFINE_DIVIDE(Frequency, Unitless, Time);
DEFINE_DIVIDE(Velocity, Length, Time);
DEFINE_MULTIPLY(Velocity, Length, Frequency);
DEFINE_DIVIDE(Acceleration, Velocity, Time);
DEFINE_MULTIPLY(Acceleration, Velocity, Frequency);
DEFINE_MULTIPLY(Force, Mass, Acceleration);
DEFINE_DIVIDE(Pressure, Force, Area);
DEFINE_MULTIPLY(Energy, Force, Length);
DEFINE_MULTIPLY(EnergyPerFrequency, Energy, Time);
DEFINE_DIVIDE(EnergyPerFrequency, Energy, Frequency);
DEFINE_DIVIDE(Power, Energy, Time);
DEFINE_MULTIPLY(Power, Energy, Frequency);
DEFINE_MULTIPLY(ElectricCharge, ElectricCurrent, Time);
DEFINE_DIVIDE(ElectricCharge, ElectricCurrent, Frequency);
DEFINE_DIVIDE(ElectricPotential, Power, ElectricCurrent);
DEFINE_DIVIDE(Capacitance, ElectricCharge, ElectricPotential);
DEFINE_DIVIDE(ElectricResistance, ElectricPotential, ElectricCurrent);
DEFINE_DIVIDE(ElectricConductance, ElectricCurrent, ElectricPotential);
DEFINE_DIVIDE(MagneticFluxDensity, MagneticFlux, Area);
DEFINE_DIVIDE(Inductance, MagneticFlux, ElectricCurrent);
DEFINE_MULTIPLY(LuminousFlux, LuminousIntensity, SolidAngle);
DEFINE_DIVIDE(Illuminance, LuminousIntensity, Area);
DEFINE_MULTIPLY(DynamicViscosity, Pressure, Time);
DEFINE_DIVIDE(DynamicViscosity, Pressure, Frequency);
DEFINE_MULTIPLY(MomentOfForce, Force, OrthogonalLength);
DEFINE_DIVIDE(AngularVelocity, PlaneAngle, Time);
DEFINE_MULTIPLY(AngularVelocity, PlaneAngle, Frequency);
DEFINE_DIVIDE(PerAmountOfSubstance, Unitless, AmountOfSubstance);

AngularFrequency operator*(const TwoPi &lhs, const Frequency &rhs) {
  return AngularFrequency(lhs.value() * rhs.value());
}

AngularFrequency operator*(const Frequency &lhs, const TwoPi &rhs) {
  return AngularFrequency(lhs.value() * rhs.value());
}

Frequency operator/(const AngularFrequency &lhs, const TwoPi &rhs) {
  return Frequency(lhs.value() / rhs.value());
}

AngularFrequency operator/(const TwoPi &lhs, const Time &rhs) {
  return AngularFrequency(lhs.value() / rhs.value());
}

Time operator/(const TwoPi &lhs, const AngularFrequency &rhs) {
  return Time(lhs.value() / rhs.value());
}

DEFINE_DIVIDE(AngularAcceleration, AngularVelocity, Time);
DEFINE_MULTIPLY(AngularAcceleration, AngularVelocity, Frequency);

DEFINE_MULTIPLY(Momentum, Mass, Velocity);
DEFINE_DIVIDE(MassDensity, Mass, Volume);

Velocity from_feet_per_second(NativeType input) {
  return from_feet(input) / 1_s;
}

Velocity from_miles_per_hour(NativeType input) {
  return from_miles(input) / 3600_s;
}

Frequency from_rounds_per_minute(NativeType input) {
  return Frequency(input / UNITS_NATIVE_SUFFIX(60.0));
}

Temperature to_celcius(ThermodynamicTemperature kelvin) {
  return Temperature(kelvin.value() - kelvin_celcius_delta);
}

ThermodynamicTemperature from_celcius(Temperature celcius) {
  return ThermodynamicTemperature(celcius.value() + kelvin_celcius_delta);
}

NativeType to_fahrenheit(ThermodynamicTemperature kelvin) {
  const auto degrees_c = to_celcius(kelvin);
  return degrees_c.value() * fahrenheit_to_celcius_ratio
         + fahrenheit_to_celcius_offset;
}

ThermodynamicTemperature from_fahrenheit(NativeType fahrenheit) {
  const auto degrees_c = Temperature(
    (fahrenheit - fahrenheit_to_celcius_offset) / fahrenheit_to_celcius_ratio);
  return from_celcius(degrees_c);
}

} // namespace units
