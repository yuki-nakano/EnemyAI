#ifndef EXEC_JUDGMENT_BASE_H
#define EXEC_JUDGMENT_BASE_H

class EnemyBehavior;

class ExecJudgmentBase
{
public:
	virtual ~ExecJudgmentBase() {};

	virtual bool Judgment(EnemyBehavior* enemy) = 0;
};

#endif // !EXEC_JUDGMENT_BASE_H
