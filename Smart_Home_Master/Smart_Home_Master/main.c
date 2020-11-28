/*
* main.c
*
* Created: 10/29/2020 4:12:18 PM
*  Author: Mirette
*/

#include "SPI.h"
#include "LCD.h"
#include "UART.h"
#include <avr/interrupt.h>

volatile unsigned short sec = 0;
volatile unsigned char i = 0, y = 0;

int main(void)
{
	DIO_Init();
	LCD_Init();
	UART_Init();
	
	SPI_InitType InitData = {Master,MSB};
	SPI_Init(InitData);
	SlaveEN();
	
	LCD_String("Welcome :)");
	LCD_StringPos("Temperature: ",2,0);
	
	
	
	TCCR1B = (1<<CS12)|(1<<CS10)|(1<<WGM12); //Prescalar 1024
	TIMSK = (1<<OCIE1A);
	TCCR1A = (1<<COM1A0);
	OCR1A = 15625;//1 sec
	
	sei();
	
	//First Temperature Read
	SPI_TransmitChar(0x44);
	_delay_ms(200);
	i = SPI_Receive_Transmit(0x21);
	_delay_ms(200);
	y = SPI_Receive_Transmit(0x22);
	LCD_CharPos(i,2,13);
	LCD_CharPos(y,2,14);
	
	
	while (1)
	{
		SPI_TransmitChar(UART_ReceiveChar());
		_delay_ms(500);
	}
}

ISR(TIMER1_COMPA_vect)
{
	sec++;
	if (sec > 9)//Check on room's temperature every 10 seconds
	{
		SPI_TransmitChar(0x44);
		_delay_ms(200);
		i = SPI_Receive_Transmit(0x21);
		_delay_ms(200);
		y = SPI_Receive_Transmit(0x22);
		sec = 0;
		LCD_CharPos(i,2,13);
		LCD_CharPos(y,2,14);
	}
}
