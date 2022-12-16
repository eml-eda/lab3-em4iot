#include <systemc-ams.h>

#include "config.h"


SCA_TDF_MODULE(bus)
{
    sca_tdf::sca_in<double> i_mcu; // Requested current from MCU
    sca_tdf::sca_in<double> i_rf; // Requested current from RF module
    sca_tdf::sca_in<double> i_air_quality_sensor; // Requested current from air_quality_sensor
    sca_tdf::sca_in<double> i_methane_sensor; // Requested current from methane_sensor
    sca_tdf::sca_in<double> i_temperature_sensor; // Requested current from temperature_sensor
    sca_tdf::sca_in<double> i_mic_click_sensor; // Requested current from mic_click_sensor
    sca_tdf::sca_in<double> real_i_pv; // Provided current from pv panel after conversion

    sca_tdf::sca_out<double> i_tot;

    SCA_CTOR(bus): i_tot("i_tot"),
                   i_mcu("i_mcu"),
                   i_rf("i_rf"),
                   i_air_quality_sensor("i_air_quality_sensor"),
                   i_methane_sensor("i_methane_sensor"),
                   i_temperature_sensor("i_temperature_sensor"),
                   i_mic_click_sensor("i_mic_click_sensor"),
                   real_i_pv("real_i_pv") {};

    void set_attributes();
    void initialize();
    void processing();
};