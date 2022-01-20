//
// Created by Tyler Gilbert on 1/19/22.
//

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
