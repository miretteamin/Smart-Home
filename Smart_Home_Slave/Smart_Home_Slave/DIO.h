/*
* DIO.h
*
* Created: 9/22/2020 9:11:08 PM
*  Author: Mirette
*/


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_Write(DIO_ChannelTypes , STD_LevelTypes );
STD_LevelTypes DIO_Read(DIO_ChannelTypes);
void DIO_Toogle(DIO_ChannelTypes);

#endif /* DIO_H_ */