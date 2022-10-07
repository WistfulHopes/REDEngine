// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameAsset.h"
#include "UObject/Object.h"
#include "REDAssetCache.generated.h"

/**
 * 
 */
UCLASS()
class REDENGINE_API UREDAssetCache : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UGameAsset* LoadedAsset;
	FDateTime LoadedDateTime;
};
