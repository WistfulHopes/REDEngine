// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDParticleDataAsset.h"
#include "REDGameState.h"
#include "REDEngine/Battle/BATTLE_CObjectManager.h"
#include "REDEngine/Battle/BATTLE_CScreenManager.h"
#include "REDGameState_Battle.generated.h"

class AREDPawnPlayer;

struct FTeamInfo
{
	AREDPawnPlayer *PlayerPawns[3];
};

/**
 * 
 */
UCLASS()
class REDENGINE_API AREDGameState_Battle : public AREDGameState
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	UREDParticleDataAsset* CommonParticle;
	UPROPERTY()
	UREDParticleDataAsset* BGParticle[6];
	TUniquePtr<FTeamInfo> TeamInfo[3];
public:
	TUniquePtr<BATTLE_CObjectManager> BattleObjectManager;
	TUniquePtr<BATTLE_CScreenManager> ScreenManager;
	uint8 m_BattleState;
	int m_NetworkErrorState;
	int m_NetworkErrorStatePrev;
	int m_BattleUpdateCount;
	int m_RoundUpdateCount;
	int m_SendMessageInterval;
	bool bNetworkBattle;
	bool bRankMatchBattle;
	bool bCasualMatchBattle;
	bool bLobbyMatchBattle;
	bool bAllocateInstances;

	virtual void HandleMatchIsWaitingToStart() override;
	virtual void Tick(float DeltaSeconds) override;
	void UpdateBattle(float DeltaSeconds);
	void UpdateBattleSub(float DeltaSeconds, bool bUpdateDraw);
};
