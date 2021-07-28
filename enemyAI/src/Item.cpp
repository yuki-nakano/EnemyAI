#include "Item.h"
#include "EnemyBehavior/EnemyBehavior.h"
#include <math.h>

ItemManager::ItemManager()
{
	for (Item& item : items)
	{
		item.isAlive = false;
	}
}

void ItemManager::Exec()
{
	Spown();
}

void ItemManager::Draw()
{
	for (Item& item : items)
	{
		if (!item.isAlive) { continue; }

		DrawBox(item.pos.X - item.halfWidht, item.pos.Y - item.HalfHeight,
			item.pos.X + item.halfWidht, item.pos.Y + item.HalfHeight, GetColor(255, 0, 0), TRUE);
	}
}

bool ItemManager::CheckHit(EnemyBehavior* enemy_)
{
	for (Item& item : items)
	{
		if (!item.isAlive) { continue; }

		float distanceX = enemy_->GetPos().X - item.pos.X;
		float distanceY = enemy_->GetPos().Y - item.pos.Y;

		if (powf(distanceX, 2.0f) + powf(distanceY, 2.0f) < powf(float(enemy_->GetHalfSize() + item.halfWidht), 2.0f))
		{
			item.isAlive = false;

			return true;
		}
	}

	return false;
}

bool ItemManager::Canlook(EnemyBehavior* enemy_)
{
	for (Item& item : items)
	{
		if (!item.isAlive) { continue; }

		float distanceX = enemy_->GetPos().X - item.pos.X;
		float distanceY = enemy_->GetPos().Y - item.pos.Y;

		if (powf(distanceX, 2.0f) + powf(distanceY, 2.0f) < powf(100.0f, 2.0f))
		{
			enemy_->SetTargetPos(item.pos);

			return true;
		}
	}

	return false;
}

void ItemManager::Spown()
{
	timer++;
	if (timer <= 60 * 1) { return; }

	timer = 0;

	for (Item& item : items)
	{
		if (item.isAlive) { continue; }

		item.pos.X = 30 + GetRand(Widht - 30 * 2);
		item.pos.Y = 30 + GetRand(Height - 30 * 2);
		item.isAlive = true;

		return;
	}
}
