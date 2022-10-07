#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "CameraData.h"
#include "REDCameraAnimDataAsset.generated.h"

UCLASS()
class REDASSET_API UREDCameraAnimDataAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FCameraData> CameraDatabase;
    
    UREDCameraAnimDataAsset();
};

