#include "OBJ_CBase.h"

#include "Constants.h"
#include "OBJ_CCharBase.h"
#include "DataTypes/AttackFlags.h"
#include "REDEngine/GameState/REDGameState_Battle.h"

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

int OBJ_CBase::GetOperandVal(const COperand* elm)
{
	if (!elm->m_Target)
		return elm->m_Val;
	OBJ_CCharBase* Player = (OBJ_CCharBase*)m_pParentPly.m_Ptr;
	OBJ_CBase* Target = m_pTargetObj.m_Ptr;
	if (!Target)
		return 0;
	switch (elm->m_Val)
	{
	case 0:
		return m_TmpReg;
	case 1:
		return m_AngleDeg_x1000;
	case 2:
		return m_CommonActionMark;
	case 3:
		return Player->m_PrivateVal[0];
	case 4:
		return Player->m_PrivateVal[1];
	case 5:
		return Player->m_PrivateVal[2];
	case 6:
		return Player->m_PrivateVal[3];
	case 7:
		if (m_Direction)
			return -m_SpeedX;
		return m_SpeedX;
	case 8:
		return m_SpeedY;
	default:
		return 0;
	}
}

void OBJ_CBase::CreateObjectArg(CXXBYTE<32>* actName, POS_TYPE exPoint)
{
	
}

void OBJ_CBase::CreateArg_Init()
{
	m_CreateArg.m_CreateArg_SocketName.m_Buf[0] = 0;
	m_CreateArg.m_CreateArg_Angle = 0i64;
	m_CreateArg.m_CreateArg_OffsetPosX = 0i64;
	m_CreateArg.m_CreateArg_OffsetPosZ = 0;
	m_CreateArg.m_CreateArg_Hikitsugi1 = 0i64;
	m_CreateArg.m_CreateArg_TransPriority = 0i64;
	m_CreateArg.m_CreateArg_LinkMaterialParticle = nullptr;
	m_CreateArg.m_CreateArg_Delay = 0;
	m_CreateArg.m_CreateArg_ScaleX = 1000;
	m_CreateArg.m_CreateArg_ScaleY = 1000;
	m_CreateArg.m_CreateArg_ScaleZ = 1000i64;
	m_CreateArg.m_CreateArg_MltColor = -1;
	m_CreateArg.m_CreateArg_SocketOwner = CO_PLAYER;
	m_CreateArg.m_CreateArg_PointLightSide = -1i64;
}

