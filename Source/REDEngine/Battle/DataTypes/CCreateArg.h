#pragma once
#include "CXXBYTE.h"
#include "Enums.h"

enum CO_TYPE : int32;

struct CCreateArg
{
	CXXBYTE<32> m_CreateArg_SocketName;
	int m_CreateArg_Angle;
	int m_CreateArg_AngleY;
	int m_CreateArg_OffsetPosX;
	int m_CreateArg_OffsetPosY;
	int m_CreateArg_OffsetPosZ;
	int m_CreateArg_ScaleX = 1000;
	int m_CreateArg_ScaleY = 1000;
	int m_CreateArg_ScaleZ = 1000;
	int m_CreateArg_Hikitsugi0;
	int m_CreateArg_Hikitsugi1;
	unsigned int m_CreateArg_HkrColor;
	unsigned int m_CreateArg_MltColor = -1;
	int m_CreateArg_TransPriority;
	TEnumAsByte<enum PTDIR> m_CreateArg_Direction;
	bool m_CreateArg_SocketUse;
	bool m_CreateArg_SocketWithRot;
	bool m_CreateArg_NoAssert;
	CO_TYPE m_CreateArg_SocketOwner = CO_PLAYER;
	bool m_CreateArg_LinkMaterialParticle;
	bool m_CreateArg_ParticleUnuseMatInstance;
	unsigned int m_CreateArg_Delay;
	int m_CreateArg_PointLightSide = -1;
	int m_CreateArg_PointLightMember;
};
