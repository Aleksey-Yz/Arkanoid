// Alexey Tishaninov. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UArrowComponent;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EState: uint8
{
	Idle, // Мячик на месте
	Moving, // Мячик в движение
};

USTRUCT(BlueprintType)
struct FInitParameters
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Стартовый размер"))
	float Scale;
	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Начальная мощь"))
	int32 Power;
	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Начальная скорость"))
	float Speed;
	UPROPERTY(EditDefaultsOnly, meta = (ToolTip = "Максимальная скорость"))
	float MaxSpeed;

	// Конструктор структуры
	FInitParameters()
	{
		Scale = 1.0f;
		Power = 1;
		Speed = 500.0f;
		MaxSpeed = 2500.0f;
	}
};

UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ForwardArrow = nullptr;

	int32 Power = 1;
	float Speed = 0.0f;
	FVector Direction = FVector::ZeroVector;
	EState State = EState::Idle;
	
public:	
	ABall();

	
protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings")
	FInitParameters InitParameters;

	UFUNCTION(BlueprintCallable, Category = "Ball")
	void Move(float DeltaTime);

	void SetBallState(const EState NewState);

public:	

};
