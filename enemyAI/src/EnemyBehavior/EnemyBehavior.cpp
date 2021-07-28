#include "EnemyBehavior.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "RandomMoveBehavior.h"
#include "TargettingMove.h"
#include "WaitBehavior.h"
#include "TargettingJudgment.h"

#include "../Item.h"

EnemyBehavior::EnemyBehavior()
{
	inputManager = InputManager::GetInstance();

	aiTree = new Tree(new Node("Root", Node::SelectRule::Random, 0));
	aiTree->AddNode("Root", new Node("Stay", Node::SelectRule::None, 0, new WaitBehavior));
	aiTree->AddNode("Root", new Node("Move", Node::SelectRule::Priority, 0));
	aiTree->AddNode("Move", new Node("Random", Node::SelectRule::None, 0, new RandomMoveBehavior));
	aiTree->AddNode("Move", new Node("Target", Node::SelectRule::None, 1, new TargettingMoveBehavior, nullptr, new TargettingJudgment));
}

void EnemyBehavior::Exec()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_SPACE))
	{
		Spown();
	}

	if (!isAlived) { return; }

	if (activeNode == nullptr)
	{
		activeNode = aiTree->Inference(this);
	}

	if (activeNode != nullptr)
	{
		activeNode = aiTree->Update(this, activeNode);
	}
}

void EnemyBehavior::Draw()
{
	if (!isAlived) { return; }

	DrawBox(pos.X - widht / 2, pos.Y - height / 2,
		pos.X + widht / 2, pos.Y + height / 2, GetColor(0, 0, 0), TRUE);
}

void EnemyBehavior::Spown()
{
	if (isAlived) { return; }

	isAlived = true;

	pos.X = Widht / 2;
	pos.Y = Height / 2;

	timer = 0;
}

ActionBase::State EnemyBehavior::Wait()
{
	if (!isInit) { InitToWait(); }

	timer--;

	if (timer <= 0)
	{
		isInit = false;

		return ActionBase::State::Success;
	}

	return ActionBase::State::Run;
}

void EnemyBehavior::InitToWait()
{
	isInit = true;

	timer = 60 * 3;
}

ActionBase::State EnemyBehavior::MoveRandom()
{
	if (!isInit) { InitToMoveRandom(); }

	timer--;

	pos.X += cosf(rad * M_PI / 180) * Speed;
	pos.Y -= sinf(rad * M_PI / 180) * Speed;

	ActionBase::State state = ActionBase::State::Run;

	if (pos.X + widht / 2 > Widht)
	{
		pos.X = Widht - widht / 2 - 1;

		state = ActionBase::State::Success;
	}
	else if (pos.X - widht / 2 < 0)
	{
		pos.X = widht / 2 + 1;

		state = ActionBase::State::Success;
	}

	if (pos.Y + height / 2 > Height)
	{
		pos.Y = Height - height / 2 - 1;

		state = ActionBase::State::Success;
	}
	else if (pos.Y - height / 2 < 0)
	{
		pos.Y = height / 2 + 1;

		state = ActionBase::State::Success;
	}

	if (timer <= 0)
	{
		state = ActionBase::State::Success;
	}

	if (state != ActionBase::State::Run)
	{
		isInit = false;
	}

	return state;
}

void EnemyBehavior::InitToMoveRandom()
{
	isInit = true;

	timer = 60 * 3;

	rad = GetRand(360);

	if (pos.X < 50)
	{
		rad = 270 + GetRand(180);
	}
	else if (pos.X > Widht - 50)
	{
		rad = 90 + GetRand(180);
	}
	else if (pos.Y < 50)
	{
		rad = 180 + GetRand(180);
	}
	else if (pos.Y > Height - 50)
	{
		rad = GetRand(180);
	}
}

ActionBase::State EnemyBehavior::MoveTargetting()
{
	if (!isInit) { InitToMoveTargetting(); }

	rad = atan2f((targetPos.Y - pos.Y) * -1, targetPos.X - pos.X);

	pos.X += cosf(rad) * Speed;
	pos.Y -= sinf(rad) * Speed;

	if (ItemManager::GetInstance()->CheckHit(this))
	{
		isInit = false;

		return ActionBase::State::Success;
	}

	return ActionBase::State::Run;
}

void EnemyBehavior::InitToMoveTargetting()
{
	isInit = true;
}
