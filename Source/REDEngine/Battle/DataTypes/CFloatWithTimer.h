#pragma once

struct __declspec(align(4)) CFloatWithTimer
{
	float m_Val;
	float m_BeginVal;
	float m_DestVal;
	int m_DestTimer;
	int m_DestTimerMax;
	bool m_bSet;
	bool m_bPause;
};
