#pragma once

#include "SceneBase.h"


// �Q�[���N���A
class GameClear : public SceneBase
{
public:
	// �X�V����
	SceneBase* Update() override;
	// �`�揈��
	void Draw() override;

	// �R���X�g���N�^
	GameClear();
	// �f�X�g���N�^
	~GameClear();

private:
	// �Q�[���N���A�摜
	int gameClearImg[2];
	//��ʂ��R�}����ɂ���Ƃ��Ɏg���ϐ�
	int number;
	int count;
	int change;

	//�L�[���������Ƃ��̌��ʉ�
	int push;

	int gameClearSound;

};
