#include <systemc-ams.h>

#include "battery.h"
#include "bus.h"
#include "converter_battery.h"
#include "converter_pv.h"
#include "mcu.h"
#include "pv_panel.h"
#include "rf.h"
#include "air_quality_sensor.h"
#include "methane_sensor.h"
#include "temperature_sensor.h"
#include "mic_click_sensor.h"


int sc_main(int argc, char* argv[])
{
    // Instantiate signals
    sca_tdf::sca_signal<double> i_batt, v_batt, soc;
    sca_tdf::sca_signal<double> i_air_quality_sensor; 
    sca_tdf::sca_signal<double> i_methane_sensor; 
    sca_tdf::sca_signal<double> i_temperature_sensor; 
    sca_tdf::sca_signal<double> i_mic_click_sensor; 
    sca_tdf::sca_signal<double> i_mcu;
    sca_tdf::sca_signal<double> i_rf;
    sca_tdf::sca_signal<double> v_pv, i_pv, real_i_pv;
    sca_tdf::sca_signal<double> i_tot;

    // Instantiate modules
    bus bus("bus");
    battery battery("battery");
    converter_battery converter_battery("converter_battery");
    pv_panel pv_panel("pv_panel");
    converter_pv conv_pv("converter_pv");
    mcu mcu("mcu");
    rf rf("rf");
    air_quality_sensor air_quality_sensor("air_quality_sensor");
    methane_sensor methane_sensor("methane_sensor");
    temperature_sensor temperature_sensor("temperature_sensor");
    mic_click_sensor mic_click_sensor("mic_click_sensor");
    
    // Connect signals to modules
    battery.i_batt(i_batt);
    battery.v_batt(v_batt);
    battery.soc(soc);

    converter_battery.i_bus(i_tot);
    converter_battery.v_batt(v_batt);
    converter_battery.i_batt(i_batt);
    
    pv_panel.i(i_pv);
    pv_panel.v(v_pv);
    
    conv_pv.i_in(i_pv);
    conv_pv.v_in(v_pv);
    conv_pv.i_out(real_i_pv);
    
    air_quality_sensor.i(i_air_quality_sensor);
    methane_sensor.i(i_methane_sensor);
    temperature_sensor.i(i_temperature_sensor);
    mic_click_sensor.i(i_mic_click_sensor);
    
    mcu.i(i_mcu);
    
    rf.i(i_rf);

    bus.i_mcu(i_mcu);
    bus.i_rf(i_rf);
    bus.real_i_pv(real_i_pv);
    bus.i_tot(i_tot);
    bus.i_air_quality_sensor(i_air_quality_sensor);
    bus.i_methane_sensor(i_methane_sensor);
    bus.i_temperature_sensor(i_temperature_sensor);
    bus.i_mic_click_sensor(i_mic_click_sensor);
    
    // define simulation file
    sca_util::sca_trace_file* atf = sca_util::sca_create_tabular_trace_file("sim_trace.txt");

    // the following signals will be traced. Comment any signal you don't want to trace    
    sca_util::sca_trace(atf, soc, "soc" );
    sca_util::sca_trace(atf, i_tot, "i_tot" );
    sca_util::sca_trace(atf, i_mcu, "i_mcu" );
    sca_util::sca_trace(atf, i_rf, "i_rf" );
    sca_util::sca_trace(atf, i_pv, "i_pv" );
    sca_util::sca_trace(atf, v_pv, "v_pv" );
    sca_util::sca_trace(atf, real_i_pv, "real_i_pv" );
    sca_util::sca_trace(atf, i_batt, "i_batt" );
    sca_util::sca_trace(atf, v_batt, "v_batt" );
    sca_util::sca_trace(atf, i_air_quality_sensor, "i_air_quality_sensor" );
    sca_util::sca_trace(atf, i_methane_sensor, "i_methane_sensor" );
    sca_util::sca_trace(atf, i_temperature_sensor, "i_temperature_sensor" );
    sca_util::sca_trace(atf, i_mic_click_sensor, "i_mic_click_sensor" );
    cout<<"The simulation starts!"<<endl;

    sc_start(SIM_LEN, sc_core::SC_SEC); // Set the simulation length

    cout<<"The simulation ends @ "<<sc_time_stamp()<<endl;

    sca_util::sca_close_tabular_trace_file(atf);

    return 0;
}