#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"

class EnemyBase;
class Apple;

// ��Q���̐�.
#define LINE_OBSTRUCT_COL 15
#define LINE_OBSTRUCT_RAW 30

#define OBSTRUCT_SPACE_D 40.0f	// ��Q���̏c�Ԋu.
#define OBSTRUCT_SPACE_W 15.0f	// ��Q���̉��Ԋu.

class Enemy
{
public:
	Enemy();				//�R���X�g���N�^
	~Enemy();			    //�f�X�g���N�^

	void Update();			// �X�V.

	void Draw();			// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	void CreateEnemy();				//�G�l�~�[����
	void DestroyEnemys();			// �G�l�~�[�폜.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR _set, int _n) { pos = _set; }

	// �����蔻�蔼�a�̎擾.
	float GetHitRadius() { return hitRadius; }

	int floatModelSourceHandle;		//�t���C�p���̑�{�̃n���h��

	// �w��ԍ��̏�Q�����擾.
	EnemyBase* GetEnemy(int _raw, int _col);


private:

	class EnemyBase* m_enemys[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];//	�G�l�~�[�x�[�X�N���X�ւ̃|�C���^�����o�ϐ�	
	

	int m_staticModelSourceHandle;	// �Î~���f���̑�{�̃n���h��.


protected:
	int		modelHandle;			// ���f���n���h��.
	VECTOR	pos;					// �|�W�V����.
	float	hitRadius;				// �����蔻��̔��a.

};

#endif // _ENEMY_H_