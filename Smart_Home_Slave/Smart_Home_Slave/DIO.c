/*
* DIO.c
*
* Created: 9/22/2020 9:11:20 PM
*  Author: Mirette
*/

#include "DIO.h"

void DIO_Write(DIO_ChannelTypes ChannelId, STD_LevelTypes Level)
{
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		if (Level == STD_High)
		{
			SetBit(PORTA_Reg, ChannelPos);
		}
		else
		{
			ClearBit(PORTA_Reg, ChannelPos);
		}
		break;
		
		case DIO_PortB:
		if (Level == STD_High)
		{
			SetBit(PORTB_Reg, ChannelPos);
		}
		else
		{
			ClearBit(PORTB_Reg, ChannelPos);
		}
		break;
		
		case DIO_PortC:
		if (Level == STD_High)
		{
			SetBit(PORTC_Reg, ChannelPos);
		}
		else
		{
			ClearBit(PORTC_Reg, ChannelPos);
		}
		break;
		
		case DIO_PortD:
		if (Level == STD_High)
		{
			SetBit(PORTD_Reg, ChannelPos);
		}
		else
		{
			ClearBit(PORTD_Reg, ChannelPos);
		}
		break;
	}
}
//ama a2sem el channel 3ala 8 akid hayetla3 7aga mn 0 le 3 then el modulus hatala3 7aga mn 0 le 7 fa a3raf anhy bit

STD_LevelTypes DIO_Read(DIO_ChannelTypes ChannelId)
{
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	STD_LevelTypes ChannelBit = STD_Low;
	switch(Portx)
	{
		case DIO_PortA:
		ChannelBit = GetBit(PINA_Reg,ChannelPos);
		break;
		
		case DIO_PortB:
		ChannelBit = GetBit(PINB_Reg,ChannelPos);
		break;
		
		case DIO_PortC:
		ChannelBit = GetBit(PINC_Reg,ChannelPos);
		break;
		
		case DIO_PortD:
		ChannelBit = GetBit(PIND_Reg,ChannelPos);
		break;
	}
	return ChannelBit;
}

void DIO_Toogle(DIO_ChannelTypes ChannelId)
{
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx)
	{
		case DIO_PortA:
		ToggleBit(PORTA_Reg,ChannelPos);
		break;
		
		case DIO_PortB:
		ToggleBit(PORTB_Reg,ChannelPos);
		break;
		
		case DIO_PortC:
		ToggleBit(PORTC_Reg,ChannelPos);
		break;
		
		case DIO_PortD:
		ToggleBit(PORTD_Reg,ChannelPos);
		break;
	}
}