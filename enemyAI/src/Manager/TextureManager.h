#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "DxLib.h"
#include "../Definition.h"
#include "../Singleton.h"

enum class TextureDate
{
	ktmp,

	kTextureMax
};

class TextureManager : public Singleton<TextureManager>
{
public:
	//テクスチャデータの初期化
	void LoadTextures();

	//テクスチャデータの削除
	void DeleteTextures();

	//テクスチャデータの取得
	int GetTextureDate(TextureDate num);

private:
	int textureDate[(int)TextureDate::kTextureMax];
	char pass[(int)TextureDate::kTextureMax][100] =
	{

	};
};

#endif // !TEXTURE_MANAGER_H
