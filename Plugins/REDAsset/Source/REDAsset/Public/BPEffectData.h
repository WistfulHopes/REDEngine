#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BPEffectData.generated.h"

class APawn;

USTRUCT(BlueprintType)
struct FBPEffectData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<APawn> PawnClass;
    
    UPROPERTY(EditAnywhere)
    int32 MaxNum;
    
    REDASSET_API FBPEffectData();
};

