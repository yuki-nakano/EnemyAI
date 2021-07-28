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
	//�e�N�X�`���f�[�^�̏�����
	void LoadTextures();

	//�e�N�X�`���f�[�^�̍폜
	void DeleteTextures();

	//�e�N�X�`���f�[�^�̎擾
	int GetTextureDate(TextureDate num);

private:
	int textureDate[(int)TextureDate::kTextureMax];
	char pass[(int)TextureDate::kTextureMax][100] =
	{

	};
};

#endif // !TEXTURE_MANAGER_H
