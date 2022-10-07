#pragma once
#include "OBJ_CBase.h"
#include "DataTypes/AA_EasyHash.h"
#include "DataTypes/AA_EasyMap.h"
#include "DataTypes/CCPUInfo.h"
#include "DataTypes/CSkillInfoList.h"

struct FREDBattleBGClashInfoSub;
class CSkillInfo;

struct FDamageCellEX
{
	CXXBYTE<32> DamageCellExName;
	CXXBYTE<32> ExCellName;
};

struct __declspec(align(4)) GAME_CCockpitEXGage
{
	unsigned int m_IconID;
	unsigned int m_SplitNum;
	int m_MaxVal;
	int m_Val;
	float m_DotWidth;
	unsigned int m_Color;
	unsigned int m_MaxColor;
	unsigned int m_EXGFlag;
	bool m_Active;
};

class OBJ_CCharBase : public OBJ_CBase
{
public:
	enum EChangeRequestCategory
	{
		CRC_EnterCutscene = 0x0,
		CRC_EnterNormal = 0x1,
		CRC_EnterAttack = 0x2,
		CRC_EnterAttackUltimate1 = 0x3,
		CRC_EnterAttackUltimate2 = 0x4,
		CRC_AssistAttack = 0x5,
		CRC_AssistAttackUltimate = 0x6,
		CRC_GuardCancelEnterAttack = 0x7,
		CRC_AssistAttackReady = 0x8,
		CRC_EnterNormalReady = 0x9,
		CRC_EnterAttackReady = 0xA,
		CRC_EnterAttackUltimate1Ready = 0xB,
		CRC_EnterAttackUltimate2Ready = 0xC,
		CRC_GuardCancelEnterAttackReady = 0xD,
		CRC_None = 0xE,
	};
	
	enum RCAS_STATE
	{
		RCAS_1ST = 0x0,
		RCAS_2ND = 0x1,
		RCAS_3RD = 0x2,
	};

	struct VSCharMouthTable
	{
		ECharaID m_id;
		AA_EasyMap<CXXBYTE<16>,CXXBYTE<128>,32,1> m_mouthTable;
	};

	struct __declspec(align(4)) FEntrySubMemberDispInfo
	{
		int x;
		int y;
		int z;
		bool bDispOn;
	};

	struct __declspec(align(4)) FVoiceSetting
	{
	  VOICE_TYPE Type;
	  char RandomNum;
	  char PlayPercent;
	};
	
	struct __declspec(align(4)) HomingDashData
	{
		int startSpeed;
		int updateSpeedRate;
		int startAngleOffset;
		int homingRate;
		int updateHomingRate;
		int startTime;
		int searchTime;
		int homingTimeMax;
		bool bFinishToBrake;
	};

	struct __declspec(align(4)) HomingDashWork
	{
		int speed;
		int targetAngle;
		int lastAngleType;
		int homingTime;
		int homingTimeMax;
		bool bNeedCreateEffect;
		bool bNeedChangeEffectAngle;
		bool bHomingDoing;
		bool bHomingEffectAngleInit;
		bool bCollision;
	};

	struct __declspec(align(4)) MikiwameMoveWork
	{
		int m_StopTime;
		int m_StopTimeEnemyDamage;
		int m_TensionPenaltyRate;
		int m_TensionPenaltyTime;
		int m_TensionPenaltyTimeMax;
		bool m_bForceFinish;
	};
	
	/* 322775 */
	struct ExtendJonParam
	{
		CXXBYTE<32> m_tag;
		TEnumAsByte<enum EXTEND_JON_TYPE> m_ExJonType;
		_CTYPE m_JonBehavior;
		int m_ColX;
		int m_ColY;
		int m_ColW;
		int m_ColH;
	};
	
	struct __declspec(align(4)) StatusIconInfo
	{
		STATUS_ICON m_IconID;
		bool m_bEffectDoing;
		bool m_bDispInfo;
	};
	
	struct SAnimBPParam
	{
		struct SSpeedParam
		{
			float Val;
			float InternalVal;
			float Speed;
			float MaxVal;
			int Interval;
			int Counter;
		};
		TBlendParam<float> m_BlendParam[4];
		SSpeedParam m_Val[4];
		bool m_FreeFlag[4];
	};

