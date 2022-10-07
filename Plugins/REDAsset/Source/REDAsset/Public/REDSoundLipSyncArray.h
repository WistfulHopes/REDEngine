#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SoundLipSyncArrayData.h"
#include "REDSoundLipSyncArray.generated.h"

UCLASS()
class REDASSET_API UREDSoundLipSyncArray : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FSoundLipSyncArrayData> LipSyncArray;
    
    UREDSoundLipSyncArray();
};

