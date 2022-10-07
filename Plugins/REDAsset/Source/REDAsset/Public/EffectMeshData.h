#pragma once
#include "CoreMinimal.h"
#include "EffectMeshData.generated.h"

class UREDMeshArray;
class UREDAnimArray;
class UREDPawnMaterials;

USTRUCT(BlueprintType)
struct FEffectMeshData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere, Instanced)
    UREDMeshArray* MeshArray;
    
    UPROPERTY(EditAnywhere, Instanced)
    UREDAnimArray* AnimArray;
    
    UPROPERTY(EditAnywhere)
    UREDPawnMaterials* PawnMaterial;
    
    UPROPERTY(EditAnywhere)
    uint8 ReserveCount;
    
    REDASSET_API FEffectMeshData();
};

