#ifndef _PAN_BASE_H_
#define _PAN_BASE_H_

#include "EnemyBase.h"
#include "Enemy.h"

class Pan :public EnemyBase
{
public:
	Pan(int sourceModelHandle);			//�R���X�g���N�^
	virtual ~Pan();						//�f�X�g���N�^

	void Update();

	float zcount;							//�t���C�p����z���ǂ̂��炢��������������

private:

	float rad;							//sin�ړ��p�̃��W�A���֐�

	// �����鉹
	int panSound;

};

#endif /*_PAN_BASE_H_*/