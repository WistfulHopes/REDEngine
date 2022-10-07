// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDSoundCueArray.h"
#include "GameFramework/GameState.h"
#include "REDEngine/Objects/MaterialInstancePool.h"
#include "REDEngine/Objects/REDGameCommon.h"
#include "REDGameState.generated.h"

class AREDPlayerController;
/**
 * 
 */
UCLASS()
class REDENGINE_API AREDGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	UREDGameCommon* GameCommon;
	UPROPERTY()
	float GameTime;
	UPROPERTY()
	float BGTime;
	UPROPERTY()
	float BGTimeSpeed;
	UPROPERTY()
	UREDSoundCueArray *NarrationSoundCueArrayENG;
	UPROPERTY()
	UREDSoundCueArray *NarrationSoundCueArrayJPN;
	UPROPERTY()
	UREDSoundCueArray *UISoundCueArray;
	UPROPERTY()
	TArray<AActor*> BGPauseActorList;
	UPROPERTY()
	TArray<UActorComponent * > BGPauseComponentList;
	UPROPERTY()
	TArray<UParticleSystemComponent * > BGPausePSCList;
	bool bBGPauseActorState;
	bool bSceneChanging;
	bool bManualUpdateSceneContextParameter;
	unsigned int GameStateCounter;
	unsigned int CurrentBGLayerIndex;
	int ChangingControllerCountdown;
	bool bEnableSigninAndControllerCheck;
	bool bChangingController;
	bool bUsePostProcessController;
	bool bEnableDynamicResolution;
	bool bEnableScreenshot;
	bool bEnableLiveStream;
	bool bEnableVideoRecording;
	bool bEnableShareControl;
	bool bEnableShareScreen;
	bool bReleaseMapInEndPlay;
	bool bEnableSoftReset;
	bool bFirstTickCall;
	float OutlineID;
protected:
	UPROPERTY()
	UGameAsset *Assets;
	UPROPERTY()
	UGameAsset *BGParticleAssets;
	UPROPERTY()
	AREDPlayerController *PrimaryPC;
	UPROPERTY()
	UMaterialInstancePool *MaterialInstancePool;
	bool bDispCinemaScope;
	bool bDispCinemaScope_FrontFade;
	bool bLockCinemaScopeControl;
	bool bIgnoreCinemaScopeCheckInSceneChange;
	UPROPERTY()
	UGameAsset *CharaIconAssets;
	bool bOverrideLightDir;
};
