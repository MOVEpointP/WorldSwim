//-----------------------------------------------------------------------------
// �t���C�p������.
//-----------------------------------------------------------------------------

#ifndef _PAN_BASE_H_
#define _PAN_BASE_H_

#include "EnemyBase.h"
#include "Enemy.h"

class FryingPan :public EnemyBase
{
public:
	FryingPan(int _sourceModelHandle);			//�R���X�g���N�^
	virtual ~FryingPan();							//�f�X�g���N�^

	void Update();

	float zcount;							//�t���C�p����z���ǂ̂��炢��������������

private:

	float m_rad;							//sin�ړ��p�̃��W�A���֐�

	int m_panSound;							// �����鉹

};

#endif /*_PAN_BASE_H_*/

