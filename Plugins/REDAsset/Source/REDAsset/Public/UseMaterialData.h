#pragma once
#include "CoreMinimal.h"
#include "EMaterialCategory.h"
#include "UseMaterialData.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FUseMaterialData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UMaterialInterface* MaterialInterface;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EMaterialCategory> MaterialCategory;
    
    REDASSET_API FUseMaterialData();
};

