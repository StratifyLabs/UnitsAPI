//
// Created by Tyler Gilbert on 1/18/22.
//

#include <cmath>

#include <printer/Printer.hpp>

#include "units/DerivedUnits.hpp"

#if 0
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
#endif

namespace printer {
class Printer;
Printer &operator<<(Printer &printer, const units::BasicUnit &basic_unit) {
  return printer.key("unit", units::BasicUnit::get_unit(basic_unit))
    .key("symbol", units::BasicUnit::get_symbol(basic_unit))
    .key("value", var::NumberString(basic_unit.value()));
}
} // namespace printer

namespace units {

bool BasicUnit::is_equal(NativeType a, NativeType b) {
  return UNITS_NATIVE_SUFFIX(fabs)(a - b) < UNITS_PRECISION;
}

var::NumberString BasicUnit::to_string(const char *fmt) const {
  return var::NumberString(value(), fmt).append(get_symbol(*this));
}

Length from_feet(NativeType value) {
  return Length(value * UNITS_NATIVE_SUFFIX(0.3048));
}

Length from_miles(NativeType value) { return from_feet(value * 5280); }

Length from_inches(NativeType value) {
  return Length(value * UNITS_NATIVE_SUFFIX(0.0254));
}

Length from_mils(NativeType value) { return from_inches(value / 1000); }

NativeType to_mils(Length input) {
  return input.value() * UNITS_NATIVE_SUFFIX(0.03937008);
}

NativeType to_inches(Length input) {
  return input.value() * UNITS_NATIVE_SUFFIX(39.37008);
}

NativeType to_feet(Length input) {
  return input.value() * UNITS_NATIVE_SUFFIX(3.28084);
}

NativeType to_miles(Length input) {
  return to_feet(input) / UNITS_NATIVE_SUFFIX(5280.0);
}

PlaneAngle from_degrees(NativeType input) {
  return PlaneAngle(input / UNITS_NATIVE_SUFFIX(180.0) * Pi().value());
}
NativeType to_degrees(PlaneAngle input) {
  return input.value() / Pi().value() * UNITS_NATIVE_SUFFIX(180.0);
}

#define HANDLE_CASE(NAME, FUNCTION)                                            \
  case Type::NAME:                                                             \
    return NAME::FUNCTION()

const char *BasicUnit::get_unit(const BasicUnit &a) {
  switch (a.m_type) {
    HANDLE_CASE(Unitless, unit);
    HANDLE_CASE(Time, unit);
    HANDLE_CASE(ElectricCurrent, unit);
    HANDLE_CASE(ThermodynamicTemperature, unit);
    HANDLE_CASE(AmountOfSubstance, unit);
    HANDLE_CASE(Mass, unit);
    HANDLE_CASE(LuminousIntensity, unit);
    HANDLE_CASE(PlaneAngle, unit);
    HANDLE_CASE(SolidAngle, unit);
    HANDLE_CASE(Length, unit);
    HANDLE_CASE(OrthogonalLength, unit);
    HANDLE_CASE(Pi, unit);
    HANDLE_CASE(TwoPi, unit);
    HANDLE_CASE(Frequency, unit);
    HANDLE_CASE(Area, unit);
    HANDLE_CASE(Volume, unit);
    HANDLE_CASE(Velocity, unit);
    HANDLE_CASE(Acceleration, unit);
    HANDLE_CASE(Force, unit);
    HANDLE_CASE(Pressure, unit);
    HANDLE_CASE(Energy, unit);
    HANDLE_CASE(Power, unit);
    HANDLE_CASE(ElectricCharge, unit);
    HANDLE_CASE(ElectricPotential, unit);
    HANDLE_CASE(Capacitance, unit);
    HANDLE_CASE(ElectricResistance, unit);
    HANDLE_CASE(ElectricConductance, unit);
    HANDLE_CASE(MagneticFlux, unit);
    HANDLE_CASE(MagneticFluxDensity, unit);
    HANDLE_CASE(Inductance, unit);
    HANDLE_CASE(Temperature, unit);
    HANDLE_CASE(LuminousFlux, unit);
    HANDLE_CASE(Illuminance, unit);
    HANDLE_CASE(DynamicViscosity, unit);
    HANDLE_CASE(MomentOfForce, unit);
    HANDLE_CASE(AngularVelocity, unit);
    HANDLE_CASE(AngularAcceleration, unit);
    HANDLE_CASE(SurfaceTension, unit);
    HANDLE_CASE(HeatFluxDensity, unit);
    HANDLE_CASE(HeatCapacity, unit);
    HANDLE_CASE(SpecificHeatCapacity, unit);
    HANDLE_CASE(SpecificEnergy, unit);
    HANDLE_CASE(ThermalConductivity, unit);
    HANDLE_CASE(EnergyDensity, unit);
    HANDLE_CASE(ElectricFieldStrength, unit);
    HANDLE_CASE(ElectricChargeDensity, unit);
    HANDLE_CASE(ElectricFluxDensity, unit);
    HANDLE_CASE(Permittivity, unit);
    HANDLE_CASE(Permeability, unit);
    HANDLE_CASE(MolarEnergy, unit);
    HANDLE_CASE(MolarHeatCapacity, unit);
    HANDLE_CASE(Radiance, unit);
    HANDLE_CASE(Momentum, unit);
    HANDLE_CASE(MassDensity, unit);
    HANDLE_CASE(MassThermodynamicTemperature, unit);
    HANDLE_CASE(LengthThermodynamicTemperature, unit);
    HANDLE_CASE(AmountOfSubstanceThermodynamicTemperature, unit);
    HANDLE_CASE(AreaSolidAngle, unit);
  }
  API_ASSERT(false);
  return "";
}

const char *BasicUnit::get_symbol(const BasicUnit &a) {
  switch (a.m_type) {
    HANDLE_CASE(Mass, symbol);
    HANDLE_CASE(Unitless, symbol);
    HANDLE_CASE(Time, symbol);
    HANDLE_CASE(ElectricCurrent, symbol);
    HANDLE_CASE(ThermodynamicTemperature, symbol);
    HANDLE_CASE(AmountOfSubstance, symbol);
    HANDLE_CASE(LuminousIntensity, symbol);
    HANDLE_CASE(PlaneAngle, symbol);
    HANDLE_CASE(SolidAngle, symbol);
    HANDLE_CASE(Length, symbol);
    HANDLE_CASE(OrthogonalLength, symbol);
    HANDLE_CASE(Pi, symbol);
    HANDLE_CASE(TwoPi, symbol);
    HANDLE_CASE(Frequency, symbol);
    HANDLE_CASE(Area, symbol);
    HANDLE_CASE(Volume, symbol);
    HANDLE_CASE(Velocity, symbol);
    HANDLE_CASE(Acceleration, symbol);
    HANDLE_CASE(Force, symbol);
    HANDLE_CASE(Pressure, symbol);
    HANDLE_CASE(Energy, symbol);
    HANDLE_CASE(Power, symbol);
    HANDLE_CASE(ElectricCharge, symbol);
    HANDLE_CASE(ElectricPotential, symbol);
    HANDLE_CASE(Capacitance, symbol);
    HANDLE_CASE(ElectricResistance, symbol);
    HANDLE_CASE(ElectricConductance, symbol);
    HANDLE_CASE(MagneticFlux, symbol);
    HANDLE_CASE(MagneticFluxDensity, symbol);
    HANDLE_CASE(Inductance, symbol);
    HANDLE_CASE(Temperature, symbol);
    HANDLE_CASE(LuminousFlux, symbol);
    HANDLE_CASE(Illuminance, symbol);
    HANDLE_CASE(DynamicViscosity, symbol);
    HANDLE_CASE(MomentOfForce, symbol);
    HANDLE_CASE(AngularVelocity, symbol);
    HANDLE_CASE(AngularAcceleration, symbol);
    HANDLE_CASE(SurfaceTension, symbol);
    HANDLE_CASE(HeatFluxDensity, symbol);
    HANDLE_CASE(HeatCapacity, symbol);
    HANDLE_CASE(SpecificHeatCapacity, symbol);
    HANDLE_CASE(SpecificEnergy, symbol);
    HANDLE_CASE(ThermalConductivity, symbol);
    HANDLE_CASE(EnergyDensity, symbol);
    HANDLE_CASE(ElectricFieldStrength, symbol);
    HANDLE_CASE(ElectricChargeDensity, symbol);
    HANDLE_CASE(ElectricFluxDensity, symbol);
    HANDLE_CASE(Permittivity, symbol);
    HANDLE_CASE(Permeability, symbol);
    HANDLE_CASE(MolarEnergy, symbol);
    HANDLE_CASE(MolarHeatCapacity, symbol);
    HANDLE_CASE(Radiance, symbol);
    HANDLE_CASE(Momentum, symbol);
    HANDLE_CASE(MassDensity, symbol);
    HANDLE_CASE(MassThermodynamicTemperature, symbol);
    HANDLE_CASE(LengthThermodynamicTemperature, symbol);
    HANDLE_CASE(AmountOfSubstanceThermodynamicTemperature, symbol);
    HANDLE_CASE(AreaSolidAngle, symbol);
  }
  API_ASSERT(false);
  return "";
}

NativeType BasicUnit::absolute_value() const {
  return UNITS_ABS(value());
}

} // namespace units
