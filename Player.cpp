#include "Player.h"
#include "EnemyBase.h"
#include "apple.h"
#include"GameScene.h"

// 静的定数.
const float Player::ACCEL = 0.9f;				// 通常の加速.
const float Player::MAX_SPEED = 0.9f;			// 最高速度.
const float Player::DEFAULT_DECEL = -0.01f;		// なにもしない時の減速.
const float Player::BREAK_DECEL = -0.05f;		// ブレーキ時の減速.
const float Player::GRIP_DECEL = -0.025f;		// グリップの減速.
const float Player::GRIP_POWER = 0.01f;			// グリップ力.
const float Player::COLIDE_DECEL_FAC = 0.4f;	// 障害物にぶつかったときの減速率.

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
	: modelHandle(-1)
	, hitRadius(5.0f)
{
	// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/model//Kirby/Kirby.pmx");

	pos = VGet(0, 0, 0);

	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);
	goal = VGet(0, 0, 1200);//ゴールのポジション

	//goal = VGet(0,0,200);//デバック用ゴールポジション
	goalnow = VGet(0, 0, 0);
	goalflag = false;
	hitover = false;	
	rotateGameover = false;
	rotationY();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
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


		if (goal.z >= pos.z)
		{
			accelVec = VScale(dir, ACCEL);

		}
		else if (goal.z <= pos.z)
		{
			goalflag = true;
		}

		// 止まっている場合は減速しない.
		if (VSize(velocity) > 0)
		{
			// 右か左を押していたらグリップによる減速.
			if (Key & PAD_INPUT_RIGHT || Key & PAD_INPUT_LEFT)
			{
				accelVec = VAdd(accelVec, VScale(pos, GRIP_DECEL));
			}

			accelVec = VScale(pos, DEFAULT_DECEL);

		}

		// ベロシティ加速計算.
		velocity = VAdd(velocity, accelVec);

		// 反対方向に進む状態になっていたら止める.
		if (VDot(velocity, dir) < 0)
		{
			velocity = VGet(0, 0, 0);
		}

		// 止まっていたら左右移動しない.
		if (VSize(velocity) > 0)
		{
			// ベロシティの大きさがGRIP_POWERより小さかった場合、GRIP_POWERの大きさをベロシティの大きさと同じにする.
			// これによって曲がるときのベロシティが最大でも45°になる.
			float velSize = VSize(velocity);
			float gripPower = GRIP_POWER;
			if (gripPower > velSize)
			{
				gripPower = velSize;
			}

			// 右を押していたら右方向に力をかける
			if (Key & PAD_INPUT_RIGHT)
			{
				if (pos.x < 70.0f)
				{
					velocity = VAdd(velocity, VGet(1.0f, 0.0f, 0.0f));
				}
			}
			// 左を押していたら左方向に力をかける
			if (Key & PAD_INPUT_LEFT)
			{
				if (pos.x > -70.0f)
				{
					velocity = VAdd(velocity, VGet(-1.0f, 0.0f, 0.0f));
				}

			}
		}


		// 上下方向にいかないようにベロシティを整える.
		velocity = VGet(velocity.x, 0, velocity.z);

		// ポジションを更新.
		pos = VAdd(pos, velocity);

		// ３Dモデルのポジション設定
		MV1SetPosition(modelHandle, pos);
	}
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  衝突処理.
//-----------------------------------------------------------------------------
void Player::OnHitObstruct(EnemyBase& enemy)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
	// Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(pos.x, 0, pos.z);
	VECTOR yZeroObstruct = VGet(enemy.GetPos().x, 0, enemy.GetPos().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (hitRadius + enemy.GetHitRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	pos = VAdd(yZeroObstruct, awayVec);

	// ぶつかったら減速する.
	velocity = VScale(velocity, COLIDE_DECEL_FAC);
}

void Player::OnHitObstructApple(EnemyBase& apple)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
// Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(pos.x, 0, pos.z);
	VECTOR yZeroObstruct = VGet(0, 0, 1);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (hitRadius + apple.GetHitRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	pos = VAdd(yZeroPlayer, yZeroObstruct);

	//// ぶつかったら減速する.
	velocity = VScale(velocity, COLIDE_DECEL_FAC);

}	 

void Player ::rotationY()
{
	MATRIX tmpMat = MV1GetMatrix(modelHandle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(modelHandle, tmpMat);

}

