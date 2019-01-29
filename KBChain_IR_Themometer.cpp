
#include "KBChain_IR_Themometer.h"

KBChain_IR_Themometer::KBChain_IR_Themometer(uint8_t i2caddr) {
  _addr = i2caddr;
}

boolean KBChain_IR_Themometer::begin(void) {
  Wire.begin();

  
  for (uint8_t i=0; i<0x20; i++) {
    Serial.print(i); Serial.print(" = ");
    Serial.println(read16(i), HEX);
  }
  
  return true;
}

//......................................................................


double KBChain_IR_Themometer::readObjectTempF(void) {
  return (readTemp(IR_Themometer_TOBJ1) * 9 / 5) + 32;
}


double KBChain_IR_Themometer::readAmbientTempF(void) {
  return (readTemp(IR_Themometer_TA) * 9 / 5) + 32;
}

double KBChain_IR_Themometer::readObjectTempC(void) {
  return readTemp(IR_Themometer_TOBJ1);
}


double KBChain_IR_Themometer::readAmbientTempC(void) {
  return readTemp(IR_Themometer_TA);
}

float KBChain_IR_Themometer::readTemp(uint8_t reg) {
  float temp;
  
  temp = read16(reg);
  temp *= .02;
  temp  -= 273.15;
  return temp;
}

/*********************************************************************/

uint16_t KBChain_IR_Themometer::read16(uint8_t a) {
  uint16_t ret;

  Wire.beginTransmission(_addr); // start transmission to device 
  Wire.write(a); // sends register Address to read from
  Wire.endTransmission(false); // end transmission
  
  Wire.requestFrom(_addr, (uint8_t)3);// send data n-bytes read
  ret = Wire.read(); // receive DATA
  ret |= Wire.read() << 8; // receive DATA

  uint8_t pec = Wire.read();

  return ret;
}
