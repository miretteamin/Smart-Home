/*
* SPI.h
*
* Created: 10/25/2020 8:34:20 PM
*  Author: Mirette
*/



#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPIPort PORTB
#define SPIDr DDRB
#define SPI ((volatile SPIRegType * )0x2D)

#define SlaveEN() (SPIPort &=~ (1<<SS))
#define SlaveDIS() (SPIPort |= (1<<SS))

typedef	enum
{
	Master = 0,
	Slave
}SPIState;

typedef	enum
{
	MSB = 0,
	LSB
}SPIDataOrderType;

typedef	struct
{
	SPIState state;
	SPIDataOrderType DataOrder;
}SPI_InitType;

typedef struct
{
	unsigned char _SPR:2;
	unsigned char _CPHA:1;
	unsigned char _CPOL:1;
	unsigned char _MSTR:1;
	unsigned char _DORD:1;
	unsigned char _SPE:1;
	unsigned char _SPIE:1;
}SPISPCRBitsType;

typedef struct
{
	unsigned char _SPI2X:1;
	unsigned char _R0:1;
	unsigned char _R1:1;
	unsigned char _R2:1;
	unsigned char _R3:1;
	unsigned char _R4:1;
	unsigned char _SWCOL:1;
	unsigned char _SPIF:1;
}SPISPSRBitsType;

typedef union
{
	SPISPCRBitsType SPCRBits;
	unsigned char SPCRALL;
}SPISPCRType;

typedef struct
{
	SPISPCRType MySPCR;
	SPISPSRBitsType MySPSR;
	unsigned char MySPDR;
}SPIRegType;


void SPI_Init(SPI_InitType status);
unsigned char SPI_Receive_Transmit(unsigned char data);
void SPI_TransmitChar(unsigned char Data);
unsigned char SPI_ReceiveChar(void);


#endif /* SPI_H_ */