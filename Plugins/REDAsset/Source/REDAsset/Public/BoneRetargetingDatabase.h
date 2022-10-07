#pragma once
#include "CoreMinimal.h"
#include "Animation/Skeleton.h"
#include "RetargetingModeData.h"
#include "BoneRetargetingDatabase.generated.h"

USTRUCT(BlueprintType)
struct FBoneRetargetingDatabase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EBoneTranslationRetargetingMode::Type> BaseRetargetingMode;
    
    UPROPERTY(EditAnywhere)
    TArray<FRetargetingModeData> OverrideRetargetingModeList;
    
    REDASSET_API FBoneRetargetingDatabase();
};

