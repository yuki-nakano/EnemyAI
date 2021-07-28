#include "WaitBehavior.h"
#include "EnemyBehavior.h"

ActionBase::State WaitBehavior::Exec(EnemyBehavior* enemy_)
{
	return enemy_->Wait();
}
