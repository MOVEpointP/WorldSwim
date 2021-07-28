#ifndef _PAN_BASE_H_
#define _PAN_BASE_H_

#include "EnemyBase.h"
#include "Enemy.h"

class Pan :public EnemyBase
{
public:
	Pan(int sourceModelHandle);			//コンストラクタ
	virtual ~Pan();						//デストラクタ

	void Update();

	float zcount;							//フライパンのzがどのくらい動いたか数える

private:

	float rad;							//sin移動用のラジアン関数

	// 投げる音
	int panSound;

};

#endif /*_PAN_BASE_H_*/