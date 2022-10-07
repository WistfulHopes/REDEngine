#pragma once
#include "CoreMinimal.h"
#include "REDAssetObject.h"
#include "BoneRetargetingDatabase.h"
#include "REDBoneRetargetingDataAsset.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDBoneRetargetingDataAsset : public UREDAssetObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FBoneRetargetingDatabase> BoneRetargetingDatabaseList;
    
    UREDBoneRetargetingDataAsset();
};

