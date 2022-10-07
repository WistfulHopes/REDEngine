#pragma once
#include "CoreMinimal.h"
#include "EffectPawnMaterialInfo.generated.h"

class UREDPawnMaterials;

USTRUCT(BlueprintType)
struct FEffectPawnMaterialInfo {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName EffectName;
    
    UPROPERTY(EditAnywhere)
    UREDPawnMaterials* Materials;
    
    REDASSET_API FEffectPawnMaterialInfo();
};

