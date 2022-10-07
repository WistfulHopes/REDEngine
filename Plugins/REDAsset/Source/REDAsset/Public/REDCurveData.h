#pragma once
#include "CoreMinimal.h"
#include "REDCurveData.generated.h"

class UCurveBase;

USTRUCT(BlueprintType)
struct FREDCurveData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UCurveBase* CurveAsset;
    
    REDASSET_API FREDCurveData();
};