void OBJ_CBase::CreateArg_HikitsugiVal(COperand param0, COperand param1)
{
	m_CreateArg.m_CreateArg_Hikitsugi0 = GetOperandVal(&param0);
	m_CreateArg.m_CreateArg_Hikitsugi1 = GetOperandVal(&param1);
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

int OBJ_CBase::GetPushColW()
{
	if (m_PushColWidth < 0)
	{
		if (m_IsPlayerObj)
		{
			OBJ_CCharBase* player = (OBJ_CCharBase*)this;
			if ((m_ActionFlag & 1) != 0 || GetPosY() > 0)
			{
				return player->ply_PushColWidthAir;
			}
			if ((player->m_PlayerFlag & PLFLG_CROUCH) != 0 || (player->m_PlayerFlag & PLFLG_LOW_BALANCE) != 0)
			{
				return player->ply_PushColWidthCrouch;
			}
			return player->ply_PushColWidthStand;
		}
		return 120;
	}
	return m_PushColWidth;
}

int OBJ_CBase::GetPushColH()
{
	if (m_PushColHeight < 0)
	{
		if (m_IsPlayerObj)
		{
			OBJ_CCharBase* player = (OBJ_CCharBase*)this;
			if ((m_ActionFlag & 1) != 0 || GetPosY() > 0)
			{
				return player->ply_PushColHeightAir;
			}
			if ((player->m_PlayerFlag & PLFLG_CROUCH) != 0 || (player->m_PlayerFlag & PLFLG_LOW_BALANCE) != 0)
			{
				return player->ply_PushColHeightCrouch;
			}
			return player->ply_PushColHeightStand;
		}
		return 100;
	}
	return m_PushColHeight;
}

int OBJ_CBase::GetPushColHLow()
{
	if (m_PushColHeightLow == -1)
	{
		if (m_IsPlayerObj && (m_ActionFlag & 1) != 0 || GetPosY() > 0)
		{
			OBJ_CCharBase* player = (OBJ_CCharBase*)this;
			return player->ply_PushColHeightLowAir;
		}
		return 0;
	}
	return m_PushColHeightLow;
}

int OBJ_CBase::GetPosX()
{
	//code for rotated objects goes here
	if (m_pLinkObject_Position.m_Ptr)
	{
		return m_PosX + m_pLinkObject_Position.m_Ptr->GetPosX();
	}
	if (m_pLinkObject_PositionCenter.m_Ptr)
	{
		return m_PosX + m_pLinkObject_PositionCenter.m_Ptr->GetPosX();
	}
	if ((m_CollisionFlag & 0x40800) == 0x40800) //lock link position and locked
	{
		return m_PosX + m_pLockLinkObj.m_Ptr->GetPosX();
	}
	return m_PosX;
}

int OBJ_CBase::GetPosY()
{
	if (m_pLinkObject_Position.m_Ptr)
	{
		return m_PosY + m_pLinkObject_Position.m_Ptr->GetPosY();
	}
	if (m_pLinkObject_PositionCenter.m_Ptr)
	{
		return m_PosY + m_pLinkObject_PositionCenter.m_Ptr->GetPosY();
	}
	if ((m_CollisionFlag & 0x40800) == 0x40800) //lock link position and locked
		{
		return m_PosY + m_pLockLinkObj.m_Ptr->GetPosY();
		}
	return m_PosY;
}

int OBJ_CBase::GetAngleY()
{
	OBJ_CBase* target = m_pLinkObject_Angle.m_Ptr;
	if ( target )
		return m_AngleYDeg_x1000 + target->GetAngleY();
	return m_AngleYDeg_x1000;
}

int OBJ_CBase::GetObjDir()
{
	OBJ_CBase* target = m_pLinkObject_Direction.m_Ptr;
	if (target)
		return target->m_Direction;
	return m_Direction;	
}

void OBJ_CBase::GetPushScreenRect(int* L, int* T, int* R, int* B)
{
	GetPushWorldRect(0, T, 0, B);
	GetPushWorldRectForWorldClip(L, R);
	int dir;
	if (m_pLinkObject_Direction.m_Ptr)
	{
		dir = m_pLinkObject_Direction.m_Ptr->GetObjDir();
	}
	else
	{
		dir = m_Direction;
	}
	if (!dir)
	{
		*R += m_PushScreenOffsetFront;
		*L -= m_PushScreenOffsetBack;
	}
	else
	{
		*L -= m_PushScreenOffsetFront;
		*R += m_PushScreenOffsetBack;
	}
	*T += m_PushScreenOffsetTop;
	*B += m_PushScreenOffsetBottom;
}

void OBJ_CBase::GetPushWorldRect(int* L, int* T, int* R, int* B)
{
	int posX = GetPosX();
	int posY = GetPosY();
	int dir;
	if (m_pLinkObject_Direction.m_Ptr)
		dir = m_pLinkObject_Direction.m_Ptr->GetObjDir();
	else
		dir = m_Direction;
	int width = GetPushColW() / 2;
	int front = GetPushColW() + m_PushColWidthFront;
	int La = front;
	if (!dir)
	{
		La = width;
		width = front;
	}
	int height = GetPushColH();
	*T = posY + height;
	int heightlow = GetPushColHLow();
	*B = posY - heightlow;
	if (L)
	{
		if (R)
		{
			*L = posX - La;
			*R = posX + width;
			if (m_ClsnAnalyzer.m_CollisionNum[5])
			{
				CCmnRect world = m_ClsnAnalyzer.m_CollisionAddr[5]->m_WorldRect;
				int worldL;
				int worldR;
				worldL = (world.m_W + world.m_X) * 1000;
				worldR = world.m_X * -1000;
				*L = posX - worldL;
				*R = posX + worldR;
			}
		}
	}
	int Ra;
	if ((m_CollisionFlag & OBJ_CLSN_LOCKING) != 0 && (m_CollisionFlag3 & OBJ_CLSN_3_NOFAT_PUSHCOL_LOCKING) != 0)
	{
		if (L && R)
		{
			m_pLockLinkObj.m_Ptr->GetPushWorldRect(&La, B, &Ra, &posY);
			if (*T < *B)
				*T = *B;
			if (*B > posY)
				*B = posY;
			if (*L > La)
				*L = La;
			if (*R < Ra)
				*R = Ra;
		}
		else
		{
			m_pLockLinkObj.m_Ptr->GetPushWorldRect(0, B, 0, &posY);
			if (*T < *B)
				*T = *B;
			if (*B > posY)
				*B = posY;
		}
	}
	if (m_pLinkObject_PushCollision.m_Ptr)
	{
		if (L && R)
		{
			m_pLinkObject_PushCollision.m_Ptr->GetPushWorldRect(&La, B, &Ra, &posY);
			if (*T < *B)
				*T = *B;
			if (*B > posY)
				*B = posY;
			if (*L > La)
				*L = La;
			if (*R < Ra)
				*R = Ra;
		}
		else
		{
			m_pLinkObject_PushCollision.m_Ptr->GetPushWorldRect(0, B, 0, &posY);
			if (*T < *B)
				*T = *B;
			if (*B > posY)
				*B = posY;
		}
	}
}

void OBJ_CBase::GetPushWorldRectForWorldClip(int* L, int* R)
{
	*L = m_PosX - RED_SIDE_OFFSET - 35000;
	*R = RED_SIDE_OFFSET + GetPosX() + 35000;
	int La;
	int Ra;
	if ((m_CollisionFlag & OBJ_CLSN_LOCKING) != 0)
	{
		m_pLockLinkObj.m_Ptr->GetPushWorldRectForWorldClip(&La, &Ra);
		if ( *L > La )
			*L = La;
		if ( *R < Ra )
			*R = Ra;
	}
	if (m_pLinkObject_PushCollision.m_Ptr)
	{
		m_pLinkObject_PushCollision.m_Ptr->GetPushWorldRectForWorldClip(&La, &Ra);
		if ( *L > La )
			*L = La;
		if ( *R < Ra )
			*R = Ra;
	}
}

void OBJ_CBase::ControlPhase_PreFrameStep()
{
	OBJ_CCharBase* Player = (OBJ_CCharBase*)this;
	if (!m_IsPlayerObj)
		Player = nullptr;
	if (Player)
	{
		int CtrlDir = Player->m_CtrlDir;
		if (Player->m_InpFlag[CtrlDir][244] && (Player->m_InpFlag[CtrlDir][120] || Player->m_InpFlag[CtrlDir][94]))
		{
			Player->m_ThrowInputTime = 0;
			if (Player->m_InpFlag[CtrlDir][1] || Player->m_InpFlag[CtrlDir][10] || Player->m_InpFlag[CtrlDir][19] || Player->m_InpFlag[CtrlDir][28])
			{
				Player->m_ThrowInputTime = 100;
			}
		}
		bool CanThrowTech = strncmp(Player->m_CurActionName.m_Buf, AN_CmnActLockWait.m_Buf, 0x20) || Player->m_ActionTime < DBM_VAL_CONST_TABLE[DBM_Nagenuke_afterCnt];
		if (Player->m_ThrowInputTime < DBM_VAL_CONST_TABLE[DBM_Nagenuke_prevCnt] && Player->m_CollisionFlag & 0x800 && Player->m_CollisionFlag2 & 0x800 && CanThrowTech)
		{
			Player->m_CollisionFlag2 &= ~0x800;
			CreateArg_Init();
			bool ThrowClash;
			if (Player->m_DmgParam.m_AtkFlag4 & 0x20)
			{
				CreateArg_HikitsugiVal(COperand(0, 1), COperand(0, 0));
				ThrowClash = true;
			}
			else
			{
				CreateArg_HikitsugiVal(COperand(0, 0), COperand(0, 0));
			}
			CXXBYTE<32> ObjectName;
			strncpy(ObjectName.m_Buf, "cmn_nagenuke", 0x20);
			CreateObjectArg(&ObjectName, POS_ZERO);
		}
		COperand IsAfro = COperand(2, 324);
		if (GetOperandVal(&IsAfro))
		{
			if (!Player->m_IsCreateAfroObj)
			{
				
			}
		}
	}
	++m_ObjTimer;
	m_bFaceBrowChanged = false;
	m_bFaceMouthChanged = false;
	m_bHairChanged = false;
	m_ObjSignal = 0;
	if (!(m_ObjFlag & 0x4000000) && !(m_ObjFlag2 & 0x200000))
	{
		if (m_HitStopTimeBySousai)
			m_HitStopTimeBySousai--;
		else
		{
			if (m_HitStopTime)
				m_HitStopTime--;
		}
	}
	if (m_ObjShakeXTime)
		m_ObjShakeXTime--;
	if (m_VoiceInfo.m_bDamageVoiceRequest && !m_HitStopTime)
	{
		CXXBYTE<16> DamageVoice;
		strncpy(DamageVoice.m_Buf, m_VoiceInfo.m_DamageVoiceName.m_Buf, 0x10);
		//OBJ_CBase::Voice(&DamageVoice);
		m_VoiceInfo.m_bDamageVoiceRequest = false;
	}
	if (m_CollisionFlag & 0x800)
	{
		if (Player)
		{
			if (Player->m_LockWaitTime)
				Player->m_BurstLog--;
			if (Player->m_LockWaitTime <= 0 && !(m_CollisionFlag & 0x2000))
			{
				m_CollisionFlag |= 0x4000;
				m_pLockLinkObj.m_Ptr->m_CollisionFlag |= 0x4000;
			}
		}
	}
	if (m_CollisionFlag & 0x20000)
	{
		if (m_CollisionFlag & 0x4000)
		{
			//OBJ_CBase::CellStop(0);
			this->m_CollisionFlag &= ~0x20000;
		}
		else
		{
			//OBJ_CBase::CellStop(1);
		}
	}
	
}

OBJ_CCharBase* OBJ_CBase::GetMainPlayerBase(SIDE_ID side)
{
	AREDGameState_Battle* GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState());
	if (IsValid(GameState))
	{
		return GameState->BattleObjectManager.Get()->m_TeamManager[side].m_pMainPlayerObject;
	}
	return nullptr;
}
