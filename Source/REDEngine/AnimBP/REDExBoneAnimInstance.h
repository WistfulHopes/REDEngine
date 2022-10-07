#pragma once
#include "CoreMinimal.h"
#include "REDAnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "REDExBoneAnimInstance.generated.h"

UCLASS(NonTransient)
class REDENGINE_API UREDExBoneAnimInstance : public UREDAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Pos0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Pos1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Pos2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Pos3;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Pos4;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator ExBone_Rot0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator ExBone_Rot1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator ExBone_Rot2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator ExBone_Rot3;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator ExBone_Rot4;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Scale0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Scale1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Scale2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Scale3;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector ExBone_Scale4;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_Float0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_Float1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_Float2;
    
    UREDExBoneAnimInstance();
};

