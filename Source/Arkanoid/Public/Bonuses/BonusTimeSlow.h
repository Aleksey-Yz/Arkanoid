// Alexey Tishaninov. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bonuses/BonusParent.h"
#include "BonusTimeSlow.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ABonusTimeSlow : public ABonusParent
{
	GENERATED_BODY()
	
public:
    ABonusTimeSlow();

protected:
    virtual void BonusAction(APaddle* Paddle) override;
    

private:
    UFUNCTION()
    void ResetTime();
    FTimerHandle TimerHandle;

};
