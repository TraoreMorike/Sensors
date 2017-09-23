#include "Arduino.h"
#include "Wire.h"
#include "Si7021.h"




void SI7021::SI7021_WRITE_REG(byte reg, byte value) {
  Wire.beginTransmission(SI7021_Addr);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
  }
  
float SI7021::SI7021_READ_RH(unsigned char rhSetting) {
  int rhlsb, rhmsb; 
  unsigned int rh_code;
  double rh; 
  
  Wire.beginTransmission(SI7021_Addr);
  Wire.write(rhSetting);
  Wire.endTransmission();
  Wire.requestFrom(SI7021_Addr, 2);
  if (Wire.available()<=2) {
  rhmsb = Wire.read(); 
  rhlsb = Wire.read();
  }
  Wire.endTransmission();
  
  rh_code = (rhmsb << 8) | rhlsb;
  return rh = ((125.0 * rh_code) / 65536) - 6;
  }
  
float SI7021::SI7021_READ_TEMPERATURE(unsigned char tempSetting) {
  int templsb, tempmsb, temp_code;
  double temp;
  
  Wire.beginTransmission(SI7021_Addr);
  Wire.write(tempSetting);
  Wire.endTransmission();
  
  Wire.requestFrom(SI7021_Addr, 2);
  if (Wire.available()<=2) {
  tempmsb = Wire.read(); 
  templsb = Wire.read();
  }
  Wire.endTransmission();
  temp_code = (tempmsb << 8) | templsb;
  
  return temp = ((175.72 * temp_code) /  65536) - 46.85;
  }
