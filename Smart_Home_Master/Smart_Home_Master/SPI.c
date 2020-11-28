/*
* SPI.c
*
* Created: 10/25/2020 8:34:33 PM
*  Author: Mirette
*/

#include "SPI.h"

void SPI_Init(SPI_InitType status)
{
	switch (status.state)
	{
		case Master:
		SPIDr |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDr &=~ (1<<MISO);
		SlaveDIS();
		SPCR |= (1<<MSTR)|(1<<SPE)|(1<<SPR1);
		//SPI->MySPCR._MSTR = 1;
		//SPI->MySPCR._SPE = 1;
		//SPI->MySPCR.SPCRBits._SPE = 1;
		//SPI->MySPCR.SPCRBits._MSTR = 1;
		//SPI->MySPCR.SPCRALL = 0x50;
		break;
		
		case Slave:
		SPIDr &=~ ((1<<SS)|(1<<MOSI)|(1<<SCK));
		SPIDr |= (1<<MISO);
		SPCR |= (1<<SPE);
		//SPI->MySPCR.SPCRBits._SPE = 1;
		break;
	}
}

unsigned char SPI_Receive_Transmit(unsigned char data)
{
	SPDR = data;
	while (!(SPSR & (1<<SPIF)));
	//while (SPI->MySPSR._SPIF == 0);
	return SPDR;
}

void SPI_TransmitChar(unsigned char Data)
{
	SPDR = Data;
	while (!(SPSR & (1<<SPIF)));
	//while (SPI->MySPSR._SPIF == 0);
}

unsigned char SPI_ReceiveChar(void)
{
	while (!(SPSR & (1<<SPIF)));
	//while (SPI->MySPSR._SPIF == 0);
	return SPDR;
}