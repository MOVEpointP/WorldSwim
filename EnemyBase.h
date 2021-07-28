#ifndef _ENEMY_BASE_H_
#define _ENEMY_BASE_H_

#include "DxLib.h"

class EnemyBase
{
public:
	EnemyBase(int sourceModelHandle);		// コンストラクタ.
	virtual ~EnemyBase();					// デストラクタ.

	virtual void Update() = 0;				// 更新.
	virtual void Draw();					// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }
	float GetHitRadius() { return hitRadius; }

protected:
	int		modelHandle;					// モデルハンドル.
	VECTOR	pos;							// ポジション.
	float	hitRadius;						// あたり判定の半径.
};

#endif // _ENEMY_BASE_H_