#pragma once
#include "CoreMinimal.h"
#include "PostProcessEffectData.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FPostProcessEffectData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UMaterialInterface* MaterialInstance;
    
    REDASSET_API FPostProcessEffectData();
};

