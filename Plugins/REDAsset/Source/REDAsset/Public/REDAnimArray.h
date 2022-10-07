#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "REDAnimData.h"
#include "REDAnimArray.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class REDASSET_API UREDAnimArray : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FREDAnimData> AnimDataArray;
    
    UREDAnimArray();
};

