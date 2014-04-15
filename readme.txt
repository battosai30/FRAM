FRAM Library for Arduino and Energia
Author:  B@tto
Contact: batto@hotmail.fr
website: battomicro.wordpress.com 

Current version
1.0

History
1.0 15/04/2014 initial release 

Description
This library is designed to use FM24C04B 4Kb Serial 5V F-RAM Memory.

Memory is organised in two pages, each page have 512 byte blocks of memory. So, a record is defined by his page and his adress in the page.

Download zip 
Put the FRAM folder in "hardware\libraries\". 
In the Arduino IDE, create a new sketch (or open one) and 
select from the menubar "Sketch->Import Library->FRAM".
Once the library is imported, an "#incude <FRAM.h>" line will appear at the top of your sketch. 
You have to add manually "#include <Wire.h>".

Creation
 FRAM(int address) -> Create instance of MCP3424.Address is A2A1 (refer to datasheet). For example, if pins A2 and A1 are high, the instanciation would be "MCP3424 MCP(3)" because A2=1 A1=1 so in binary 11 and 3 in decimal.
 
Methods
	
The available methods do how they are named. 

void WriteLong(byte Page, byte Address, long Data); ==> write a long at page Page and address Adress. Takes 4 bytes
long ReadLong(byte Page,byte Address); ==> return the long stored at page Page and address Adress
void WriteInt(byte Page,byte Address, int Data); ==> same WriteLong but for int. Takes 2 bytes
int ReadInt(byte Page,byte Address); ==> same as ReadLong but for int
void WriteByte(byte Page,byte Address,byte Data); ==> same WriteLong but for byte. Takes 1 bytes
byte ReadByte(byte Page,byte Address);==> same as ReadLong but for byte

Example
FRAM_EXAMPLE -> simple write / serial read back

Cautions

- Take care of the supply voltage : the range is 4,5V - 5,5V. If you apply 4V it won't work (which can happen easily is you use USB supply).
- The library doesn't take account of what have been written. That means if for example you write a long at page=0 address=20 and after you write an integer at page=0 and address=22, your long is corrupted because you overwrited its last two bytes 