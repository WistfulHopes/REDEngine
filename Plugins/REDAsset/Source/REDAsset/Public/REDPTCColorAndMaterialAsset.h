#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "ParticleNamedColor.h"
#include "ParticleNamedMaterial.h"
#include "REDPTCColorAndMaterialAsset.generated.h"

UCLASS()
class REDASSET_API UREDPTCColorAndMaterialAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FParticleNamedColor> ColorTable;
    
    UPROPERTY(EditAnywhere)
    TArray<FParticleNamedMaterial> MaterialTable;
    
    UREDPTCColorAndMaterialAsset();
};

