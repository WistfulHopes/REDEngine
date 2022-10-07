#pragma once
#include "CoreMinimal.h"
#include "REDBinaryObject.h"
#include "REDCharaSelectMaskData.generated.h"

UCLASS()
class REDASSET_API UREDCharaSelectMaskData : public UREDBinaryObject {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, VisibleAnywhere)
    int32 Width;
    
    UPROPERTY(AdvancedDisplay, VisibleAnywhere)
    int32 Height;
    
    UREDCharaSelectMaskData();
};

