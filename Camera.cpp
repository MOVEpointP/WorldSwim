//-----------------------------------------------------------------------------
// @brief  カメラクラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Player.h"
#include "Camera.h"

#define USE_LERP_CAMERA 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
{
    //奥行0.1～1000までをカメラの描画範囲とする
    SetCameraNearFar(20.0f, 1300.0f);

    pos = VGet(0, 0, 0);
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
    // 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Camera::Update(const Player& player)
{
#if !USE_LERP_CAMERA
    // z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
    pos = VGet(0, player.GetPos().y + 20.0f, player.GetPos().z - 30.0f);
#else
    // lerpを使用して実装.
    // lerp(VECTOR a, VECTOR b, float t)は
    // answer = a + ((b-a) * t)

    // カメラの位置をプレイヤーの後ろに来るように設定
    VECTOR aimPos = VAdd(player.GetPos(), VScale(player.GetDir(), -30.0f));
    // カメラのy座標を設定
    aimPos = VAdd(aimPos, VGet(0, 25.0f, 0));
    // 見たい位置と今のカメラの位置の差分を求める
    VECTOR posToAim = VSub(aimPos, pos);
    // なんやこれ←気持ちわかる
    VECTOR scaledPosToAim = VScale(posToAim, 1.0f);
    // カメラのポジションを更新
    pos = VAdd(pos, scaledPosToAim);
#endif
    // カメラの注視点を設定
    SetCameraPositionAndTarget_UpVecY(pos, VAdd(player.GetPos(), VGet(0.0f, 0.0f, 50.0f)));
}