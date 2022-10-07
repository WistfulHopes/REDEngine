// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "REDDestructionShotObject.generated.h"

UCLASS()
class REDENGINE_API AREDDestructionShotObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AREDDestructionShotObject();
    UPROPERTY(BlueprintReadOnly)
	bool bStaticCollision;
	FVector m_velocity;
	FVector m_targetPos;
	int m_destructObjIdx;
	bool m_bTarget;
	bool m_bFinish;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
