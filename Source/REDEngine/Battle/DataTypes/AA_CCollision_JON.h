#pragma once

struct CCmnRect
{
	float m_X;
	float m_Y;
	float m_W;
	float m_H;
};

enum _ZTYPE : int32
{
	ZTYPE_DEFAULT = 0x0,
	ZTYPE_MOST_FAR = 0x1,
	ZTYPE_FAR = 0x2,
	ZTYPE_LITTLE_FAR = 0x3,
	ZTYPE_LITTLE_NEAR = 0x4,
	ZTYPE_NEAR = 0x5,
	ZTYPE_MOST_NEAR = 0x6,
	ZTYPE_NUM = 0x7,
};

enum _TRANSTYPE : int32
{
	TTYPE_DEFAULT = 0x0,
	TTYPE_NORMAL = 0x1,
	TTYPE_ADD = 0x2,
	TTYPE_DEC = 0x3,
	TTYPE_REVERSE = 0x4,
	TTYPE_NUM = 0x5,
};

struct sJonElmView
{
	CCmnRect m_TextureRect;
	CCmnRect m_WorldRect;
	_ZTYPE m_ZType;
	float m_OfsZ;
	float m_Alpha01;
	_TRANSTYPE m_TransType;
	float m_RadZ;
	float m_AngleCenterOfsX;
	float m_AngleCenterOfsY;
	unsigned int m_ImageIndex;
	unsigned int m_Usage;
	unsigned int m_AfterImage;
	unsigned int m_Palette;
	unsigned int m_Rsv;
};

struct sJonElmCollision
{
	unsigned int m_CollisionType;
	CCmnRect m_WorldRect;
};

class AA_CCollision_JON
{
public:
	sJonElmView *m_ViewAddr;
	sJonElmCollision *m_CollisionAddr[18];
	int m_ViewNum;
	int m_CollisionNum[18];
	char *m_ImageFileName[8];
	int m_ImageFileNum;
};
