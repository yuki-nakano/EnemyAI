#include "Wait.h"
#include "EnemyState.h"

Wait::~Wait()
{
}

void Wait::Exec(EnemyState* enemy)
{
	enemy->AddTimer();

	if (enemy->GetTimer() > WaitTime)
	{
		switch (enemy->GetPreviousState())
		{
		case State::kMoveRight:
			enemy->ChangeState(State::kMoveLeft);
			break;
		case State::kMoveLeft:
			enemy->ChangeState(State::kMoveRight);
			break;
		case State::kInvalid:
			enemy->ChangeState(State::kMoveLeft);
		default:
			break;
		}
	}
}
