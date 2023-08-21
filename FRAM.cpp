#include "FRAM.h"

FRAM::FRAM(uint8_t Address) {

Wire.begin();
_i2cAddress= (0b101000 | Address)<<1;

}

FRAM::~FRAM() {

}

void FRAM::WriteByte(uint8_t Page, uint8_t Address, uint8_t Data) {
 
  Wire.beginTransmission(_i2cAddress | (Page&1));
  Wire.write(Address);
  Wire.write(Data);
  Wire.endTransmission(); 
  
}


uint8_t FRAM::ReadByte(uint8_t Page,uint8_t Address) {
 
  ReadBurst(Page,Address, 1);
     
  return Wire.read();
  
}

int16_t FRAM::ReadInt(uint8_t Page, uint8_t Address) {

  ReadBurst(Page,Address, 2);
     
  return int(Wire.read()) | int(Wire.read())<<8;

}

void FRAM::WriteInt(uint8_t Page, uint8_t Address, int16_t Data) {

  uint8_t Data_Array[2]={Data & 0xFF, (Data>>8) & 0xFF};

  WriteBurst(Page, Address, Data_Array, 2);

}

int32_t FRAM::ReadLong(uint8_t Page, uint8_t Address) {

  ReadBurst(Page,Address, 4);
     
  return int32_t(Wire.read()) | int32_t(Wire.read())<<8 | int32_t(Wire.read())<<16 | int32_t(Wire.read())<<24 ;

}

void FRAM::WriteLong(uint8_t Page, uint8_t Address, int32_t Data) {

 uint8_t Data_Array[4]={Data & 0xFF, (Data>>8) & 0xFF, (Data>>16) & 0xFF, (Data>>24) & 0xFF};

 WriteBurst(Page, Address, Data_Array, 4);

}

void FRAM::ReadBurst(uint8_t Page, uint8_t Address, uint16_t NumberOfByte) {

  Wire.beginTransmission(_i2cAddress | (Page&1));
  Wire.write(Address);
  Wire.endTransmission();  
  Wire.requestFrom(_i2cAddress | (Page&1), NumberOfByte);
  
}
 
 void FRAM::WriteBurst(uint8_t Page, uint8_t Address, uint8_t* Data, uint16_t NumberOfByte) {

  Wire.beginTransmission(_i2cAddress | (Page&1));
  Wire.write(Address);
  
  for(int i=0;i<NumberOfByte;i++) {
   Wire.write(Data[i]);
  }
  
  Wire.endTransmission(); 
  
}
