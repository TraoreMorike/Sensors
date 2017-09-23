#ifndef Si7021_h
#define Si7021_h

#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#define SI7021_Addr 0x40

#define RESET                                  0xFE
#define HTRE                                   0x04
#define MEASURE_RH_HOLD_MASTER                 0xE5
#define MEASURE_RH_NO_HOLD_MASTER              0xF5
#define MEASURE_TEMPERATURE_HOLD_MASTER        0xE3
#define MEASURE_TEMPERATURE_NO_HOLD_MASTER     0xF3
#define MEASURE_TEMPERATURE_PREVIOUS_RH        0xE0
#define WRITE_RHT_USER_REGISTER                0xE6
#define READ_RHT_USER_REGISTER                 0xE7
#define WRITE_HEATER_CONTROL_REGISTER          0x51
#define READ_HEATER_CONTROL_REGISTER           0x11



class SI7021 {
	public:
		void SI7021_WRITE_REG(byte reg, byte value);
		float SI7021_READ_RH(unsigned char rhSetting);
		float SI7021_READ_TEMPERATURE(unsigned char tempSetting);
};


	