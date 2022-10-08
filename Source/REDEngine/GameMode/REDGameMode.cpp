#include "REDGameMode.h"

#include "REDEngine/REDPawnCamera.h"
#include "REDEngine/Actors/REDPlayerController.h"
#include "REDEngine/GameState/REDGameState.h"

AREDGameMode::AREDGameMode() {
	GameStateClass = AREDGameState::StaticClass();
	PlayerControllerClass = AREDPlayerController::StaticClass();
	DefaultPawnClass = AREDPawnCamera::StaticClass();
}

