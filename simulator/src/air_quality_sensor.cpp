#include "air_quality_sensor.h"


void air_quality_sensor::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void air_quality_sensor::initialize() {}

void air_quality_sensor::processing()
{
    if(cnt >= AIR_QUALITY_SENSOR_T_ACT &&
       cnt < AIR_QUALITY_SENSOR_T_ACT + AIR_QUALITY_SENSOR_T_ON)
    {
        i.write(AIR_QUALITY_SENSOR_I_ON);
        cnt = (cnt + 1) % PERIOD;
    }
    else
    {
        i.write(AIR_QUALITY_SENSOR_I_IDLE);
        cnt = (cnt + 1) % PERIOD;
    }
}
