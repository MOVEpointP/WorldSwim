//-----------------------------------------------------------------------------
// @brief  プレイヤークラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"
#include "Enemy.h"
#include "apple.h"
class Apple;
class EnemyBase;

class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画.

	// 衝突処理.
	void OnHitObstruct(EnemyBase& enemy);
	void OnHitObstructApple(EnemyBase& apple);


	// モデルハンドルの取得.
	int GetModelHandle(){ return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return dir; }
	void SetDir(const VECTOR set) { dir = set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return hitRadius; }

	//ゴールの座標
	VECTOR  goal;
	VECTOR  goalnow;
	//プレイヤーがゴールしているか
	bool goalflag;
	//敵に当たったかどうか、もしあったらゲームオーバー
	bool hitover;

	void rotationY();
	bool GetRotateGameover() {
		return rotateGameover;
	}
	void SetRotateGameover(bool flag) { rotateGameover = flag; }


private:
	int		modelHandle, AttachIndex;;	// モデルハンドル.
	VECTOR	pos;			// ポジション.

	VECTOR	velocity;		// 移動力.

	VECTOR	dir;			// 回転方向.
	float	hitRadius;		// あたり判定の半径.
	int overcount;

	VECTOR  scale;

	bool rotateGameover;
	// 静的定数.
	static const float ACCEL;
	static const float MAX_SPEED;
	static const float DEFAULT_DECEL;
	static const float BREAK_DECEL;
	static const float GRIP_DECEL;
	static const float GRIP_POWER;
	static const float COLIDE_DECEL_FAC;
};

#endif // _PLAYER_H_