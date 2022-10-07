#pragma once
#include "CoreMinimal.h"
#include "REDTasteGradationData.generated.h"

USTRUCT(BlueprintType)
struct FREDTasteGradationData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName MeshName;
    
    UPROPERTY(EditAnywhere)
    TArray<FName> BoneList;
    
    UPROPERTY(EditAnywhere)
    float OffsetUp;
    
    UPROPERTY(EditAnywhere)
    float OffsetDown;
    
    UPROPERTY(EditAnywhere)
    bool bCharacter;
    
    UPROPERTY(EditAnywhere)
    bool bParticle;
    
    UPROPERTY(EditAnywhere)
    int32 GroupID;
    
    REDASSET_API FREDTasteGradationData();
};

