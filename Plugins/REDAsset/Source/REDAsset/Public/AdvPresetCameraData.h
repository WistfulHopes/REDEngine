#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AdvPresetCameraData.generated.h"

USTRUCT(BlueprintType)
struct FAdvPresetCameraData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName SocketName;
    
    UPROPERTY(EditAnywhere)
    FVector Location;
    
    UPROPERTY(EditAnywhere)
    FVector Rotation;
    
    UPROPERTY(EditAnywhere)
    float fov;
    
    REDASSET_API FAdvPresetCameraData();
};

