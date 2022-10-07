#pragma once
#include "CoreMinimal.h"
#include "NamedObject.h"
#include "CameraShakeData.generated.h"

class UCameraShake;

USTRUCT(BlueprintType)
struct FCameraShakeData : public FNamedObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Instanced)
    UCameraShake* CameraAnim;
    
    REDASSET_API FCameraShakeData();
};

