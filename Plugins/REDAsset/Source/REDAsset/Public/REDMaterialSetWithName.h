#pragma once
#include "CoreMinimal.h"
#include "REDMaterialSetWithName.generated.h"

class UREDMeshMaterialSet;

USTRUCT(BlueprintType)
struct FREDMaterialSetWithName {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SetName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UREDMeshMaterialSet* MaterialSet;
    
    REDASSET_API FREDMaterialSetWithName();
};

