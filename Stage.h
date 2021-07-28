#include "DxLib.h"

#ifndef _STAGE_H_
#define _STAGE_H_


class ObstructBase;

class Stage final
{
public:	
	Stage();					// �R���X�g���N�^.
	~Stage();					// �f�X�g���N�^.

	void Update();				// �X�V.
	void Draw();				// �`��.


	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle2; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	// �f�B���N�V������getter/setter.
	const VECTOR& GetDir() const { return dir; }
	void SetDir(const VECTOR set) { dir = set; }


private:
	int		modelHandle2;		// ���f���n���h��.
	VECTOR	pos;				// �|�W�V����.

	int		modelHandlegoal;	// ���f���n���h��.
	VECTOR	goalpos;			// �|�W�V����.

	VECTOR	velocity;			// �ړ���.

	VECTOR	dir;				// ��]����.
	float	hitRadius;			// �����蔻��̔��a.

	int     arrow;				//���
	int		rightarrow;			//�E���
	int		leftarrow;			//�����

};

#endif	 // _STAGE_H_