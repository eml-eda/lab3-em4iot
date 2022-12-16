#include "mic_click_sensor.h"


void mic_click_sensor::set_attributes()
{
    i.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void mic_click_sensor::initialize() {}

void mic_click_sensor::processing()
{
    if(cnt >= MIC_CLICK_SENSOR_T_ACT &&
       cnt < MIC_CLICK_SENSOR_T_ACT + MIC_CLICK_SENSOR_T_ON)
    {
        i.write(MIC_CLICK_SENSOR_I_ON);
        cnt = (cnt + 1) % PERIOD;
    }
    else
    {
        i.write(MIC_CLICK_SENSOR_I_IDLE);
        cnt = (cnt + 1) % PERIOD;
    }
}
