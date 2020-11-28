/*
 * DC_Motor.c
 *
 * Created: 10/29/2020 9:27:46 PM
 *  Author: Mirette
 */ 

#include "DC_Motor.h"

void DC_Motor_Init()
{
	DDRC |= (1<<5)|(1<<6);
	DDRD |= (1<<5);
	OCR1A = 200;
	TCCR1A =  (1<<WGM10) | (1<<COM1A1);
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10);
}

void DC_Motor_Direction(unsigned char Dir)
{
	switch(Dir)
	{
		case 'F':
		PORTC |= (1<<5);
		PORTC &=~ (1<<6);
		break;
		case 'B':
		PORTC |= (1<<6);
		PORTC &=~ (1<<5);
		break;
	}
}