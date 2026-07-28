// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusTimeSlow.h"
#include "Framework/Paddle.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ABonusTimeSlow::ABonusTimeSlow()
{
    Value = 5.0f;      // длительность бонуса
}

void ABonusTimeSlow::BonusAction(APaddle* Paddle)
{
    UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.25f);

    FTimerHandle Timer;

    GetWorld()->GetTimerManager().SetTimer(
        Timer,
        this,
        &ABonusTimeSlow::ResetTime,
        Value,
        false);

    Super::BonusAction(Paddle);
}

void ABonusTimeSlow::ResetTime()
{
    UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
}
