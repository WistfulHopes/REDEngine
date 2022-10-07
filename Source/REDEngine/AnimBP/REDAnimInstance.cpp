#include "REDAnimInstance.h"

void UREDAnimInstance::AnimNotify_LoopStart() {
}

void UREDAnimInstance::AnimNotify_LoopEnd() {
}

UREDAnimInstance::UREDAnimInstance() {
    this->Root_SlotBlendAlpha = 0.00f;
    this->bStoryMode = false;
    this->Slow_BlendAlpha = 0.00f;
    this->Ex_BlendAlpha0 = 0.00f;
    this->Ex_BlendAlpha1 = 0.00f;
    this->Ex_BlendAlpha2 = 0.00f;
    this->Ex_BlendAlpha3 = 0.00f;
    this->RootAnimeMontage = NULL;
}

