#include "RandomMoveBehavior.h"
#include "EnemyBehavior.h"

ActionBase::State RandomMoveBehavior::Exec(EnemyBehavior* enemy_)
{
	return enemy_->MoveRandom();
}
