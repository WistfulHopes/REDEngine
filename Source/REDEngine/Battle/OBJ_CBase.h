#pragma once
#include "DataTypes/AA_CCollision_JON.h"
#include "DataTypes/AA_Filepack_FPAC.h"
#include "DataTypes/AA_Flag.h"
#include "COperand.h"
#include "DataTypes/AA_Handle.h"
#include "DataTypes/C256BYTE.h"
#include "DataTypes/CCreateArg.h"
#include "DataTypes/CFloatWithTimer.h"
#include "DataTypes/CVectorWithTimer.h"
#include "DataTypes/CXXBYTE.h"
#include "DataTypes/Enums.h"
#include "DataTypes/StatisticsCheckSkillData.h"
#include "DataTypes/TBlendParam.h"

class AREDDestructionShotObject;
class AREDPawn;
class CBBSFileAnalyzeData;
class OBJ_CBase;

struct OBJ_CBaseRelativePtr
{
	OBJ_CBase *m_Ptr;
};

struct FREDAudioHandle
{
	int Index;
	unsigned int UniqueId;
};

struct LoopedFloatParam
{
	float Value;
	float Speed;
	float BeginValue;
	float EndValue;
	int LoopCount;
	int FrameCounter;
	int FrameCountMax;
	float MINVALUE;
	float MAXVALUE = 10;
};

struct __declspec(align(4)) CColorWithSpeed
{
	LoopedFloatParam R;
	LoopedFloatParam G;
	LoopedFloatParam B;
	LoopedFloatParam A;
	bool IgnoreStop;
};

struct AtkShakeCameraParam
{
	CXXBYTE<32> patternName;
	int scale;
	int inFrame;
	int stayFrame;
	int outFrame;
};

