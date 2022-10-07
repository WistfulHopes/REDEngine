#pragma once

template <int x, int y>
class CMultiBuffer
{
public:
	struct MEM
	{
		uint8 buffer[x];
		MEM *pPrev;
		MEM *pNext;
	};
	MEM *m_pEmptyChain;
	MEM m_Memory[y];
};
