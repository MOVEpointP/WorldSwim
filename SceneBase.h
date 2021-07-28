#ifndef _SCENEBASE_H_
#define _SCENEBASE_H_

#include "DxLib.h"
#include "Player.h"

// �V�[���̃x�[�X�N���X
class SceneBase
{
public:
	// �X�V����
	virtual SceneBase* Update() = 0;
	// �`�揈��
	virtual void Draw() = 0;

	// �R���X�g���N�^
	SceneBase() {};
	// �f�X�g���N�^
	virtual ~SceneBase() {};
};
#endif	//_SCENEBASE_H_
