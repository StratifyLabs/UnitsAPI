//
// Created by Tyler Gilbert on 1/19/22.
//

#ifndef UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP
#define UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP

#include "TaitBryanAngles.hpp"

namespace units {

template <class Derived, class Type> class ThreeDimensionalCartesianCoordinate {
public:
  Type x;
  Type y;
  Type z;

  Derived operator+(const Derived &a) const {
    return Derived{x + a.x, y + a.y, z + a.z};
  }

  Derived &operator+=(const Derived &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return static_cast<Derived &>(*this);
  }

  Derived operator-(const Derived &a) const {
    return Derived{x - a.x, y - a.y, z - a.z};
  }

  Derived &operator-=(const Derived &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return static_cast<Derived &>(*this);
  }

};

struct Point3d : public ThreeDimensionalCartesianCoordinate<Point3d, Length> {

  // calculate the distance to another point
  Length get_distance(const Point3d &a) const;
};

using SpatialPosition3d = Point3d;

struct Velocity3d : public ThreeDimensionalCartesianCoordinate<Velocity3d, Velocity> {

  // calculate the distance to another point
  Point3d get_change_in_position(Time duration) const;
};

struct Acceleration3d
  : public ThreeDimensionalCartesianCoordinate<Acceleration3d, Acceleration> {

  // calculate the distance to another point
  Velocity3d get_velocity(Time duration) const;
};

struct Size3d {
  Length width;
  Length length;
  Length height;

  Volume get_volume() const;
};

struct Position6d {
  SpatialPosition3d spatial;
  AngularPosition3d angular;
};

struct Velocity6d {
  Velocity3d spatial;
  AngularVelocity3d angular;
};

struct Acceleration6d {
  Acceleration3d spatial;
  AngularAcceleration3d angular;
};

} // namespace units

namespace printer {
class Printer;
Printer &operator<<(Printer &printer, const units::Point3d &a);
Printer &operator<<(Printer &printer, const units::Velocity3d &a);
Printer &operator<<(Printer &printer, const units::Acceleration3d &a);
Printer &operator<<(Printer &printer, const units::Size3d &a);
Printer &operator<<(Printer &printer, const units::Position6d &a);
Printer &operator<<(Printer &printer, const units::Velocity6d &a);
Printer &operator<<(Printer &printer, const units::Acceleration6d &a);
} // namespace printer

#endif // UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP
