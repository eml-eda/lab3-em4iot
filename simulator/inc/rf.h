#include <systemc-ams.h>

#include "config.h"


SCA_TDF_MODULE(rf)
{
    sca_tdf::sca_out<double> i; // Requested current

    SCA_CTOR(rf): i("i"),
                  cnt(0) {}

    void set_attributes();
    void initialize();
    void processing();
    
    private:
        int cnt;
};
