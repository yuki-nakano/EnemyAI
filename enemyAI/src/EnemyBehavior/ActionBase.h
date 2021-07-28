#ifndef ACTION_BASE_H
#define ACTION_BASE_H

class EnemyBehavior;

class ActionBase
{
public:
	enum class State
	{
		Run,		//実行中
		Success,	//行動成功
		Failed,		//行動失敗
	};

public:
	//行動実行関数
	virtual State Exec(EnemyBehavior*) = 0;
};

#endif // !ACTION_BASE_H
