#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "SceneBase.h"
#include "fade.h"

// �^�C�g���V�[��
class TitleScene : public SceneBase
{
public:
	// �X�V����
	SceneBase* Update() override;
	// �`�揈��
	void Draw() override;

	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

private:
	// �^�C�g���摜
	int titleImg[3];
	int titlepushSound;

	//�t�F�[�h�C���A�t�F�[�h�A�E�g�Ɏg���ϐ�
	bool fade;
	int FeedInCount;
	int FeedOutCount;
	//�摜���R�}���肷��ϐ�
	int number;
	int count;
	int change;


	//�^�C�g�����y
	int titleSound;


	Fade<int> inout;
};
#endif	_TITLESCENE_H_