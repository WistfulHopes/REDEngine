#pragma once
#include "CXXBYTE.h"

enum CO_TYPE : int32;

struct CCreateArg
{
	CXXBYTE<32> m_CreateArg_SocketName;
	int m_CreateArg_Angle;
	int m_CreateArg_AngleY;
	int m_CreateArg_OffsetPosX;
	int m_CreateArg_OffsetPosY;
	int m_CreateArg_OffsetPosZ;
	int m_CreateArg_ScaleX;
	int m_CreateArg_ScaleY;
	int m_CreateArg_ScaleZ;
	int m_CreateArg_Hikitsugi0;
	int m_CreateArg_Hikitsugi1;
	unsigned int m_CreateArg_HkrColor;
	unsigned int m_CreateArg_MltColor;
	int m_CreateArg_TransPriority;
	TEnumAsByte<enum PTDIR> m_CreateArg_Direction;
	bool m_CreateArg_SocketUse;
	bool m_CreateArg_SocketWithRot;
	bool m_CreateArg_NoAssert;
	CO_TYPE m_CreateArg_SocketOwner;
	bool m_CreateArg_LinkMaterialParticle;
	bool m_CreateArg_ParticleUnuseMatInstance;
	unsigned int m_CreateArg_Delay;
	int m_CreateArg_PointLightSide;
	int m_CreateArg_PointLightMember;
};
