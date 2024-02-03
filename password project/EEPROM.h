/*
 * EEPROM.h
 *
 * Created: 10/21/2023 4:05:15 PM
 *  Author: DELL
 */ 

#include "LCD_config.h"
#ifndef EEPROM_H_
#define EEPROM_H_
void EEPROM_WRITE(unsigned short address,unsigned char data);
unsigned char EEPROM_READ( unsigned short address);
void eeprom_readblock_from_address(const uint16 address2,uint8* data1,const uint16 size);
void eeprom_writebyte_to_address(const uint16 address2,const uint8 data2);
void eeprom_writeblock_from_address(const uint16 address2,const uint8* data2,const uint16 size);





#endif /* EEPROM_H_ */