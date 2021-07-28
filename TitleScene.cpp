#include "TitleScene.h"
#include "GameScene.h"


// �R���X�g���N�^
TitleScene::TitleScene()
	: fade(false)
	, FeedInCount(0)
	, FeedOutCount(255)
	,count(0)
	,number(0)
	,change(0)

{
	// �^�C�g���摜�ǂݍ���
	titleImg[0] = LoadGraph("data/texture/Game title.png");
	titleImg[1] = LoadGraph("data/texture/Game title2.png");
	titleImg[2] = LoadGraph("data/texture/Game title3.png");

	//�L�[���������Ƃ��̌��ʉ�
	titlepushSound = LoadSoundMem("data/Sound/push.MP3");

	//���t�@�C���ǂݍ���
	titleSound = LoadSoundMem("data/Sound/Title.wav");

	//���Đ�
	PlaySoundFile("data/Sound/Title.wav", DX_PLAYTYPE_LOOP);


}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
	//�����Ȃ�
}

// �X�V����
SceneBase* TitleScene::Update()
{
	// Enter�L�[�������ꂽ��
	if (CheckHitKey(KEY_INPUT_RETURN))
	{

		fade = true;

		//�摜���R�}����ŕ\������
		PlaySoundMem(titlepushSound, DX_PLAYTYPE_NORMAL);

		for (int i=0; i < 255; i++)
		{
			ClearDrawScreen();                   // ����ʂ̃f�[�^��S�č폜

			inout.set(fade, titleImg[number]);

			// ����ʂ̓��e��\��ʂɔ��f������
			ScreenFlip();
		}
		// �e�L�X�g����
		clsDx();
		return new GameScene();
	}

	// �����̃|�C���^��Ԃ�
	return this;
}

// �`�揈��
void TitleScene::Draw()
{
	//�摜���R�}����ŕ\������

	change++;

	if (change >= 50)
	{
		count++;

		number = count % 3;
		change = 0;
	}


	if (!fade)
	{
		//�t�F�[�h�C��
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedInCount);
		DrawGraph(0, 0, titleImg[number], true);
		FeedInCount++;
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	//else
	//{
	//	//�t�F�[�h�A�E�g
	//	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedOutCount);
	//	//DrawGraph(0, 0, titleImg[number], false);
	//	//FeedOutCount--;
	//	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}


	// �摜�\��
	DrawGraph(0, 0, titleImg[number], false);
}