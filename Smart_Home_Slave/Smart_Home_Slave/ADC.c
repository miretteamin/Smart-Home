/*
* ADC.c
*
* Created: 10/11/2020 9:33:19 PM
*  Author: Mirette
*/

#include "ADC.h"


void ADC_Init()
{
	ADMUX |= (1<<REFS1) | (1<<REFS0);
	ADCSRA |= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2)|(1 << ADIE);
}

unsigned short ADC_Read(unsigned char channel)
{
	unsigned short data = 0;
	ADMUX = (ADMUX & 0b11100000)|(channel & 0b00011111);
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);	
	data = ADCL;
	data |= (ADCH << 8);
	return data;
}
