// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusBallPower.h"
#include "Framework/Paddle.h"

ABonusBallPower::ABonusBallPower()
{
	Value = 1.0f;
	Duraction = 10.0f;
}

void ABonusBallPower::BonusAction(APaddle* Paddle)
{
	Paddle->BonusChangeBallPower(Value, Duraction);
	Super::BonusAction(Paddle);
}
