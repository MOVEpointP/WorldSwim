#include "GameScene.h"
#include "Player.h"
#include "Camera.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Stage.h"
#include "DxLib.h"
#include "HitChecker.h"
#include "Enemy.h"
#include "apple.h"
#include "MapChip.h"


// �R���X�g���N�^
GameScene::GameScene()
	: m_hitOverSound(0)
	, player(nullptr)
	, camera(nullptr)
	, stage(nullptr)
	,apple(nullptr)
	, m_kawasakiOverSound(0)
	, m_GameSceneSound(0)
	, m_OverSound(0)
	,gauge(0)
	,meter(0)
	,now(0)
	,m_kawasakicount(0)
	
{
	// ���t�@�C����ǂݍ���
	m_hitOverSound = LoadSoundMem("data/Sound/kawasaki.wav");

	m_OverSound = LoadSoundMem("data/Sound/Over.wav");
	m_kawasakiOverSound = LoadSoundMem("data/Sound/kawasakiOver.wav");
	// ���t�@�C����ǂݍ���(�Q�[���V�[���j
	m_GameSceneSound = LoadSoundMem("data/Sound/GameScene.wav");


	// �v���C���[�𐶐�.
	player = new Player();

	// �J�����𐶐�.
	camera = new Camera();

	// �X�e�[�W�𐶐�
	stage = new Stage();

	// �G�l�~�[�𐶐�.
	enemy = new Enemy();
	enemy->CreateEnemy();
	//�X�R�A�\���𐶐�
	Score = new MapChipClass();
	//�����S�𐶐�
	apple = new Apple();
	apple->CreateApple();
	//�S�[���܂ł̋�����\���Q�[�W�𐶐�
	gauge = new MapChipClass();

	// �Q�[���V�[���̉��y�Đ�
	PlaySoundFile("data/Sound/GameScene.wav", DX_PLAYTYPE_LOOP);
}

// �f�X�g���N�^
GameScene::~GameScene()
{
	// �v���C���[���폜.
	delete(player);
	// �J�������폜.
	delete(camera);
	//�X�e�[�W�𐶐�
	delete(stage);

	//// �G�l�~�[���폜.
	enemy->DestroyEnemys();
	delete(enemy);
	//�X�R�A���폜
	delete(Score);
	//�����S���폜
	delete(apple);
	//�Q�[�W���폜
	delete(gauge);
}

// �X�V����
SceneBase* GameScene::Update()
{
	// �v���C���[����.
	player->Update();
	// �J��������.
	camera->Update(*player);
	//�X�e�[�W�̐���
	stage->Update();

	//�G�l�~�[����.
	enemy->Update();
	//�����S�̐���
	apple->Update();

	// �q�b�g�̃`�F�b�N.
	HitChecker::Check(*player, *enemy);
	//�����S�̃q�b�g�`�F�b�N
	HitChecker::Checkapple(*player, *apple);





	// �v���C���[���S�[��������
	if (player->goalflag == true)
	{
		// �e�L�X�g����
		clsDx();

		// GameClear�ɑJ��
		return new GameClear();
	}

	// �v���C���[���J���T�Lor�t���C�p���ɓ���������
	if (player->hitover==true)
	{

		if (!player->GetRotateGameover())
		{
			// ���Đ�
			PlaySoundFile("data/Sound/kawasakiOver.wav", DX_PLAYTYPE_BACK);
			player->rotationY();
			player->SetRotateGameover(true);
		}

		m_kawasakicount++;
		if (m_kawasakicount>240)
		{

			// GameOver�ɑJ��
			return new GameOver();

		}

		// �e�L�X�g����
		clsDx();

	}

	// �����̃|�C���^��Ԃ�
	return this;
}

// �`�揈��
void GameScene::Draw()
{
	// �v���C���[�`��.
	player->Draw();

	//�X�e�[�W�`��.
	stage->Draw();


	// �G�l�~�[�`��.S
	enemy->Draw();

	//�����S�̕`��
	apple->Draw();


	//�����S�������������
	int point = apple->getapplepoint;
	//�X�R�A�\��
	int score = point / 10;
	int score2 = point % 10;
	Score->DrawArrayMapChip(0, score);
	Score->DrawArrayMapChip(1, score2);
	Score->DrawArrayMapChip(2, 0);
	Score->DrawArrayMapChip(3, 0);

	//�Q�[�����n�܂�����J�E���g����
	now++;
	//�J�E���g�����܂ł���ƃ��[�^�[������܂�
	if (now==346)
	{
		meter++;
		now = 0;
	}

	gauge->Drawgauge(meter);

}
