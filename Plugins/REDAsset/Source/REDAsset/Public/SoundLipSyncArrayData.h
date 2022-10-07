#pragma once
#include "CoreMinimal.h"
#include "SoundLipSyncArrayData.generated.h"

class UREDLipSyncData;

USTRUCT(BlueprintType)
struct FSoundLipSyncArrayData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UREDLipSyncData* Data;
    
    REDASSET_API FSoundLipSyncArrayData();
};

