#include "TargettingMove.h"
#include "EnemyBehavior.h"

ActionBase::State TargettingMoveBehavior::Exec(EnemyBehavior* enemy_)
{
	return enemy_->MoveTargetting();
}
