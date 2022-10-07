#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "REDMeshData.h"
#include "UObject/NoExportTypes.h"
#include "REDTasteGradationData.h"
#include "REDAsanoLightData.h"
#include "REDMeshArray.generated.h"

class UREDMeshEffect;

UCLASS(EditInlineNew, BlueprintType)
class REDASSET_API UREDMeshArray : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FREDMeshData> MeshDataArray;
    
    UPROPERTY(EditAnywhere)
    FVector XSILightDirFront;
    
    UPROPERTY(EditAnywhere)
    FVector XSILightDirBack;
    
    UPROPERTY(EditAnywhere)
    FVector XSILightDirCustom1;
    
    UPROPERTY(EditAnywhere)
    FVector XSILightDirCustom2;
    
    UPROPERTY(EditAnywhere)
    TArray<FREDAsanoLightData> AsanoLightArray;
    
    UPROPERTY(EditAnywhere)
    TArray<FREDTasteGradationData> TasteGradationArray;
    
    UPROPERTY(EditAnywhere)
    float TasteGradationMinWidth;
    
    UPROPERTY(EditAnywhere)
    UREDMeshEffect* EffectInfo;
    
    UREDMeshArray();
};

