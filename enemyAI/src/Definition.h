#ifndef DEFINITION_H
#define DEFINITION_H

#include "DxLib.h"

//画面サイズ
const int Widht = 640;
const int Height = 480;

//プレイヤーのサイズ
const int PlayerWidht = 30;
const int PlayerHeight = 60;

//ボスのサイズ
const int BossWidht = 160;
const int BossHeight = 90;

struct Vec2
{
	Vec2() :
		X(0.0f),
		Y(0.0f)
	{
	}

	Vec2(float x, float y) :
		X(x),
		Y(y)
	{
	}

	float X;
	float Y;
};


enum Direction
{
	kRight, //右向き
	kLeft,	//左向き
};

enum SceneID
{
	//タイトルシーン
	SceneID_Title,
	//ゲームシーン
	SceneID_InGame,
	
	SceneID_Max,
	SceneID_Invalid,	//無効値
};

#endif // !DEFINITION_H
