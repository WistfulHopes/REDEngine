#pragma once
#include "BATTLE_TeamManager.h"
#include "CBattleInputAnalyzer.h"
#include "OBJ_CBase.h"
#include "OBJ_CCharBase.h"
#include "DataTypes/AA_EasyHash.h"
#include "CBBSFileAnalyzeData.h"
#include "DataTypes/CBattleRecord.h"
#include "DataTypes/CMultiBuffer.h"

class AREDPawnPlayer;

struct FForceEffectInfo
{
	FVector Position;
	FVector Direction;
	float InnerForce;
	float OuterForce;
	float Radius;
	float InnerAngularForce;
	float OuterAngularForce;
};

class BATTLE_CObjectManager
{
public:
	struct __declspec(align(8)) FCommonPawn
	{
		AREDPawnPlayer *Pawn;
		bool bUsed;
	};
	
	struct SEventData
	{
		int MessageTime;
		bool bMessageSet;
		OBJ_CBase *pManagerObj;
		OBJ_CBase *pSpeakChara[4];
		int LipSyncFrame;
		bool bLipSyncFlag;
		bool bEnd;
		OBJ_CBase *pExChara[4];
		CXXBYTE<16> ExCharaID[4];
		OBJ_CBase *pLoadWaitObj;
	};
	
	struct __declspec(align(4)) SGameSpeedControlParam
	{
		int InFrame;
		int StayFrame;
		int OutFrame;
		int CurrentFrame;
		int InCurve;
		int OutCurve;
		int StartGameSpeed;
		int EndGameSpeed;
		int CurrentGameSpeed;
		int CurrentGameSpeedFrame;
		bool bRequestApplyParticle;
		bool bCurrentApplyParticle;
	};

	BATTLE_CObjectManager();
	
