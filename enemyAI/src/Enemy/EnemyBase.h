#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "../Definition.h"

class EnemyBase
{
public:
	virtual ~EnemyBase() {}

	virtual void Exec() = 0;
	virtual void Draw() = 0;

	//virtual void Spown() = 0;

	Vec2 GetPos() const { return pos; }
	void SetPosX(float pos_x_) { pos.X = pos_x_; }
	void AddPosX(int moving_distance_) { pos.X += moving_distance_; }

	Vec2 GetInitPos() const { return initPos; }

	int GetHalfSize() const { return widht / 2; }

	bool GetIsAlive() const { return isAlived; }
	void SetIsAlive(bool is_alive_) { isAlived = is_alive_; }

protected:
	Vec2 pos;
	Vec2 initPos;
	int widht = 10;
	int height = 10;

	float Speed = 1.0f;	//速度

	bool isAlived = false;	//生存判定フラグ
};

#endif // !ENEMY_BACE_H
