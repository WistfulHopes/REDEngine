#include "OBJ_CBase.h"

#include "Constants.h"
#include "DataTypes/AttackFlags.h"

CAtkParam::CAtkParam()
{
	CAtkParamInit();
}

void CAtkParam::CAtkParamInit()
{
	m_AtkFlag4 = APFLG4_DAMAGE_NOT_INITIALIZED;
	m_AtkFlag2 = APFLG2_HOSEI_TADAN;
	m_AtkFlag3 = APFLG3_MULTI_HIT;
	m_AtkHitStopTimeEnemyAddition[0] = 0x7FFFFFFF;
	m_AtkHitStopTimeEnemyAddition[1] = 0x7FFFFFFF;
	m_AtkHitStopTimeEnemyAddition[2] = 0x7FFFFFFF;
	m_AtkHitStopTime = 0x7FFFFFFF;
	m_AtkLockWaitTime = 15;
	m_AtkGuardTime = 0x7FFFFFFF;
	m_AtkAirGuardTimeAddition = 0x7FFFFFFF;
	m_AtkRangeMaxX = 0x7FFFFFFF;
	m_AtkRangeMaxY = 0x7FFFFFFF;
	m_AtkPushRangeX = 0x7FFFFFFF;
	m_AtkBarrierDamageRate = 0x7FFFFFFF;
	m_AtkEffectScale = 1000;
	m_AtkHitPositionX = 0x7FFFFFFF;
	m_AtkHitPositionY = 0x7FFFFFFF;
	m_AtkExHitParamMax = 1000000;
	m_AtkExHitParamMin = -1000000;
	m_AtkKizetsuDamage = 0x7FFFFFFF;
	m_AtkFlag |= APFLG3_NO_FINISH_CAMERA;
	m_AtkHitBack = 100;
	m_AtkFDMinHitBack = 0x7FFFFFFF;
	m_AtkHitBackGuardBreak = 0x7FFFFFFF;
	m_AtkHitBackForHit = 100;
	m_AtkWallPushBack = 0x7FFFFFFF;
	m_AtkLandStunTimeCrouchAddition = 0x7FFFFFFF;
	m_AtkJitabataTime = 30;
	m_AtkTensionGG = 0x7FFFFFFF;
	m_AtkRecoverDamageRate = 0x7FFFFFFF;
	m_AtkLevelForGuard = 0x7FFFFFFF;
	m_AtkGuardBalance = 0x7FFFFFFF;
	m_AtkHosei = 0x7FFFFFFF;
	m_AtkHoseiRateFirst = 0x7FFFFFFF;
	m_AtkHoseiRateForce = 0x7FFFFFFF;
	m_AtkHoseiOnece = 0x7FFFFFFF;
	m_AtkKezuriGG = 0x7FFFFFFF;
	m_AtkRushSousaiJizokuFrame = 0x7FFFFFFF;
	m_ExplosionFinishActCountLimit = 0x7FFFFFFF;
	m_AtkGuardBalanceHosei = 0x7FFFFFFF;
	m_AtkDmgActCount = 1;
	m_AtkGuardGravity = 0x7FFFFFFF;
	m_AtkAngleGuardForce = 0x7FFFFFFF;
	m_AtkHajikareTime = 30;
	m_AtkFixBoundSpeed = 0x7FFFFFFF;
	m_AtkFixBoundSpeed2 = 0x7FFFFFFF;
	m_AtkFixWallBoundSpeed = 0x7FFFFFFF;
	m_AtkFixWallBoundSpeed2 = 0x7FFFFFFF;
	m_AtkDmgActCountRateX = 100;
	m_AtkDmgActCountRateY = 100;
	m_AtkSameAttackNum = DBM_VAL_CONST_TABLE[DBM_SameAttackNumDefault];
	m_AtkSameAttackGravity = DBM_VAL_CONST_TABLE[DBM_SameAttackGravityDefault];
	m_AtkPreGuardRangeDot = 400;
	m_AtkPreGuardRangeDotY = 190;
}

void FBoneController::SetResetOnActionChange(bool flag)
{
	bResetOnActionChange = flag;
}

OBJ_CBase::OBJ_CBase()
{
	ObjectConstructor_ForObject();
}

