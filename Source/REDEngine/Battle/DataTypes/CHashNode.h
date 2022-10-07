#pragma once
#include "CHashKey.h"

class CHashNode
{
public:
	
};

struct __declspec(align(8)) CHashNodeC32BYTE : CHashNode
{
	CHashKeyC32BYTE m_HashKey;
};

struct __declspec(align(8)) CHashNodeC32BYTEtoU32 : CHashNodeC32BYTE
{
	unsigned int m_Data;
};