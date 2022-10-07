#pragma once
#include "BitArrayRED.h"
#include "CXXBYTE.h"
#include "Enums.h"

class CSkillInfo
{
public:
  CXXBYTE<32> m_SkillName;
  CXXBYTE<32> m_SkillNameCopyFrom;
  CXXBYTE<32> m_ReqActName;
  unsigned int m_ReqActFlag;
  unsigned int m_SkillFlag;
  unsigned int m_SkillEst;
  INPUT_ID m_SkillInputList[16];
  CXXBYTE<32> m_RecipeFirstSkillName;
  int m_RecipeStopFrame;
  int m_RecipeDataBufferStartIndex;
  int m_RecipeDataBufferUseNum;
  int m_AtkBoxX;
  int m_AtkBoxY;
  int m_AtkBoxW;
  int m_AtkBoxH;
  CXXBYTE<32> m_ChainCountGroup;
  int m_EnemyHitPointRate;
  CXXBYTE<32> m_FuncName;
  CXXBYTE<32> m_ConditionCheckFunc;
  int m_SkillHeightLimit;
  int m_SkillEnemyXNear;
  int m_SkillEnemyYRangeMin;
  int m_SkillEnemyYRangeMax;
  unsigned int m_SkillForceDisableFlag;
  int m_BasePoint;
  int m_LevelLimit;
  int m_IntervalBase;
  int m_SkillFunctionGroup;
  int m_SkillFunctionPriority;
  int m_RBMemcpyBegin;
  BitArrayRED<129,enum CD_CONDITION> m_ConditionBitArray;
  int m_IntervalCountDown;
  int m_TsubusareCnt;
  int m_IntervalMini;
  int m_IntervalEx;
  int m_ChusenMoreTimer;
  int m_ChusenMorePer;
  int m_NewCPUPoint;
  int m_NewCPUPointRand;
  unsigned int m_SkillActiveFlag;
  int m_SkillLastInputTimer[2];
  int m_SkillLastInputTimerStop[2];
  int m_SkillSenkoInputTime;
  int m_ScriptEstimateValue;
  int m_RendaSmashLastInputTimer[3];
  int m_RendaSmashLastInputTimerStop[3];
  bool m_OneButtonSkill;
  bool m_NormalInputSuccess;
  bool m_AlternativeInput;
  bool m_CancelDoing;
  bool m_BeginCancelReq;
  bool m_RomanCancelSpecialCancelReq;
  int16 m_SkillSelfIndex;
  int16 m_SkillSelfIndexStylishComboSlotBaseSkill;
  TEnumAsByte<SKILL_CATEGORY> m_SkillCategory;
  TEnumAsByte<SKILL_SUB_CATEGORY> m_SkillSubCategory;
  TEnumAsByte<SKILL_STANCE> m_SkillStance;
  TEnumAsByte<CO_TYPE> m_SkillInputDirectionBaseObject;
  TEnumAsByte<SRSF_TYPE> m_RecipeStopFrameType;
  TEnumAsByte<SRSFN_TYPE> m_RecipeStopFrameTypeN;
  TEnumAsByte<SKLDG> m_SkillDG;
  TEnumAsByte<CPUTsuyosa> m_TsuyosaLimit;
  uint8 m_SkillPriority;
  char m_ChainCountMax;
  char m_ChainCount;
  TEnumAsByte<SKILL_CND_RET> m_SkillCondition_Chain;
  TEnumAsByte<SKILL_CND_RET> m_SkillCondition_ChainPreAct;
  bool m_SkillCondition_Other;
  bool m_SkillCondition_OtherPreAct;
  TEnumAsByte<SKILL_RENDASMASH_INPUT_TYPE> m_RendaSmashInputType;
  int m_RBMemcpyEnd;
};
