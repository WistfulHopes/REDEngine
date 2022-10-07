#pragma once
#include "CoreMinimal.h"
#include "REDBinaryObject.h"
#include "REDAdvScriptData.generated.h"

class UObject;
class UWorld;

UCLASS()
class REDASSET_API UREDAdvScriptData : public UREDBinaryObject {
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere)
    TMap<FName, UObject*> UseAssets;
    
    UPROPERTY(EditAnywhere)
    TMap<FName, TSoftObjectPtr<UWorld>> Levels;
    
    UREDAdvScriptData();
};

