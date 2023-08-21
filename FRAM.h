/* 

This library is designed to drive FRAM memories model FM24C04B

Author : B@tto battomicro.wordpress.com

Compatible with Arduino and Energia

V1.1

 */


#ifndef FRAM_H
#define FRAM_H

#ifdef ARDUINO // Arduino
#if ARDUINO >= 100
#include <Arduino.h> // Arduino 1.0
#else
#include <WProgram.h> // Arduino 0022
#endif
#endif
 
#ifdef ENERGIA // Energia
#include <Energia.h>
#endif

#include <Wire.h>

class FRAM
{
	private:
	
	uint8_t _i2cAddress;    
	void ReadBurst(uint8_t Page, uint8_t Address, uint16_t NumberOfByte);
	void WriteBurst(uint8_t Page, uint8_t Address, uint8_t* Data, uint16_t NumberOfByte);
	
	public:
	
	FRAM(byte Adress);
	~FRAM();
	
	void WriteLong(uint8_t Page, uint8_t Address, int32_t Data); 
	int32_t ReadLong(uint8_t Page, uint8_t Address);
	void WriteInt(uint8_t Page,uint8_t Address, int16_t Data); 
	int16_t ReadInt(uint8_t Page,uint8_t Address);
	void WriteByte(uint8_t Page,uint8_t Address, uint8_t Data);
	uint8_t ReadByte(uint8_t Page,uint8_t Address);
};

#endif
