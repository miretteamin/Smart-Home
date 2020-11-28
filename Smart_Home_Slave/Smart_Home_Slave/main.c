/*
* SmartHome_Slave.c
*
* Created: 10/28/2020 6:59:21 PM
* Author : Mirette
*/

#include "SPI.h"
#include "LCD.h"
#include "ADC.h"
#include "DC_Motor.h"
#include <stdlib.h>

int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init();
	DC_Motor_Init();
	
	SetBit(DDRC,7);
	
	SPI_InitType InitData = {Slave, MSB};
	SPI_Init(InitData);
	
	unsigned short temp = 0;
	char buffer[2];
	unsigned char cmd;
	
	while (1)
	{
		cmd = SPI_ReceiveChar(); //Receive Command from Master
		_delay_ms(100);
		
		switch (cmd)
		{
			case '1':
			SetBit(PORTC,7);
			LCD_Clear();
			LCD_String("Light ON");
			break;
			
			case '2':
			ClearBit(PORTC,7);
			LCD_Clear();
			LCD_String("Light OFF");
			break;
			
			case '3':
			DC_Motor_Direction('F');
			LCD_Clear();
			LCD_StringPos("DC Motor ON",1,0);
			LCD_StringPos("Forward Dir",2,0);;
			break;
			
			case '4':
			DC_Motor_Direction('B');
			LCD_Clear();
			LCD_StringPos("DC Motor ON",1,0);
			LCD_StringPos("Backward Dir",2,0);
			break;
			
			case 0x44:
			temp = ADC_Read(0);
			temp /= 4;
			itoa(temp,buffer,10);
			
			if (SPI_Receive_Transmit(buffer[0]) == 0x21)
			{
				LCD_Clear();
				LCD_StringPos("Reading",1,0);
				LCD_StringPos("Temperature",2,0);
			}
			if (SPI_Receive_Transmit(buffer[1]) == 0x22) LCD_Clear();
			break;
		}
	}
}