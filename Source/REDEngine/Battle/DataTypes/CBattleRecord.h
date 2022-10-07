#pragma once

class CSkillInfo;

class CBattleRecord
{
public:
	struct Battle_Record
	{
		uint16 m_LightAtk;
		uint16 m_MiddleAtk;
		uint16 m_HeavyAtk;
		uint16 m_chudanAtk;
		uint16 m_SpecialAtk;
		uint16 m_ExSpecialAtk;
		uint16 m_UltimateAtk;
		uint16 m_MeteoUltimateAtk;
		uint16 m_Special;
		uint16 m_ExSpecial;
		uint16 m_Ultimate;
		uint16 m_MeteoUltimate;
		uint16 m_GuardCancelAttack;
		uint16 m_Shot;
		uint16 m_Sousai;
		uint16 m_ShotSousai;
		uint16 m_HomingDashAtk;
		uint16 m_HomingDash;
		uint16 m_MikiwameMoveAtk;
		uint16 m_MikiwameMove;
		uint16 m_ShotReflect;
		uint16 m_ZReverse;
		uint16 m_RushStart;
		uint16 m_RushRush;
		uint16 m_RushChange;
		uint16 m_RushSousai;
		uint16 m_RushDamage;
		uint16 m_Burst;
		uint16 m_SparkingBurst;
		uint16 m_Assist;
		uint16 m_Change;
		uint16 m_GuardCancelChange;
		uint16 m_UltimateChange;
		uint16 m_FirstAtk;
		uint16 m_Counter;
		uint16 m_CounterDamage;
		uint16 m_Guard;
		uint16 m_ChudanGuard;
		uint16 m_GedanGuard;
		uint16 m_Shenlong;
		uint16 m_Down;
		uint16 m_EnemyDown;
		uint16 m_SpecialAtkFinish;
		uint16 m_ExSpecialAtkFinish;
		uint16 m_UltimateFinish;
		uint16 m_MeteoUltimateFinish;
		uint16 m_FuttobiFinish;
		uint16 m_DestructionFinish;
		uint16 m_DramaticFinish;
		uint16 m_BGDestroy;
		uint16 m_GroundDestroy;
		uint16 m_FrontWalkFrame;
	};

	Battle_Record m_Record[2];
    const CSkillInfo *m_pSkill[2];
};
