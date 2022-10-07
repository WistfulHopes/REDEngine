#pragma once
#include "CoreMinimal.h"
#include "NamedObject.generated.h"

USTRUCT()
struct FNamedObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    REDASSET_API FNamedObject();
};

