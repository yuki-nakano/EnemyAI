#include "DxLib.h"
#include "Definition.h"
#include "Manager/InputManager.h"
#include "Manager/TextureManager.h"
#include "EnemyState/EnemyState.h"
#include "EnemyBehavior/EnemyBehavior.h"
#include "Item.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(Widht, Height, 16);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("enemy課題");

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラスの作成
	InputManager::CreateInstance();
	InputManager* inputManager = InputManager::GetInstance();
	TextureManager::CreateInstance();

	ItemManager::CreateInstance();
	ItemManager* item = ItemManager::GetInstance();
	EnemyState* enemyState = new EnemyState;
	EnemyBehavior* enemyBehavior = new EnemyBehavior;


	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 ||
			inputManager->IsKeyPushed(KEY_INPUT_ESCAPE))
		{
			break;        // エラーが起きたらループを抜ける
		}
		else
		{
			//フレームごとにキーの状態更新
			inputManager->UpdateKeyStatus();

			ClearDrawScreen();
			clsDx();

			//処理
			enemyState->Exec();
			enemyBehavior->Exec();
			item->Exec();

			//描画
			enemyState->Draw();
			enemyBehavior->Draw();
			item->Draw();

			ScreenFlip();
		}
	}

	inputManager = nullptr;
	TextureManager::DeleteInstance();
	InputManager::DeleteInstance();

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}