void OBJ_CBase::ObjectConstructor_ForObject()
{
	m_ObjectSortPriority = 100;
	if (m_pColorParent.m_Ptr)
		--m_pColorParent.m_Ptr->m_WatchedCount;
	m_pColorParent.m_Ptr = this;
	++m_WatchedCount;
	m_ExHoming.m_HomingObj = CO_NULL;
	m_ExHoming.m_HomingPos = POS_ZERO;
	m_ScaleForLink = 1000;
	m_ScaleForLinkX = 1000;
	m_ScaleForLinkY = 1000;
	m_ScaleForLinkZ = 1000;
	m_MaxHit = -1;
	m_AttackerHoseiMemory = 0x7FFFFFFF;
	m_AttackerHoseiMemoryTypeHistory = 0x7FFFFFFF;
	m_VeBallFlag = 1;
	m_PerSpeedXEveryFrame = 100;
	m_PerSpeedYEveryFrame = 100;
	m_DiffusionFilter2Level = 1000;
	SetHitPointMax(420);
	SetHitPoint(m_HitPointMax);
	m_HitPoint_x1000 = 1000 * m_HitPoint;
	m_ObjectPriority = 1;
	m_LandingHeight = 0xFFFFFFF;
	m_Direction	= 1;
	m_ScaleX = 1000;
	m_ScaleY = 1000;
	m_ScaleZ = 1000;
	m_SpeedRateX = 100;
	m_WallPushBackAPBefore = 0x7FFFFFFF;
	m_PushColHeightLow = 0xFFFFFFFF;
	m_MltColor.R.Value = 1;
	m_MltColor.B.Value = 1;
	m_MltColor.G.Value = 1;
	m_MltColor.A.Value = 1;
	if (m_pAttackSlave[0].m_Ptr)
	{
		--m_pAttackSlave[0].m_Ptr->m_WatchedCount;
		m_pAttackSlave[0].m_Ptr = nullptr;
	}
	m_AttackObjectMax = 10;
	if (m_pAttackSlaveNewest.m_Ptr)
	{
		--m_pAttackSlaveNewest.m_Ptr->m_WatchedCount;
		m_pAttackSlaveNewest.m_Ptr = nullptr;
	}
	if (m_pLockLinkObj.m_Ptr)
	{
		--m_pLockLinkObj.m_Ptr->m_WatchedCount;
		m_pLockLinkObj.m_Ptr = nullptr;
	}
	if (m_pAttackMaster.m_Ptr)
	{
		--m_pAttackMaster.m_Ptr->m_WatchedCount;
		m_pAttackMaster.m_Ptr = nullptr;
	}
	if (m_pAttackMasterPlayer.m_Ptr)
	{
		--m_pAttackMasterPlayer.m_Ptr->m_WatchedCount;
		m_pAttackMasterPlayer.m_Ptr = nullptr;
	}
	m_Weight = 3000;
	m_MutekiHitStopSelf = -2;
	m_MutekiHitStopEnemy = -2;
	m_MutekiAtkLevel = 100;
	m_ShotDamageRate = 100;
	m_DispModel = true;
	SetupPawn();
	m_NaguruSignal = ON_SIGNAL_NULL;
	m_LastChangeFace = -1;
	m_InnerForceEffectRate = 500;
	m_OuterForceEffectRate = 500;
	m_InterruptStack.Interrupts[0] = ON_XXXX_NUM;
	m_ExecutionInterrupt = ON_XXXX_NUM;
	m_FirstHitDamageHoseiRate = 0x7FFFFFFF;
	m_SocketPosType = POS_ZERO;
	ResetScreenPushOffset();
	for (int i = 0; i < 29; i++)
	{
		m_MaterialVal_Default[i] = GetObjMaterialParamDefaultVal((MATERIAL_PARAM)i);
	}
	m_CellSlow.ParamFinishStop.bActive = true;
	m_CellSlow.ParamFinishStop.Interval = 1;
	m_CellSlow.ParamFinishStop.Frame1 = 200;
	m_CellSlow.ParamFinishStop.Frame2 = 1;
	m_CellSlow.ParamFinishStop.Blend1 = 1;
	m_CellSlow.ParamFinishStop.Blend2 = 1;
	m_CellSlow.MaxMoveRate = 1;
	m_CellSlowDefaultParam.bActive = true;
	m_CellSlowDefaultParam.Interval = 2;
	m_CellSlowDefaultParam.Frame1 = 6;
	m_CellSlowDefaultParam.Frame2 = 0.7;
	m_CellSlowDefaultParam.Blend1 = 60;
	m_CellSlowDefaultParam.Blend2 = 1;
	m_LinkExBlendIndex = -1;
	m_BoneCtrl.SetResetOnActionChange(true);
	m_ResetOverwriteLinkBoneOnActionChange = true;
	
}

void OBJ_CBase::SetHitPointMax(int val)
{
	m_HitPointMax = val;
}

void OBJ_CBase::SetHitPoint(int val)
{
	if (val <= m_HitPointMax)
	{
		if (val < 0)
			val = 0;
	}
	else
	{
		val = m_HitPointMax;
	}
	m_HitPoint = val;
	if (m_IsPlayerObj)
	{
		
	}
}

void OBJ_CBase::SetupPawn()
{
	if (m_pPawn)
	{
		
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_pPawn)
		{
			//AREDPawn::BlendExAnime(m_pPawn, v10, 0, 0, 0.0);
		}
		m_ExBlendParam[i].bActive = false;
		if (m_LinkExBlendIndex == i)
			m_LinkExBlendIndex = -1;
	}
}

void OBJ_CBase::ResetScreenPushOffset()
{
	m_PushScreenOffsetFront = 0;
	m_PushScreenOffsetTop = 0;
}
