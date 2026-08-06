// Alexey Tishaninov. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ArkanoidGameState.generated.h"


UCLASS()
class ARKANOID_API AArkanoidGameState : public AGameStateBase
{
	GENERATED_BODY()
	

private:
	float GameTime = 0.0f;
	bool bGameStarted = false;

protected:
	virtual void Tick(float DeltaTime) override;

public:
	AArkanoidGameState();

	void StartGame();
	void EndGame();

	UFUNCTION(BlueprintPure, Category = "GameState")
	void GetGameTime(int32& minutes, int32& seconds, int32& milliseconds) const;

};
