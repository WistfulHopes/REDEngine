// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDBBSData.h"
#include "REDCollisionData.h"
#include "REDParticleDataAsset.h"
#include "REDPawn.h"
#include "REDPawnPlayer.generated.h"

/**
 * 
 */
UCLASS()
class REDENGINE_API AREDPawnPlayer : public AREDPawn
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UREDBBSData* CharaScript;
	UPROPERTY()
	UREDBBSData* EffectScript;
	UPROPERTY()
	UREDCollisionData* CollisionData;
	UPROPERTY()
	UREDParticleDataAsset* SelfParticleByMesh;
	UPROPERTY()
	UREDParticleDataAsset* SelfParticle;
	UPROPERTY()
	TArray<UREDParticleDataAsset*> VSParticles;
	UPROPERTY()
	bool bNoEntry;
	int IndexForReservedEffect;
};
