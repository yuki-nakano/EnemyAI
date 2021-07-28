#ifndef RANDOM_MOVE_BEHAVIOR
#define RANDOM_MOVE_BEHAVIOR

#include "ActionBase.h"

//ランダム移動処理
class RandomMoveBehavior : public ActionBase
{
public:
	ActionBase::State Exec(EnemyBehavior* enemy_);
};

#endif // !RANDOM_MOVE_BEHAVIOR
