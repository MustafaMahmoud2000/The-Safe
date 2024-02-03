#include "keybad.h"
void keybad_vinit(void)
{
	vDIO_SET_BIT_DIR(keybad_port,0,1);
	vDIO_SET_BIT_DIR(keybad_port,1,1);
	vDIO_SET_BIT_DIR(keybad_port,2,1);
	vDIO_SET_BIT_DIR(keybad_port,3,1);
	vDIO_SET_BIT_DIR(keybad_port,4,0);
	vDIO_SET_BIT_DIR(keybad_port,5,0);
	vDIO_SET_BIT_DIR(keybad_port,6,0);
	vDIO_SET_BIT_DIR(keybad_port,7,0);
	vDIO_PULLUP_CONNECT(keybad_port,4,1);
	vDIO_PULLUP_CONNECT(keybad_port,5,1);
	vDIO_PULLUP_CONNECT(keybad_port,6,1);
	vDIO_PULLUP_CONNECT(keybad_port,7,1);
}
char keybad_u8read_press()
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char row,colum,val;
	char returnval=notpassed;
	for(row=0;row<4;row++)
	{
		vDIO_WRITE_BIT(keybad_port,0,1);
		vDIO_WRITE_BIT(keybad_port,1,1);
		vDIO_WRITE_BIT(keybad_port,2,1);
		vDIO_WRITE_BIT(keybad_port,3,1);
		vDIO_WRITE_BIT(keybad_port,row,0);
		for(colum=0;colum<4;colum++)
		{
		val=u8DIO_READ_BIT(keybad_port,(colum+4));
		if(val==0)
			{
			returnval=arr[row][colum];
			break;
			}
		}
			if (val==0)
			{
			break;
			}
	}
	return returnval;
}