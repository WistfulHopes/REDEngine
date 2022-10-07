#pragma once
#include "CoreMinimal.h"
#include "AdvPresetCameraData.h"
#include "UObject/Object.h"
#include "REDAdvPresetCameraArray.generated.h"

UCLASS()
class REDASSET_API UREDAdvPresetCameraArray : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FAdvPresetCameraData> PresetCameraArray;
    
    UREDAdvPresetCameraArray();
};

