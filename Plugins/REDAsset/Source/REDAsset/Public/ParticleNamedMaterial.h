#pragma once
#include "CoreMinimal.h"
#include "ParticleNamedMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FParticleNamedMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    TArray<UMaterialInterface*> MaterialInstances;
    
    REDASSET_API FParticleNamedMaterial();
};

