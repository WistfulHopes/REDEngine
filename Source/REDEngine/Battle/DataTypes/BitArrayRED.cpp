#include "BitArrayRED.h"

#define BYTEn(x, n)   (*((uint8*)&(x)+n))
#define BYTE1(x)   BYTEn(x,  1)

template <int i, typename T>
int64 BitArrayRED<i, T>::CountTrueBit()
{
	int v1;
	if (m_U32DataArray[0] == -1)
		v1 = 32;
	else
	{
		unsigned int v2;
		v2 = (((m_U32DataArray[0] & 0x55555555) + ((m_U32DataArray[0] >> 1) & 0x55555555)) & 0x33333333)
			+ ((((m_U32DataArray[0] & 0x55555555) + ((m_U32DataArray[0] >> 1) & 0x55555555)) >> 2) & 0x33333333);
		unsigned int v3;
		v3 = (((v2 & 0xF0F0F0F) + ((v2 >> 4) & 0xF0F0F0F)) & 0xFF00FF)
			+ ((((v2 & 0xF0F0F0F) + ((v2 >> 4) & 0xF0F0F0F)) >> 8) & 0xFF00FF);
		v1 = (uint16)v3 + HIWORD(v3);
	}
	unsigned int v4;
	v4 = (m_U32DataArray[1] & 0x55555555) + ((m_U32DataArray[1] >> 1) & 0x55555555);
	unsigned int v5;
	v5 = (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333)) & 0xF0F0F0F)
	   + ((((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F);
	return v1 + (((v5 & 0xFF00FF) + ((v5 >> 8) & 0xFF00FF)) >> 16) + (uint16)((uint8)v5 + BYTE1(v5));
}
