#pragma once
#ifndef _OBSTRUCT_STATIC_H_
#define _OBSTRUCT_STATIC_H_

#include "EnemyBase.h"

class AppleStatic : public EnemyBase
{
public:
	AppleStatic(int sourceModelHandle);		// �R���X�g���N�^.
	virtual ~AppleStatic();					// �f�X�g���N�^.


	void Update();							// �X�V.
};

#endif // _OBSTACLE_BASE_H_

