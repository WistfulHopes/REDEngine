#pragma once

template <typename T>
class CHashTable
{
public:
	T *m_Node;
	unsigned int m_NodeCnt;
	unsigned int m_NodeMax;
};
