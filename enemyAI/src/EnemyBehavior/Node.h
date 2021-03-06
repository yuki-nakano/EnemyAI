#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "ExecJudgmentBase.h"
#include "ActionBase.h"

class EnemyBehavior;

class Node
{
public:
	enum class SelectRule
	{
		None,		//最後尾ノードのみ選択
		Priority,	//優先
		Random		//ランダム
	};

public:
	Node(std::string name_, SelectRule rule_, unsigned int priority_, ActionBase* action_ = nullptr, Node* parent_ = nullptr, ExecJudgmentBase* execute_ = nullptr)
		:name(name_)
		, parent(parent_)
		, Execute(execute_)
		, Rule(rule_)
		, Action(action_)
		, Priority(priority_)
	{
	}

	//ノードの検索
	Node* Search(std::string swarch_name_);

	//子の追加
	void AddChild(Node* child_);

	//親の設定
	void SetParent(Node* parent_) { parent = parent_; }

	//ノードの全削除
	void Delete();

	//行動決定
	Node* Inference(EnemyBehavior* enemy_);

	//ランダムにノードを選択
	Node* SelectRandom(std::vector<Node*>& list_);

	//優先でノードを選択
	Node* SelectPriorty(std::vector<Node*>& list_);

	//更新
	ActionBase::State Update(EnemyBehavior* enemy_);

private:
	std::string name;	//名前
	Node* parent;		//親
	std::vector<Node*> children;	//子供ノードのリスト
	ExecJudgmentBase* Execute;		//実行可能かの判定関数
	SelectRule Rule;
	unsigned int Priority;

	ActionBase* Action;	//実行関数
};

#endif // !NODE_H
