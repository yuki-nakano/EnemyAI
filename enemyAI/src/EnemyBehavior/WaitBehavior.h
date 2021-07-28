#ifndef WAIT_BEHAVIOR
#define WAIT_BEHAVIOR

#include "ActionBase.h"

class EnemyBehavior;

//待機処理
class WaitBehavior : public ActionBase
{
public:
	ActionBase::State Exec(EnemyBehavior* enemy_);
};

#endif // !WAIT_BEHAVIOR