struct CAtkParam
{
	CAtkParam();
  int m_AtkType;
  int m_AtkLevel;
  int m_AtkLevelForSousai;
  int m_AtkDamage;
  int m_AtkFlag;
  int m_AtkFlag2;
  int m_AtkFlag3;
  int m_AtkFlag4;
  int m_AtkFlag5;
  int m_AtkHitStopTimeEnemyAddition[3];
  int m_AtkHitStopTime;
  int m_AtkLockWaitTime;
  int m_AtkGuardTime;
  int m_AtkAirGuardTimeAddition;
  int m_AtkRangeMaxX;
  int m_AtkRangeMaxY;
  int m_AtkRangeMinX;
  int m_AtkRangeMinY;
  int m_AtkPushRangeX;
  CXXBYTE<32> m_AtkLockAction;
  CXXBYTE<32> m_AtkDamageEffectName;
  CXXBYTE<32> m_AtkGuardEffectName;
  int m_AtkBarrierDamageRate;
  int m_AtkEffectScale;
  CXXBYTE<32> m_AtkNextHitActionName;
  int m_AtkHitPositionX;
  int m_AtkHitPositionY;
  int m_AtkExHitParamAddVal;
  COperand m_AtkExHitParamOperand;
  int m_AtkExHitParamMax;
  int m_AtkExHitParamMin;
  int m_AtkPoisonTime;
  int m_AtkPoisonDamage;
  int m_AtkLockRejectType;
  int m_AtkFixDamageRate;
  int m_AtkKizetsuDamage;
  CXXBYTE<32> m_AtkGGThrowCell;
  int m_AtkHitBack;
  int m_AtkFDMinHitBack;
  int m_AtkHitBackGuardBreak;
  int m_AtkHitBackForHit;
  int m_AtkWallPushBack;
  int m_AtkLandStunTimeCrouchAddition;
  int m_AtkAirStunTime_FromLandAddition;
  int m_AtkAngle;
  int m_AtkJitabataTime;
  int m_AtkTensionGG;
  CXXBYTE<32> m_AtkHitCommonSE;
  CXXBYTE<32> m_AtkHitCommonSEAppend[3];
  CXXBYTE<32> m_AtkGuardCommonSE;
  CXXBYTE<32> m_AtkGuardCommonSEAppend[3];
  int m_AtkLevelForGuard;
  int m_AtkGuardBalance;
  int m_AtkHosei;
  int m_AtkHoseiRateFirst;
  int m_AtkHoseiRateForce;
  int m_AtkHoseiFirst;
  int m_AtkHoseiOnece;
  int m_AtkKezuriGG;
  int m_AtkKezuriRate;
  int m_AtkNoBurstTime;
  int m_AtkMutekiTime;
  int m_AtkDustMutekiTime;
  int m_AtkDrain;
  CXXBYTE<32> m_AtkTrialName;
  CXXBYTE<32> m_AtkTrialDrawName;
  int m_AtkSuikomiPowerX;
  int m_AtkSuikomiPowerY;
  int m_AtkRecoverDamageRate;
  int m_AtkAdditionalHitCount;
  int m_AtkRushSousaiJizokuFrame;
  int m_ExplosionFinishActCountLimit;
  int m_AtkGuardBalanceHosei;
  int m_AtkFixBoundSpeed;
  int m_AtkHitBackAir;
  int m_AtkAirGuardVectorX;
  int m_AtkAirGuardVectorY;
  int m_AtkDmgActCount;
  int m_AtkDmgActCountFirst;
  int m_AtkGuardGravity;
  int m_AtkAngleGuardForce;
  int m_AtkHajikareTime;
  int m_AtkDmgActCountRateX;
  int m_AtkDmgActCountRateY;
  int m_AtkFixBoundSpeed2;
  int m_AtkFixWallBoundSpeed;
  int m_AtkFixWallBoundSpeed2;
  int m_AtkConsiderVectorPerX;
  int m_AtkConsiderVectorPerY;
  int m_AtkSameAttackNum;
  int m_AtkSameAttackGravity;
  int m_AtkPreGuardRangeDot;
  int m_AtkPreGuardRangeDotY;
  CXXBYTE<32> m_AtkWallBoundNextAction;
  CXXBYTE<32> m_AtkLandBoundNextAction;
  AtkShakeCameraParam m_ShakeCamera;
  SKILL_CATEGORY m_AtkSkillCategory;
  TEnumAsByte<CHT_TYPE> m_AtkCounterHitType;
  TEnumAsByte<HIT_EFFECT> m_AtkDamageEffectType;
  TEnumAsByte<HIT_EFFECT> m_AtkGuardEffectType;
  TEnumAsByte<ATK_FRONT> m_AtkFrontDirection;
  TEnumAsByte<KILL_TYPE> m_AtkKillType;
  TEnumAsByte<FINISH_BG> m_AtkFinishBG;
  TEnumAsByte<HIT_POSITION_TYPE> m_AtkHitPositionType;
  TEnumAsByte<CO_TYPE> m_AtkExHitParamObjType;
  TEnumAsByte<ATKDAN> m_AtkDan;
  TEnumAsByte<DMG_CELL> m_AtkDamageCell;
  TEnumAsByte<EDT_TYPE> m_AtkExDamageType;
  TEnumAsByte<POS_TYPE> m_AtkSuikomiPos;
  TEnumAsByte<FACE_TYPE> m_AtkDamageFace;
  TEnumAsByte<ESoundBank> m_AtkHitSEBankId;
  TEnumAsByte<ESoundBank> m_AtkGuardSEBankId;
  TEnumAsByte<EDestructionFinish> m_AtkDestFinish;
  TEnumAsByte<EDestructionFinishEffect> m_AtkDestFinishEffect;
  TEnumAsByte<AtkEasyGuardReadyFlg> m_AtkEasyGuardReady;
  TEnumAsByte<CHT_PROCESS> m_AtkCounterHitProcess;
  char m_AtkShotLevel;
  uint8 m_AtkEffectLimit;
  uint8 m_AtkExHitParamFlag;
  OBJ_CBase *m_AtkTargetObj;
  CXXBYTE<32> m_AtkDamageCellEx;
  uint8 m_AtkDamageMouthType;
  uint8 m_AtkHead;
  uint8 m_AtkDownTuigekiAvailable;
  uint8 m_AtkTensionAddOnlyEnemy;
  uint8 m_AtkGuardCancel;
  uint8 m_AtkBlowOffGravityIsZero;
  uint8 m_AtkHitOnceInCombo;
  uint8 m_AtkHitNoTensionSelfDamage;
  uint8 m_AtkSuikomiBasePos;
  uint8 m_AtkDamageToRecovery;
  uint8 m_AtkInitialLeft;
  uint8 m_AtkSubObjectSousai;
  bool m_bAtkHitBankSEFromSet;
  bool m_bAtkHitBankSEOverwrite;
  bool m_bAtkGuardBankSEFromSet;
  bool m_bAtkGuardBankSEOverwrite;

	void CAtkParamInit();
};

struct AtkTimeCtrlParam
{
	int startTime;
	int endTime;
	int value1;
};

