//
// Created by Tyler Gilbert on 1/18/22.
//

#include "units/DerivedUnits.hpp"

#define DEFINE_MULTIPLY(RESULT, LHS, RHS)                                      \
  RESULT operator*(LHS lhs, RHS rhs) {                                         \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  RESULT operator*(RHS lhs, LHS rhs) {                                         \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  LHS operator/(RESULT lhs, RHS rhs) {                                         \
    return LHS(lhs.native_value() / rhs.native_value());                       \
  }                                                                            \
  RHS operator/(RESULT lhs, LHS rhs) {                                         \
    return RHS(lhs.native_value() / rhs.native_value());                       \
  }

#define DEFINE_MULTIPLY_SAME(RESULT, LHS)                                      \
  RESULT operator*(LHS lhs, LHS rhs) {                                         \
    return RESULT(lhs.native_value() * rhs.native_value());                    \
  }                                                                            \
  LHS operator/(RESULT lhs, LHS rhs) {                                         \
    return LHS(lhs.native_value() / rhs.native_value());                       \
  }

#define DEFINE_DIVIDE(RESULT, LHS, RHS)                                        \
  RESULT operator/(LHS lhs, RHS rhs) {                                         \
    return RESULT(lhs.native_value() / rhs.native_value());                    \
  }                                                                            \
  RHS operator/(LHS lhs, RESULT rhs) {                                         \
    return RHS(lhs.native_value() / rhs.native_value());                       \
  }                                                                            \
  LHS operator*(RESULT lhs, RHS rhs) {                                         \
    return LHS(lhs.native_value() * rhs.native_value());                       \
  }                                                                            \
  LHS operator*(RHS lhs, RESULT rhs) {                                         \
    return LHS(lhs.native_value() * rhs.native_value());                       \
  }

namespace units {

DEFINE_MULTIPLY(Volume, Area, Length);
DEFINE_MULTIPLY_SAME(Area, Length);
DEFINE_DIVIDE(Frequency, Unitless, Time);
DEFINE_DIVIDE(Velocity, Length, Time);
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
DEFINE_DIVIDE(AngularAcceleration, AngularVelocity, Time);

Length operator / (Velocity lhs, Frequency rhs){
  return Length(lhs.native_value() * rhs.native_value());
}

Frequency operator / (Velocity lhs, Length rhs){
  return Frequency(lhs.native_value() * rhs.native_value());
}

Velocity from_feet_per_second(NativeType input){
  return from_feet(input) / 1_s;
}

Velocity from_miles_per_hour(NativeType input){
  return from_miles(input) / 3600_s;
}



} // namespace units
