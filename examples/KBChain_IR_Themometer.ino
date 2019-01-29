#include <Wire.h>
#include <KBChain_IR_Themometer.h>

KBChain_IR_Themometer MLX90614 = KBChain_IR_Themometer();

void setup() {
  Wire.begin(4,5);
  Serial.begin(9600); 
 MLX90614.begin();
}

void loop() {
  Serial.print("Ambient = "); 
  Serial.print(MLX90614.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(MLX90614.readObjectTempC()); 
  Serial.println("*C");
  Serial.print("Ambient = "); 
  Serial.print(MLX90614.readAmbientTempF()); 
  Serial.print("*F\tObject = "); 
  Serial.print(MLX90614.readObjectTempF()); 
  Serial.println("*F");

  Serial.println();
  delay(500);
}
