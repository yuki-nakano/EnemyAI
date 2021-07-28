#ifndef ENEMY_STATE_H
#define ENEMY_STATE_H

#include "DxLib.h"
#include "../Manager/TextureManager.h"
#include "../Manager/InputManager.h"
#include "../Definition.h"
#include "../Enemy/EnemyBase.h"

class EnemyRule : public EnemyBase
{
public:
	EnemyRule();
	~EnemyRule();

	void Exec();
	void Draw();

	void Spown();

private:
	void CeckItem();

	void IsCollide();

private:
	Vec2 targetPos;

	int timer = 0;
};

#endif // !ENEMY_STATE_H
