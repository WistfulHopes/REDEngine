#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BPEffectData.h"
#include "EffectMeshData.h"
#include "REDEffectData.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDEffectData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FEffectMeshData> EffectMeshData;
    
    UPROPERTY(EditAnywhere)
    TArray<FBPEffectData> BPEffectData;
    
    UREDEffectData();
};

