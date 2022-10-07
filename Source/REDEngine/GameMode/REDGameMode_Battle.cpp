#include "REDGameMode_Battle.h"

#include "REDEngine/GameState/REDGameState_Battle.h"

AREDGameMode_Battle::AREDGameMode_Battle() {
	GameStateClass = AREDGameState_Battle::StaticClass();
}

