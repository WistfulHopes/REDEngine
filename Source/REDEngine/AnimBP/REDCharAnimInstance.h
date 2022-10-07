#pragma once
#include "CoreMinimal.h"
#include "REDExBoneAnimInstance.h"
#include "AnimScarfSystemParam.h"
#include "UObject/NoExportTypes.h"
#include "FaceParam.h"
#include "AnimLinkBone.h"
#include "EyeBlinkParam.h"
#include "REDEngine/Battle/DataTypes/Enums.h"
#include "REDCharAnimInstance.generated.h"

UCLASS(NonTransient)
class REDENGINE_API UREDCharAnimInstance : public UREDExBoneAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Pupil_L_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Pupil_R_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Eye_L_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Eye_R_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Eye_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Eye_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Eye_L_Pos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Eye_R_Pos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Mouth_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Mouth_Pos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator LowerArm_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator LowerArm_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Waist_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Thigh_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Thigh_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Calf_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Calf_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Ankle_L_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FRotator Ankle_R_Rot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector Afro_Scale;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Hair_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Mouth_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Brow_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Eye_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Mouth_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Pupil_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float EyeBlink_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float HandL_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float HandR_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float UpperBody_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ArmL_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ArmR_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex1_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex2_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex3_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex4_BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Hair_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Brow_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Eye_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Face_Mouth_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Mouth_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float HandL_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float HandR_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float UpperBody_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ArmL_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ArmR_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex1_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex2_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex3_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Ex4_SlotBlendAlpha;
    
    UPROPERTY(BlueprintReadWrite)
    FAnimScarfSystemParam ScarfSystemParam;
    
    UPROPERTY(BlueprintReadWrite)
    FAnimLinkBone LinkBone;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FAnimLinkBone> AdditionalLinkBones;
    
    UPROPERTY(BlueprintReadWrite)
    FFaceParam FaceParam;
    
    UPROPERTY(BlueprintReadWrite)
    FEyeBlinkParam EyeBlinkParam;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Blend0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Blend1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Blend2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Blend3;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Val0;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Val1;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Val2;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ScriptParam_Val3;
    
    UFUNCTION(BlueprintPure)
    TEnumAsByte<EColorID> GetColorID() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void BlueprintInitializeLinkBone();
    
    UFUNCTION(BlueprintImplementableEvent)
    void BlueprintInitializeFaceParam();
    
    UFUNCTION(BlueprintCallable)
    void AddLinkBone(FName AttachMeshName, FName ParentBoneName, FName LinkBoneName);
    
    UREDCharAnimInstance();
};

