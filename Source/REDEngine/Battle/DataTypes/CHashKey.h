#pragma once

struct U32KEY
{
	unsigned int m_Key;
};

struct CHashKey
{
	U32KEY m_Key;
};

struct CHashKeyC32BYTE : CHashKey
{
};
