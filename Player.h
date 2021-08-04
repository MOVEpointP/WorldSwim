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
	int GetModelHandle(){ return m_modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR set) { m_pos = set; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return m_dir; }
	void SetDir(const VECTOR set) { m_dir = set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return m_hitRadius; }

	//ゴールの座標
	VECTOR  goal;

	//プレイヤーがゴールしているか
	bool goalflag;
	//敵に当たったかどうか、もしあったらゲームオーバー
	bool hitover;

	void rotationY();
	bool GetRotateGameover() {
		return m_rotateGameover;
	}
	void SetRotateGameover(bool flag) { m_rotateGameover = flag; }


private:
	int		m_modelHandle, m_AttachIndex;;	// モデルハンドル.
	VECTOR	m_pos;			// ポジション.

	VECTOR	m_velocity;		// 移動力.

	VECTOR	m_dir;			// 回転方向.
	float	m_hitRadius;		// あたり判定の半径.
	int m_overcount;

	VECTOR  m_scale;

	bool m_rotateGameover;
	// 静的定数.
	static const float m_ACCEL;
	static const float m_MAX_SPEED;
	static const float m_DEFAULT_DECEL;
	static const float m_BREAK_DECEL;
	static const float m_GRIP_DECEL;
	static const float m_GRIP_POWER;
	static const float m_COLIDE_DECEL_FAC;
};

#endif // _PLAYER_H_