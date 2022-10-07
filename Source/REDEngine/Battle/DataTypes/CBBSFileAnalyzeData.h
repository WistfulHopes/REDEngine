#pragma once
#include "CHashTable.h"
#include "CXXBYTE.h"

struct CHashNodeC32BYTEtoU32;

struct sActionBegin
{
	CXXBYTE<32> m_ActionName;
	unsigned int m_OffsetAddr;
};

class CBBSFileAnalyzeData
{
public:
	unsigned __int8 *m_DataTopAddr;
	unsigned __int8 *m_ScriptTopAddr;
	int m_ActionBeginCount;
	sActionBegin *m_ActionBeginListAddr;
	TSharedPtr<CHashTable<CHashNodeC32BYTEtoU32>,ESPMode::NotThreadSafe> m_ActIndexTable;
	TSharedPtr<CHashTable<CHashNodeC32BYTEtoU32>,ESPMode::NotThreadSafe> m_FuncAddrTable;
	TSharedPtr<CHashTable<CHashNodeC32BYTEtoU32>,ESPMode::NotThreadSafe> m_PreFuncAddrTable;
	TSharedPtr<CHashTable<CHashNodeC32BYTEtoU32>,ESPMode::NotThreadSafe> m_PostFuncAddrTable;
	bool m_bAllocate;
};
