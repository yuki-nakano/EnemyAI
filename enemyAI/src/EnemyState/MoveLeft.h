#ifndef MOVE_LEFT_H
#define MOVE_LEFT_H

#include "StateBace.h"
#include "../Singleton.h"

//左移動
class MoveLeft : public Singleton<MoveLeft>, public StateBace
{
public:
	~MoveLeft();

	void Exec(EnemyState* enemy);
};


#endif // !MOVE_LEFT_H
