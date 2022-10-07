#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "REDAnimInstance.generated.h"

class UAnimMontage;

UCLASS(NonTransient, BlueprintType)
class REDENGINE_API UREDAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    float Root_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly)
    bool bStoryMode;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Slow_BlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_BlendAlpha0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_BlendAlpha1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_BlendAlpha2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex_BlendAlpha3;
    
protected:
    UPROPERTY()
    UAnimMontage* RootAnimeMontage;
    
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Head_Pos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Head_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Head_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Chest_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Shoulder_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Shoulder_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator UpperArm_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator UpperArm_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Hand_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Hand_L_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Hand_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Hand_R_Scale;
    
    UFUNCTION()
    void AnimNotify_LoopStart();
    
    UFUNCTION()
    void AnimNotify_LoopEnd();
    
    UREDAnimInstance();
};

