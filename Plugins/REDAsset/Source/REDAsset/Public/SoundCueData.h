#pragma once
#include "CoreMinimal.h"
#include "SoundCueData.generated.h"

class USoundCue;
class UREDLipSyncData;

USTRUCT(BlueprintType)
struct FSoundCueData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    USoundCue* SoundCue;
    
    UPROPERTY(EditAnywhere)
    UREDLipSyncData* LipSync;
    
    REDASSET_API FSoundCueData();
};

