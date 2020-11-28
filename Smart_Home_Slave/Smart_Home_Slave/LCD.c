/*
* CFile1.c
*
* Created: 9/29/2020 7:06:09 PM
*  Author: Mirette
*/
#include "LCD.h"


void LCD_Cmd(Uint8 cmd)
{
	//For example cmd: 0x32 3 is high and 2 is low
	LCDDataPort = (LCDDataPort & 0x0F) | (cmd & 0xF0); //to send HIGH nibble
	DIO_Write(RS, STD_Low);
	DIO_Write(E, STD_High);
	_delay_us(100);
	DIO_Write(E, STD_Low);
	
	_delay_ms(5);
	
	LCDDataPort = (LCDDataPort & 0x0F) | (cmd << 4); //to send LOW nibble
	DIO_Write(RS, STD_Low);
	DIO_Write(E, STD_High);
	_delay_us(100);
	DIO_Write(E, STD_Low);
	_delay_ms(2);
	
}

void LCD_Init()
{
	//According to the Data Sheet
	DIO_Write(RW, STD_Low);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(200);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x18);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
	_delay_ms(2);
}

void LCD_Char(Sint8 data)
{
	LCDDataPort = (LCDDataPort & 0x0F) | (data & 0xF0); //to send HIGH nibble
	DIO_Write(RS, STD_High);
	DIO_Write(E, STD_High);
	_delay_us(100);
	DIO_Write(E, STD_Low);
	
	_delay_ms(5);
	
	LCDDataPort = (LCDDataPort & 0x0F) | (data << 4); //to send LOW nibble
	DIO_Write(RS, STD_High);
	DIO_Write(E, STD_High);
	_delay_us(100);
	DIO_Write(E, STD_Low);
	_delay_ms(2);
}

void LCD_String(Sint8 * string)
{
	Uint8 cnt = 0;
	while (string[cnt] != '\0')
	{
		LCD_Char(string[cnt]);
		cnt++;
	}
}

void LCD_StringPos(Sint8 * string, Uint8 line, Uint8 pos)
{
	switch (line)
	{
		case 1:
		LCD_Cmd((0x80) | (pos & 0x0F));
		LCD_String(string);
		break;
		case 2:
		LCD_Cmd((0xC0) | (pos & 0x0F));
		LCD_String(string);
		break;
	}
}

void LCD_Custom_Char(Uint8 * data, Uint8 loc)
{
	Uint8 i = 0;
	if(loc<8) LCD_Cmd(0x40 + (loc * 8));
	for (i = 0; i< 8; i++)
	{
		LCD_Char(data[i]);
	}
}

void LCD_CharPos(Sint8 data, Uint8 line, Uint8 pos)
{
	switch (line)
	{
		case 1:
		LCD_Cmd((0x80) | (pos & 0x0F));
		LCD_Char(data);
		break;
		case 2:
		LCD_Cmd((0xC0) | (pos & 0x0F));
		LCD_Char(data);
		break;
	}
}

void LCD_CharLine(Sint8 data, Uint8 line)
{
	switch (line)
	{
		case 1:
		LCD_Cmd(0x80);
		LCD_Char(data);
		break;
		case 2:
		LCD_Cmd(0xC0);
		LCD_Char(data);
		break;
	}
}

void LCD_StringLine(Sint8 * string, Uint8 line)
{
	switch (line)
	{
		case 1:
		LCD_Cmd(0x80);
		LCD_String(string);
		break;
		case 2:
		LCD_Cmd(0xC0);
		LCD_String(string);
		break;
	}
}

void LCD_ClearbyLine(Uint8 line)
{
	switch (line)
	{
		case 1:
		LCD_Cmd(0x80);
		LCD_String("                ");
		break;
		case 2:
		LCD_Cmd(0xC0);
		LCD_String("                ");
		break;
	}
}

void LCD_Clear()
{
	LCD_Cmd(0x01);
}