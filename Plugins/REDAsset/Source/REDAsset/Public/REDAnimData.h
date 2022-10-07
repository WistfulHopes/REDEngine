#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "REDAnimData.generated.h"

class UAnimInstance;
class UREDAnimSet;

USTRUCT(BlueprintType)
struct FREDAnimData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UAnimInstance> AnimBPClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UREDAnimSet* AnimSet;
    
    REDASSET_API FREDAnimData();
};

