#include "TargettingJudgment.h"
#include "../Item.h"

bool TargettingJudgment::Judgment(EnemyBehavior* enemy_)
{
	return ItemManager::GetInstance()->Canlook(enemy_);
}
