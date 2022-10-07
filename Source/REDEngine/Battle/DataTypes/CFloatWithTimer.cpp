#include "CFloatWithTimer.h"

void CFloatWithTimer::Init()
{
	m_Val = 0;
	m_DestVal = 0;
	m_DestTimerMax = 0;
	m_bSet = nullptr;
}

void CFloatWithTimer::SetVal(float beginVal, float destVal, unsigned time)
{
	if (time)
		m_Val = beginVal;
	else
		m_Val = destVal;
	m_BeginVal = beginVal;
	m_DestVal = destVal;
	m_DestTimer = 0;
	m_DestTimerMax = time;
	m_bSet = true;
}
