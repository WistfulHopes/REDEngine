#pragma once
#include "AA_CCollision_JON.h"
#include "Enums.h"

class CSkillInfo;

struct sRecipeInputKey
{
	RPINP m_Type;
	uint16 m_RecFlg;
	uint16 m_Time;
};

struct __declspec(align(8)) CCPUInfo
{
	int m_LastInitializedLevel;
	int m_Level;
	int m_LastInitializedGuardLevelBonus;
	float m_LevelF01;
	float m_LevelF01Katayori;
	CSkillInfo *m_PlayingSkill;
	const CSkillInfo *m_PlayingSkillLastForDisp;
	int m_RecipeStopTypeForDebug;
	int m_RecipePlayElmTimer;
	int m_RecipePlayElmTimerWithStop;
	unsigned int m_RecipePlayElmFlag;
	int m_RecipePlayingTime;
	int m_RecipePlayingTimeWithStop;
	int m_RecipeLandNeutralTime;
	int m_RecipePlayIndex;
	sRecipeInputKey *m_RecipeElmCurPtr;
	int m_RecipePlayElmDone;
	CSkillInfo *m_SkillByRecipe;
	int m_RecipePlayElmCount;
	int m_KeyDirection;
	uint16 m_KeyFlagReg;
	int m_InputWait;
	int m_DefGuard;
	int m_DefSwitchGuard;
	int m_DefJustGuard;
	int m_DefBarrierGuard;
	int m_RangeGuard;
	int m_RangeSwitchGuard;
	int m_RangeJustGuard;
	int m_RangeBarrierGuard;
	int m_FDKeizoku;
	int m_GuardShitaiTime;
	int m_GuardReversalTime;
	int m_Guard;
	int m_SwitchGuard;
	int m_JustGuard;
	int m_BarrierGuard;
	int m_BarrierGuardSub;
	int m_Ukemi;
	int m_LockReject;
	int m_NCHandanWait;
	CCmnRect m_DlEnemyCollision;
	int m_DlEnemyPosX;
	int m_DlEnemyPosY;
	int m_DlKuguriChikuseki;
	int m_DlKuguriSaikin;
	int m_DlShotChikuseki;
	int m_DlShotSaikin;
	int m_DlTobiChikuseki;
	int m_DlTobiSaikin;
	int m_DlSukidarakeSaikin;
	int m_DlEnemyCrouchTimer;
	int m_DlEnemyNoAttackTimer;
	int m_DlReversalTimer;
	int m_DlStress;
	int m_DlNageReady;
	CSkillInfo *m_DlEnemyLastUseSkill;
	CSkillInfo *m_DlEnemyLastDelayUpdateSkill;
	TEnumAsByte<CPUTsuyosa> m_CPUTsuyosa;
	TEnumAsByte<RPINP> m_RecipePlayStructType;
	TEnumAsByte<SBRS_STATE> m_SkillByRecipeState;
	bool m_isRecipePlaying;
	TEnumAsByte<GUARD_DAN> m_PrevGuardDan;
	bool m_NCNowHandan;
	bool m_DlEnemyDamage;
	bool m_DlEnemyGuard;
	bool m_DlEnemyAttacking;
	TEnumAsByte<GUARD_DAN> m_DlEnemyGuardDan;
};
