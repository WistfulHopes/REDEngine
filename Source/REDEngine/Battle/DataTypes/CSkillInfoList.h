#pragma once
#include "AA_EasyHash.h"
#include "CSkillInfo.h"

struct CSkillInfoList
{
	CSkillInfo m_SkillInfo[180];
	int m_RBMemcpyBegin;
	int m_SkillRegisterIndexList[180];
	int m_SkillRegisterNum;
	unsigned __int8 m_RecipeDataBuffer[8000];
	unsigned int m_RecipeDataBufferTotal;
	int m_SkillInfoCount;
	int m_SkillSettingID;
	int m_RBMemcpyEnd;
	AA_EasyHash<CXXBYTE<32>,200,800> m_SkillNameMap;
};
