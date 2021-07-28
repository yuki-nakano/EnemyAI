#include "MoveRight.h"
#include "EnemyState.h"

MoveRight::~MoveRight()
{
}

void MoveRight::Exec(EnemyState* enemy)
{
	const int timer = enemy->GetTimer();

	if (MoveTime > timer)
	{
		enemy->AddPosX(Speed);
	}
	else if (MoveTime + WaitTime < timer)
	{
		enemy->AddPosX(Speed * -1);
		if (enemy->GetPos().X < enemy->GetInitPos().X)
		{
			enemy->SetPosX(enemy->GetInitPos().X);
			enemy->ChangeState(State::kWait);
		}
	}

	enemy->AddTimer();
}
