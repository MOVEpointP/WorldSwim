#pragma once
#ifndef _OBSTRUCT_STATIC_H_
#define _OBSTRUCT_STATIC_H_

#include "EnemyBase.h"

class AppleStatic : public EnemyBase
{
public:
	AppleStatic(int sourceModelHandle);		// コンストラクタ.
	virtual ~AppleStatic();					// デストラクタ.


	void Update();							// 更新.
};

#endif // _OBSTACLE_BASE_H_

