#include "REDGameMode_Battle.h"

#include "REDEngine/REDPawnCamera.h"
#include "REDEngine/Actors/REDPlayerController_Battle.h"
#include "REDEngine/GameState/REDGameState_Battle.h"

AREDGameMode_Battle::AREDGameMode_Battle() {
	GameStateClass = AREDGameState_Battle::StaticClass();
	PlayerControllerClass = AREDPlayerController_Battle::StaticClass();
	DefaultPawnClass = AREDPawnCamera_Battle::StaticClass();
}

