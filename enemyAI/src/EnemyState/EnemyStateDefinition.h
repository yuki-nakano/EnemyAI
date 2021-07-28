#ifndef ENEMY_STATE_DEFINITION_H
#define ENEMY_STATE_DEFINITION_H

#include "StateBace.h"
#include "Wait.h"
#include "MoveRight.h"
#include "MoveLeft.h"

enum class State
{
	kWait,		//待機
	kMoveRight,	//右移動
	kMoveLeft,	//左移動
	kMax,
	kInvalid	//無効値
};

#endif // !ENEMY_STATE_DEFINITION_H
