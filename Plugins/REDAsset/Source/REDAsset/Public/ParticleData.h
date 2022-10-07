#pragma once
#include "CoreMinimal.h"
#include "ParticleData.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FParticleData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UParticleSystem* PSTemplate;
    
    REDASSET_API FParticleData();
};

