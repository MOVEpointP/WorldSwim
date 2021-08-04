//-----------------------------------------------------------------------------
// @brief  障害物：動かない.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#ifndef _OBSTRUCT_STATIC_H_
#define _OBSTRUCT_STATIC_H_

#include "EnemyBase.h"

class EnemyStatic : public EnemyBase
{
public:
	EnemyStatic(int _sourceModelHandle);		// コンストラクタ.
	virtual ~EnemyStatic();						// デストラクタ.

	void Update();								// 更新.
};

#endif // _OBSTACLE_BASE_H_