	struct ArcadeEnemyParam
	{
		bool m_bValid;
		int m_Atk;
		int m_HP;
		int m_Tension;
		int m_Lv;
	};
	
	int CharBaseSyncBegin;
	unsigned int m_PlayerFlag;
	unsigned int m_PlayerFlag2;
	unsigned int m_PlayerFlag3;
	unsigned int m_PlayerFlag4;
	unsigned int m_PlayerFlag5;
	unsigned int m_PlayerFlagTrial;
	unsigned int m_CtrlDir;
	unsigned int m_EnableFlag;
	unsigned int m_Enable2Flag;
	unsigned int m_EnableFlagPreAction;
	unsigned int m_AttackFlag;
	unsigned int m_AttackFlag2;
	long double m_LocalWorldTimer;
	int m_GuardStopCount;
	int m_AirJumpCount;
	int m_AirDashCount;
	int m_AirDashTimer;
	int m_AirDashTimerMax;
	int m_AirDashGravity;
	VSCharMouthTable m_VsCharMouthTable[3];
	int m_VsCharMouthTableIdx;
	int m_IgnoreSkillTime;
	int m_StunCount;
	int m_StunCountZeroTimer;
	int m_LockWaitTime;
	int m_StunCountMax;
	unsigned int m_ChangeDir;
	int m_ChangeHeight;
	int ply_FWalkSpeed;
	int ply_BWalkSpeed;
	int ply_FDashStartSpeed;
	int ply_BDashXSpeed;
	int ply_BDashYSpeed;
	int ply_BDashGravity;
	int ply_FJumpXSpeed;
	int ply_BJumpXSpeed;
	int ply_JumpSpeed;
	int ply_JumpGravity;
	int ply_FHighJumpXSpeed;
	int ply_BHighJumpXSpeed;
	int ply_HighJumpSpeed;
	int ply_HighJumpGravity;
	int ply_FDashAccelSpeed;
	int ply_FDashReduce;
	int ply_HomingJumpMaxYSpeed;
	int ply_HomingJumpMaxXSpeed;
	int ply_HomingJumpXReduce;
	int ply_HomingJumpYOffset;
	int ply_AirDashHeightLimit;
	int ply_AFDashTime;
	int ply_ABDashTime;
	int ply_Kizetsu;
	int ply_Defence;
	int ply_Guts;
	int ply_Critical;
	int ply_DamageWeight;
	int ply_AirDashCountMax;
	int ply_AirJumpCountMax;
	int ply_AirFDashNoAttackTime;
	int ply_AirBDashNoAttackTime;
	int ply_FWalkTension;
	int ply_FJumpTension;
	int ply_FDashTension;
	int ply_AirFDashTension;
	int ply_GBDefence;
	int ply_GBRecover;
	int ply_JGTension;
	int ply_AFDashStartSpeed;
	int ply_ABDashStartSpeed;
	int ply_PushColWidthStand;
	int ply_PushColHeightStand;
	int ply_PushColWidthCrouch;
	int ply_PushColHeightCrouch;
	int ply_PushColWidthAir;
	int ply_PushColHeightAir;
	int ply_PushColHeightLowAir;
	int ply_NearSlashRange;
	int ply_JumpMotionFrame_v_up;
	int ply_JumpMotionFrame_v_dn;
	int ply_JumpMotionFrame_f_up;
	int ply_JumpMotionFrame_f_dn;
	int ply_JumpMotionFrame_b_up;
	int ply_JumpMotionFrame_b_dn;
	unsigned int ply_PlayerPrivateFlag;
	int ply_HomingJumpYOffset_RED;
	int ply_JumpLandingStiffFrame;
	CHARSHOES_TYPE ply_ShoesType;
	int ply_LandingStiffTime;
	int ply_LandingStiffTimeTmp;
	int ply_LandingStiffTimeForKy;
	int ply_NegativeAnti;
	bool ply_ForceNormalDemoAction;
	int ply_CPUYowameruRate;
	int ply_CPUTokuiKyori;
	int ply_CPUTokuiKyoriKodawari;
	int16 ply_TBalanceExec;
	int16 ply_TBalanceFWalk;
	int16 ply_TBalanceFJump;
	int16 ply_TBalanceFDash;
	int16 ply_TBalanceFAirDash;
	int16 ply_TBalanceBWalk;
	int16 ply_TBalanceBJump;
	int16 ply_TBalanceBDash;
	int16 ply_TBalanceBAirDash;
	int16 ply_TBalanceAtkHit[5];
	int16 ply_TBalanceAtkHitGuard;
	int16 ply_TBalanceGuard[5];
	int16 ply_TBalanceJGuard[5];
	int16 ply_TBalanceNoTouch;
	int16 ply_TBalanceNoTouchTime;
	int16 ply_TBalanceSide;
	int16 ply_TBalanceSideTime;
	int16 ply_NegativeExec;
	int16 ply_NegativeBWalk;
	int16 ply_NegativeBJump;
	int16 ply_NegativeBDash;
	int16 ply_NegativeBAirDash;
	int16 ply_NegativeNoTouch;
	int16 ply_NegativeNoTouchTime;
	int16 ply_NegativeSide;
	int16 ply_NegativeSideTime;
	int16 ply_TBalanceMagnify[10];
	int16 ply_NegativeMagnify[10];
	int16 ply_DistanceThreshold[3];
	int16 ply_TBalanceDistanceMagnify[3];
	int16 ply_NegativeDistanceMagnify[3];
	int16 ply_PositiveBonus;
	int16 ply_PositiveTPenalty;
	int16 ply_NegativeWarning;
	int16 ply_NegativeWarningTension;
	int16 ply_NegativeTensionPenalty;
	int16 ply_NegativeTensionBalance;
	int16 ply_GuardTension[5];
	int16 ply_BarrierGuardStop;
	int16 ply_BarrierGuardStopAir;
	int16 ply_BarrierGuardTension[5];
	int16 ply_BarrierGuardTensionShotPer;
	int16 ply_BarrierUseTension;
	int16 ply_BarrierUseTensionAir;
	int16 ply_BarrierAirSpeedX;
	int16 ply_BarrierAirSpeedY;
	int16 ply_BarrierGravity;
	int16 ply_CDT_Assist;
	int16 ply_CDT_Change;
	int16 ply_CDT_UltimateChange;
	int16 ply_CDT_GuardCancelChange;
	int16 ply_CDT_ForceChange;
	int16 ply_CooldownHoseiTime;
	int16 ply_CDT_Inner;
	int ply_HPRecoverPerFrame;
	int ply_HPRecoverPerFrameInBurst;
	CHAR_PHYSIQUE ply_Physique;
	CHAR_ATTR_TYPE ply_AttrType;
	int ply_Weight;
	CXXBYTE<32> ply_DamageCell[57];
	FDamageCellEX ply_DamageCellEx[128];
	unsigned int m_ComboCount;
	unsigned int m_ComboBreakTime;
	unsigned int m_ComboCountAddTime;
	unsigned int m_ComboCountAddTimeWithStop;
	int m_ComboDamage;
	int m_ComboDamageFromBSCA;
	int m_ComboDamageTotal;
	int m_ComboDamageDisp;
	int m_ComboPreDamage;
	int m_ComboTime;
	int m_ComboTimeWithOutAnten;
	int m_ComboHoseiOnceDone;
	int m_ComboDamageRate;
	int m_ComboDamageRomanCancel;
	float m_ComboDamageRedF01;
	unsigned int m_OwnComboCount;
	CXXBYTE<32> m_ComboAcceptActionName;
	CXXBYTE<32> m_ComboLastDamageActionName;
	bool m_IsImperfectCombo;
	bool m_IsImperfectComboAddFlag;
	bool m_UkemiMiss;
	bool m_NagenukeMiss;
	bool m_ComboNoDie;
	int m_ImperfectComboLog[3];
	int m_KizetsuPoint;
	int m_KizetsuMax;
	int m_KizetsuTime;
	int m_KizetsuTimeMax;
	int m_KizetsuDecForTutorial;
	int m_GuardSustain;
	int m_GuardOshikomareSustain;
	int m_GuardOshikomareCount;
	int m_ThrowResistTime;
	int m_LockRejectInputTime;
	int m_LockRejectDisableTime;
	bool m_LockRejectIsRenda;
	int m_JustGuardAutoKeyBackTime;
	int m_TensionVal;
	int m_TensionLimitTime;
	bool m_IsOldBarrier;
	int m_AccelVal;
	int m_KeyBackMaintain;
	int m_GuardDirectionWithMekuri;
	int m_MekuriMaintain;
	bool m_IamLeft;
	bool m_IamLeftPrev;
	ID_CMNACT m_CurCommonActionID;
	uint8 m_InpFlag[2][324];
	int m_BtnLastTrgCount[8];
	int m_BtnLastTrgOffCount[8];
	int m_BtnHoldCount[8];
	int m_BtnRendaCount[8];
	int m_BtnRendaAddTime[8];
	int m_UkemiBtnTime;
	int m_BtnHoldCountWithoutGuard[8];
	uint8 m_PreFRCInput;
	uint8 m_PreTenkey;
	uint8 m_DashTime1st[2];
	uint8 m_DashTime2nd[2];
	uint8 m_DashChangeTenkey[2];
	uint8 m_JustGuardInputTime[2];
	uint8 m_JustGuardPenaltyTime[2];
	uint8 m_PreTenkeyEasy;
	uint8 m_DashTime1stEasy[2];
	uint8 m_DashTime2ndEasy[2];
	uint8 m_DashChangeTenkeyEasy[2];
	int m_stylishComboCount;
	int m_PrivateVal[8];
	int m_SkillCheckBit;
	int m_ChargeShotVal[4];
	uint8 m_CameraComboOnce[10];
	uint8 m_RendaSmashStartType[3];
	uint8 m_RendaSmashType[3];
	int m_DemoTimer;
	GAME_CCockpitEXGage m_ExGage[5];
	int m_DashInputKeepTime;
	int m_PlayerAttackRate;
	int m_PlayerDefenceRate;
	int m_CharacterAddAttackRate;
	int m_CharacterAddDefenceRate;
	int m_PlayerCrushRate;
	int m_PlayerTensionRate;
	int m_SousaiCancelTime;
	int m_ReactionWait;
	CXXBYTE<32> m_TmpLabel;
	int m_AirTimer;
	int m_DamageColX;
	int m_DamageColY;
	int m_DamageColW;
	int m_DamageColH;
	unsigned int m_ActionRequestFlagForJumpTmp;
	HACT_HitAction m_HitAction;
	ADAT_TYPE m_AirDamageAngleType;
	int m_SkyDashCorrect;
	int m_BackStepInvalidTime;
	int m_BoundReadyTime;
	int m_ExKizetsu;
	int m_RomanCancelRsvSpeedX;
	int m_LongSenkoInputActiveTime;
	int m_LongSenkoInputActiveTimeForDust;
	bool m_LongSenkoInputActiveOnCurAction;
	int m_OldPosXDebug;
	int m_OldPosYDebug;
	int m_AttackTimeDebug;
	int m_DustHomingTime;
	int m_DustHomingSubTime;
	int m_DustBoundTime;
	int m_NewDustHomingTime;
	int m_CmnActObjReg0;
	int m_CmnActObjReg1;
	int m_CmnActObjReg2;
	int m_CmnActObjReg3;
	int m_CmnActObjReg4;
	int m_CmnActObjReg5;
	int m_CmnActObjReg6;
	int m_CmnActObjReg7;
	int m_ForceRomanCancelYoyakuTimer;
	int m_ForceRomanCancelTimer;
	int m_ForceRomanCancelDoneTimer;
	int m_ForceRomanCancelIgnoreTimer;
	int m_NandemoCancelTime;
	int m_ExPointForPGX;
	int m_ExPointForPGY;
	int m_GuardBalance;
	int m_GuardBalanceStopTime;
	int m_GuardBalanceMaxTime;
	unsigned int m_TmpSkillForceDisableFlag;
	CSkillInfo *m_LastSkillAttackPtr;
	int m_AttackLastHitTime;
	CXXBYTE<16> m_CommonVoiceTable[120];
	int m_SlowTime;
	int m_SlowTimeBySC;
	int m_RomanCancelEndTime;
	int m_RomanCancelEndTimeByAttack;
	int m_RomanCancelEndTimeByAttackTmp;
	int m_RomanCancelBattenTime;
	int m_IchigekiGage;
	CXXBYTE<32> m_JimakuName;
	int m_JimakuTime;
	int m_JimakuForceTime;
	int m_JimakuBGTime;
	int m_DemoEnd_YoinTime;
	CXXBYTE<32> m_EntryActionNameSelf;
	CXXBYTE<32> m_EntryActionNameEnemy;
	CXXBYTE<32> m_EntryActionNameReady;
	int m_HeliumTime;
	int m_GTmpReg[8];
	int m_JitabataHitStopHendou;
	int m_BurstYomiTime;
	int m_ComboVoiceSpeakingTimer;
	int m_ComboVoiceUkemiWait;
	int m_ComboVoiceReadyTimer;
	int m_JumpCancelSenkoActiveTime;
	CXXBYTE<32> m_MeshSetNameExchangeTable[20];
	CXXBYTE<32> m_AnimeNameExchangeTable[8];
	float m_HitPointLengthDispMaxF01;
	int m_AirJumpTime;
	bool m_AirJumpFlyMOM;
	int m_WinActionButton;
	int m_TrainingValue;
	int m_GGBlockingOKTime;
	int m_GGBlockingIgnoreTime;
	int m_ThrowInputTime;
	int m_NoNagenukeTime;
	int m_HomingDashTsuigekiTime;
	int m_DokiDokiStopTime;
	int m_DokiDokiStopDamage;
	unsigned int m_TimeWithoutAnten;
	int m_DustHomingDash2HoseiBase;
	int m_DustHomingDash2HoseiUntilBound;
	int m_NearSlashObjectDistance;
	int m_RedRomanCancelTime;
	int m_FaultlessDefenceDisableTime;
	int m_SlowRate;
	int m_HitPointRecover;
	int m_HitPointRecoverStopTime;
	int m_TrainingHPRecoverWait;
	int16 m_SenkoInputNormal;
	int16 m_SenkoInputSpecial;
	int16 m_SenkoInputUltimate;
	int m_DeadCounter;
	int m_DmgColCounter;
	int m_AssistAttackPosZ;
	int m_JumpDir;
	uint8 m_CmdSuccessInAnten;
	uint8 m_DownFromSlideDown;
	int m_WorldSideBreakPoint;
	int m_CmnCharaReg[24];
	int m_CmnCharaActReg[8];
	int m_DamageActionCount;
	int m_FuwafuwaDownTimer;
	CXXBYTE<32> m_DamageTransferInterruptFunc;
	int m_RedRCTime;
	uint16 m_WSBEstimateDamage;
	CXXBYTE<32> m_ComboSameNameStack[100];
	int m_SameAttackGravity;
	int m_BoundAddGravity;
	CAtkParam m_AtkParamForGGThrowStack;
	CAtkParamEx m_AtkParamCHForGGThrowStack;
	CAtkParamEx m_AtkParamNHForGGThrowStack;
	int m_TensionBalance;
	int m_TensionPenaltyTime;
	int m_BurstPenaltyTime;
	int m_TensionGG;
	int m_TensionGGUseDisp;
	int m_BurstLog;
	int m_TensionNoTouchTime;
	int m_NegativeVal;
	int m_TensionMovePenaltyTime;
	int m_TensionSideTime;
	FEntrySubMemberDispInfo m_EntrySubMemberDispInfo[2];
	FVoiceSetting m_VoiceSettingTable[100];
	bool m_Entry;
	bool m_EntryBattle;
	bool m_EntryBattleDoing;
	bool m_LeaveRequest;
	bool m_LeaveRequestImm;
	EChangeRequestCategory m_ChangeRequestCategory;
	bool m_Win;
	CXXBYTE<32> m_DefaultMeshSet;
	CXXBYTE<32> m_WinCameraObjName;
	int16 m_CooldownTime;
	int16 m_CooldownTimeMax;
	int16 m_InnerCooldownTime;
	bool m_bFullCooldownTime;
	bool m_bPlayReadySE;
	int m_ResultWinPos;
	bool m_isAddUltimateChangeCommand;
	EMemberID m_callingChar;
	EMemberID m_calledChar;
	HomingDashData m_HomingDashData;
	HomingDashWork m_HomingDashWork;
	int m_HomingDashCount;
	int m_HomingDashCountMax;
	bool m_bChangeHomingDash;
	bool m_bGCHomingDash;
	MikiwameMoveWork m_MikiwameMoveWork;
	int m_MikiwameMoveCount;
	int m_MikiwameMoveCountMax;
	uint8 m_MikiwameMoveCancelAvailable;
	uint8 m_MemberChangeUltimateAvailable;
	OBJ_CBaseRelativePtr m_SparkingAuraObj[13];
	OBJ_CBaseRelativePtr m_SocketParticleObj[13];
	uint8 m_AtkSkillHistory[3][100];
	int m_AtkSkillHistoryIndex[3];
	FREDAudioHandle m_PlyAudioHandle[16];
	FREDAudioHandle m_NativeAudioHandle[16];
	TEnumAsByte<RCAS_STATE> m_RomanCancelAttackState;
	TEnumAsByte<RCU_TYPE> m_RomanCancelUseType;
	TEnumAsByte<ICHIGEKI_STATE> m_IchigekiState;
	TEnumAsByte<ICHIGEKI_STATE> m_IchigekiStateTmp;
	TEnumAsByte<EATYPE> m_EntryActionType;
	TEnumAsByte<CHARSHOES_TYPE> m_TmpShoesType;
	int m_IsAfro;
	int m_IsCreateAfroObj;
	ExtendJonParam m_ExtendJon[4];
	int m_ExtendJonNum;
	StatusIconInfo m_StatusIconInfos[5];
	CXXBYTE<32> m_Statistics_EnemyComboStartActName;
	int m_Statistics_EnemyComboActionNum;
	int m_Statistics_AirJumpNum;
	int m_Statistics_AirDashNum;
	SAnimBPParam m_AnimBPParam;  bool m_bBGClashEvent;
	FREDBattleBGClashInfoSub *m_pBGClashEventInfo;
	int CharBaseSyncEnd;
	CXXBYTE<16> m_CharName;
	CXXBYTE<16> m_CharNameForVoice;
	int m_VoiceCond_MyHP[10];
	int m_VoiceCond_OpponentHP[10];
	bool m_VoiceCond_OpponentCharaEnable[10];
	bool m_VoiceCond_OpponentChara[10][32];
	VAR_Type m_VoiceCond_Var[10];
	ArcadeEnemyParam m_EnemyParam;
	CCPUInfo m_CPUInfo;
	CSkillInfoList m_SkillInfoList;
	AA_EasyHash<CXXBYTE<16>,120,480> m_CommonVoiceHash;
	AA_EasyHash<CXXBYTE<16>,100,400> m_VoiceSettingHash;
	AA_EasyHash<CXXBYTE<32>,20,80> m_MeshSetNameExchangeHash;
	AA_EasyHash<CXXBYTE<32>,600,2400> m_MeshSetCellHash;
	unsigned __int8 m_MeshSetCellTable[600];
	AA_EasyHash<CXXBYTE<32>,8,32> m_AnimeNameExchangeHash;
	AA_EasyMap<CXXBYTE<16>,CXXBYTE<128>,128,1> m_MouthTable;
	int m_GuardCountInGuardStopCount;
	unsigned int m_GuardBreakCount;
	int m_TrainingAutoBurstRandomCount;
	int m_TrainingAutoGuardCancelRandomCount;
	int m_TrainingAutoBurstDelayCount;
	int m_TrainingAutoGuardCancelDelayCount;
	int m_GuardLevelBonus;
};
