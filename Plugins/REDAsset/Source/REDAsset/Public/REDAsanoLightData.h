#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "REDAsanoLightData.generated.h"

USTRUCT(BlueprintType)
struct FREDAsanoLightData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName MeshName;
    
    UPROPERTY(EditAnywhere)
    FName BoneName;
    
    UPROPERTY(EditAnywhere)
    FVector BoneOffset;
    
    REDASSET_API FREDAsanoLightData();
};

