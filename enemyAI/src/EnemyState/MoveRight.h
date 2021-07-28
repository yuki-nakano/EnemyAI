#ifndef MOVE_RIGHT_H
#define MOVE_RIGHT_H

#include "StateBace.h"
#include "../Singleton.h"

//右移動
class MoveRight : public Singleton<MoveRight>, public StateBace
{
public:
	~MoveRight();

	void Exec(EnemyState* enemy);
};


#endif // !MOVE_RIGHT_H
