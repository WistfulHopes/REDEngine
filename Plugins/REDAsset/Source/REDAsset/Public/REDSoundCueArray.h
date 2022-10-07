#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SoundCueData.h"
#include "REDSoundCueArray.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDSoundCueArray : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FSoundCueData> SoundCueArray;
    
    UREDSoundCueArray();
};

