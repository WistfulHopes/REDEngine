#pragma once
#include "CoreMinimal.h"
#include "REDMeshMaterialData.h"
#include "UObject/Object.h"
#include "REDMeshMaterialSet.generated.h"

UCLASS()
class REDASSET_API UREDMeshMaterialSet : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FREDMeshMaterialData> MaterialArray;
    
    UREDMeshMaterialSet();
};

