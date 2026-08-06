// Alexey Tishaninov. All rights reserved.


#include "Framework/ArkanoidGameState.h"

AArkanoidGameState::AArkanoidGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AArkanoidGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bGameStarted)
	{
		GameTime += DeltaTime;
	}
}

void AArkanoidGameState::StartGame()
{
	bGameStarted = true;
}
void AArkanoidGameState::EndGame()
{
	bGameStarted = false;
}
void AArkanoidGameState::GetGameTime(int32& minutes, int32& seconds, int32& milliseconds) const
{
	minutes = static_cast<int32>(GameTime) / 60;
	seconds = static_cast<int32>(GameTime) % 60;
	milliseconds= static_cast<int32>((GameTime - FMath::Floor(GameTime)) * 1000);
}