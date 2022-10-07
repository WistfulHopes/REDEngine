// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDParticleDataAsset.h"
#include "REDGameState.h"
#include "REDEngine/Battle/BATTLE_CObjectManager.h"
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
	TUniquePtr<BATTLE_CObjectManager> BattleObjectManager;
	TUniquePtr<BATTLE_CObjectManager> ScreenManager;
};
