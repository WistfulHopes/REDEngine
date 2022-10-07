#include "btl.h"

#include "REDEngine/GameState/REDGameState_Battle.h"

BATTLE_CObjectManager* red::btl::GetObjectManager()
{
	const AREDGameState_Battle* GameState = Cast<AREDGameState_Battle>(GWorld->GetGameState());
	
	if (IsValid(GameState))
	{
		return GameState->BattleObjectManager.Get();
	}

	return nullptr;
}