struct CAtkParamEx
{
	int m_AtkVectorX;
	int m_AtkVectorY;
	int m_AtkGravity;
	int m_AtkWallBoundRate;
	int m_AtkLandBoundRate;
	int m_AtkLandStunTime;
	int m_AtkAirStunTime;
	int m_AtkWallBoundCount;
	int m_AtkLandBoundCount;
	int m_AtkSleepStunTime;
	int m_AtkLandHitAction;
	int m_AtkAirHitAction;
	int m_AtkWallHaritsukiTime;
	int m_AtkWallBoundWorldOnly;
	int m_AtkKorogariTime;
	int m_AtkSlideDownTime;
	int m_AtkWallBoundWaitTime;
	int m_AtkKorogariUnlimited;
	int m_AtkQuickDownFlag;
	int m_AtkWSBPoint;
	int m_AtkIgnoreWSB;
	int m_AtkWSBBlowOffType;
	int m_AtkWSBLimitTime;
	int m_AtkFinishStopTime;
	int m_AtkSlashUITime;
	int m_AtkWallBoundGravity;
	int m_AtkLandBoundGravity;
	int m_AtkWallBoundStunTime;
	int m_AtkLandBoundStunTime;
	int m_AtkWallBoundStunTimeAddition;
	int m_AtkLandBoundStunTimeAddition;
	int m_AtkWallBoundRateY;
	int m_AtkLandBoundRateX;
	int m_AtkFuwafuwaDown;
	AtkTimeCtrlParam m_AtkVectorXPer;
	AtkTimeCtrlParam m_AtkVectorYPer;
	AtkTimeCtrlParam m_AtkGravityAdd;
	int m_AtkBlowOffLabel;
	int m_AtkBomberRate;
	int m_AtkRedRCTime;
};

struct __declspec(align(8)) CInterruptInfo
{
	uint8 *m_BeginAddr;
	CXXBYTE<32> m_ActionName;
	int m_IIParam0;
	int m_IIParam1;
	CXXBYTE<32> m_GotoLabel;
	unsigned int m_IntFlg;
};

struct CActionRequestInfo
{
	CXXBYTE<32> m_RequestName;
	unsigned int m_RequestFlag;
	CXXBYTE<32> m_RequestGotoLabel;
	int m_RequestSkillID = -1;
	bool m_SomeSkillIsRequested;
	bool m_SomeSkillIsRequestReserved;
	int m_RequestGCSkill = -1;
};

struct __declspec(align(4)) CVoiceInfo
{
	struct SFinishBranchVoiceInfo
	{
		bool bSet;
		CXXBYTE<16> DefaultVoice;
		CXXBYTE<16> FinishVoice;
	};
	int m_VoiceTimer;
	int m_VoiceHistoryTimer;
	CXXBYTE<16> m_VoiceHistoryName;
	char m_DamageVoiceWait;
	bool m_ForceVoicePlay;
	bool m_IgnoreForceVoicePlay;
	VOICE_TYPE m_LastVoiceType[8];
	CXXBYTE<16> m_LastPlayVoiceName[8];
	int m_LastRandomVoiceIndex[8];
	int m_LastVoicePriority[8];
	int m_LastVoiceRemainCount[8];
	bool m_bDamageVoiceRequest;
	CXXBYTE<16> m_DamageVoiceName;
	SFinishBranchVoiceInfo m_FinishBranchVoiceInfo;
};

struct CExHoming
{
	EXHOMING m_HomingType;
	CO_TYPE m_HomingObj;
	POS_TYPE m_HomingPos = POS_ZERO;
	int m_HomingOfsX;
	int m_HomingOfsY;
	int m_HomingParamA;
	int m_HomingParamB;
};

struct __declspec(align(4)) CJumpHoming
{
	CO_TYPE HomingTarget;
	int OffsetX;
	int OffsetY;
	int OffsetZ;
	int MaxSpeedX;
	int SpeedY;
	int Gravity;
	int Count;
	bool bFirstFrame;
};

struct sSoundReq
{
	int m_Volume = 100;
	int m_Pitch = 100;
	unsigned int m_SoundReqFlag;
	unsigned int m_Channel;
	int m_RandomChannel = -1;
	ESoundBank m_Bank = SND_BANK_INVALID;
	int m_Priority;
};

struct FBoneControlParam
{
	int LastX;
	int LastY;
	int LastZ;
	int CurrentX;
	int CurrentY;
	int CurrentZ;
};

struct __declspec(align(4)) FBoneControlUnit
{
	int UpdateInterval;
	int UpdateIntervalCount;
	int CurrentFrame;
	int EndFrame;
	EBoneControl_Interp InterpType;
	FBoneControlParam ControlParam;
	bool bSetParams;
};

struct __declspec(align(4)) FBoneController
{	
	enum ETargetBone : __int32
	{
		TargetBone_Head = 0x0,
		TargetBone_Clavicle_L = 0x1,
		TargetBone_Clavicle_R = 0x2,
		TargetBone_UpArm_L = 0x3,
		TargetBone_UpArm_R = 0x4,
		TargetBone_LowArm_L = 0x5,
		TargetBone_LowArm_R = 0x6,
		TargetBone_Hand_L = 0x7,
		TargetBone_Hand_R = 0x8,
		TargetBone_Chest = 0x9,
		TargetBone_Ex0 = 0xA,
		TargetBone_Ex1 = 0xB,
		TargetBone_Ex2 = 0xC,
		TargetBone_Ex3 = 0xD,
		TargetBone_Ex4 = 0xE,
		TargetBone_Max = 0xF,
	  };

