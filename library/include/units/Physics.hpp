//
// Created by Tyler Gilbert on 1/19/22.
//

#ifndef UNITSAPI_UNITS_PHYSICS_HPP
#define UNITSAPI_UNITS_PHYSICS_HPP

#include "CartesianCoordinates.hpp"
#include "DerivedUnits.hpp"

namespace units {


static inline constexpr Velocity speed_of_light() {
  return Velocity(UNITS_NATIVE_SUFFIX(299'792'458.0));
}

static inline constexpr Frequency caesium_hyperfine_frequency() {
  return Frequency(UNITS_NATIVE_SUFFIX(9'192'631'770.0));
}

static inline constexpr HeatCapacity boltzmann() {
  return HeatCapacity(
    UNITS_NATIVE_SUFFIX(1.380'649) * UNITS_NATIVE_SUFFIX(10E-23));
}

static inline constexpr EnergyPerFrequency plank() {
  return EnergyPerFrequency(
    UNITS_NATIVE_SUFFIX(6.626'070) * UNITS_NATIVE_SUFFIX(10E-34));
}

static inline constexpr PerAmountOfSubstance avogadro() {
  return PerAmountOfSubstance(
    UNITS_NATIVE_SUFFIX(6.022'140) * UNITS_NATIVE_SUFFIX(10E23));
}

static inline constexpr ElectricCharge elementary_charge() {
  return ElectricCharge(
    UNITS_NATIVE_SUFFIX(1.602176634) * UNITS_NATIVE_SUFFIX(10E-19));
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

namespace constants {
static inline constexpr Velocity c(){ return speed_of_light(); }
static inline constexpr ElectricCharge e(){ return elementary_charge(); }
static inline constexpr HeatCapacity k(){ return boltzmann(); }
static inline constexpr EnergyPerFrequency h(){ return plank(); }
static inline constexpr PerAmountOfSubstance N_A(){ return avogadro(); }
}

Energy get_kinetic_energy(Mass mass, Velocity velocity);
Energy get_potential_energy(
  Mass mass,
  Length height,
  Acceleration acceleration = gravity());

// angular velocity is cross of angular acceleration and radius vector
// angular momentum is the cross of radius and linear momentum (point)
// angular momentum is also cross of rotational inertia and angular velocity
// (extended) Work is dot product of F and S (displacement) Power is the dot
// product of Force and Velocity

// torque is the cross product of Force and Vector R
// tangential velocity is the cross of Angular velocity and a radius vector

} // namespace units

#endif // UNITSAPI_UNITS_PHYSICS_HPP
