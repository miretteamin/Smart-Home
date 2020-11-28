/*
* UART.c
*
* Created: 10/20/2020 8:27:07 PM
*  Author: Mirette
*/

#include "UART.h"

void UART_Init()
{
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL = MyUBRR;
	UBRRH = (MyUBRR >> 8);
}

void UART_SendChar(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

unsigned char UART_ReceiveChar()
{
	while((UCSRA & (1 << RXC)) == 0);
	return UDR;
}

void UART_SendString(char* str)
{
	unsigned char i = 0;
	while (str[i] != '\0')
	{
		UART_SendChar(str[i]);
	}
}