	enum EParamType : __int32
	{
		ParamType_Position = 0x0,
		ParamType_Rotation = 0x1,
		ParamType_Scale = 0x2,
		ParamType_Max = 0x3,
	  };

	struct FBoneControlCommand
	{
		int DelayCount;
		ETargetBone TargetBone;
		EParamType TargetType;
		int Frames;
		int UpdateInterval;
		int ParamX;
		int ParamY;
		int ParamZ;
		EBoneControl_Interp InterpType;
	};

	FBoneControlCommand BoneControlQue[16];
	FBoneControlUnit BoneControlUnit[45];
	bool bEnableBoneControl;
	bool bTriggerOnCellBegin;
	bool bIgnoreObjStop;
	bool bForceUpdateSkeleton;
	bool bResetOnActionChange;

	void SetResetOnActionChange(bool flag);
};

class OBJ_CBase
{
public:
	struct SCellBlendParam
	{
		bool bActive;
		CXXBYTE<32> CellName;
		TBlendParam<float> BlendParam;
	};

	struct SCellSlowParam
	{
		bool bActive;
		int Interval;
		int Frame1;
		int Frame2;
		float Blend1;
		float Blend2;
	};

	struct SCellSlow
	{
		bool bOverride;
		SCellSlowParam Param;
		SCellSlowParam ParamFinishStop;
		int Counter;
		float WorldStopAdvanceRate;
		int DrawOffsetX;
		int DrawOffsetY;
		float MoveRate;
		float MaxMoveRate;
	};

	struct SExBlendParam
	{
		bool bActive;
		CXXBYTE<32> CellName;
	};

	struct FInterruptStack
	{
		ON_XXXX_INTRPT Interrupts[8];
		int StackCount;
	};

	struct SDispWithoutMove
	{
		bool bActive;
		int OffsetPosX;
		int ApplyRate;
		bool bInit;
		int BasePosX;
	};
	
	struct SRollbackVoiceParam
	{
		CXXBYTE<32> VoiceCueName;
		int VoiceDuration;
		int VoiceRemainCount;
	};

	struct SRollbackData
	{
		CXXBYTE<32> LinkParticleName;
		CO_TYPE LinkParticleObjType = CO_SELF;
		bool LinkParticleUseArg;
		CCreateArg LinkParticleCreateArg;
		bool bLinkParticleSet;
		unsigned int LinkParticleStartFrame;
		CXXBYTE<32> LinkParticleActName;
		unsigned int PointLightId;
		CXXBYTE<32> LinkPawnName;
		bool LinkPawnSet;
		bool LinkCommonPawn;
		bool LinkCommonPawnEffect;
		bool LinkCommonPawnSelf;
		bool LinkPawnPlayingCutSceneAnime;
		unsigned int LinkPawnStartFrame;
		CXXBYTE<32> LinkPawnActName;
		CXXBYTE<32> MeshSetName;
		CXXBYTE<32> MaterialSetName;
		CXXBYTE<32> PlayAnimeName;
		int PlayAnimeStartFrame;
		bool bPlayAnimeSet;
		float PlayAnimeCurrentTime;
		int PlayAnimCutSceneStepFramePawn;
		int PlayAnimCutSceneStepFrameAnimInst;
		CXXBYTE<32> AttachPawnMeshName;
		CXXBYTE<32> AttachPawnSocketName;
		bool bAttachPawnSet;
		SRollbackVoiceParam VoiceParams[8];
	};

	struct SRollbackMeshControl
	{
		bool bSetForceDispFlag;
		bool bForceDispFlag;
	};

	OBJ_CBase();
	
