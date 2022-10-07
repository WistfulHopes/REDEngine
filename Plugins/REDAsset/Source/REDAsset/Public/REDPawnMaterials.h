#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "REDMaterialSetWithName.h"
#include "UseMaterialData.h"
#include "REDPawnMaterials.generated.h"

UCLASS(BlueprintType)
class REDASSET_API UREDPawnMaterials : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FREDMaterialSetWithName> MaterialSetWithName;
    
    UPROPERTY(EditAnywhere)
    TArray<FUseMaterialData> UseMaterials;
    
    UREDPawnMaterials();
};