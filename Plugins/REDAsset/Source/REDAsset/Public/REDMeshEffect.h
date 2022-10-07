#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "REDTasteGradationData.h"
#include "REDAsanoLightData.h"
#include "REDMeshEffect.generated.h"

UCLASS()
class REDASSET_API UREDMeshEffect : public UObject {
    GENERATED_BODY()
public:
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
    float TasteGradationMinPos;
    
    UREDMeshEffect();
};

