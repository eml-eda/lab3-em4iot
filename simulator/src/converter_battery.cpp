#include <math.h>
#include "converter_battery.h"


void converter_battery::set_attributes()
{
    i_batt.set_timestep(SIM_STEP, sc_core::SC_SEC);
    i_batt.set_delay(1);
}

void converter_battery::initialize() {}

void converter_battery::processing()
{
    double eta; // Efficiency
    double i_bus_tmp;
    double v_batt_tmp;

    // Read input quantities
    i_bus_tmp = i_bus.read();
    v_batt_tmp = v_batt.read();
    
    // Avoid div by zero
    if (v_batt_tmp == 0)
    {
        v_batt_tmp = 3.6;
    }

    // Get efficiency
    // Absolute value is needed cause current might be negative due to pv
    eta = lut_eta.get_val(fabs(i_bus_tmp)) / 100;
    
    i_batt.write(i_bus_tmp * VREF_BUS / (eta * v_batt_tmp));
}
