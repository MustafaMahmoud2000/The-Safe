#include <avr/io.h>
#include "EEPROM.h"
#include "std_macros.h"
#include "LCD_config.h"
void EEPROM_WRITE(unsigned short address,unsigned char data)
{
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
unsigned char EEPROM_READ( unsigned short address)
{
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	SET_BIT(EECR,EERE);
	return EEDR;
}
	
void eeprom_readblock_from_address(const uint16 address2,uint8* data1,const uint16 size)
{
	while(((EECR & (1<< EERE)) >>EEWE)==1);
	uint16 counter=0;
	while(counter<size)
	{
		EEAR=address2+counter;
		EECR|=(1<<EERE);
		*(data1+counter)=EEDR;
		counter++;
	}
}
void eeprom_writebyte_to_address(const uint16 address2,const uint8 data2)
{
	while(((EECR & (1<< EERE)) >>EEWE)==1);
	EEAR=address2;
	EECR|=(1<<EERE);
	if (EEDR !=data2)
	{
		EEDR=data2;
		EECR|=(1<<EEMWE);
		EECR|=(1<<EEWE);
	}
}
void eeprom_writeblock_from_address(const uint16 address2,const uint8* data2,const uint16 size)
{
	uint16 counter=0;
	
	while(counter < size)
	{
		while(((EECR & (1<< EERE)) >>EEWE)==1);
		EEAR=address2+counter;
		EECR|=(1<<EERE);
		if (EEDR != (*(data2+counter)))
		{
			EEDR=*(data2+counter);
			EECR|=(1<<EEMWE);
			EECR|=(1<<EEWE);
		}
		else
		{
			
		}
		counter++;
	}
}






























