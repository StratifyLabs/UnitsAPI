//
// Created by Tyler Gilbert on 1/19/22.
//

#ifndef UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP
#define UNITSAPI_UNITS_CARTESIAN_COORDINATES_HPP

#include "TaitBryanAngles.hpp"

namespace units {

template <class Type> class ThreeDimensionalPolarCoordinate {
public:
  Type r;
  Type phi;
  Type theta;
};

using PolarPoint3d = ThreeDimensionalPolarCoordinate<Length>;
using PolarVelocity3d = ThreeDimensionalPolarCoordinate<Velocity>;
using PolarAcceleration3d = ThreeDimensionalPolarCoordinate<Acceleration>;

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

  ThreeDimensionalPolarCoordinate<Type> get_polar_coordinate() const {
    return {
      .r = UNITS_SQRT(x * x + y * y + z * z),
      .phi = UNITS_NATIVE_SUFFIX(0.0),
      .theta = UNITS_NATIVE_SUFFIX(0.0)};
  }
};

struct Point3d : public ThreeDimensionalCartesianCoordinate<Point3d, Length> {

  // calculate the distance to another point
  Length get_distance(const Point3d &a) const;
};

using SpatialPosition3d = Point3d;

struct Velocity3d
  : public ThreeDimensionalCartesianCoordinate<Velocity3d, Velocity> {

  Velocity get_speed() const;
  float get_magnitude() const;

  // calculate the distance to another point
  Point3d get_change_in_position(Time duration) const;

  Point3d operator*(Time duration) const {
    return get_change_in_position(duration);
  }
};

struct Acceleration3d
  : public ThreeDimensionalCartesianCoordinate<Acceleration3d, Acceleration> {

  // calculate the distance to another point
  Velocity3d get_velocity(Time duration) const;

  Velocity3d operator*(Time duration) const { return get_velocity(duration); }
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

  Position6d operator+(const Position6d &a) const {
    return {.spatial = spatial + a.spatial, .angular = angular + a.angular};
  }
};

struct Velocity6d {
  Velocity3d spatial;
  AngularVelocity3d angular;

  Velocity6d operator+(const Velocity6d &a) const {
    return {.spatial = spatial + a.spatial, .angular = angular + a.angular};
  }

  Position6d operator*(Time duration) const {
    return {.spatial = spatial * duration, .angular = angular * duration};
  }
};

struct Acceleration6d {
  Acceleration3d spatial;
  AngularAcceleration3d angular;

  Acceleration6d operator+(const Acceleration6d &a) const {
    return {.spatial = spatial + a.spatial, .angular = angular + a.angular};
  }

  Velocity6d operator*(Time duration) const {
    return {.spatial = spatial * duration, .angular = angular * duration};
  }
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
