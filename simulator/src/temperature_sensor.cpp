#include "temperature_sensor.h"


void temperature_sensor::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void temperature_sensor::initialize() {}

void temperature_sensor::processing()
{
    if(cnt >= TEMPERATURE_SENSOR_T_ACT &&
       cnt < TEMPERATURE_SENSOR_T_ACT + TEMPERATURE_SENSOR_T_ON)
    {
        i.write(TEMPERATURE_SENSOR_I_ON);
        cnt = (cnt + 1) % PERIOD;
    }
    else
    {
        i.write(TEMPERATURE_SENSOR_I_IDLE);
        cnt = (cnt + 1) % PERIOD;
    }
}
