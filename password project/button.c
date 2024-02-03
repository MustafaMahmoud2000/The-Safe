#include "DIO.h" 
 
 void vButton_init(unsigned char port,unsigned char pin)
{
	vDIO_SET_BIT_DIR(port,pin,0);
	
}
unsigned char u8Button_read(unsigned char port,unsigned char pin)
{
	
	return u8DIO_READ_BIT(port,pin);
}



