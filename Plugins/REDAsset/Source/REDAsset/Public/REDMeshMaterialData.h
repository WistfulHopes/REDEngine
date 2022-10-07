#pragma once
#include "CoreMinimal.h"
#include "REDMeshMaterialData.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FREDMeshMaterialData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName MeshName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* Base;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* Outline;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* Shadow;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* Decal;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* Specular;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* UniqueA;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* UniqueB;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* UniqueC;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* DmgDecalA;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UMaterialInterface* DmgDecalB;
    
    REDASSET_API FREDMeshMaterialData();
};

