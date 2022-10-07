#include "BATTLE_CObjectManager.h"

BATTLE_CObjectManager::BATTLE_CObjectManager()
{
	memset(m_MultiBufferLarge.m_Memory, 0, sizeof m_MultiBufferLarge.m_Memory);
	m_MultiBufferLarge.m_Memory[1].pPrev = &m_MultiBufferLarge.m_Memory[0];
	m_MultiBufferLarge.m_Memory[1].pNext = &m_MultiBufferLarge.m_Memory[2];
	m_MultiBufferLarge.m_Memory[2].pPrev = &m_MultiBufferLarge.m_Memory[1];
	m_MultiBufferLarge.m_Memory[2].pNext = &m_MultiBufferLarge.m_Memory[3];
	m_MultiBufferLarge.m_pEmptyChain = m_MultiBufferLarge.m_Memory;
	m_MultiBufferLarge.m_Memory[0].pNext = &m_MultiBufferLarge.m_Memory[1];
	m_MultiBufferLarge.m_Memory[3].pNext = &m_MultiBufferLarge.m_Memory[2];
	m_MultiBufferLarge.m_Memory[0].pPrev = nullptr;
	m_MultiBufferLarge.m_Memory[3].pPrev = nullptr;
	memset(m_MultiBufferSmall.m_Memory, 0, sizeof m_MultiBufferSmall.m_Memory);
	m_MultiBufferSmall.m_Memory[1].pPrev = &m_MultiBufferSmall.m_Memory[0];
	m_MultiBufferSmall.m_Memory[1].pNext = &m_MultiBufferSmall.m_Memory[2];
	m_MultiBufferSmall.m_Memory[2].pPrev = &m_MultiBufferSmall.m_Memory[1];
	m_MultiBufferSmall.m_Memory[2].pNext = &m_MultiBufferSmall.m_Memory[3];
	m_MultiBufferSmall.m_pEmptyChain = m_MultiBufferSmall.m_Memory;
	m_MultiBufferSmall.m_Memory[0].pNext = &m_MultiBufferSmall.m_Memory[1];
	m_MultiBufferSmall.m_Memory[3].pNext = &m_MultiBufferSmall.m_Memory[2];
	m_MultiBufferSmall.m_Memory[0].pPrev = nullptr;
	m_MultiBufferSmall.m_Memory[3].pPrev = nullptr;
	m_BGSaturation.Init();
	for (int i = 0; i < 800; i++)
	{
		m_CommonActionHash.m_HashTable[i] = -1;
	}
	for (int i = 0; i < 200; i++)
	{
		m_CommonActionHash.m_LinkTable[i] = -1;
	}
	memset(m_BattleInputAnalyzer, 0, sizeof m_BattleInputAnalyzer);
	m_BattleRecord.ResetRecord();
	m_BGMVolume.Init();
	m_AmbientVolume.Init();
	BOM_ConstructorSub();
}

void BATTLE_CObjectManager::BOM_ConstructorSub()
{
	m_pPlayerPawn[0] = nullptr;
	m_pPlayerPawn[1] = nullptr;
	m_pPlayerPawn[2] = nullptr;
	m_pPlayerPawn[3] = nullptr;
	m_pPlayerPawn[4] = nullptr;
	m_pPlayerPawn[5] = nullptr;
	m_pPlayerPawn[6] = nullptr;
	m_BOMFlag = 0;
	m_FinishBG = FBG_Normal;
	m_FinishAtk = 1;
	m_FinishAssistAtk = false;
	m_WorldBlacker = false;
	m_EtcActiveObjectCount = 0;
	m_FinishStopCount = 0;
	m_OverrideFinishStopTime[0] = -1;
	m_OverrideSlashUITime[0] = -1;
	m_WSBPattern = WORLDSID_EBREAK_PATTERN_DEFAULT;
	m_WorldStopper.m_Ptr = nullptr;
	m_WorldStopTimer = 0;
	m_WorldStopTimerMax = 0;
	m_IsForceReload = false;
	m_ActiveObjectCount = 0;
	m_NoActiveObjectCount = 0;
	m_FadeOut01 = 1;
	m_BGSaturation.Init();
	m_ShinSousaiTimer = 0;
	m_BGFadeInSpeed = 0.1;
	m_BGFadeOutSpeed = 0.1;
	m_BGFadeAlpha = 0.25;
	memset(&m_EventData, 0, sizeof m_EventData);
	m_StartInputTimeAC15 = 0;
	m_LastLoadedCharID[0] = CHARA_ID_MAX;
	m_LastLoadedCharID[1] = CHARA_ID_MAX;
	m_EnvStylishDefence = 80;
	m_EnvStylishTension = 80;
	m_EnvStylishBurst = 80;
	m_EnvDokiDokiStop = 1;
	m_EnvDokiDokiStopHikitsuke = 6;
	m_EnvDokiDokiStopXRangeMin = 100000;
	m_EnvDokiDokiStopXRangeMax = 800000;
	m_EnvDokiDokiStopYRangeMax = 400000;
	m_EnvDokiDokiStopHassei = 7;
	m_EnvDokiDokiStopFinishStop = 60;
	m_DokiDokiStopIgnoreTime = 0;
	m_TrialBossHP = 0;
	m_TrialBossBarrier = 0;
	m_TrialExVal1 = 0;
	m_TrialExVal3 = 0;
	m_bMOMItemDesc = false;
	m_FinishSlowTime = 0;
	m_bDrawPlayerOutIcon = 1;
	if (m_OutIconSettingObj.m_Ptr)
	{
		--m_OutIconSettingObj.m_Ptr->m_WatchedCount;
		m_OutIconSettingObj.m_Ptr = nullptr;
	}
	m_bForceBGHide = 0;
	m_bRequestDisplayFade = false;
	m_delayType = INP_DELAY_NORMAL;
	m_DragonBall = 0;
	m_bARendaComplete = 0;
	m_lastGainedDBSide = SIDE_ID_INVALID;
	if (m_pShenlongSystem.m_Ptr)
	{
		--m_pShenlongSystem.m_Ptr->m_WatchedCount;
		m_pShenlongSystem.m_Ptr = nullptr;
	}
	m_lastTensionAddAction = TENSION_ACT_INVALID;
	m_CallShenlongSide = SIDE_ID_INVALID;
	m_MotionBlurAmount = 0;
	m_DustSpeedX = 0;
	m_ParticleSpeed = 1;
	m_LinkParticleSpeed = 1;
	m_LinkParticleSpeed_IgnoreSlow = 1;
	m_ExternalParticleSpeed = 1;
	memset(m_FuncCallArg, 0, sizeof m_FuncCallArg);
	m_FuncCallArgStack = 0;
	m_FuncCallArgStackDebug = 1;
	m_BGMVolume.SetVal(1,1,0);
	m_AmbientVolume.SetVal(1,1,0);
	GameSpeedControlParam.StartGameSpeed = 100;
	GameSpeedControlParam.EndGameSpeed = 100;
	GameSpeedControlParam.CurrentGameSpeed = 100;
	GameSpeedControlParam.InFrame = 0;
	GameSpeedControlParam.OutFrame = 0;
	GameSpeedControlParam.InCurve = -1;
	GameSpeedControlParam.bRequestApplyParticle = false;
	m_GameFrame = 0;
}
