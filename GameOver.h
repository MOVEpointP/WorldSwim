#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "SceneBase.h"

// �Q�[���I�[�o�[
class GameOver : public SceneBase
{
public:
	// �X�V����
	SceneBase* Update() override;
	// �`�揈��
	void Draw() override;

	// �R���X�g���N�^
	GameOver();
	// �f�X�g���N�^
	~GameOver();

private:
	// �Q�[���N���A�摜
	int gameOverImg[2];
	//��ʂ��R�}����ɂ���Ƃ��Ɏg���ϐ�
	int number;
	int count;
	int change;

	int push;


};
#endif	//_GAMEOVER_H_