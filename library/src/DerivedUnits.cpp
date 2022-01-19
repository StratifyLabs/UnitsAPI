//
// Created by Tyler Gilbert on 1/18/22.
//

#include "units/DerivedUnits.hpp"

#define DEFINE_MULTIPLY(RESULT, LHS, RHS)                                      \
  RESULT operator*(const LHS &lhs, const RHS &rhs) {                           \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  RESULT operator*(const RHS &lhs, const LHS &rhs) {                           \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  LHS operator/(const RESULT &lhs, const RHS &rhs) {                           \
    return LHS(lhs.native_value() / rhs.native_value());                       \
  }                                                                            \
  RHS operator/(const RESULT &lhs, const LHS &rhs) {                           \
    return RHS(lhs.native_value() / rhs.native_value());                       \
  }

#define DEFINE_MULTIPLY_SAME(RESULT, LHS)                                      \
  RESULT operator*(const LHS &lhs, const LHS &rhs) {                           \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  LHS operator/(const RESULT &lhs, const LHS &rhs) {                           \
    return LHS(lhs.native_value() / rhs.native_value());                       \
  }

#define DEFINE_DIVIDE(RESULT, LHS, RHS)                                        \
  RESULT operator/(const LHS &lhs, const RHS &rhs) {                           \
    return RESULT(lhs.native_value() / rhs.native_value());                    \
  }                                                                            \
  RHS operator/(const LHS &lhs, const RESULT &rhs) {                           \
    return RHS(lhs.native_value() / rhs.native_value());                       \
  }                                                                            \
  LHS operator*(const RESULT &lhs, const RHS &rhs) {                           \
    return LHS(lhs.native_value() * rhs.native_value());                       \
  }                                                                            \
  LHS operator*(const RHS &lhs, const RESULT &rhs) {                           \
    return LHS(lhs.native_value() * rhs.native_value());                       \
  }

namespace units {

DEFINE_MULTIPLY(Volume, Area, Length);
DEFINE_MULTIPLY_SAME(Area, Length);
DEFINE_DIVIDE(Frequency, Unitless, Time);
DEFINE_DIVIDE(Velocity, Length, Time);
DEFINE_DIVIDE(Acceleration, Velocity, Time);
DEFINE_MULTIPLY(Force, Mass, Acceleration);
DEFINE_DIVIDE(Pressure, Force, Area);
DEFINE_MULTIPLY(Energy, Force, Length);
DEFINE_DIVIDE(Power, Energy, Time);
DEFINE_MULTIPLY(ElectricCharge, ElectricCurrent, Time);
DEFINE_DIVIDE(ElectricPotential, Power, ElectricCurrent);
DEFINE_DIVIDE(Capacitance, ElectricCharge, ElectricPotential);
DEFINE_DIVIDE(ElectricResistance, ElectricPotential, ElectricCurrent);
DEFINE_DIVIDE(ElectricConductance, ElectricCurrent, ElectricPotential);
DEFINE_DIVIDE(MagneticFluxDensity, MagneticFlux, Area);
DEFINE_DIVIDE(Inductance, MagneticFlux, ElectricCurrent);
DEFINE_MULTIPLY(LuminousFlux, LuminousIntensity, SolidAngle);
DEFINE_DIVIDE(Illuminance, LuminousIntensity, Area);
DEFINE_MULTIPLY(DynamicViscosity, Pressure, Time);
DEFINE_MULTIPLY(MomentOfForce, Force, OrthogonalLength);
DEFINE_DIVIDE(AngularVelocity, PlaneAngle, Time);

AngularFrequency operator*(const TwoPi &lhs, const Frequency &rhs) {
  return AngularFrequency(lhs.native_value() * rhs.native_value());
}

AngularFrequency operator*(const Frequency &lhs, const TwoPi &rhs) {
  return AngularFrequency(lhs.native_value() * rhs.native_value());
}

Frequency operator/(const AngularFrequency &lhs, const TwoPi &rhs) {
  return Frequency(lhs.native_value() / rhs.native_value());
}

AngularFrequency operator/(const TwoPi &lhs, const Time &rhs){
  return AngularFrequency(lhs.native_value() / rhs.native_value());
}

Time operator/(const TwoPi &lhs, const AngularFrequency &rhs){
  return Time(lhs.native_value() / rhs.native_value());
}

DEFINE_DIVIDE(AngularAcceleration, AngularVelocity, Time);

DEFINE_MULTIPLY(Momentum, Mass, Velocity);
DEFINE_DIVIDE(MassDensity, Mass, Volume);

Length operator/(const Velocity &lhs, const Frequency & rhs) {
  return Length(lhs.native_value() * rhs.native_value());
}

Frequency operator/(const Velocity & lhs, const Length & rhs) {
  return Frequency(lhs.native_value() * rhs.native_value());
}

Velocity from_feet_per_second(NativeType input) {
  return from_feet(input) / 1_s;
}

Velocity from_miles_per_hour(NativeType input) {
  return from_miles(input) / 3600_s;
}

Frequency from_rounds_per_minute(NativeType input) {
  return Frequency(input / UNITS_NATIVE_SUFFIX(60.0));
}

} // namespace units
