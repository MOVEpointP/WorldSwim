#include "GameOver.h"
#include "TitleScene.h"

// �R���X�g���N�^
GameOver::GameOver()
	: count(0)
	, number(0)
	, change(0)
	, push(0)


{
	// �Q�[���N���A�摜�ǂݍ���
	gameOverImg[0] = LoadGraph("data/texture/GameOver.png");
	gameOverImg[1] = LoadGraph("data/texture/GameOver2.png");
	push = LoadSoundMem("data/Sound/push.MP3");

	// �Q�[���I�[�o�[���y�Đ�
	PlaySoundFile("data/Sound/OverMusic.wav", DX_PLAYTYPE_LOOP);

}

// �f�X�g���N�^
GameOver::~GameOver()
{
	//�����Ȃ�
}

// �X�V����
SceneBase* GameOver::Update()
{
	// Enter�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_RETURN))
	{

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
void GameOver::Draw()
{

	change++;

	if (change >= 50)
	{
		count++;

		number = count % 2;
		change = 0;
	}

	// �摜�\��
	DrawGraph(0, 0, gameOverImg[number], false);
}
