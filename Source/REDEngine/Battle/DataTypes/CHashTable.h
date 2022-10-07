#pragma once

template <typename T>
class CHashTable<T>
{
public:
	T *m_Node;
	unsigned int m_NodeCnt;
	unsigned int m_NodeMax;
};
