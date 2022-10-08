// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "REDPlayerController.generated.h"

typedef ESelectionMode::Type EDisplayNameType;

const struct __declspec(align(16)) UREDSceneContext
{
	FLinearColor BGMultColor;
	FVector4 DisasterPosition;
	FVector4 DisasterWind;
	FVector4 DisasterQuake;
	float GameTime;
	float BGTime;
};

/**
 * 
 */
UCLASS()
class REDENGINE_API AREDPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AREDPlayerController();
	
	UREDSceneContext REDSceneContext;
};
