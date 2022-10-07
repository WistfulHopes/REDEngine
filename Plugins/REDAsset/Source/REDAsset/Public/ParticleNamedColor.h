#pragma once
#include "CoreMinimal.h"
#include "ParticleNamedColor.generated.h"

class UParticleModuleColorOverLife;

USTRUCT(BlueprintType)
struct FParticleNamedColor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditInstanceOnly, Instanced)
    UParticleModuleColorOverLife* ColorOverLife;
    
    REDASSET_API FParticleNamedColor();
};

