#include <systemc-ams.h>

#include "config.h"


SCA_TDF_MODULE(air_quality_sensor)
{
    sca_tdf::sca_out<double> i;  // Consumed current
    
    SCA_CTOR(air_quality_sensor): i("i"), cnt(0) {}

    void set_attributes();
    void initialize();
    void processing();

    private:
        int cnt;
};
