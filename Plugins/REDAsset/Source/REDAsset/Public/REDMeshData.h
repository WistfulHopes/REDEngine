#pragma once
#include "CoreMinimal.h"
#include "REDMeshData.generated.h"

class USkeletalMesh;
class UREDBoneRetargetingDataAsset;

USTRUCT(BlueprintType)
struct FREDMeshData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    bool DefaultDisplay;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USkeletalMesh* SkeletalMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AnimSetName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UREDBoneRetargetingDataAsset* CommonBoneRetargetingData;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UREDBoneRetargetingDataAsset* ExBoneRetargetingData;
    
    REDASSET_API FREDMeshData();
};

