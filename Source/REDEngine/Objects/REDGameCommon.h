// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameAsset.h"
#include "Engine/GameInstance.h"
#include "REDEngine/Battle/DataTypes/Enums.h"
#include "REDGameCommon.generated.h"

class UREDAssetCache;
/**
 * 
 */
UCLASS()
class REDENGINE_API UREDGameCommon : public UGameInstance
{
	GENERATED_BODY()
	
	int playerID;
	SIDE_ID m_PlayerSide;
	TEnumAsByte<GAME_MODE> m_GameMode;
	TEnumAsByte<GAME_MODE> m_PrevGameMode;
	TEnumAsByte<PAD_ID> m_MainQuadrant;
	TEnumAsByte<SIDE_ID> m_MainPlayerSide;
	uint64 m_FrameCounter;
	uint64 m_FrameCounterEx;
	bool m_bNowOnlineCheck;
	bool m_bOnlineCheckFalse;
	UPROPERTY()
	UGameAsset *m_LoadedBattleAssets;
	UPROPERTY()
	UGameAsset *m_LoadedBattleAssets_Common;
	UPROPERTY()
	UGameAsset *m_StaticResourceAssets;
	UPROPERTY()
	UREDAssetCache *m_Cache_BattleChara[32];
	UPROPERTY()
	UGameAsset *m_Cache_BattleCommon;
	bool bNetworkBattle;
};
