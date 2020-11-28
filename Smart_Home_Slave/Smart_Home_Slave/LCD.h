/*
* LCD.h
*
* Created: 9/29/2020 7:06:30 PM
*  Author: Mirette
*/


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define F_CPU 16000000UL
#include<util/delay.h>

#define RS DIO_ChannelA1
#define RW DIO_ChannelA2
#define E DIO_ChannelA3  //Enable

#define LCDDataPort PORTA_Reg

void LCD_Init();
void LCD_Cmd(Uint8 cmd); //Command
void LCD_Char(Sint8 data);
void LCD_String(Sint8 * string);
void LCD_CharPos(Sint8 data, Uint8 line, Uint8 pos);
void LCD_StringPos(Sint8 * string, Uint8 line, Uint8 pos);
void LCD_Custom_Char(Uint8 * data, Uint8 loc);
void LCD_CharLine(Sint8 data, Uint8 line);
void LCD_StringLine(Sint8 * string, Uint8 line);
void LCD_ClearbyLine(Uint8 line);
void LCD_Clear();

#endif /* LCD_H_ */