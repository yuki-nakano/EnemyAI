#ifndef ITEM_H
#define ITEM_H

#include "Definition.h"
#include "Singleton.h"

class EnemyBehavior;

//アイテムの最大出現数
const int MaxItem = 5;

struct Item
{
	int halfWidht = 5;
	int HalfHeight = 5;
	Vec2 pos;
	bool isAlive;
};

class ItemManager : public Singleton<ItemManager>
{
public:
	ItemManager();

	void Exec();
	void Draw();

	//当たり判定
	bool CheckHit(EnemyBehavior* enemy_);

	//Enemyの追跡範囲内にあるか判定
	bool Canlook(EnemyBehavior* enemy_);

private:
	//アイテム出現関数
	void Spown();

private:
	Item items[MaxItem];

	int timer = 0;
};

#endif // !ITEM_H
