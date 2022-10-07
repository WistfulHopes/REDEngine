// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialInstancePool.generated.h"

/**
 * 
 */
UCLASS()
class REDENGINE_API UMaterialInstancePool : public UObject
{
	GENERATED_BODY()
	bool bInitialized;
public:
	UPROPERTY()
	TArray<UMaterialInstanceDynamic*>                 MaterialInstancePool;
private:
	UPROPERTY()
	TArray<UMaterialInstanceDynamic*>                 FreeMaterialInstanceList;
};
