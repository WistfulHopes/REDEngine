#pragma once

struct __declspec(align(4)) CVectorWithTimer
{
	float m_Val[4];
	float m_BeginVal[4];
	float m_DestVal[4];
	int m_DestTimer[4];
	int m_DestTimerMax[4];
	bool m_bSet;
};
