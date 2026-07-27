// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusParent.h"
#include "Framework/Paddle.h"

ABonusParent::ABonusParent()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	BonusMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bonus Mesh"));
	SetRootComponent(BonusMesh);
	BonusMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BonusMesh->SetCollisionObjectType(ECC_WorldDynamic);
	BonusMesh->SetCollisionResponseToAllChannels(ECR_Overlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		BonusMesh->SetStaticMesh(MeshAsset.Object);
	}

}

void ABonusParent::BeginPlay()
{
	Super::BeginPlay();

	Direction = Direction.GetSafeNormal();
	
}

void ABonusParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);

}

void ABonusParent::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (IsValid(OtherActor))
	{
		if ( auto Paddle = Cast<APaddle>(OtherActor))
		{
			BonusAction(Paddle);
		}
	}
}

void ABonusParent::Move(const float DeltaTime)
{
	const FVector Offset = Direction * Speed * DeltaTime;
	AddActorWorldOffset(Offset);
}
void ABonusParent::BonusAction(APaddle* Paddle)
{
	Destroy();
}

void ABonusParent::InitScale(FVector NewScale)
{
	SetActorScale3D(NewScale);
}
