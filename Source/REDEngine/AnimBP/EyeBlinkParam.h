#pragma once
#include "CoreMinimal.h"
#include "EyeBlinkParam.generated.h"

USTRUCT(BlueprintType)
struct FEyeBlinkParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FString AnimSeqName;
    
    UPROPERTY(BlueprintReadWrite)
    int32 WaitTimeMin;
    
    UPROPERTY(BlueprintReadWrite)
    int32 WaitTimeMax;
    
    UPROPERTY(BlueprintReadWrite)
    int32 FastBlinkPercent;
    
    REDENGINE_API FEyeBlinkParam();
};

