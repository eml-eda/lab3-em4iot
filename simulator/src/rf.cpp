#include "rf.h"


void rf::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void rf::initialize() {}

void rf::processing()
{
    if(cnt >= RF_T_ACT_ON && cnt < RF_T_ACT_ON + RF_ON_T_ON)
    {
        i.write(RF_ON_I_ON);
        cnt = (cnt + 1) % PERIOD;
    }
    else
    {
        i.write(RF_I_IDLE);
        cnt = (cnt + 1) % PERIOD;
    }
}
