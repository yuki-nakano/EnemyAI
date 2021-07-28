#ifndef TREE_H
#define TREE_H

#include "Node.h"

class EnemyBehavior;

class Tree
{
public:
	Tree(Node* node_)
		:root(node_)
	{
	}

	~Tree()
	{
	}

	//ノード追加
	bool AddNode(std::string search_name_, Node* add_node_);

	//行動決定
	Node* Inference(EnemyBehavior* enemy_);

	//行動更新
	Node* Update(EnemyBehavior* enemy_, Node* active_node_);

private:
	//ノードの削除
	void Delete();

private:
	//ルートの削除
	Node* root;

};


#endif // !TREE_H
