#include "bus.h"


void bus::set_attributes() {}

void bus::initialize() {}

void bus::processing()
{
    // Compute total current consumption
    double tot_consumed = i_mcu.read() + i_rf.read()
                          + i_air_quality_sensor.read()
                          + i_methane_sensor.read()
                          + i_temperature_sensor.read()
                          + i_mic_click_sensor.read()
                          ;

    double tot_scavenged = real_i_pv.read();

    double tot_requested = tot_consumed - tot_scavenged;

    i_tot.write(tot_requested); // tot_requested >= 0 ? pow_from_battery : pow_to_battery
}
