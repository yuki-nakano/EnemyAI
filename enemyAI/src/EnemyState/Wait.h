#ifndef WAIT_H
#define WAIT_H

#include "StateBace.h"
#include "../Singleton.h"

//待機
class Wait : public Singleton<Wait>, public StateBace
{
public:
	~Wait();

	void Exec(EnemyState* enemy);
};

#endif // !WAIT_H
