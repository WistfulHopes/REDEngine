#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameAsset.generated.h"

UCLASS()
class UGameAsset : public UObject
{
	GENERATED_BODY()
public:
	TArray<UObject*> Assets;
	TArray<UPackage*> LoadedPackages;
	int NumPendingPackages;
	FDateTime StartLoadTime;
	bool bLoadComplete;
	TArray<FSoftObjectPath> LoadAssetRefs;
};
