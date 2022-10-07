#pragma once

template <typename T, typename T2, int x, int y>
class __declspec(align(4)) AA_EasyMap
{
public:
	T m_pKeyList[x];
	T2 m_pItemList[x];
	int m_pSortList[x];
	int m_Cursor;
	bool m_IsOverWriteInsert;
};
