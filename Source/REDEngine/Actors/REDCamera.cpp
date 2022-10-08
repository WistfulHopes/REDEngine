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

void AREDCamera_Battle::UpdateViewTargetFromBattle(double DeltaTime)
{
	if (PendingViewTarget.Target)
	{
		if ((*((char*)&BlendParams + 12) & 1) != 0
			&& FinalViewTarget.Equal(FinalViewTarget))
		{
			return;
		}
	}
	if (PauseFrameCount)
	{
		PauseFrameCount--;
		return;
	}
	FMinimalViewInfo ViewInfo = FMinimalViewInfo(FinalViewTarget.POV);
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
		ApplyCameraModifiers(DeltaTime, FinalViewTarget.POV);
	}
	LastPOV_WithoutOffset = FinalViewTarget.POV;
}

void AREDCamera_Battle::UpdateCameraLocation(FMinimalViewInfo* POV, float DeltaTime, bool bWithoutBattleCameraRotation)
{
	auto v7 = GAASystemRed->m_CameraManager.m_Instances[0];
	FRotator result;
	if (!bInitCameraLocation)
	{
		CurrentCameraLocation.X = v7->m_Pos.X;
		CurrentCameraLocation.Z = v7->m_Pos.Z;
		bInitCameraLocation = true;
	}
	if (!bWithoutBattleCameraRotation && (BATTLE_IsCameraForDBZ() || DBM_VAL_CONST_TABLE[DBM_CameraPitch_DBZ]))
	{
		float v14;
		if (v7->m_Pos.Y >= 550)
			v14 = fminf((v7->m_Pos.Y - 550) / 1000, 1);
		else
			v14 = 0;
		float v17 = -5 * v14;
		float v18;
		v18 = 0.3;
		FRotator p_TargetRotation = TargetRotation;
		p_TargetRotation.Pitch = v17;
		CurrentYaw = 0;
		TargetRotation.Roll = 0;
		TargetRotation.Yaw = -90;
		result = FMath::Lerp(CurrentRotation, p_TargetRotation, v18);
		CurrentRotation = result;
		CurrentRotation.Yaw = TargetRotation.Yaw;
		float v23 = v7->m_Pos.X - 460 * tanf(TargetRotation.Yaw + 90) * 0.017453292;
		float v26 = v7->m_Pos.Y - tanf(CurrentRotation.Pitch * 0.017453292) * 460;
		if (BATTLE_IsCameraForDBZ())
			v26 -= 1;
		CurrentCameraLocation.X = v23;
		CurrentCameraLocation.Y = v7->m_Pos.Z;
		CurrentCameraLocation.Z = v26;
	}
	else
	{
		TargetRotation.Roll = 0;
		TargetRotation.Yaw = -90;
		CurrentRotation.Pitch = TargetRotation.Pitch;
		CurrentRotation.Roll = TargetRotation.Roll;
		float v32 = v7->m_Pos.Y - tanf(CurrentRotation.Pitch * 0.01753292) * 460;
		if (BATTLE_IsCameraForDBZ())
			v32 -= 1;
		CurrentCameraLocation.X = v7->m_Pos.X;
		CurrentCameraLocation.Z = v32;
	}
	POV->Rotation.Pitch = CurrentRotation.Pitch;
	POV->Rotation.Roll = CurrentRotation.Roll;
	POV->FOV = 65;
	POV->Location.X = CurrentCameraLocation.X;
	POV->Location.Z = CurrentCameraLocation.Z;
}
