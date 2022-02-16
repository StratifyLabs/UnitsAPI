//
// Created by Tyler Gilbert on 1/19/22.
//
#include <cmath>

#include <printer/Printer.hpp>

#include "units/CartesianCoordinates.hpp"

printer::Printer &
printer::operator<<(Printer &printer, const units::Point3d &a) {
  return printer.key("x", a.x.to_string())
    .key("y", a.y.to_string())
    .key("z", a.z.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Velocity3d &a) {
  return printer.key("x", a.x.to_string())
    .key("y", a.y.to_string())
    .key("z", a.z.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Acceleration3d &a) {
  return printer.key("x", a.x.to_string())
    .key("y", a.y.to_string())
    .key("z", a.z.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Size3d &a) {
  return printer.key("width", a.width.to_string())
    .key("length", a.length.to_string())
    .key("height", a.height.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Position6d &a) {
  return printer.object("spatial", a.spatial).object("angular", a.angular);
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Velocity6d &a) {
  return printer.object("spatial", a.spatial).object("angular", a.angular);
}

printer::Printer &
printer::operator<<(Printer &printer, const units::Acceleration6d &a) {
  return printer.object("spatial", a.spatial).object("angular", a.angular);
}

units::Length units::Point3d::get_distance(const units::Point3d &a) const {
  const auto x_diff = (x - a.x).value();
  const auto y_diff = (y - a.y).value();
  const auto z_diff = (z - a.z).value();
  return Length(
    UNITS_SQRT(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff));
}

units::Point3d
units::Velocity3d::get_change_in_position(units::Time duration) const {
  return {x * duration, y * duration, z * duration};
}

units::Velocity units::Velocity3d::get_speed() const {
  return units::Velocity(UNITS_SQRT(
    x.value() * x.value() + y.value() * y.value() + z.value() * z.value()));
}

units::Velocity3d
units::Acceleration3d::get_velocity(units::Time duration) const {
  return {x * duration, y * duration, z * duration};
}

units::Volume units::Size3d::get_volume() const {
  return width * length * height;
}
