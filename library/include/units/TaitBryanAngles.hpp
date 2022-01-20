//
// Created by Tyler Gilbert on 1/19/22.
//

#ifndef UNITSAPI_UNITS_TAITBRYAN_ANGLES_HPP
#define UNITSAPI_UNITS_TAITBRYAN_ANGLES_HPP

#include "DerivedUnits.hpp"

namespace units {


//Tait-Bryan Angles
template <class Derived, class Type> class ThreeDimensionalTaitBryanAngle {
public:
  Type phi; //roll
  Type theta; //pitch
  Type psi; //yaw

  Derived operator+(const Derived &a) const {
    return Derived{phi + a.phi, theta + a.theta, psi + a.psi};
  }

  Derived &operator+=(const Derived &a) {
    phi += a.phi;
    theta += a.theta;
    psi += a.psi;
    return static_cast<Derived &>(*this);
  }

  Derived operator-(const Derived &a) const {
    return Derived{phi - a.phi, theta - a.theta, psi - a.psi};
  }

  Derived &operator-=(const Derived &a) {
    phi -= a.phi;
    theta -= a.theta;
    psi -= a.psi;
    return static_cast<Derived &>(*this);
  }
};


struct AngularPosition3d
  : public ThreeDimensionalTaitBryanAngle<AngularPosition3d, PlaneAngle> {


};

struct AngularVelocity3d
  : public ThreeDimensionalTaitBryanAngle<AngularVelocity3d, AngularVelocity> {

  AngularPosition3d get_change_in_position(Time duration) const;

};

struct AngularAcceleration3d
  : public ThreeDimensionalTaitBryanAngle<AngularAcceleration3d, AngularAcceleration> {

  AngularVelocity3d get_change_in_velocity(Time duration) const;
};


} // namespace units

namespace printer {
class Printer;
Printer &operator<<(Printer &printer, const units::AngularPosition3d &a);
Printer &operator<<(Printer &printer, const units::AngularVelocity3d &a);
Printer &operator<<(Printer &printer, const units::AngularAcceleration3d &a);
} // namespace printer

#endif // UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP
