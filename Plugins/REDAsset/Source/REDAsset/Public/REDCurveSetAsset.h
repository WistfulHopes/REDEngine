#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "REDCurveData.h"
#include "REDCurveSetAsset.generated.h"

UCLASS()
class REDASSET_API UREDCurveSetAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FREDCurveData> CurveDataArray;
    
    UREDCurveSetAsset();
};

