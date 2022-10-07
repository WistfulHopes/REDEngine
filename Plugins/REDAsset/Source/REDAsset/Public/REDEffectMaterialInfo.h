#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EffectPawnMaterialInfo.h"
#include "REDEffectMaterialInfo.generated.h"

UCLASS()
class REDASSET_API UREDEffectMaterialInfo : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FEffectPawnMaterialInfo> MaterialData;
    
    UREDEffectMaterialInfo();
};

