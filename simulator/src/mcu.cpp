#include "mcu.h"


void mcu::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void mcu::initialize() {}

void mcu::processing()
{
    if(cnt >= MCU_T_ACT && cnt < MCU_T_ACT + MCU_ON_T_ON)
        {
            i.write(MCU_ON_I_ON);
            cnt = (cnt + 1) % PERIOD;
        }
        else
        {
            i.write(MCU_I_IDLE);
            cnt = (cnt + 1) % PERIOD;
        }
}
