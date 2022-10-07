#pragma once

class CBattleInputAnalyzer
{
public:
	uint16 m_PreRecFlg;
	uint16 m_CurRecFlg;
	uint16 m_RecFlgList[30];
	uint16 m_RecFlgTime[30];
	uint16 m_CurIndex;
};
