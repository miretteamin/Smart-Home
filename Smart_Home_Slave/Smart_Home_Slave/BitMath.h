/*
* BitMath.h
*
* Created: 9/22/2020 3:34:16 AM
*  Author: Mirette
*/


#ifndef BITMATH_H_
#define BITMATH_H_


#define SetBit(reg,nbit)  ((reg) |= (1<<(nbit)))
#define ClearBit(reg,nbit) ((reg) &= ~(1<<(nbit)))
#define ToggleBit(reg,nbit) ((reg) ^= (1<<(nbit)))
#define GetBit(reg,nbit)  ((reg>>nbit) & 1)


#endif /* BITMATH_H_ */