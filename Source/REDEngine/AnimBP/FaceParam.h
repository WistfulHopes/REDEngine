#pragma once
#include "CoreMinimal.h"
#include "FaceParam.generated.h"

USTRUCT(BlueprintType)
struct FFaceParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool bFace;
    
    UPROPERTY(BlueprintReadWrite)
    bool bHasHair;
    
    UPROPERTY(BlueprintReadWrite)
    bool bEnableEyeBlink;
    
    REDENGINE_API FFaceParam();
};

