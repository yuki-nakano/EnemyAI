#ifndef ENEMY_STATE_H
#define ENEMY_STATE_H

#include "DxLib.h"
#include "../Manager/TextureManager.h"
#include "../Manager/InputManager.h"
#include "../Definition.h"
#include "EnemyStateDefinition.h"
#include "../Enemy/EnemyBase.h"

const float Speed = 3.0f;
const int WaitTime = 80;
const int MoveTime = 80;

class EnemyState : public EnemyBase
{
public:
	EnemyState();
	~EnemyState();

	void Exec();
	void Draw();

	void Spown();

	void ChangeState(State next_state_);

	int GetTimer() const { return timer; }
	void AddTimer() { timer++; }

	State GetPreviousState() const { return previousState; }

private:
	InputManager* inputManager = nullptr;

	StateBace* state = nullptr;

	//状態保存
	State currentState = State::kInvalid;
	State previousState = State::kInvalid;


	int timer = 0;
};

#endif // !ENEMY_STATE_H
