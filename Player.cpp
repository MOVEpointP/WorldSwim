#include "Player.h"
#include "EnemyBase.h"
#include "apple.h"
#include"GameScene.h"

// 静的定数.
const float Player::m_ACCEL = 0.9f;				// 通常の加速.
const float Player::m_MAX_SPEED = 0.9f;			// 最高速度.
const float Player::m_DEFAULT_DECEL = -0.01f;		// なにもしない時の減速.
const float Player::m_BREAK_DECEL = -0.05f;		// ブレーキ時の減速.
const float Player::m_GRIP_DECEL = -0.025f;		// グリップの減速.
const float Player::m_GRIP_POWER = 0.01f;			// グリップ力.
const float Player::m_COLIDE_DECEL_FAC = 0.4f;	// 障害物にぶつかったときの減速率.

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: m_modelHandle(-1)
	, m_hitRadius(5.0f)
{
	// ３Ｄモデルの読み込み
	m_modelHandle = MV1LoadModel("data/model//Kirby/Kirby.pmx");

	m_pos = VGet(0, 0, 0);

	m_velocity = VGet(0, 0, 0);
	m_dir = VGet(0, 0, 1);
	goal = VGet(0, 0, 1200);//ゴールのポジション

	//goal = VGet(0,0,200);//デバック用ゴールポジション
	goalflag = false;
	hitover = false;	
	m_rotateGameover = false;
	rotationY();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(m_modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Player::Update()
{
	if (!hitover)
	{
		// キー入力取得
		int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// 加速処理.
		VECTOR accelVec = VGet(0, 0, 0);


		if (goal.z >= m_pos.z)
		{
			accelVec = VScale(m_dir, m_ACCEL);

		}
		else if (goal.z <= m_pos.z)
		{
			goalflag = true;
		}

		// 止まっている場合は減速しない.
		if (VSize(m_velocity) > 0)
		{
			// 右か左を押していたらグリップによる減速.
			if (Key & PAD_INPUT_RIGHT || Key & PAD_INPUT_LEFT)
			{
				accelVec = VAdd(accelVec, VScale(m_pos, m_GRIP_DECEL));
			}

			accelVec = VScale(m_pos, m_DEFAULT_DECEL);

		}

		// ベロシティ加速計算.
		m_velocity = VAdd(m_velocity, accelVec);

		// 反対方向に進む状態になっていたら止める.
		if (VDot(m_velocity, m_dir) < 0)
		{
			m_velocity = VGet(0, 0, 0);
		}

		// 止まっていたら左右移動しない.
		if (VSize(m_velocity) > 0)
		{
			// ベロシティの大きさがGRIP_POWERより小さかった場合、GRIP_POWERの大きさをベロシティの大きさと同じにする.
			// これによって曲がるときのベロシティが最大でも45°になる.
			float velSize = VSize(m_velocity);
			float gripPower = m_GRIP_POWER;
			if (gripPower > velSize)
			{
				gripPower = velSize;
			}

			// 右を押していたら右方向に力をかける
			if (Key & PAD_INPUT_RIGHT)
			{
				if (m_pos.x < 70.0f)
				{
					m_velocity = VAdd(m_velocity, VGet(1.0f, 0.0f, 0.0f));
				}
			}
			// 左を押していたら左方向に力をかける
			if (Key & PAD_INPUT_LEFT)
			{
				if (m_pos.x > -70.0f)
				{
					m_velocity = VAdd(m_velocity, VGet(-1.0f, 0.0f, 0.0f));
				}

			}
		}


		// 上下方向にいかないようにベロシティを整える.
		m_velocity = VGet(m_velocity.x, 0, m_velocity.z);

		// ポジションを更新.
		m_pos = VAdd(m_pos, m_velocity);

		// ３Dモデルのポジション設定
		MV1SetPosition(m_modelHandle, m_pos);
	}
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(m_modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  衝突処理.
//-----------------------------------------------------------------------------
void Player::OnHitObstruct(EnemyBase& enemy)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
	// Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(m_pos.x, 0, m_pos.z);
	VECTOR yZeroObstruct = VGet(enemy.GetPos().x, 0, enemy.GetPos().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (m_hitRadius + enemy.GetHitRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_pos = VAdd(yZeroObstruct, awayVec);

	// ぶつかったら減速する.
	m_velocity = VScale(m_velocity, m_COLIDE_DECEL_FAC);
}

void Player::OnHitObstructApple(EnemyBase& apple)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
// Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(m_pos.x, 0, m_pos.z);
	VECTOR yZeroObstruct = VGet(0, 0, 1);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (m_hitRadius + apple.GetHitRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_pos = VAdd(yZeroPlayer, yZeroObstruct);

	//// ぶつかったら減速する.
	m_velocity = VScale(m_velocity, m_COLIDE_DECEL_FAC);

}	 

void Player ::rotationY()
{
	MATRIX tmpMat = MV1GetMatrix(m_modelHandle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(m_modelHandle, tmpMat);

}

