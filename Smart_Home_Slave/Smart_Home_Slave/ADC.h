/*
 * ADC.h
 *
 * Created: 10/11/2020 9:33:35 PM
 *  Author: Mirette
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();
unsigned short ADC_Read(unsigned char);



#endif /* ADC_H_ */