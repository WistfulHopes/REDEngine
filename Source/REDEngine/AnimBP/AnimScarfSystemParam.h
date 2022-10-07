#pragma once
#include "CoreMinimal.h"
#include "AnimScarfSystemParam.generated.h"

USTRUCT(BlueprintType)
struct FAnimScarfSystemParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    bool bEnableScarfSystem;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float BoneBlendAlpha;
    
    UPROPERTY(BlueprintReadWrite)
    float MinLength;
    
    UPROPERTY(BlueprintReadWrite)
    float MaxLength;
    
    UPROPERTY(BlueprintReadWrite)
    float ShrinkDec;
    
    UPROPERTY(BlueprintReadWrite)
    float ShrinkAccPower;
    
    UPROPERTY(BlueprintReadWrite)
    int32 NoShrinkFrame;
    
    UPROPERTY(BlueprintReadWrite)
    int32 NoShrinkFrameABS;
    
    UPROPERTY(BlueprintReadWrite)
    int32 UpdateIntervalFrame;
    
    UPROPERTY(BlueprintReadWrite)
    float SlantAngle;
    
    UPROPERTY(BlueprintReadWrite)
    float MinRoll;
    
    UPROPERTY(BlueprintReadWrite)
    float MaxRoll;
    
    UPROPERTY(BlueprintReadWrite)
    bool bUseMotionChildBone;
    
    UPROPERTY(BlueprintReadWrite)
    float LimitLengthRate;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FName> BoneNameList;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<float> BoneScaleXList;
    
    REDENGINE_API FAnimScarfSystemParam();
};