	int ObjBaseSyncBegin;
	unsigned int m_AtkPriority;
	ACTV_STATE m_ActiveState;
	unsigned int m_ObjectSortPriority;
	bool m_IsPlayerObj;
	unsigned int m_UniqID;
	unsigned int m_ObjTimer;
	unsigned int m_BuruBuruPartsTime;
	bool m_IsDirty;
	unsigned int m_WatchedCount;
	unsigned int m_ActionChangeID;
	int m_TmpWork;
	int m_ObjectPriority;
	int m_ObjectGeneration;
	TEnumAsByte<SIDE_ID> m_SideID;
	TEnumAsByte<SIDE_ID> m_FixedSideID;
	TEnumAsByte<ECharaID> m_CharaID;
	TEnumAsByte<ECharaID> m_FixedCharaID;
	TEnumAsByte<EMemberID> m_MemberID;
	TEnumAsByte<EMemberID> m_FixedMemberID;
	EBattleScript m_ScriptType;
	AA_CCollision_JON m_ClsnAnalyzer;
	AA_Filepack_FPAC m_ColPac;
	unsigned int m_ObjFlag;
	unsigned int m_ObjFlag2;
	unsigned int m_ObjFlag3;
	unsigned int m_ObjFlag4;
	unsigned int m_ObjFlag5;
	unsigned int m_ActionKeepFlag;
	unsigned int m_ObjSignal;
	unsigned int m_ActionTime;
	unsigned int m_LinkModelTime;
	unsigned int m_ActionTimeMax;
	unsigned int m_ActionTimeNoStop;
	unsigned int m_OnIdlingTime;
	int m_CommonActionMark;
	int m_TmpReg;
	int m_ActReg0;
	int m_ActReg1;
	int m_ActReg2;
	int m_ActReg3;
	int m_ActReg4;
	int m_ActReg5;
	int m_ActReg6;
	int m_ActReg7;
	int m_ObjReg0;
	int m_ObjReg1;
	int m_ObjReg2;
	int m_ObjReg3;
	int m_ObjReg4;
	int m_ObjReg5;
	int m_ObjReg6;
	int m_ObjReg7;
	int m_PgActReg0;
	int m_PgActReg1;
	int m_PgActReg2;
	int m_PgActReg3;
	int m_PgObjReg0;
	int m_PgObjReg1;
	int m_PgObjReg2;
	int m_PgObjReg3;
	int m_SoundActReg0;
	int m_SoundActReg1;
	int m_SoundActReg2;
	int m_SoundActReg3;
	int m_SoundObjReg0;
	int m_SoundObjReg1;
	int m_SoundObjReg2;
	int m_SoundObjReg3;
	int m_CPUVal0;
	int m_CPUVal1;
	int m_CPUVal2;
	int m_CPUVal3;
	int m_CPUVal4;
	int m_CPUVal5;
	int m_CPUVal6;
	int m_CPUVal7;
	unsigned int m_HitStopTime;
	bool m_bSlowHitStop;
	unsigned int m_HitStopTimeMax;
	unsigned int m_HitStopTimeBySousai;
	unsigned int m_HitStopTimeReq;
	unsigned int m_HitStopTimeReqLevel;
	bool m_bHitStopTimeReqSlow;
	int m_UltimateReq_StopTime;
	int m_UltimateReq_StopTimeSelf;
	unsigned int m_UltimateReq_Flag;
	BG_TYPE m_BGType;
	int m_LandingHeight;
	OBJ_CBaseRelativePtr m_pParentPly;
	OBJ_CBaseRelativePtr m_pParentObj;
	OBJ_CBaseRelativePtr m_pTargetObj;
	OBJ_CBaseRelativePtr m_pLinkObject_PushCollision;
	OBJ_CBaseRelativePtr m_pLinkObject_Angle;
	OBJ_CBaseRelativePtr m_pLinkObject_Position;
	OBJ_CBaseRelativePtr m_pLinkObject_Direction;
	OBJ_CBaseRelativePtr m_pLinkObject_DamageToEliminate;
	OBJ_CBaseRelativePtr m_pLinkObject_ChangeToEliminate;
	OBJ_CBaseRelativePtr m_pLinkObject_Stop;
	OBJ_CBaseRelativePtr m_pLinkObject_PositionCenter;
	OBJ_CBaseRelativePtr m_pLinkObject_Scale;
	OBJ_CBaseRelativePtr m_pLinkObject_Z;
	OBJ_CBaseRelativePtr m_pLinkObject_Collision;
	OBJ_CBaseRelativePtr m_pLinkObject_Color;
	OBJ_CBaseRelativePtr m_pLinkObject_MaterialSet;
	OBJ_CBaseRelativePtr m_pLinkObject_CmnMaterialParam;
	OBJ_CBaseRelativePtr m_pPrevChild;
	OBJ_CBaseRelativePtr m_pTrialObj;
	OBJ_CBaseRelativePtr m_pChildStack[9];
	unsigned int m_ActionFlag;
	unsigned int m_ActionFlag2;
	unsigned int m_CollisionFlag;
	unsigned int m_CollisionFlag2;
	unsigned int m_CollisionFlag3;
	unsigned int m_Direction;
	int m_PosX;
	int m_PosY;
	int m_PosZ;
	int m_AngleDeg_x1000;
	int m_AngleXDeg_x1000;
	int m_AngleYDeg_x1000;
	int m_AngleSpeed;
	int m_ScaleX;
	int m_ScaleY;
	int m_ScaleZ;
	int m_ScaleSpeedX;
	int m_ScaleSpeedY;
	int m_ScaleSpeedZ;
	int m_TransformCenterX;
	int m_TransformCenterY;
	int m_DrawOffsetX;
	int m_DrawOffsetY;
	int m_BoundRate;
	int m_PushPosX;
	int m_PushPosY;
	int m_PushPosZ;
	int m_PushSpeedX;
	int m_PushSpeedY;
	int m_PushSpeedZ;
	int m_PushGravity;
	int m_PushAcceleration;
	int m_PushAccelerationZ;
	int m_PushInertia;
	float m_ZVal;
	int m_ZLineNearMultiplier;
	FREDAudioHandle m_ActAudioHandle[16];
	int m_OldPosX;
	int m_OldPosY;
	int m_CalcTmpPosX;
	int m_CalcTmpHitBackX;
	int m_ObjShakeXTime;
	int m_ObjShakeXDot;
	int m_Inertia;
	int m_InertiaTime;
	int m_SpeedX;
	int m_SpeedY;
	int m_Gravity;
	int m_Acceleration;
	int m_SpeedZ;
	int m_AccelerationZ;
	int m_SpeedTimeLimit;
	int m_SpeedRateX;
	int m_HitBackX;
	int m_HitBackXModoshi;
	int m_WallPushBack;
	int m_WallPushBackAPBefore;
	int m_PushColWidth;
	int m_PushColHeight;
	int m_PushColHeightLow;
	int m_PushColWidthFront;
	unsigned int m_WallTouchTime;
	int m_FrameMoveX;
	int m_FrameMoveY;
	int m_FrameMoveYCalc;
	int m_FrameMoveZ;
	int m_NamerakaMoveX;
	int m_PassiveMoveX;
	int m_PassiveMoveY;
	CColorWithSpeed m_MltColor;
	CColorWithSpeed m_HkrColor;
	int m_PushScreenOffsetFront;
	int m_PushScreenOffsetBack;
	int m_PushScreenOffsetTop;
	int m_PushScreenOffsetBottom;
	int m_YogoreLevel;
	int m_Weight;
	uint8 m_WhiteFlashCount;
	uint8 m_WhiteCount;
	uint8 m_RedFlashCount;
	uint8 m_RedCount;
	uint8 m_BlueFlashCount;
	uint8 m_BlueCount;
	uint8 m_WhiteAuraCount;
	uint8 m_RedAuraCount;
	uint8 m_GreenAuraCount;
	uint8 m_GreenFlashCount;
	uint8 m_YellowAuraCount;
	uint8 m_YellowFlashCount;
	uint8 m_EtcAuraCount;
	unsigned int m_EtcAuraColor;
	OBJ_CBaseRelativePtr m_pAttackSlave[10];
	OBJ_CBaseRelativePtr m_pLockLinkObj;
	OBJ_CBaseRelativePtr m_pAttackSlaveNewest;
	int m_AttackSlaveCount;
	int m_AttackObjectMax;
	CAtkParam m_AtkParam;
	CAtkParamEx m_AtkParamNH;
	CAtkParamEx m_AtkParamCH;
	OBJ_CBaseRelativePtr m_pAttackMaster;
	OBJ_CBaseRelativePtr m_pHitBackMaster;
	OBJ_CBaseRelativePtr m_pColorParent;
	OBJ_CBaseRelativePtr m_pAttackMasterPlayer;
	CAtkParam m_DmgParam;
	CAtkParamEx m_DmgParamEx;
	HIT_TYPE m_DmgHitType;
	unsigned int m_DmgHitTypeFlag;
	int m_DmgBaseDirection;
	unsigned int m_bIsCounterHit;
	uint8 m_SpecialGuardIsKezuri;
	int m_ExMutekiTime;
	int m_MutekiNageTime;
	int m_MutekiDagekiTime;
	unsigned int m_MutekiFlag;
	SG_TYPE m_MutekiType;
	uint8 m_MutekiLevel;
	int m_MutekiHitStopSelf;
	int m_MutekiHitStopEnemy;
	int m_MutekiDamageRate;
	int m_MutekiAtkLevel;
	bool m_MutekiKezuri;
	int m_MutekiForceTime;
	int m_DisableChangeTime;
	float m_HitPosX;
	float m_HitPosY;
	int m_HitPoint;
	int m_HitPointMax;
	int m_RecoverHitPoint;
	int m_HitPoint_x1000;
	int m_RecoverBlueHitPoint;
	int m_RecoverBlueHitPointTime;
	int m_DistortionLevel;
	int m_DistortionLevelSpeed;
	uint8 *m_pMultiBufferLarge;
	uint8 *m_pMultiBufferSmall;
	AA_Flag<unsigned int> m_ValidInterruptFlag[5][4];
	CBBSFileAnalyzeData *m_pBBSFile;
	uint8 *m_TopAddr;
	uint8 *m_CurAddr;
	uint8 *m_CurActionTopAddr;
	CXXBYTE<32> m_CellName;
	int m_CellTime;
	int m_CellTimeReserve;
	int m_CellTimeMax;
	int m_CellBeginCount;
	int m_CellNoStopCellNum;
	CXXBYTE<32> m_CellNoStopCellNameList[6];
	int m_CellNoStopCellFrameList[6];
	int m_CellNoStopCellCurIndex;
	int m_CellNoStopCellCurFrame;
	bool m_bCellUpdated;
	CInterruptInfo m_InterruptInfo[104];
	uint8 *m_TmpArgAddr;
	CXXBYTE<32> m_PreActionName;
	CXXBYTE<32> m_CurActionName;
	CXXBYTE<32> m_ParentActionName;
	OBJ_CBaseRelativePtr m_pControlObject;
	bool m_IfReturnVal;
	bool m_IsCellTimeStop;
	bool m_CellTimeStopOnece;
	CActionRequestInfo m_ActionRequestInfo;
	CActionRequestInfo m_ActionRequestInfoReg;
	OBJ_CBaseRelativePtr m_pIgnoreDispOnlyMeObject;
	int m_DamageEffectCount;
	int m_PoisonTime;
	unsigned int m_PoisonTimeLoop;
	int m_PoisonDamage;
	unsigned int m_PlayerActionChangeIdOnCreate;
	uint8 m_AstralCameraTimer;
	uint8 m_AstralCameraRate;
	int m_ShotDamageRate;
	int m_DodgeEffectTimer;
	CVoiceInfo m_VoiceInfo;
	int m_EyeBlinkCounter;
	C256BYTE m_MouthString;
	int m_MouthStringIndex;
	uint8 m_MouthChar;
	int m_MouthCharTime;
	int m_MouthPauseTime;
	int m_MouthVoiceTime;
	bool m_KowareDone;
	int m_KowareCur;
	int m_KowareMax;
	int m_KowareOnEnemyDamage;
	int m_KowareOnEnemyGuard;
	int m_KowareOnObjectHit;
	int m_KowareOnSousai;
	int m_KowareOnDamageCollision;
	int m_KowareTenmetsuTime;
	int m_KowareOnDamageOnly;
	int m_YukkuriSpeedPer;
	int m_YukkuriSpeedX;
	int m_YukkuriSpeedY;
	CExHoming m_ExHoming;
	CJumpHoming m_JumpHoming;
	int m_DebugActionChangeCount;
	int m_SlowSeigyo;
	int m_ScreenAdditionalWidth;
	int m_ScaleForLink;
	int m_ScaleForLinkX;
	int m_ScaleForLinkY;
	int m_ScaleForLinkZ;
	int m_MaxHit;
	int m_ExPointFX;
	int m_ExPointFY;
	int m_AttackerHoseiMemory;
	int m_AttackerHoseiMemoryTypeHistory;
	int m_VeBallAngle;
	int m_VeBallPower;
	unsigned int m_VeBallFlag;
	unsigned int m_ObjSkillForceDisableFlag;
	unsigned int m_HideFlag;
	int m_PerSpeedXEveryFrame;
	int m_PerSpeedYEveryFrame;
	int m_IgnoreSpeedTime;
	sSoundReq m_SoundReq;
	uint16 m_DiffusionFilter2Level;
	uint16 m_DiffusionFilter2Saturation;
	int m_SuikomiRange;
	int m_SuikomiRangeGensui;
	int m_SuikomiItem;
	int m_SuikomiPlayer;
	int m_SuikomiEnemy;
	int m_Suikomare;
	int m_SuikomareYRate;
	int m_SuikomareLandRate;
	bool m_SuikomareIsReFloating;
	int m_OilRange;
	int m_OilMoveX;
	CCreateArg m_CreateArg;
	CCreateArg m_CreateArgFromParent;
	ATKTGT m_AttackTarget;
	CXXBYTE<32> m_CellForNotFound;
	int m_AttackHitUniqID;
	int m_DamageHitUniqID;
	int m_ReAttackCallCount;
	CVectorWithTimer m_DramaMatParam;
	int m_FirstHitDamageHoseiRate;
	bool m_KowareDispGauge;
	int m_KowareDispOffsetX;
	int m_KowareDispOffsetY;
	int m_KowareDispWidth;
	bool m_AttackLandStart;
	int m_SuikomiPowerX;
	int m_SuikomiPowerY;
	int m_SuikomiHitRateX;
	int m_SuikomiHitRateY;
	int m_SuikomiGuardRateX;
	int m_SuikomiGuardRateY;
	int m_SuikomiOffsetX;
	int m_SuikomiOffsetY;
	int m_SuikomiTargetX;
	int m_SuikomiTargetY;
	int m_PosXOnActivate;
	int m_PosYOnActivate;
	int m_PosZOnActivate;
	CFloatWithTimer m_PawnSaturation;
	CFloatWithTimer m_ForceExOutlineOn;
	CFloatWithTimer m_MaterialVal[29];
	float m_MaterialVal_Default[29];
	bool m_bMaterialValResetOnActionChange[29];
	CXXBYTE<32> m_MaterialSetOnPlayAnime;
	bool m_bLinkMaterialParticle;
	uint16 m_MotionBlurAmount;
	int m_FaceBrowIndex;
	int m_FaceEyeIndex;
	int m_FaceMouthIndex;
	CXXBYTE<32> m_HairMotionName;
	CXXBYTE<32> m_SignalName;
	int m_SignalName_Param;
	AREDPawn *m_pPawn;
	CXXBYTE<32> m_PawnName;
	UParticleSystemComponent *m_pLinkPSC;
	CXXBYTE<32> m_LinkPSCSocketName;
	bool m_LinkPSCSocketRot;
	OBJ_CBaseRelativePtr m_pLinkObject_PSCSocket;
	AREDDestructionShotObject *m_pLinkDestructionActor;
	bool m_AttachPawnToSocket;
	long double m_BaseLocalTime;
	__int16 m_AtkForBGEffectDoneCount;
	int m_BGFadeSpeed;
	int m_BGFadeAlpha;
	bool m_EnableForceEffectX;
	bool m_EnableForceMoveX;
	bool m_EnableForceEffectY;
	bool m_EnableForceMoveY;
	int m_InnerForceEffectRate;
	int m_OuterForceEffectRate;
	int m_ReceiveForceX;
	int m_ReceiveForceY;
	bool m_bFaceBrowChanged;
	bool m_bFaceEyeChanged;
	bool m_bFaceMouthChanged;
	int m_LastChangeFace;
	bool m_bHairChanged;
	bool m_bLinkPause_PSC;
	bool m_DispModel;
	bool m_DispModelByOther;
	FBoneController m_BoneCtrl;
	bool m_StepAnimeMode;
	bool m_AutoResetAnimeMode;
	bool m_bOverwriteLightDir;
	int m_OverwriteLightDirX;
	int m_OverwriteLightDirY;
	float m_DepthDarken;
	POS_TYPE m_SocketPosType;
	bool m_bUpdateSocketPos;
	int m_PlayAnimeFaceIndex;
	bool m_CameraOption_UpdateOrthoBlend;
	ON_XXXX_INTRPT m_NaguruSignal;  int m_L;
	int m_R;
	int m_T;
	int m_B;
	int m_XForCalc;
	int m_YForCalc;
	SCellBlendParam m_CellBlendParam;
	SCellSlow m_CellSlow;
	SCellSlowParam m_CellSlowDefaultParam;
	SExBlendParam m_ExBlendParam[4];
	int m_LinkExBlendIndex;
	ON_XXXX_INTRPT m_ExecutionInterrupt;
	FInterruptStack m_InterruptStack;
	unsigned int m_ScriptFlag;
	uint8 *m_ScriptGotoAddr;
	uint8 *m_GotoForLoopAddr;
	int m_GotoTimes;
	SDispWithoutMove m_DispWithoutMove;
	bool m_ResetOverwriteLinkBoneOnActionChange;
	SRollbackData m_RollbackData;
	bool m_bPlayAnimForRollback;
	float m_LinkParticleStartTime;
	int m_LinkParticleActiveFrame;
	SRollbackMeshControl m_RollbackMeshControl[50];
	int m_RollbackMeshControlNum;
	int ObjBaseSyncEnd;
	bool bLinkPSCWasDeleted = true;
	AA_Handle m_hResource;
	CXXBYTE<32> m_StatisticsActionName;
	StatisticsCheckSkillData m_StatisticsCheckSkill[108];

	//functions
	void ObjectConstructor_ForObject();
	void SetHitPointMax(int val);
	void SetHitPoint(int val);
	void SetupPawn();
	void ResetScreenPushOffset();
	int GetPushColW();
	int GetPushColH();
	int GetPushColHLow();
	int GetPosX();
	int GetPosY();
	int GetAngleY();
	int GetObjDir();
	void GetPushScreenRect(int *L, int *T, int *R, int *B);
	void GetPushWorldRect(int *L, int *T, int *R, int *B);
	void GetPushWorldRectForWorldClip(int *L, int *R);
};
