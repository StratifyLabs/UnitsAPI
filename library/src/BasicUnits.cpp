//
// Created by Tyler Gilbert on 1/18/22.
//

#include <printer/Printer.hpp>

#include "units/BasicUnits.hpp"

namespace printer {
class Printer;
Printer &operator<<(Printer &printer, const units::BasicUnit &basic_unit) {
  return printer.key("unit", basic_unit.unit())
    .key("symbol", basic_unit.symbol())
    .key("value", var::NumberString(basic_unit.value()));
}
} // namespace printer

namespace units {

var::NumberString BasicUnit::to_string(const char *fmt) const {
  return var::NumberString(value(), fmt).append(symbol());
}

Length from_feet(NativeType value) {
  return Length(value * UNITS_NATIVE_SUFFIX(0.3048));
}

Length from_miles(NativeType value) {
  return from_feet(value * 5280);
}

Length from_inches(NativeType value) {
  return Length(value * UNITS_NATIVE_SUFFIX(0.0254));
}

Length from_mils(NativeType value) {
  return from_inches(value / 1000);
}

} // namespace units
