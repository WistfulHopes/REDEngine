#pragma once
#include "CoreMinimal.h"
#include "AnimLinkBone.generated.h"

USTRUCT(BlueprintType)
struct FAnimLinkBone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FName AttachMeshName;
    
    UPROPERTY(BlueprintReadWrite)
    FName ParentBoneName;
    
    UPROPERTY(BlueprintReadWrite)
    FName LinkBoneName;
    
    REDENGINE_API FAnimLinkBone();
};

