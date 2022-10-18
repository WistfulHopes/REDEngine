// Fill out your copyright notice in the Description page of Project Settings.


#include "REDGameState_Battle.h"

#include "REDEngine/Actors/REDCamera.h"
#include "REDEngine/Actors/REDPlayerController.h"

constexpr float FRAME_RATE = 0.016666668;

void AREDGameState_Battle::HandleMatchIsWaitingToStart()
{
	m_BattleUpdateCount = 0;
	if (!bAllocateInstances)
	{
		BattleObjectManager = MakeUnique<BATTLE_CObjectManager>();
		ScreenManager = MakeUnique<BATTLE_CScreenManager>();
	}
	Super::HandleMatchIsWaitingToStart();
}

void AREDGameState_Battle::HandleMatchHasStarted()
{
	/*BattleObjectManager.Get()->m_pPlayerPawn[0] = TeamInfo[0].Get()->PlayerPawns[0];
	BattleObjectManager.Get()->m_pPlayerPawn[3] = TeamInfo[1].Get()->PlayerPawns[0];
	BattleObjectManager.Get()->m_pPlayerPawn[1] = TeamInfo[0].Get()->PlayerPawns[1];
	BattleObjectManager.Get()->m_pPlayerPawn[4] = TeamInfo[1].Get()->PlayerPawns[1];
	BattleObjectManager.Get()->m_pPlayerPawn[2] = TeamInfo[0].Get()->PlayerPawns[2];
	BattleObjectManager.Get()->m_pPlayerPawn[5] = TeamInfo[1].Get()->PlayerPawns[2];
	BattleObjectManager.Get()->m_pPlayerPawn[6] = TeamInfo[2].Get()->PlayerPawns[0];*/
	ScreenManager.Get()->ResetScreenManager();
	Super::HandleMatchHasStarted();
}

void AREDGameState_Battle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateBattle(DeltaSeconds);
}

void AREDGameState_Battle::UpdateBattle(float DeltaSeconds)
{
	UpdateBattleSub(FRAME_RATE, true);
	if (PrimaryPC)
	{
		if (PrimaryPC->PlayerCameraManager)
		{
			AREDCamera_Battle* BattleCam = Cast<AREDCamera_Battle>(PrimaryPC->PlayerCameraManager);
			if (IsValid(BattleCam))
			{
				BattleCam->UpdateViewTargetFromBattle(FRAME_RATE);
			}
		}
	}
}

void AREDGameState_Battle::UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw)
{
	ScreenManager->UpdateScreenPosition(false);
}
