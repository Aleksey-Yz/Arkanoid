// Alexey Tishaninov. All rights reserved.


#include "Bonuses/BonusPaddleSize.h"
#include "Framework/Paddle.h"



ABonusPaddleSize::ABonusPaddleSize()
{
	Duraction = 10.0f;
}

void ABonusPaddleSize::BonusAction(APaddle* Paddle)
{
	Paddle->BonusChangeSize(Value, Duraction);

	Super::BonusAction(Paddle);
}
