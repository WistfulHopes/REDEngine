#include "AnimScarfSystemParam.h"

FAnimScarfSystemParam::FAnimScarfSystemParam() {
    this->bEnableScarfSystem = false;
    this->BoneBlendAlpha = 0.00f;
    this->MinLength = 0.00f;
    this->MaxLength = 0.00f;
    this->ShrinkDec = 0.00f;
    this->ShrinkAccPower = 0.00f;
    this->NoShrinkFrame = 0;
    this->NoShrinkFrameABS = 0;
    this->UpdateIntervalFrame = 0;
    this->SlantAngle = 0.00f;
    this->MinRoll = 0.00f;
    this->MaxRoll = 0.00f;
    this->bUseMotionChildBone = false;
    this->LimitLengthRate = 0.00f;
}

