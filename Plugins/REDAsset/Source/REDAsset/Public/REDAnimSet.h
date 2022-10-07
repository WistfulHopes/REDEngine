#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimSequenceData.h"
#include "REDAnimSet.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDAnimSet : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FAnimSequenceData> AnimSeqArray;
    
    UREDAnimSet();
};

