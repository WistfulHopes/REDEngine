// Fill out your copyright notice in the Description page of Project Settings.


#include "REDPlayerController.h"

AREDPlayerController::AREDPlayerController()
{
	REDSceneContext.DisasterPosition.X = 0;
	REDSceneContext.DisasterPosition.Z = 0;
	REDSceneContext.DisasterPosition.W = 1;
	REDSceneContext.DisasterWind.Y = 0;
	REDSceneContext.DisasterWind.W = 1;
	REDSceneContext.DisasterQuake.Y = 0;
	REDSceneContext.DisasterQuake.W = 1;
}
