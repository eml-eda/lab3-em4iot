#include <systemc-ams.h>

#include "config.h"


SCA_TDF_MODULE(mic_click_sensor)
{
    sca_tdf::sca_out<double> i;  // Consumed current
    
    SCA_CTOR(mic_click_sensor): i("i"), cnt(0) {}

    void set_attributes();
    void initialize();
    void processing();

    private:
        int cnt;
};
