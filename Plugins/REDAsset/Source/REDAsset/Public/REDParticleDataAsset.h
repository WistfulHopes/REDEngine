#pragma once
#include "CoreMinimal.h"
#include "PostProcessEffectData.h"
#include "REDAssetObject.h"
#include "ParticleData.h"
#include "REDParticleDataAsset.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDParticleDataAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FParticleData> ParticleDatabase;
    
    UPROPERTY(EditAnywhere)
    TArray<FPostProcessEffectData> PostProcessEffect;
    
    UREDParticleDataAsset();
};

