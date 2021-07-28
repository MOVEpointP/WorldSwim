#ifndef _APPLE_H_
#define _APPLE_H_

#include "DxLib.h"

class EnemyBase;
class Apple;

// ��Q���̐�.
#define LINE_OBSTRUCT_COL 15
#define LINE_OBSTRUCT_RAW 30

#define OBSTRUCT_SPACE_D 40.0f// ��Q���̏c�Ԋu.
#define OBSTRUCT_SPACE_W 15.0f // ��Q���̉��Ԋu.

class Apple
{
public:
	Apple();
	~Apple();

	void Update();			// �X�V.

	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	//���[�v�p
	int i;
	int getapplepoint;

	void CreateApple();			//�G�l�~�[����
	void DestroyApple();		// �G�l�~�[�폜.
	EnemyBase* DestroyAppleHit(int raw,int col);

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set, int n) { pos = set; }

	// �����蔻�蔼�a�̎擾.
	float GetHitRadius() { return hitRadius; }



	// �w��ԍ��̏�Q�����擾.
	EnemyBase* GetApple(int raw, int col);


private:

	EnemyBase* apple[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];


	int appleModelSourceHandle;		//apple�̑�{�̃n���h��


protected:


	int		modelHandle;			// ���f���n���h��.
	VECTOR	pos;					// �|�W�V����.
	float	hitRadius;				// �����蔻��̔��a.

};

#endif // _APPLE_H_