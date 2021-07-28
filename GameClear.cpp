#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_


#include "GameClear.h"
#include "TitleScene.h"
#include "Player.h"


// �R���X�g���N�^
GameClear::GameClear()
	: count(0)
	, number(0)
	, change(0)
	, push(0)
	, gameClearSound(0)



{
	// �Q�[���N���A�摜�ǂݍ���
	gameClearImg[0] = LoadGraph("data/texture/GameClear.png");
	gameClearImg[1] = LoadGraph("data/texture/GameClear2.png");

	push = LoadSoundMem("data/Sound/push.MP3");

	// �Q�[���N���A���ǂݍ���
	gameClearSound = LoadSoundMem("data/Sound/Clear.wav");
	
		// �Q�[���N���A���y�Đ�
	PlaySoundFile("data/Sound/Clear.wav", DX_PLAYTYPE_BACK);

}

// �f�X�g���N�^
GameClear::~GameClear()
{
	//�����Ȃ�
}

// �X�V����
SceneBase* GameClear::Update()
{

	// Enter�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		//�L�[������������ʉ�����
		PlaySoundMem(push, DX_PLAYTYPE_NORMAL);

		// �e�L�X�g����
		clsDx();

		// TitleScene�ɑJ��
		return new TitleScene();
	}

	// �����̃|�C���^��Ԃ�
	return this;
}

// �`�揈��
void GameClear::Draw()
{


	//�摜���R�}����ŕ\������
	change++;

	if (change >= 50)
	{
		count++;

		number = count % 2;
		change = 0;
	}


	// �摜�\��
	DrawGraph(0, 0, gameClearImg[number], false);


}

#endif