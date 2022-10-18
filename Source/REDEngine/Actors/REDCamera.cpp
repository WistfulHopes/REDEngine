// Fill out your copyright notice in the Description page of Project Settings.


#include "REDCamera.h"

#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "REDEngine/Battle/AASystemRED.h"
#include "REDEngine/Battle/AA_Camera.h"
#include "REDEngine/Battle/Constants.h"
#include "REDEngine/Battle/DataTypes/Enums.h"

bool BATTLE_IsCameraForDBZ()
{
	return DBM_VAL_CONST_TABLE[DBM_CameraBehavior] == 1;
}

void AREDCamera_Battle::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
{
	if (PendingViewTarget.Target)
	{
		if ((*((char*)&BlendParams + 12) & 1) != 0
			&& ViewTarget.Equal(OutVT))
		{
			return;
		}
	}
	if (PauseFrameCount)
	{
		PauseFrameCount--;
		return;
	}
	OutVT.POV.FOV = 65;
	OutVT.POV.OrthoWidth = DefaultOrthoWidth;
	*((int32 *)&OutVT.POV + 12) = *((int32 *)&OutVT.POV + 12) & 0xFFFFFFFE | ((*((int32 *)this + 2552) & 2 | 4u) >> 1);
	OutVT.POV.PostProcessSettings.SetBaseValues();
	OutVT.POV.PostProcessBlendWeight = 1;
	UpdateCameraLocation(&OutVT.POV, DeltaTime, 0);
	ApplyCameraModifiers(DeltaTime, OutVT.POV);
	LastPOV_WithoutOffset = OutVT.POV;
	SetActorLocationAndRotation(OutVT.POV.Location, OutVT.POV.Rotation);
}

void AREDCamera_Battle::UpdateViewTargetFromBattle(double DeltaTime)
{
	if (PendingViewTarget.Target)
	{
		if ((*((char*)&BlendParams + 12) & 1) != 0
			&& ViewTarget.Equal(FinalViewTarget))
		{
			return;
		}
	}
	if (PauseFrameCount)
	{
		PauseFrameCount--;
		return;
	}
	FinalViewTarget.POV.FOV = 65;
	FinalViewTarget.POV.OrthoWidth = DefaultOrthoWidth;
	*((int32 *)&this->FinalViewTarget.POV + 12) = *((int32 *)&this->FinalViewTarget.POV + 12) & 0xFFFFFFFE | ((*((int32 *)this + 2552) & 2 | 4u) >> 1);
	FinalViewTarget.POV.PostProcessSettings.SetBaseValues();
	FinalViewTarget.POV.PostProcessBlendWeight = 1;
	if (FinalViewTarget.Target)
	{
		ACameraActor* CameraActor = Cast<ACameraActor>(FinalViewTarget.Target);
		if (IsValid(CameraActor))
		{
			CameraActor->GetCameraComponent()->GetCameraView(DeltaTime, FinalViewTarget.POV);
			ApplyCameraModifiers(DeltaTime, FinalViewTarget.POV);
		}
	}
	else
	{
		if (CameraStyle == TEXT("Battle"))
		{
			UpdateCameraLocation(&FinalViewTarget.POV, DeltaTime, 0);
		}
		else
		{
			UpdateCameraLocation(&FinalViewTarget.POV, DeltaTime, 0);
		}
		ApplyCameraModifiers(DeltaTime, FinalViewTarget.POV);
	}
	LastPOV_WithoutOffset = FinalViewTarget.POV;
	SetActorLocationAndRotation(FinalViewTarget.POV.Location, FinalViewTarget.POV.Rotation);
}

void AREDCamera_Battle::UpdateCameraLocation(FMinimalViewInfo* POV, float DeltaTime, bool bWithoutBattleCameraRotation)
{
	auto v7 = GAASystemRed->m_CameraManager.m_Instances[0];
	CurrentCameraLocation.X = v7->m_Pos.X;
	CurrentCameraLocation.Y = v7->m_Pos.Y;
	CurrentCameraLocation.Z = v7->m_Pos.Z;
	TargetRotation.Roll = 0;
	TargetRotation.Yaw = -90;
	CurrentRotation.Pitch = TargetRotation.Pitch;
	CurrentRotation.Roll = TargetRotation.Roll;
	POV->Rotation.Pitch = CurrentRotation.Pitch;
	POV->Rotation.Roll = CurrentRotation.Roll;
	POV->FOV = 65;
	POV->Location.X = CurrentCameraLocation.X;
	POV->Location.Y = -CurrentCameraLocation.Z;
	POV->Location.Z = CurrentCameraLocation.Y;
}
