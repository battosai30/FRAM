// Example of using FRAM library

#include <FRAM.h>
#include <Wire.h>

FRAM fram(0b00); // i2c adress is determined by state of pins A2 and A1
                 // for example, if A2 = VCC and A1 = GND write : FRAM fram(0b10);
              
void setup() {
  
  Serial.begin(9600);
  fram.WriteByte(0,5,55);
  Serial.println(fram.ReadByte(0,5));
  
  fram.WriteInt(0,15,30000);
  Serial.println(fram.ReadInt(0,15));
  
  fram.WriteInt(0,20,-30000);
  Serial.println(fram.ReadInt(0,20));
  
}

void loop() {
  
}


