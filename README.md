# UnitsAPI

UnitsAPI is a library to using SI units in modern C++ programs.

Here are a few examples:

```cpp
#include <units/SI.hpp>

using namespace units;
//convert ADC value to a voltage
const auto adc_input = Unitless(adc().read());
const auto adc_max = Unitless(4095); //12-bit value
const auto voltage_input = 3300_mV * (adc_input / adc_max);

//now convert the voltage through a voltage divider
const auto voltage_output = voltage_input * ((10_kohms + 20_kohms) / (10_kohms));

//now use a user defined ratio to convert the voltage
//to temperature assuming the voltage is connected to a temperature sensor
const auto temperature = voltage_output.convert<Temperature>(0.010f); //0.010 V per degree Celcius
```

```cpp

//calculate speed from distance and time
const auto velocity = 10_cm / 523_ms;

//wavelength calculations
const auto wavelength = speed_of_light() * 323_ns;

```