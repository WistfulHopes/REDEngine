// Fill out your copyright notice in the Description page of Project Settings.


#include "REDGameState_Battle.h"

constexpr float FRAME_RATE = 0.016666668;

void AREDGameState_Battle::HandleMatchIsWaitingToStart()
{
	m_BattleUpdateCount = 0;
	if (!bAllocateInstances)
	{
		BattleObjectManager = TUniquePtr<BATTLE_CObjectManager>();
		ScreenManager = TUniquePtr<BATTLE_CScreenManager>();
	}
	Super::HandleMatchIsWaitingToStart();
}

void AREDGameState_Battle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateBattle(DeltaSeconds);
}

void AREDGameState_Battle::UpdateBattle(float DeltaSeconds)
{
	UpdateBattleSub(FRAME_RATE, true);
}

void AREDGameState_Battle::UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw)
{
	
}
