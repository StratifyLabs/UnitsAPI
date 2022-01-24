
#include <cstdio>

#include <fs.hpp>
#include <printer.hpp>
#include <test/Test.hpp>
#include <var.hpp>

#include "units.hpp"

class UnitTest : public test::Test {
public:
  UnitTest(var::StringView name) : test::Test(name) {}

  bool execute_class_api_case() {
    TEST_ASSERT_RESULT(test_macros());
    TEST_ASSERT_RESULT(test_units());
    TEST_ASSERT_RESULT(test_usage());
    TEST_ASSERT_RESULT(test_code_generation());
    TEST_ASSERT_RESULT(test_compare());
    return true;
  }

  bool test_compare(){
    auto voltage = 3300_mV;
    auto current = 1000_mA;
    auto resistance = voltage / current;
    auto power_va = voltage * current;
    auto power_v2pr = voltage * (voltage / resistance);
    auto power_i2r = current * (current * resistance);
    TEST_ASSERT(power_va == power_v2pr);
    TEST_ASSERT(power_va == power_i2r);
    TEST_ASSERT(power_v2pr == power_i2r);
    TEST_ASSERT(1_V < 2_V);
    TEST_ASSERT(1_V <= 2_V);
    TEST_ASSERT(3_V > 2_V);
    TEST_ASSERT(3_V >= 2_V);

    return true;
  }

  bool test_code_generation(){
    printer().key("sizeOfNativeType", var::NumberString(sizeof(NativeType)));
    printer().key("sizeOfFrequency", var::NumberString(sizeof(Frequency)));
    return true;
  }

  bool test_usage() {

    // convert ADC to a real value
    const auto adc_input = 50_number; //unitless value
    const auto adc_max = Unitless(1024); //or use 1024_number
    const auto voltage_in = 3300_mV * (adc_input / adc_max);
    printer().object("adcInputVoltage", voltage_in);

    // convert voltage to a height using a ratio
    auto voltage_out
      = voltage_in
        * (20_kohms / (100_kohms + 20_kohms));
    printer().object("adcOutputVoltage", voltage_out);

    // calculate a resistance from a voltage
    auto current = (3300_mV - 1200_mV)
                   / 10_kohms;

    auto resistance = 1200_mV / current;
    printer().object("resistance", resistance);

    auto speed = from_feet(12) / 1_s;
    printer().object("speed", speed);

    auto angular_velocity = 3140_mrad / 1_s;
    printer().object("angular_velocity", angular_velocity);

    const auto c = speed_of_light();
    printer().object("c", c);

    //dead reckoning calculations
    const auto step = 0.001;
    auto position = Length(0);
    auto velocity = Velocity(0);
    for(auto time: api::Index(50)){
      velocity += (gravity() * (1_s * Unitless(step)));
      velocity += (gravity() * (Unitless(step) * 1_s));
      velocity += (gravity() * 50_ms);
      position += velocity * 50_ms;
    }


    return true;
  }

  template <class ResultType, class LhsType, class RhsType>
  void multiply(const char *name) {
    ResultType result = LhsType(1.0f) * RhsType(1.0f);
    printer().object(name, result);
  };

  template <class ResultType, class LhsType, class RhsType>
  void divide(const char *name) {
    ResultType result = LhsType(1.0f) / RhsType(1.0f);
    printer().object(name, result);
  };

  template <class ResultType> void add(const char *name) {
    ResultType result = ResultType(1.0f) + ResultType(1.0f);
    result += ResultType(1.0f);
    printer().object(name, result);
  };

  template <class ResultType> void subtract(const char *name) {
    ResultType result = ResultType(1.0f) - ResultType(1.0f);
    result -= ResultType(1.0f);
    printer().object(name, result);
  };

  bool test_units() {
    // this just needs to build -- execution will work
    add<OrthogonalLength>("addOrthogonalLength");
    subtract<OrthogonalLength>("subtractOrthogonalLength");

    add<Length>("addLength");
    subtract<Length>("subtractLength");

    add<Volume>("addVolume");
    subtract<Volume>("subtractVolume");

    multiply<Volume, Area, Length>("volume");
    multiply<Area, Length, Length>("area");
    divide<Frequency, Unitless, Time>("frequency");
    divide<Velocity, Length, Time>("velocity");
    multiply<Force, Mass, Acceleration>("force");
    divide<Pressure, Force, Area>("pressure");
    multiply<Energy, Force, Length>("energy");
    divide<Power, Energy, Time>("energy");
    multiply<ElectricCharge, ElectricCurrent, Time>("electricCharge");
    divide<ElectricPotential, Power, ElectricCurrent>("voltage");
    divide<ElectricResistance, ElectricPotential, ElectricCurrent>(
      "electricResistance");
    divide<ElectricConductance, ElectricCurrent, ElectricPotential>(
      "electricConductance");
    divide<MagneticFluxDensity, MagneticFlux, Area>("magneticFluxDensity");
    divide<Inductance, MagneticFlux, ElectricCurrent>("inductance");
    multiply<LuminousFlux, LuminousIntensity, SolidAngle>("luminousFlux");
    divide<Illuminance, LuminousIntensity, Area>("illuminance");
    multiply<DynamicViscosity, Pressure, Time>("dynamicViscosity");
    multiply<MomentOfForce, Force, OrthogonalLength>("momentOfForce");
    divide<AngularVelocity, PlaneAngle, Time>("angularVelocity");
    divide<AngularAcceleration, AngularVelocity, Time>("angularAcceleration");

    return true;
  }

  bool test_macros() {
    {
      // tests  DEFINE_DIVIDE
      Printer::Object(printer(), "frequency");
      auto frequency = Unitless(1.0f) / Time(2.0f);
      printer().object("frequency", frequency);
      printer().key("frequencyString", frequency.to_string());
      TEST_ASSERT(frequency.to_string() == "0.500Hz");

      auto time = Unitless(1.0f) / frequency;
      printer().object("time", time);
      printer().key("timeString", time.to_string());
      TEST_ASSERT(time.to_string() == "2.000s");

      auto revolutions = frequency * time;
      printer().object("revolutions", revolutions);
      printer().key("revolutionsString", revolutions.to_string());
      TEST_ASSERT(revolutions.to_string() == "1.000");
    }

    {
      // tests DEFINE_MULTIPLY
      Printer::Object(printer(), "volume");
      auto volume = Area(1.0f) * Length(2.0f);
      printer().object("volume", volume);
      printer().key("volumeString", volume.to_string());
      TEST_ASSERT(volume.to_string() == "2.000m^3");

      auto length = volume / Area(1.0f);
      printer().object("length", length);
      printer().key("lengthString", length.to_string());
      TEST_ASSERT(length.to_string() == "2.000m");

      auto area = volume / Length(2.0f);
      printer().object("area", area);
      printer().key("areaString", area.to_string());
      TEST_ASSERT(area.to_string() == "1.000m^2");
    }

    {
      // tests DEFINE_MULTIPLY_SAME
      Printer::Object(printer(), "area");
      auto area = Length(1.0f) * Length(2.0f);
      printer().object("area", area);
      printer().key("areaString", area.to_string());
      TEST_ASSERT(area.to_string() == "2.000m^2");

      auto length = area / Length(2.0f);
      printer().object("length", length);
      printer().key("lengthString", length.to_string());
      TEST_ASSERT(length.to_string() == "1.000m");
    }

    return true;
  }
};
