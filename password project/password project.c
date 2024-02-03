
#define F_CPU 800000UL
#include <util/delay.h>
#include "keybad.h"
#include "LCD 8BIT.h"
#define EEPROM_STATUS 0X20
#define EEPROM_LOCATION1 0x01
#define EEPROM_LOCATION2 0X02
#define EEPROM_LOCATION3 0X03
#define EEPROM_LOCATION4 0X04
#define max_tries 3
char arr[4];
unsigned char x =0;
int main(void)
{
	
	unsigned char value=notpassed;
	unsigned char flag=0,counter1;
	unsigned char max=max_tries;
    LCD_SEND_CMD(0x0C);
	keybad_vinit();
	LCD_INIT();
	LCD_MOVE_CURSOR(1,5);
	LCD_SEND_STRING("Welcome");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("Electronic Safe");
	_delay_ms(6000);
	LCD_clear_screen();
	vLed_init('c',1);
	vDIO_SET_BIT_DIR('c',4,1);
	if (EEPROM_READ(EEPROM_STATUS)==notpassed)//Set
	{
			LCD_SEND_STRING("set passward:");
			LCD_MOVE_CURSOR(2,7);
			for(counter1=0;counter1<=3;counter1++)
			{
				do 
				{
				value=keybad_u8read_press();
				}while(value==notpassed);
				LCD_MOVE_CURSOR(2,counter1+7);
				LCD_SEND_CHAR(value);
				_delay_ms(1000);
				LCD_MOVE_CURSOR(2,counter1+7);
				LCD_SEND_CHAR('*');
				_delay_ms(500);
				EEPROM_WRITE(EEPROM_LOCATION1+counter1,value);
			}
			EEPROM_WRITE(EEPROM_STATUS,0x00);			
		}
// 	else if (EEPROM_READ(EEPROM_STATUS)!=notpassed)
// 		{
		while(flag==0)//Check
		{
			arr[0]=arr[1]=arr[2]=arr[3]=notpassed;
			LCD_clear_screen();
			LCD_SEND_STRING("enter pass:");
			LCD_MOVE_CURSOR(2,7);
			for(counter1=0;counter1<=3;counter1++)
			{
		  		do 
				{
				arr[counter1]=keybad_u8read_press();
				}while(arr[counter1]==notpassed);
				LCD_MOVE_CURSOR(2,counter1+7);
				LCD_SEND_CHAR(arr[counter1]);
				_delay_ms(1000);
				LCD_MOVE_CURSOR(2,counter1+7);
				LCD_SEND_CHAR('*');
				_delay_ms(500);
			}			
		if(EEPROM_READ(EEPROM_LOCATION1)==arr[0] && EEPROM_READ(EEPROM_LOCATION2)==arr[1] && EEPROM_READ(EEPROM_LOCATION3)==arr[2] && EEPROM_READ(EEPROM_LOCATION4)==arr[3] )
		{
			LCD_clear_screen();
			LCD_SEND_STRING("password right");
		     vLed_toggle('c',1);
			_delay_ms(500);
			LCD_MOVE_CURSOR(2,3);
			LCD_SEND_STRING("safa open");
			flag=1;
		}
		else
		{
			max=max-1;
			if(max>0)
			{
				LCD_clear_screen();
				LCD_SEND_STRING("wrong password");
				_delay_ms(3000);
				LCD_MOVE_CURSOR(2,2);
				LCD_SEND_STRING("tries left");
				LCD_SEND_CHAR(max+48);
				_delay_ms(3000);
			}
			else
			{
				LCD_clear_screen();
				LCD_SEND_STRING("worng password");
				LCD_MOVE_CURSOR(2,3);
				vDIO_WRITE_BIT('c',4,1);
				LCD_SEND_STRING("wait 30sec");
				_delay_ms(30000);
				max=3;
			}	
			
		 }
		
	  }  
	    
		
	//}		
	//}	
}  			
         
    
