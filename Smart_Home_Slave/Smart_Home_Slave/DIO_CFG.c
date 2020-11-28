/*
* DIO_CFG.c
*
* Created: 9/22/2020 9:28:13 PM
*  Author: Mirette
*/

#include "DIO_CFG.h"

const DIO_PinCFG PinCfg[] = {
	//PORTA
	{Input, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	
	//PORTB
	{Input, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Input, STD_High},
	{Input, STD_High},
	{Output, STD_High},
	{Input, STD_High},
	
	//PORTC
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	
	//PORTD
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low}
};

void DIO_Init()
{
	Uint8 count = 0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes ChannelPos;
	for (count = DIO_ChannelA0; count<PINCOUNT; count++)
	{
		Portx = count/8;
		ChannelPos = count%8;
		switch(Portx)
		{
			case  DIO_PortA:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRA_Reg, ChannelPos);
			}
			else
			{
				ClearBit(DDRA_Reg, ChannelPos);
			}
			break;
			
			case  DIO_PortB:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRB_Reg, ChannelPos);
			}
			else
			{
				ClearBit(DDRB_Reg, ChannelPos);
			}
			break;
			
			case  DIO_PortC:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRC_Reg, ChannelPos);
			}
			else
			{
				ClearBit(DDRC_Reg, ChannelPos);
			}
			break;
			
			case  DIO_PortD:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRD_Reg, ChannelPos);
			}
			else
			{
				ClearBit(DDRD_Reg, ChannelPos);
			}
			break;
		}
	}
}