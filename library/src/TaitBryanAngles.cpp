//
// Created by Tyler Gilbert on 1/19/22.
//

#include <printer/Printer.hpp>

#include "units/TaitBryanAngles.hpp"

printer::Printer &
printer::operator<<(Printer &printer, const units::AngularPosition3d &a) {
  return printer.key("phi", a.phi.to_string())
    .key("theta", a.theta.to_string())
    .key("psi", a.psi.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::AngularVelocity3d &a) {
  return printer.key("phi", a.phi.to_string())
    .key("theta", a.theta.to_string())
    .key("psi", a.psi.to_string());
}

printer::Printer &
printer::operator<<(Printer &printer, const units::AngularAcceleration3d &a) {
  return printer.key("phi", a.phi.to_string())
    .key("theta", a.theta.to_string())
    .key("psi", a.psi.to_string());
}




