//
// Created by Tyler Gilbert on 1/18/22.
//

#ifndef UNITSAPI_UNITS_DERIVEDUNITS_HPP
#define UNITSAPI_UNITS_DERIVEDUNITS_HPP

#include "BasicUnits.hpp"

namespace units {

UNITS_DECLARE_DERIVED_UNIT(Frequency, hertz, "Hz");
UNITS_DECLARE_DERIVED_UNIT(Area, square meter,"m^2");
UNITS_DECLARE_DERIVED_UNIT(Volume, cubic meter, "m^3");
UNITS_DECLARE_DERIVED_UNIT(Velocity, meter per second, "m/s");
UNITS_DECLARE_DERIVED_UNIT(Acceleration, meter per second squared, "m/s^2");
UNITS_DECLARE_DERIVED_UNIT(Force, newton, "N");
UNITS_DECLARE_DERIVED_UNIT(Pressure, pascal, "Pa");
UNITS_DECLARE_DERIVED_UNIT(Energy, joule, "J");
UNITS_DECLARE_DERIVED_UNIT(Power, watt, "W");
UNITS_DECLARE_DERIVED_UNIT(ElectricCharge, coulomb, "C");
UNITS_DECLARE_DERIVED_UNIT(ElectricPotential, volt, "V");
UNITS_DECLARE_DERIVED_UNIT(Capacitance, farad, "F");
UNITS_DECLARE_DERIVED_UNIT(ElectricResistance, ohm, "ohms");
UNITS_DECLARE_DERIVED_UNIT(ElectricConductance, siemens, "S");
UNITS_DECLARE_DERIVED_UNIT(MagneticFlux, weber, "Wb");
UNITS_DECLARE_DERIVED_UNIT(MagneticFluxDensity, tesla, "T");
UNITS_DECLARE_DERIVED_UNIT(Inductance, henry, "H");
UNITS_DECLARE_DERIVED_UNIT(Temperature, degree Celsius, "C");
UNITS_DECLARE_DERIVED_UNIT(LuminousFlux, lumen, "lm");
UNITS_DECLARE_DERIVED_UNIT(Illuminance, lux, "lx");
UNITS_DECLARE_DERIVED_UNIT(DynamicViscosity, pascal second, "Pa*s");
UNITS_DECLARE_DERIVED_UNIT(MomentOfForce, newton meter, "N*m");
UNITS_DECLARE_DERIVED_UNIT(AngularVelocity, radian per second, "rad/s");
UNITS_DECLARE_DERIVED_UNIT(
  AngularAcceleration,
  radian per second squared,
  "rad/s^2");

UNITS_DECLARE_DERIVED_UNIT(SurfaceTension, newton per meter, "N/m");
UNITS_DECLARE_DERIVED_UNIT(HeatFluxDensity, watt per square meter, "W/m^2");
UNITS_DECLARE_DERIVED_UNIT(HeatCapacity, joule per kelvin, "J/K");
UNITS_DECLARE_DERIVED_UNIT(
  SpecificHeatCapacity,
  joule per kilogram kelvin,
  "J/(kg*K)");
UNITS_DECLARE_DERIVED_UNIT(SpecificEnergy, joule per kilogram, "J/kg");
UNITS_DECLARE_DERIVED_UNIT(
  ThermalConductivity,
  watt per meter kelvin,
  "W/(m*K)");
UNITS_DECLARE_DERIVED_UNIT(EnergyDensity, joule per cubic meter, "J/m^3");
UNITS_DECLARE_DERIVED_UNIT(ElectricFieldStrength, volt per meter, "V/m");
UNITS_DECLARE_DERIVED_UNIT(
  ElectricChargeDensity,
  coulomb per cubic meter,
  "C/m^3");
UNITS_DECLARE_DERIVED_UNIT(
  ElectricFluxDensity,
  coulomb per square meter,
  "C/m^2");
UNITS_DECLARE_DERIVED_UNIT(Permittivity, farad per meter, "F/m");
UNITS_DECLARE_DERIVED_UNIT(Permeability, henry per meter, "H/m");
UNITS_DECLARE_DERIVED_UNIT(MolarEnergy, joule per mole, "J/mol");
UNITS_DECLARE_DERIVED_UNIT(
  MolarHeatCapacity,
  joule per mole kelvin,
  "J/(mol*K)");

UNITS_DECLARE_DERIVED_UNIT(
  Radiance,
  watt per square meter steradian,
  "W/(m^2*sr)");

// declare operations
UNITS_DECLARE_MULTIPLY(Volume, Area, Length);
UNITS_DECLARE_MULTIPLY_SAME(Area, Length);
UNITS_DECLARE_DIVIDE(Frequency, Unitless, Time);
UNITS_DECLARE_DIVIDE(Velocity, Length, Time);
UNITS_DECLARE_DIVIDE(Acceleration, Velocity, Time);
Length operator/(Velocity lhs, Frequency rhs);
Frequency operator/(Velocity lhs, Length rhs);
UNITS_DECLARE_MULTIPLY(Force, Mass, Acceleration);
UNITS_DECLARE_DIVIDE(Pressure, Force, Area);
UNITS_DECLARE_MULTIPLY(Energy, Force, Length);
UNITS_DECLARE_DIVIDE(Power, Energy, Time);
UNITS_DECLARE_MULTIPLY(ElectricCharge, ElectricCurrent, Time);
UNITS_DECLARE_DIVIDE(ElectricPotential, Power, ElectricCurrent);
UNITS_DECLARE_DIVIDE(Capacitance, ElectricCharge, ElectricPotential);
UNITS_DECLARE_DIVIDE(ElectricResistance, ElectricPotential, ElectricCurrent);
UNITS_DECLARE_DIVIDE(ElectricConductance, ElectricCurrent, ElectricPotential);
UNITS_DECLARE_DIVIDE(MagneticFluxDensity, MagneticFlux, Area);
UNITS_DECLARE_DIVIDE(Inductance, MagneticFlux, ElectricCurrent);
UNITS_DECLARE_MULTIPLY(LuminousFlux, LuminousIntensity, SolidAngle);
UNITS_DECLARE_DIVIDE(Illuminance, LuminousIntensity, Area);
UNITS_DECLARE_MULTIPLY(DynamicViscosity, Pressure, Time);
UNITS_DECLARE_MULTIPLY(MomentOfForce, Force, OrthogonalLength);
UNITS_DECLARE_DIVIDE(AngularVelocity, PlaneAngle, Time);
UNITS_DECLARE_DIVIDE(AngularAcceleration, AngularVelocity, Time);
UNITS_DECLARE_DIVIDE(SurfaceTension, Force, Length);
UNITS_DECLARE_DIVIDE(HeatFluxDensity, Power, Area);
UNITS_DECLARE_DIVIDE(HeatCapacity, Energy, ThermodynamicTemperature);
// UNITS_DECLARE_DIVIDE(SpecificHeatCapacity,Energy,Mass *
// ThermodynamicTemperature);
UNITS_DECLARE_DIVIDE(SpecificEnergy, Energy, Mass);
// UNITS_DECLARE_DIVIDE(ThermalConductivity,Power,Length *
// ThermodynamicTemperature);
UNITS_DECLARE_DIVIDE(EnergyDensity, Energy, Volume);
UNITS_DECLARE_DIVIDE(ElectricFieldStrength, ElectricPotential, Length);
UNITS_DECLARE_DIVIDE(ElectricChargeDensity, ElectricCharge, Volume);
UNITS_DECLARE_DIVIDE(ElectricFluxDensity, ElectricCharge, Area);
UNITS_DECLARE_DIVIDE(Permittivity, Capacitance, Length);
UNITS_DECLARE_DIVIDE(Permeability, Inductance, Length);
UNITS_DECLARE_DIVIDE(MolarEnergy, Energy, AmountOfSubstance);
// UNITS_DECLARE_DIVIDE(MolarHeatCapacity,Energy,AmountOfSubstance *
// ThermodynamicTemperature); UNITS_DECLARE_DIVIDE(Radiance,Power,Area *
// SolidAngle);

UNITS_BASIC_UNIT_DEFINE_LITERAL(Area, m2)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Volume, m3)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Frequency, Hz)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Power, W)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Energy, J)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ElectricPotential, V)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ElectricCharge, C)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ElectricResistance, ohms)
UNITS_BASIC_UNIT_DEFINE_LITERAL(ElectricConductance, S)
UNITS_BASIC_UNIT_DEFINE_LITERAL(MagneticFlux, Wb)
UNITS_BASIC_UNIT_DEFINE_LITERAL(MagneticFluxDensity, T)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Capacitance, F)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Inductance, H)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Force, N)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Pressure, Pa)
UNITS_BASIC_UNIT_DEFINE_LITERAL(Velocity, mps)
UNITS_BASIC_UNIT_DEFINE_LITERAL(AngularVelocity, radps)

Velocity from_feet_per_second(NativeType input);
Velocity from_miles_per_hour(NativeType input);

static inline constexpr Velocity speed_of_light() {
  return Velocity(UNITS_NATIVE_SUFFIX(299'792'458.0));
}

static inline constexpr ElectricCharge elementary_charge() {
  return ElectricCharge(UNITS_NATIVE_SUFFIX(1.602176634) * UNITS_NATIVE_SUFFIX(10E-19));
}

static inline constexpr Acceleration gravity() {
  return Acceleration(UNITS_NATIVE_SUFFIX(9.81));
}

static inline constexpr Mass atomic_mass_unit() {
  return Mass(UNITS_NATIVE_SUFFIX(1.660'540) * UNITS_NATIVE_SUFFIX(10E-27));
}

static inline constexpr Pressure atmospheric_pressure() {
  return Pressure(UNITS_NATIVE_SUFFIX(1.01325) * UNITS_NATIVE_SUFFIX(10E5));
}

} // namespace units

#endif // UNITSAPI_UNITS_DERIVEDUNITS_HPP
