#include "REDCharAnimInstance.h"

TEnumAsByte<EColorID> UREDCharAnimInstance::GetColorID() const {
    return COLOR_ID_01;
}



void UREDCharAnimInstance::AddLinkBone(FName AttachMeshName, FName ParentBoneName, FName LinkBoneName) {
}

UREDCharAnimInstance::UREDCharAnimInstance() {
    this->Hair_BoneBlendAlpha = 0.00f;
    this->Face_BoneBlendAlpha = 0.00f;
    this->Mouth_BoneBlendAlpha = 0.00f;
    this->Face_Brow_BoneBlendAlpha = 0.00f;
    this->Face_Eye_BoneBlendAlpha = 0.00f;
    this->Face_Mouth_BoneBlendAlpha = 0.00f;
    this->Pupil_BoneBlendAlpha = 0.00f;
    this->EyeBlink_BoneBlendAlpha = 0.00f;
    this->HandL_BoneBlendAlpha = 0.00f;
    this->HandR_BoneBlendAlpha = 0.00f;
    this->UpperBody_BoneBlendAlpha = 0.00f;
    this->ArmL_BoneBlendAlpha = 0.00f;
    this->ArmR_BoneBlendAlpha = 0.00f;
    this->Ex1_BoneBlendAlpha = 0.00f;
    this->Ex2_BoneBlendAlpha = 0.00f;
    this->Ex3_BoneBlendAlpha = 0.00f;
    this->Ex4_BoneBlendAlpha = 0.00f;
    this->Hair_SlotBlendAlpha = 0.00f;
    this->Face_SlotBlendAlpha = 0.00f;
    this->Face_Brow_SlotBlendAlpha = 0.00f;
    this->Face_Eye_SlotBlendAlpha = 0.00f;
    this->Face_Mouth_SlotBlendAlpha = 0.00f;
    this->Mouth_SlotBlendAlpha = 0.00f;
    this->HandL_SlotBlendAlpha = 0.00f;
    this->HandR_SlotBlendAlpha = 0.00f;
    this->UpperBody_SlotBlendAlpha = 0.00f;
    this->ArmL_SlotBlendAlpha = 0.00f;
    this->ArmR_SlotBlendAlpha = 0.00f;
    this->Ex1_SlotBlendAlpha = 0.00f;
    this->Ex2_SlotBlendAlpha = 0.00f;
    this->Ex3_SlotBlendAlpha = 0.00f;
    this->Ex4_SlotBlendAlpha = 0.00f;
    this->ScriptParam_Blend0 = 0.00f;
    this->ScriptParam_Blend1 = 0.00f;
    this->ScriptParam_Blend2 = 0.00f;
    this->ScriptParam_Blend3 = 0.00f;
    this->ScriptParam_Val0 = 0.00f;
    this->ScriptParam_Val1 = 0.00f;
    this->ScriptParam_Val2 = 0.00f;
    this->ScriptParam_Val3 = 0.00f;
}

