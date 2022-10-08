// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "REDCamera.generated.h"

class OBJ_CBase;
class AREDPawn;
class USplineComponent;
/**
 * 
 */
UCLASS()
class REDENGINE_API AREDCamera : public APlayerCameraManager
{
	GENERATED_BODY()
	
};

bool BATTLE_IsCameraForDBZ();

struct FMoveCameraParam
{
	float InFrameParam;
	float TargetParam;
	float LastParam;
	int CurrentFrame;
	int InFrame;
	int StayFrame;
	int OutFrame;
	int InterpIn;
	int InterpOut;
	int Speed;
};

struct FMoveCameraParamXYZ
{
	FMoveCameraParam X;
	FMoveCameraParam Y;
	FMoveCameraParam Z;
};

UCLASS()
class AREDCamera_Battle : public AREDCamera
{
	GENERATED_BODY()
public:
	struct __declspec(align(16)) FMoveCamera
	{
		struct FParamData
		{
			FMoveCameraParam *Param;
		};

		FMoveCameraParamXYZ Pos;
		FMoveCameraParamXYZ Rot;
		FMoveCameraParamXYZ TargetOffsetFrom;
		FMoveCameraParamXYZ TargetOffsetTo;
		FMoveCameraParam TargetDistance;
		FMoveCameraParam TargetPercent;
		FMoveCameraParamXYZ TargetPosRate;
		FMoveCameraParamXYZ TargetRotRate;
		FMoveCameraParam TargetRotRoll;
		FMoveCameraParam FOV;
		FMoveCameraParam BlendLastPOVRate;
		FMoveCameraParam CameraAnim_LocationRate;
		FMoveCameraParam CameraAnim_RotationRate;
		FMoveCameraParam CameraAnim_FOVRate;
		FMoveCameraParam TrackUp;
		FMoveCameraParam SplinePos;
		FMoveCameraParam SplinePosRate;
		int CurrentOrthoBlendCurveIndex;
		int LastOrthoBlendCurveIndex;
		FMoveCameraParam OrthoBlendCurveRate;
		//const UREDSplineComponent *Spline;
		bool bSplineFlipH;
		FMinimalViewInfo LastPOV;
		AREDPawn *PlayRequestPawn;
		AREDPawn *BasePawn;
		AREDPawn *LookAtPawn;
		FName PrevCameraStyle;
		bool bUpdateOrthoBlend;
		UCameraAnimInst *CameraAnimInst;
		UCameraAnim *CameraAnim;
		FVector CameraAnim_BaseLocation;
		int CameraAnim_InFrame;
		int CameraAnim_OutFrame;
		bool bCameraAnim_MirrorX;
		bool bCameraAnim_LockBaseLocation;
		bool bCameraAnim_UpdatedBaseLocation;
		bool bCameraAnim_SyncAnimeInOut;
		int AnimSpeed;
		TArray<FParamData> Params;
	};
	struct FBattleCameraPlayAnimInfo
	{
		AREDPawn *CenterPawn;
		UCameraAnimInst *CurrentCamAnimInst;
		FVector CenterLocation;
		float SelfBlendInTime;
		float SelfBlendInTimeMax;
		bool bUseCenterLocation;
		bool bUpdateOrthoBlend;
		bool bBlendInLastPOV;
	};
	struct FBattleCameraMoveToPosInfo
	{
		FMinimalViewInfo TargetPOV;
		FMinimalViewInfo PrevPOV;
		FMinimalViewInfo LastPOV;
		AREDPawn *PlayRequestPawn;
		AREDPawn *BasePawn;
		AREDPawn *LookAtPawn;
		FVector LookAtOffset;
		int InFrame;
		int StayFrame;
		int OutFrame;
		int FreezeFrame;
		float Distance;
		float LookPosPercent;
		int State;
		int InInterpType;
		int OutInterpType;
		int Counter;
		bool bBlendLastPOV;
		bool bUpdateOrthoBlend;
	};

	struct FBattleCameraFixedPosInfo
	{
		FVector Location;
		FRotator Rotation;
		float FOV;
		AREDPawn *PlayRequestPawn;
	};
	
	struct __declspec(align(8)) FSplineCurvesParam
	{
		FInterpCurveVector Position;
		FInterpCurveVector Rotation;
		FInterpCurveFloat FOV;
		TArray<float> HandleScalePosition;
		TArray<float> HandleScaleRotation;
		TArray<float> HandleScaleFOV;
		FRotator LastRotation;
		FName PrevCameraStyle;
		int Counter;
		bool bMirrorX;
		bool bRegistered;
	};
	struct FPlayBattleCameraAnimArg
	{
		UCameraAnim *CameraAnim;
		OBJ_CBase *PawnObj;
		OBJ_CBase *LocCenterPawnObj;
		int BlendInFrame;
		int BlendOutFrame;
		bool bMirrorX;
		bool bIsUpdateOrthoBlend;
		bool bUseCenterPos;
		FVector center;
	};

	FMoveCamera MoveCamera;
	FBattleCameraPlayAnimInfo PlayCamAnim;
	__declspec(align(16)) FBattleCameraMoveToPosInfo MoveToCam;
	FBattleCameraFixedPosInfo FixedPos;
	UPROPERTY()
	AREDPawn *CurrentPlayPawn;
	FRotator AddRotation;
	FVector RotationBlendRate;
	FVector CurrentCameraLocation;
	bool bInitCameraLocation;
	FRotator CurrentRotation;
	FRotator TargetRotation;
	int BattleCameraYawDirection;
	float CurrentYaw;
	int PauseFrameCount;
	int CameraAnimStepFrame;
	FVector LastTargetLocation;
	FMinimalViewInfo LastPOV;
	FMinimalViewInfo LastPOV_WithoutOffset;
	int AdvCameraEndFrame;
	int AdvCameraEndFrameMax;
	FVector LastAdvCameraViewPoint;
	bool bAdvCameraEnd;
	FName LastCameraStyle;
	UPROPERTY()
	USplineComponent *SplineComponent;
	UPROPERTY()
	ULineBatchComponent *LineComponent;
	FTViewTarget FinalViewTarget;
	FSplineCurvesParam SplineCurve;
	FPlayBattleCameraAnimArg PlayBattleCameraAnimArg;

	void UpdateViewTargetFromBattle(double DeltaTime);
	void UpdateCameraLocation(FMinimalViewInfo* POV, float DeltaTime, bool bWithoutBattleCameraRotation);
};
