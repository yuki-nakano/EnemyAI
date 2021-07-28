#ifndef TARGETTING_MOVE_BEHAVIOR
#define TARGETTING_MOVE_BEHAVIOR

#include "ActionBase.h"

//追跡処理
class TargettingMoveBehavior : public ActionBase
{
public:
	ActionBase::State Exec(EnemyBehavior* enemy_);
};

#endif // !TARGETTING_MOVE_BEHAVIOR
