#pragma once

template <typename T, int x, int y>
class AA_EasyHash
{
public:
	uint16 m_MaxLinkErrorCount;
	uint16 m_ElmCount;
	uint16 m_HashTable[y];
	uint16 m_LinkTable[x];
	T m_ElmTable[2200];
};
