// Alexey Tishaninov. All rights reserved.


#include "Framework/ArkanoidGameMode.h"
#include "Framework/ArkanoidGameState.h"
#include "Framework/ArkanoidPlayerState.h"
#include "Framework/ArkanoidPC.h"

AArkanoidGameMode::AArkanoidGameMode()
{
	GameStateClass = AArkanoidGameState::StaticClass();
	PlayerStateClass = AArkanoidPlayerState::StaticClass();
}

void AArkanoidGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameStarted();
}

void AArkanoidGameMode::GameStarted()
{
	auto ArkanoidGameState = Cast<AArkanoidGameState>(GameState);
	if (ArkanoidGameState)
	{
		ArkanoidGameState->StartGame();
	}
}

void AArkanoidGameMode::GameEnded(const bool bIsWinner)
{
	auto ArkanoidGameState = Cast<AArkanoidGameState>(GameState);
	if (ArkanoidGameState)
		ArkanoidGameState->EndGame();
		
		//UE_LOG(LogTemp, Warning, TEXT("Game Ended"));
	for (APlayerState* PlayerState : GameState->PlayerArray)
	{
		if (PlayerState)
		{
			auto Player = Cast<AArkanoidPC>(PlayerState->GetPlayerController());
				if (Player)
				{
					Player->ShowGameEndMenu(bIsWinner);

				}
		}
				
	}
	
}
