// Fill out your copyright notice in the Description page of Project Settings.


#include "REDGameState.h"

#include "GameFramework/PlayerState.h"
#include "REDEngine/Actors/REDCamera.h"
#include "REDEngine/Actors/REDPlayerController.h"
#include "REDEngine/Battle/AASystemRED.h"

AREDGameState::AREDGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AREDGameState::ReceivedGameModeClass()
{
	Super::ReceivedGameModeClass();
	REDInitializeOnce();
}

void AREDGameState::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();
	PrimaryPC = Cast<AREDPlayerController>(PlayerArray[0]->GetOwner());
	if (PrimaryPC)
	{
		PrimaryCamera = Cast<AREDCamera>(PrimaryPC->PlayerCameraManager);
	}
}

void AREDGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void REDInitializeOnce()
{
	if (!s_bInitialized)
	{
		AASystemRED::StaticInitialize();
		s_bInitialized = true;
	}
}
