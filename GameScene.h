#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "SceneBase.h"
#include "Player.h"


// �O���錾
class Camera;
class Player;
class Stage;
class Enemy;
class Apple;
class MapChipClass;

// �Q�[���V�[��
class GameScene : public SceneBase
{
public:
	// �X�V����
	SceneBase* Update() override;
	// �`�揈��
	void Draw() override;

	// �R���X�g���N�^
	GameScene();
	// �f�X�g���N�^
	~GameScene();

	int meter;
	int now;


private:
	// �J���T�L�̉�
	int hitOverSound;
	// �Q�[���I�[�o�[�̉�
	int OverSound;
	// ���̌�����
	int kawasakiOverSound;
	// �Q�[���V�[���̉��y
	int GameSceneSound;
	// �v���C���[�̃|�C���^
	Player* player;
	// �J�����̃|�C���^
	Camera* camera;
	//�X�e�[�W�̃|�C���^
	Stage* stage;
	//�G�l�~�[�̃|�C���^
	Enemy* enemy;

	Apple* apple;

	MapChipClass* map;

	MapChipClass* gauge;

	int kawasakicount;
};
#endif	//_GAMESCENE_H_