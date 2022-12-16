// generic simulation settings
#define SIM_STEP 1
#define SIM_LEN 7736400
#define PERIOD 120
#define VREF_BUS 3.3
#define SOC_INIT 1.0
#define SELFDISCH_FACTOR 0.0

// params for sensor air_quality_sensor
#define AIR_QUALITY_SENSOR_I_ON 48.2
#define AIR_QUALITY_SENSOR_T_ON 30
#define AIR_QUALITY_SENSOR_I_IDLE 0.002
#define AIR_QUALITY_SENSOR_T_ACT 0
// params for sensor methane_sensor
#define METHANE_SENSOR_I_ON 18
#define METHANE_SENSOR_T_ON 30
#define METHANE_SENSOR_I_IDLE 0.002
#define METHANE_SENSOR_T_ACT 0
// params for sensor temperature_sensor
#define TEMPERATURE_SENSOR_I_ON 0.3
#define TEMPERATURE_SENSOR_T_ON 6
#define TEMPERATURE_SENSOR_I_IDLE 0.002
#define TEMPERATURE_SENSOR_T_ACT 0
// params for sensor mic_click_sensor
#define MIC_CLICK_SENSOR_I_ON 0.15
#define MIC_CLICK_SENSOR_T_ON 12
#define MIC_CLICK_SENSOR_I_IDLE 0.002
#define MIC_CLICK_SENSOR_T_ACT 0

// params for MCU
#define MCU_I_IDLE 0.002
#define MCU_T_ACT 31
#define MCU_ON_I_ON 13
#define MCU_ON_T_ON 6

// params from MCU for RF
#define RF_T_ACT_ON 38

// params for RF
#define RF_ON_I_ON 0.1
#define RF_ON_T_ON 24
#define RF_I_IDLE 0.001
