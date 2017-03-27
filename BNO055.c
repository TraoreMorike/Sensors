#include <Wire.h>

// Registers definition
#define 	BNO_055_ADR		0x28
#define 	BNO_055_ADR_		0x29

#define 	OPR_MODE		0x3D
#define		PWR_MODE		0x3E
#define		NDOF			0x12

#define		EUL_PITCH_MSB		0x1F
#define 	EUL_PITCH_LSB		0x1E

#define		EUL_ROLL_MSB		0x1D
#define 	EUL_ROLL_LSB		0x1C

#define 	EUL_HEADING_MSB		0x1B
#define 	EUL_HEADING_LSB		0x1A

uint16_t	rollEulAngle;
uint8_t		rollEulLsb;
uint8_t		rollEulMsb;


void setup() {
	Wire.begin();
	Serial.begin(9600);
	
	Serial.println("BNO 055 I2C Test.."); 
	
	// Initializing BNO 055 - Fusion Mode - Normal Power Mode
	bnoInit(); 	
	
	
}


void loop() {
	getRoll(&rollEulMsb, &rollEulLsb);
	rollEulAngle = (rollEulMsb << 8) | rollEulLsb;

	Serial.print("ROLL :"); Serial.println(rollEulAngle);
	
}


void	bnoInit(void) {
	Wire.beginTransmission(BNO_055_ADR);
	// Alternative adress
	//Wire.beginTransmission(BNO_055_ADR_);
	
	Wire.write(OPR_MODE);
	Wire.write(NDOF);
	
	delay(7);
	
	Wire.write(PWR_MODE);
	Wire.write(0x00);
	
	Wire.endTransmission(); 
	
	
	
}
// Get roll euler angle
void	bnoGetRoll(uint8_t *msb, uint8_t *lsb) {
	Wire.beginTransmission(BNO_055_ADR);
	
	Wire.write(EUL_PITCH_MSB);
	
	Wire.requestFrom(BNO_055_ADR, 2);
	
	*msb = Wire.read();
	*lsb = Wire.read();
	
	Wire.endTransmission();
	
}
