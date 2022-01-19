//
// Created by Tyler Gilbert on 1/19/22.
//

#include "units/Physics.hpp"

namespace units {

Energy get_kinetic_energy(Mass mass, Velocity velocity){
  return (Unitless(UNITS_NATIVE_SUFFIX(0.5)) * mass * velocity) * velocity;
}

Energy get_potential_energy(Mass mass, Length height, Acceleration acceleration){
  return (Unitless(UNITS_NATIVE_SUFFIX(0.5)) * mass * acceleration * height);
}

} // namespace units