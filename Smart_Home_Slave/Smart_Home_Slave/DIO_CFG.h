/*
 * DIO_CFG.h
 *
 * Created: 9/22/2020 9:28:29 PM
 *  Author: Mirette
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

#define PINCOUNT 32

typedef struct  
{
	DIO_DirTypes PinDir;
	STD_LevelTypes PinLevel;
}DIO_PinCFG;

void DIO_Init(void);

#endif /* DIO_CFG_H_ */