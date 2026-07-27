// Alexey Tishaninov. All rights reserved.


#include "World/PlayingBoard.h"

// Sets default values
APlayingBoard::APlayingBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayingBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayingBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

