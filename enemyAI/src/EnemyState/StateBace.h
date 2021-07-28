#ifndef STATE_BACE_H
#define STATE_BACE_H

class EnemyState;

class StateBace
{
public:
	virtual ~StateBace() {};

	virtual void Exec(EnemyState* enemy) = 0;
};

#endif // !STATE_BACE_H

