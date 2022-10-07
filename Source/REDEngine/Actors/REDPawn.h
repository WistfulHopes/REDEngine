// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "REDAnimArray.h"
#include "REDMeshArray.h"
#include "REDPawnMaterials.h"
#include "REDPTCColorAndMaterialAsset.h"
#include "GameFramework/Pawn.h"
#include "REDEngine/Battle/DataTypes/Enums.h"
#include "REDPawn.generated.h"

class OBJ_CBase;
class UMaterialInstancePool;
class UREDAnimInstance;

USTRUCT()
struct FTasteGradationMeshData
{
	GENERATED_BODY()

	int MeshIndex;
	TArray<int> BoneIndexList;
	float OffsetUp;
	float OffsetDown;
};

USTRUCT()
struct FTasteGradation
{
	GENERATED_BODY()
	
	TArray<FTasteGradationMeshData> MeshData;
	bool bCharacter;
	bool bParticle;
	int GroupID;
};

USTRUCT()
struct FAnimControl
{
	GENERATED_BODY()
	
	UAnimMontage *Montage;
	FName LastPlaySeqName;
};


struct FFaceKeyPattern
{
	int Pattern;
	int frame;
};

struct FFaceControl
{
	int CurrentFrame;
	int RestFrame;
	int Type;
	int PlayingType;
	bool bAutoUpdate;
	bool bLinear;
	bool bUseMouthSlot;
	bool bPlaying;
	float PlaySpeed;
	float UpdateTimer;
	int NextTypeFrame;
	bool bPlayingClose;
	bool bAutoUpdateFaceBlendWeight;
	bool bPauseLip;
	FFaceKeyPattern *FaceKeyPattern;
	int FaceKeyPatternNum;
	int FaceKeyIndex;
};

struct FAdvAnimControl
{
	struct __declspec(align(8)) SMontagePlayInfo
	{
		UAnimMontage *Montage;
		int AnimeLength;
		bool IsLoop;
		int AnimFramePos;
	};

	USkeletalMeshComponent *TargetMesh;
	UAnimMontage *Montage;
	UAnimMontage *PrevMontage;
	FName LastPlaySeqName;
	FName SlotName;
	int NextSlotNo;
	int LastPlayType;
	int AnimeLength;
	bool IsLoop;
	bool IsPlay;
	bool IsBoneBlend;
	bool IsBoneBlendInSetFunc;
	bool IsMoveBoneBlendAlpha;
	bool IsSlotBlend;
	float CurrentBoneBlendAlpha;
	float CurrentSlotBlendAlpha;
	int BlendCount;
	int BlendCountMax;
	int BlendFrame;
	bool IsBlendFirstFrame;
	int8 BlendInterval;
	char BlendAcc[1];
	bool BlendAutoPlayAnim;
	bool IsBlendPupil;
	float SlotAlpha;
	float BoneAlpha;
	int AnimFramePos;
	int AnimStartFrame;
	int AnimEndFrame;
	int AnimEndCount;
	float BlendTimer;
	bool bLinkMotion;
	float StartBoneBlendAlpha;
	float StartSlotBlendAlpha;
	SMontagePlayInfo NormalAnimationInfo[2];
};

USTRUCT()
struct FMeshControl
{
	GENERATED_BODY()
	
	UPROPERTY(Export)
	USkeletalMeshComponent* TargetMesh;
	UPROPERTY()
	UMaterialInstanceDynamic *BaseMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *ShadowMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *OutlineMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *DecalMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *SpecularMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *UniqueAMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *UniqueBMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *UniqueCMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *DmgDecalAMatInst;
	UPROPERTY()
	UMaterialInstanceDynamic *DmgDecalBMatInst;
	unsigned int MaterialCategories[10];
	UPROPERTY()
	UREDAnimInstance *AnimInstance;
	UPROPERTY()
	FAnimControl RootAnime;
	FFaceControl FaceCtrl;
	FAnimControl EyeAnime;
	FAdvAnimControl AdvAnime[12];
	FAnimControl ExBlendAnime[5];
	UPROPERTY()
	TSubclassOf<UAnimInstance> AnimBPClass;
	UPROPERTY()
	UREDAnimSet* AnimSet;
	UPROPERTY()
	TArray<UREDAnimSet*> ExtraAnimSet;
	UPROPERTY()
	UREDBoneRetargetingDataAsset *CommonBoneRetargetingData;
	UPROPERTY()
	UREDBoneRetargetingDataAsset *ExBoneRetargetingData;
	FName MeshName;
	FName AnimSetName;
	bool DefaultDisplay;
	bool bDispThisFrame;
	bool bAlwaysDispOn;
	bool bFoundAnime;
	bool bFace;
	bool bHasHair;
	bool bEnableEyeBlink;
	bool bSetForceDispFlag;
	bool bForceDispFlag;
	bool bLockMeshFlag;
};

USTRUCT()
struct FLocalMaterialPool
{
	GENERATED_BODY()

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstances[0x64];
	unsigned int CategoryFlags[100];
	int MaterialInstancesNum;
};

struct FMeshSet
{
	FName SetName;
	FName MeshNames[16];
	unsigned int MeshNameNum;
};

UCLASS()
class REDENGINE_API AREDPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AREDPawn();
	UPROPERTY()
	UMaterialInstancePool* MaterialPool;                                            
	UPROPERTY()
	UREDMeshArray* MeshArray;                                               
	UPROPERTY()
	UREDAnimArray* AnimArray;                                               
	UPROPERTY()
	TArray<UREDAnimArray*> VSAnimArrayList;                                         
	UPROPERTY()
	UREDAnimArray* HandAnimArray;                                           
	UPROPERTY()
	UREDPawnMaterials* PawnMaterials;                                           
	UPROPERTY()
	TArray<UREDPawnMaterials*> ExPawnMaterials;                                         
	UPROPERTY()
	UREDPTCColorAndMaterialAsset* PTCColorAndMaterial;                                     
	UPROPERTY()
	UREDPTCColorAndMaterialAsset* PTCColorAndMaterial_Original;                            
	UPROPERTY()
	UCurveFloat* ResOutlineScaleCurve;
	TArray<FREDAsanoLightData> AsanoLightData;
	TArray<FVector> AsanoLightPos;
	TArray<float> AsanoLightPow;
	TArray<FTasteGradation> TasteGradation;
	float TasteGradationMinWidth;
	float TasteGradationMinPos;
	const FMeshControl *pAttachParentMeshControl;
	UPROPERTY()
	FMeshControl MeshControl[0x32];
	int MeshControlNum;
	bool bRefreshAnimation;
	FVector ActorLocationOffset;
	bool bHasFaceControl;
	bool bIgnoreTick;
	bool bUpdateMaterialParameters;
	bool bAutoCreateMaterialInstance;
	UPROPERTY()
	FLocalMaterialPool MyLocalMaterialPool;
    bool bNowStop;
	TArray<FMeshSet> MeshSetArray;
	FName SavedMeshSetName;
	FName CurrentMeshSetName;
	FName CurrentMaterialSetName;
	EMeshDir MeshDir;
	EMeshDirMode MeshDirMode;
	bool bMeshDirReverse;
	bool bDispAnyMesh;
	bool bDisplayMeshFlag;
	FName LastAnimSeqName;
	bool bPlayingCutSceneAnime;
	float LoopSectionCheckTime;
	int LoopSectionCount;
	int LastLoopSectionCount;
	int CurrentAnimeFaceIndex;
	float CutSceneAnimeTime;
	bool bPauseLipSync;
	OBJ_CBase *ObjPtr;
	FVector ObjScale;
	int CutSceneStepFrame;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};