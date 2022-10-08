// Fill out your copyright notice in the Description page of Project Settings.


#include "REDGameState.h"

#include "REDEngine/Battle/AASystemRED.h"

void AREDGameState::ReceivedGameModeClass()
{
	Super::ReceivedGameModeClass();
	REDInitializeOnce();
}

void AREDGameState::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();
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
