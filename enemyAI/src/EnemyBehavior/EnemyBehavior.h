#ifndef ENEMY_BEHAVIOR
#define ENEMY_BEHAVIOR

#include "../Manager/InputManager.h"
#include "../Enemy/EnemyBase.h"
#include "ActionBase.h"
#include "Tree.h"

class EnemyBehavior : public EnemyBase
{
public:
	EnemyBehavior();

	void Exec();

	void Draw();

	void SetTargetPos(Vec2 vec2_) { targetPos = vec2_; }

	//生成
	void Spown();

	//待機
	ActionBase::State Wait();
	void InitToWait();

	//ランダム移動
	ActionBase::State MoveRandom();
	void InitToMoveRandom();

	//アイテム追跡
	ActionBase::State MoveTargetting();
	void InitToMoveTargetting();

private:
	InputManager* inputManager;

	Tree* aiTree;
	Node* activeNode;

	//追跡中アイテム座標
	Vec2 targetPos;

	int timer;
	float rad;
	bool isInit = false;
};


#endif // !ENEMY_BEHAVIOR
