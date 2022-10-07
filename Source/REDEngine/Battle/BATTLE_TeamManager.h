#pragma once
#include "DataTypes/Enums.h"

class OBJ_CCharBase;

class BATTLE_TeamManager
{
public:
	SIDE_ID m_SideID;
	OBJ_CCharBase *m_pMainPlayerObject;
    OBJ_CCharBase *m_pMemberObjects[3];
    OBJ_CCharBase *m_pPrevMainPlayerObject;
	EMemberID m_TeamMemberIndex[3];
	EMemberID m_TeamMemberIndexForResult[3];
	int m_TensionVal;
	int m_BurstStock;
	int m_BurstStockMax;
	ESubMemberID m_ChangeMemberID;
	ESubMemberID m_ReserveChangeMemberID;
	char m_UltimateChangeFlag;
	char m_ReserveUltimateChangeFlag;
	char m_changeType;
	char m_ReserveChangeType;
	unsigned int m_forceChangeDir;
	uint8 m_AlternativeUltimateChange;
	int m_AssistActInvalidTime;
	bool m_bAssistActInvalidTimeClear;
	int m_AssistCallCount;
	bool m_bDoingUltimateChange;
	int m_SparkingTime;
	int m_SparkingAuraCounter;
	bool m_bSparkingAuraUpdate;
	int m_ComboCount[3];
	int m_TotalComboCount;
	int m_LastTotalComboCount;
	int m_OwnComboCount[3];
	int m_TotalOwnComboCount;
	int m_LastTotalOwnComboCount;
	int m_Damage[3];
	int m_TotalDamage;
	int m_MaxTotalDamage;
	uint8 m_AtkSkillHistory[100];
	int m_AtkSkillHistoryIndex;
	int m_AtkPriority;
	TENSION_ADD_ACTION m_TensionAddAct;
	int16 m_AttackHitCount;
	int16 m_AttackGuardCount;
	int m_LiveRushCounter;
	uint8 m_changeDisableTimeChar;
	char m_dispChangeDisableMark[2];
	bool m_bRequestedChangeVoice;
	bool m_bRequestedAssistVoice[2];
	bool m_TensionPenalty;
	int m_TensionPenaltyTime;
	int m_TensionBalance;
	int m_TensionNoTouchTime;
	int m_TensionSideTime;
	int m_NegativeVal;
	int m_NegativeSuspend;
	int m_PositiveBonus;
	int m_PositiveBonusNum;
};
