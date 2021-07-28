#include "EnemyState.h"

EnemyState::EnemyState()
{
	MoveRight::CreateInstance();
	MoveLeft::CreateInstance();
	Wait::CreateInstance();

	inputManager = InputManager::GetInstance();
}

EnemyState::~EnemyState()
{
}

void EnemyState::Exec()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		Spown();
	}

	if (!isAlived) { return; }

	state->Exec(this);
}

void EnemyState::Draw()
{
	if (!isAlived) { return; }

	DrawBox(pos.X - widht / 2, pos.Y - height / 2,
		pos.X + widht / 2, pos.Y + height / 2, GetColor(0, 0, 0), TRUE);
}

void EnemyState::Spown()
{
	if (isAlived) { return; }

	isAlived = true;

	pos.X = Widht / 2;
	pos.Y = Height / 2;

	timer = 0;

	state = Wait::GetInstance();
	currentState = State::kWait;
}

void EnemyState::ChangeState(State next_state_)
{
	timer = 0;

	initPos.X = pos.X;
	initPos.Y = pos.Y;

	previousState = currentState;
	currentState = next_state_;

	switch (next_state_)
	{
	case State::kMoveRight:
		state = MoveRight::GetInstance();
		break;
	case State::kMoveLeft:
		state = MoveLeft::GetInstance();
		break;
	case State::kWait:
		state = Wait::GetInstance();
		break;
	default:
		break;
	}

}
