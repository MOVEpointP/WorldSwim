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
	int GetModelHandle() { return m_stage; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR set) { m_pos = set; }

	// �f�B���N�V������getter/setter.
	const VECTOR& GetDir() const { return m_dir; }
	void SetDir(const VECTOR set) { m_dir = set; }


private:
	int		m_stage;		// ���f���n���h��.
	VECTOR	m_pos;				// �|�W�V����.

	int		m_goal;	// ���f���n���h��.
	VECTOR	m_goalpos;			// �|�W�V����.

	VECTOR	m_velocity;			// �ړ���.

	VECTOR	m_dir;				// ��]����.
	float	m_hitRadius;			// �����蔻��̔��a.

	int     m_arrow;				//���
	int		m_rightarrow;			//�E���
	int		m_leftarrow;			//�����

};

#endif	 // _STAGE_H_