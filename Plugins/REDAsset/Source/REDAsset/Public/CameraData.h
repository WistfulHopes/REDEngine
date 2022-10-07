#pragma once
#include "CoreMinimal.h"
#include "CameraData.generated.h"

class UCameraAnim;

USTRUCT(BlueprintType)
struct FCameraData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UCameraAnim* CameraAnim;
    
    REDASSET_API FCameraData();
};

