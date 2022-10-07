#include "CBattleRecord.h"

void CBattleRecord::ResetRecord()
{
	memset(m_Record, 0, 0x68);
	m_pSkill[0] = nullptr;
	memset(&m_Record[1], 0, sizeof(m_Record[1]));
	m_pSkill[1] = nullptr;
}
