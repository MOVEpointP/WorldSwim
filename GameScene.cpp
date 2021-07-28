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
	: hitOverSound(0)
	, player(nullptr)
	, camera(nullptr)
	, stage(nullptr)
	,apple(nullptr)
	, kawasakiOverSound(0)
	, GameSceneSound(0)
	, OverSound(0)
	,gauge(0)
	,meter(0)
	,now(0)
	,kawasakicount(0)
	
{
	// ���t�@�C����ǂݍ���
	hitOverSound = LoadSoundMem("data/Sound/kawasaki.wav");

	OverSound = LoadSoundMem("data/Sound/Over.wav");
	kawasakiOverSound = LoadSoundMem("data/Sound/kawasakiOver.wav");
	// ���t�@�C����ǂݍ���(�Q�[���V�[���j
	GameSceneSound = LoadSoundMem("data/Sound/GameScene.wav");


	// �v���C���[�𐶐�.
	player = new Player();

	// �J�����𐶐�.
	camera = new Camera();

	// �X�e�[�W�𐶐�
	stage = new Stage();

	// �G�l�~�[�𐶐�.
	enemy = new Enemy();
	enemy->CreateEnemy();

	map = new MapChipClass();

	apple = new Apple();
	apple->CreateApple();

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

	delete(stage);

	//// �G�l�~�[���폜.
	enemy->DestroyEnemys();

	delete(enemy);

	delete(map);

	delete(apple);

	delete(gauge);
}

// �X�V����
SceneBase* GameScene::Update()
{
	// �v���C���[����.
	player->Update();
	// �J��������.
	camera->Update(*player);

	stage->Update();

	//�G�l�~�[����.
	enemy->Update();

	apple->Update();

	// �q�b�g�̃`�F�b�N.
	HitChecker::Check(*player, *enemy);

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

		kawasakicount++;
		if (kawasakicount>240)
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


	apple->Draw();



	int point = apple->getapplepoint;

	int score = point / 10;
	int score2 = point % 10;
	map->DrawArrayMapChip(0, score);
	map->DrawArrayMapChip(1, score2);
	map->DrawArrayMapChip(2, 0);
	map->DrawArrayMapChip(3, 0);


	now++;

	if (now==346)
	{
		meter++;
		now = 0;
	}

	gauge->Drawgauge(meter);

}
