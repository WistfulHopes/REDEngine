#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "CameraShakeData.h"
#include "REDCameraShakePatternAsset.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDCameraShakePatternAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FCameraShakeData> CameraShakePatterns;
    
    UREDCameraShakePatternAsset();
};

