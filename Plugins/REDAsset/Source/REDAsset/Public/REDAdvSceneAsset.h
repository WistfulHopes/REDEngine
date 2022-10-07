#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "SoundCueData.h"
#include "REDAdvSceneAsset.generated.h"

class UREDAdvScriptData;

UCLASS()
class REDASSET_API UREDAdvSceneAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UREDAdvScriptData* Script;
    
    UPROPERTY(EditAnywhere)
    TArray<FSoundCueData> SEList;
    
    UREDAdvSceneAsset();
};

