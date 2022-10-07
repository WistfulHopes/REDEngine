#pragma once
#include "CoreMinimal.h"
#include "EMaterialCategory.generated.h"

UENUM()
enum EMaterialCategory {
    MC_Base,
    MC_Outline,
    MC_Shadow,
    MC_Decal,
    MC_Specular,
    MC_UniqueA,
    MC_UniqueB,
    MC_UniqueC,
    MC_DmgDecalA,
    MC_DmgDecalB,
    MC_Max,
};

