#include <systemc-ams.h>

#include "config.h"
#include "config_converter_battery.h"
#include "lut.h"


SCA_TDF_MODULE(converter_battery)
{
    sca_tdf::sca_in<double> i_bus; // Current requested/delivered to battery conv
    sca_tdf::sca_in<double> v_batt; // Battery voltage
    sca_tdf::sca_out<double> i_batt; // Battery current

    SCA_CTOR(converter_battery): i_bus("i_bus"),
                                 v_batt("v_batt"),
                                 i_batt("i_batt") {};

    void set_attributes();
    void initialize();
    void processing();

    private:
        LUT lut_eta = LUT(I_CONV_BATT, ETA_CONV_BATT, SIZE_CONV_BATT);
};
