#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

//.................................................................
#define IR_Themometer_I2CADDR 0x5A           // Slave address 
#define IR_Themometer_RAWIR1 0x04            // Raw data IR channel 1
#define IR_Themometer_RAWIR2 0x05            // Raw data IR channel 2
#define IR_Themometer_TA 0x06
#define IR_Themometer_TOBJ1 0x07
#define IR_Themometer_TOBJ2 0x08
#define IR_Themometer_TOMAX 0x20
#define IR_Themometer_TOMIN 0x21
#define IR_Themometer_PWMCTRL 0x22
#define IR_Themometer_TARANGE 0x23
#define IR_Themometer_EMISS 0x24
#define IR_Themometer_CONFIG 0x25
#define IR_Themometer_ADDR 0x0E
#define IR_Themometer_ID1 0x3C
#define IR_Themometer_ID2 0x3D
#define IR_Themometer_ID3 0x3E
#define IR_Themometer_ID4 0x3F


class KBChain_IR_Themometer  {
 public:
  KBChain_IR_Themometer(uint8_t addr = IR_Themometer_I2CADDR);
  boolean begin();
  uint32_t readID(void);

  double readObjectTempC(void);
  double readAmbientTempC(void);
  double readObjectTempF(void);
  double readAmbientTempF(void);

 private:
  float readTemp(uint8_t reg);

  uint8_t _addr;
  uint16_t read16(uint8_t addr);
  void write16(uint8_t addr, uint16_t data);
};

