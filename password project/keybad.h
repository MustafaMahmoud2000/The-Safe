/*
 * keybad.h
 *
 * Created: 11/3/2023 11:26:27 AM
 *  Author: DELL
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#include "DIO.h"
#define keybad_port 'D'
#define notpassed 0xFF
void keybad_vinit(void);
char keybad_u8read_press();




#endif /* KEYBAD_H_ */