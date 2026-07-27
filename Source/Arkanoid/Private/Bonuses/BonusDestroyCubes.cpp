// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusDestroyCubes.h"
#include "EngineUtils.h"
#include "World/PlayingBoard.h"

ABonusDestroyCubes::ABonusDestroyCubes()
{ 
	Value = 3.0f;
}

void ABonusDestroyCubes::BonusAction(APaddle* Paddle)
{
	for (TActorIterator<APlayingBoard> It(GetWorld()); It; ++It )
	{
		if (const auto CurrentBoard = *It)
		{
			CurrentBoard->BonusDestroyCubes(Value);
		}
	}

	Super::BonusAction(Paddle);
}
