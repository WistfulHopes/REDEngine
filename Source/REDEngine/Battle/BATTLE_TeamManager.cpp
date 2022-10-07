#include "BATTLE_TeamManager.h"

BATTLE_TeamManager::BATTLE_TeamManager()
{
  this->m_pMainPlayerObject = 0;
  this->m_pPrevMainPlayerObject = 0;
  this->m_TensionVal = 0;
  this->m_BurstStockMax = 0;
  this->m_AssistActInvalidTime = 0;
  this->m_bDoingUltimateChange = 0;
  this->m_SparkingTime = 0;
  this->m_pMemberObjects[0] = 0;
  this->m_pMemberObjects[1] = 0;
  this->m_pMemberObjects[2] = 0;
  this->m_TeamMemberIndex[0] = MemberID_INVALID;
  this->m_TeamMemberIndexForResult[0] = MemberID_INVALID;
  this->m_TeamMemberIndex[1] = MemberID_INVALID;
  this->m_TeamMemberIndexForResult[1] = MemberID_INVALID;
  this->m_TeamMemberIndex[2] = MemberID_INVALID;
  this->m_TeamMemberIndexForResult[2] = MemberID_INVALID;
  this->m_bSparkingAuraUpdate = 0;
  this->m_AlternativeUltimateChange = 0;
  this->m_SideID = SIDE_ID_INVALID;
  this->m_ChangeMemberID = SubMemberID_INVALID;
  this->m_UltimateChangeFlag = -1;
  this->m_ReserveChangeMemberID = SubMemberID_INVALID;
  this->m_forceChangeDir = 0;
  this->m_AssistCallCount = 0;
  this->m_bAssistActInvalidTimeClear = 1;
  this->m_ComboCount[2] = 0;
  this->m_Damage[2] = 0;
  this->m_OwnComboCount[2] = 0;
  this->m_changeDisableTimeChar = 0;
  this->m_LastTotalComboCount = 0;
  this->m_MaxTotalDamage = 0;
  this->m_LastTotalOwnComboCount = 0;
  this->m_AtkPriority = 0;
  this->m_TensionAddAct = TENSION_ACT_INVALID;
  this->m_AttackHitCount = 0;
  this->m_bRequestedAssistVoice[1] = 0;
  this->m_TensionPenaltyTime = 0;
  this->m_TensionNoTouchTime = 0;
  this->m_NegativeVal = 0;
  this->m_PositiveBonus = 0;
  this->m_bRequestedAssistVoice[0] = 0;
  for (int i = 0; i < 100; i++)
  {
    m_AtkSkillHistory[i] = -1;
  }
  this->m_AtkSkillHistoryIndex = 0;
}
