#include "MoveLeft.h"
#include "EnemyState.h"

MoveLeft::~MoveLeft()
{
}

void MoveLeft::Exec(EnemyState* enemy)
{
	const int timer = enemy->GetTimer();

	if (MoveTime > timer)
	{
		enemy->AddPosX(Speed * -1);
	}
	else if (MoveTime + WaitTime < timer)
	{
		enemy->AddPosX(Speed);
		if (enemy->GetPos().X > enemy->GetInitPos().X)
		{
			enemy->SetPosX(enemy->GetInitPos().X);
			enemy->ChangeState(State::kWait);
		}
	}

	enemy->AddTimer();
}
