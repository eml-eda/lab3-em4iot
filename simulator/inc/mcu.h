#include <systemc-ams.h>

#include "config.h"


SCA_TDF_MODULE(mcu)
{
    sca_tdf::sca_out<double> i; // Consumed current

    SCA_CTOR(mcu): i("i"),
                   cnt(0) {}

    void set_attributes();
    void initialize();
    void processing();

    private:
        int cnt;
};
