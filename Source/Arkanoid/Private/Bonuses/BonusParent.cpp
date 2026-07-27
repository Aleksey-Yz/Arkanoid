// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusParent.h"

// Sets default values
ABonusParent::ABonusParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonusParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABonusParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

