// Fill out your copyright notice in the Description page of Project Settings.


#include "REDPlayerController_Battle.h"

#include "REDCamera.h"

AREDPlayerController_Battle::AREDPlayerController_Battle()
{
	PlayerCameraManagerClass = AREDCamera_Battle::StaticClass();
}
