#ifndef TARGETTING_JUDGMENT_H
#define TARGETTING_JUDGMENT_H

#include "ExecJudgmentBase.h"

class TargettingJudgment : public ExecJudgmentBase
{
public:
	bool Judgment(EnemyBehavior* enemy_);
};

#endif // !TARGETTING_JUDGMENT_H
