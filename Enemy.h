#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"

class EnemyBase;
class Apple;

// ��Q���̐�.
#define LINE_OBSTRUCT_COL 15
#define LINE_OBSTRUCT_RAW 30

#define OBSTRUCT_SPACE_D 40.0f// ��Q���̏c�Ԋu.
#define OBSTRUCT_SPACE_W 15.0f // ��Q���̉��Ԋu.

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Update();			// �X�V.

	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	//���[�v�p
	int i;

	void CreateEnemy();			//�G�l�~�[����
	void DestroyEnemys();		// �G�l�~�[�폜.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set, int n) { pos = set; }

	// �����蔻�蔼�a�̎擾.
	float GetHitRadius() { return hitRadius; }

	//////�t���C�p�����G�l�~�[�����f����
	//int enemypan[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];

	int floatModelSourceHandle;		//�t���C�p���̑�{�̃n���h��

	// �w��ԍ��̏�Q�����擾.
	EnemyBase* GetEnemy(int raw, int col);


private:

	EnemyBase* enemys[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];
	

	int staticModelSourceHandle;	// �Î~���f���̑�{�̃n���h��.


protected:
	int		modelHandle;			// ���f���n���h��.
	VECTOR	pos;					// �|�W�V����.
	float	hitRadius;				// �����蔻��̔��a.

};

#endif // _ENEMY_H_