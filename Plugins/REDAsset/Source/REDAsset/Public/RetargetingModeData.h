#pragma once
#include "CoreMinimal.h"
#include "Animation/Skeleton.h"
#include "RetargetingModeData.generated.h"

USTRUCT(BlueprintType)
struct FRetargetingModeData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName BoneName;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EBoneTranslationRetargetingMode::Type> RetargetingMode;
    
    UPROPERTY(EditAnywhere)
    bool IsChildrenToo;
    
    REDASSET_API FRetargetingModeData();
};

