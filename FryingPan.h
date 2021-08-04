//-----------------------------------------------------------------------------
// フライパン処理.
//-----------------------------------------------------------------------------

#ifndef _PAN_BASE_H_
#define _PAN_BASE_H_

#include "EnemyBase.h"
#include "Enemy.h"

class FryingPan :public EnemyBase
{
public:
	FryingPan(int _sourceModelHandle);			//コンストラクタ
	virtual ~FryingPan();							//デストラクタ

	void Update();

	float zcount;							//フライパンのzがどのくらい動いたか数える

private:

	float m_rad;							//sin移動用のラジアン関数

	int m_panSound;							// 投げる音

};

#endif /*_PAN_BASE_H_*/

