#pragma once
#include "CoreMinimal.h"
#include "AnimSequenceData.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct FAnimSequenceData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UAnimSequence* Sequence;
    
    REDASSET_API FAnimSequenceData();
};