	BATTLE_TeamManager m_TeamManager[2];
	unsigned int m_BOMFlag;
	FINISH_BG m_FinishBG;
	int m_FinishAtk;
	bool m_FinishAssistAtk;
	WORLDSID_EBREAK_PATTERN m_WSBPattern;
	unsigned __int8 m_DragonBall;
	unsigned __int8 m_Wish;
	bool m_bARendaComplete;
	SIDE_ID m_lastGainedDBSide;
	OBJ_CBaseRelativePtr m_pShenlongSystem;
	TENSION_ADD_ACTION m_lastTensionAddAction;
	SIDE_ID m_CallShenlongSide;
	CBBSFileAnalyzeData m_BBSFileAnalyzeData[7][2];
	int m_ActiveObjectCount;
	int m_CreateChokugoObjectCount;
	int m_NoActiveObjectCount;
	int m_EtcActiveObjectCount;
	int m_ForceDeleteCount;
	OBJ_CBase *m_ObjPtrVector[107];
	OBJ_CBase *m_SortedObjPtrVector[107];
	OBJ_CBase *m_CreateChokugoObjPtrVector[107];
	unsigned int m_UsesObjPtrVectorNum;
	bool m_bDrawPlayerOutIcon;
	bool m_bForceDrawPlayerOutIcon;
	OBJ_CBaseRelativePtr m_OutIconSettingObj;
	int m_AttackHitUniqIDGen;
	unsigned int m_UniqIDGen;
	int m_AtkHitCount;
	unsigned int m_ActionChangeCount;
	bool m_WorldBlacker;
	bool m_bBackGroundStop;
	int m_FinishStopCount;
	int m_FinishStopCountMax;
	int m_OverrideFinishStopTime[2];
	int m_OverrideSlashUITime[2];
	FForceEffectInfo m_ForceEffectInfo[2];
	int m_ActiveForceEffectNum;
	OBJ_CBaseRelativePtr m_WorldStopper;
	int m_WorldStopTimer;
	int m_WorldStopTimerSelf;
	int m_WorldStopTimerMax;
	int m_WorldStopTimerSelfMax;
	int m_RoundTimer;
	unsigned int m_DrawTimer;
	CMultiBuffer<4,4> m_MultiBufferLarge;
	CMultiBuffer<4,4> m_MultiBufferSmall;
	int m_BurstVal[2];
	int m_MatchStaticValue0[2];
	int m_MatchStaticValue1[2];
	int m_Rakusyo[2];
	int m_YogoreLevel[2];
	int m_PreBurstVal[2];
	int m_PreMatchStaticValue0[2];
	int m_PreMatchStaticValue1[2];
	int m_PreRakusyo[2];
	int m_PreYogoreLevel[2];
	AREDPawnPlayer *m_pPlayerPawn[7];
	SIDE_ID m_WinnerSideID;
	FCommonPawn CommonPawns[12];
	SIDE_ID m_IchigekiBGMRequestSideID;
	CXXBYTE<32> m_IchigekiBGMName;
	bool m_IsForceReload;
	float m_FadeOut01;
	float m_BGFadeInSpeed;
	float m_BGFadeOutSpeed;
	float m_BGFadeAlpha;
	bool m_RequestFadeOut;
	bool m_bForceBGHide;
	unsigned int m_DisplayFadeColor;
	float m_DisplayFadeAdd;
	float m_DisplayFade01;
	int m_DisplayFadeRenderStage;
	bool m_bRequestDisplayFade;
	bool m_bDrawDisplayFade;
	CFloatWithTimer m_BGSaturation;
	AA_EasyHash<CXXBYTE<32>,200,800> m_CommonActionHash;
	int m_ShinSousaiTimer;
	int m_DiffusionFilter2LevelMax;
	int m_DiffusionFilter2SaturationMin;
	int m_FinishSlowTime;
	int m_MotionBlurAmount;
	SEventData m_EventData;
	bool m_OnlineTraining_IsSwitch;
	int m_OnlineTraining_IsSwitchHold[2];
	int m_OnlineTraining_SwitchCoolTime;
	bool m_OnlineTraining_IsResetDone;
	bool m_OnlineTraining_StartSideFrip;
	MAAI_TYPE m_OnlineTraining_StartPos;
	unsigned int m_OnlineTraining_Wins[2];
	CBattleInputAnalyzer m_BattleInputAnalyzer[6];
	int m_StartInputTimeAC15;
	ECharaID m_LastLoadedCharID[2];
	int m_EnvStylishDefence;
	int m_EnvStylishTension;
	int m_EnvStylishBurst;
	int m_EnvDokiDokiStop;
	int m_EnvDokiDokiStopHikitsuke;
	int m_EnvDokiDokiStopXRangeMin;
	int m_EnvDokiDokiStopXRangeMax;
	int m_EnvDokiDokiStopYRangeMax;
	int m_EnvDokiDokiStopHassei;
	int m_EnvDokiDokiStopFinishStop;
	int m_DokiDokiStopByDokiDokiKill;
	int m_DokiDokiStopIgnoreTime;
	bool m_bMOMItemDesc;
	bool m_bMOMLifeDesc;
	int m_TrialBossHP;
	int m_TrialBossHPMax;
	int m_TrialBossBarrier;
	int m_TrialExVal0;
	int m_TrialExVal1;
	int m_TrialExVal2;
	int m_TrialExVal3;
	unsigned int m_BattleCheckSumTimeCount;
	unsigned int m_BattleCheckSum;
	unsigned int m_BattleCheckSumErrorFound;
	unsigned __int8 m_BattleCheckSumErrorFoundList[2];
	unsigned int m_BOMRandomSeed;
	HANDICAP_TYPE m_BattleHandiCap[2];
	int m_YogoreLv[2][3];
	uint8 m_ComboCameraInfo[2][10];
	int m_EventVsVoiceRandomIndex;
	int m_EventVsVoiceNum;
	int m_EntryEventRandomValue[2][3];
	INPUT_DELAY_TYPE m_delayType;
	int m_delayReserve;
	CBattleRecord m_BattleRecord;
	int m_DustSpeedX;
	int m_DustSpeedY;
	float m_ParticleSpeed;
	float m_LinkParticleSpeed;
	float m_LinkParticleSpeed_IgnoreSlow;
	int m_ExternalParticleSpeedCounter;
	float m_ExternalParticleSpeed;
	int m_TrainingHighJumpCheck[2][3];
	bool bExecWSBFlag;
	int ExecWSBWaitCounter;
	int m_FuncCallArg[10][4];
	int m_FuncCallArgStack;
	bool m_FuncCallArgStackDebug;
	CFloatWithTimer m_BGMVolume;
	CFloatWithTimer m_AmbientVolume;
	SGameSpeedControlParam GameSpeedControlParam;
	unsigned int m_GameFrame;
	int ObjMngCopyEnd;
	OBJ_CBase m_ObjVector[101];
	OBJ_CCharBase m_CharVector[6];

	void BOM_ConstructorSub();
	void ControlBattleObject();
	void AllActiveCheck();
};
