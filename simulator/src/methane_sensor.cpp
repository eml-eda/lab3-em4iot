#include "methane_sensor.h"


void methane_sensor::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void methane_sensor::initialize() {}

void methane_sensor::processing()
{
    if(cnt >= METHANE_SENSOR_T_ACT &&
       cnt < METHANE_SENSOR_T_ACT + METHANE_SENSOR_T_ON)
    {
        i.write(METHANE_SENSOR_I_ON);
        cnt = (cnt + 1) % PERIOD;
    }
    else
    {
        i.write(METHANE_SENSOR_I_IDLE);
        cnt = (cnt + 1) % PERIOD;
    }
}
