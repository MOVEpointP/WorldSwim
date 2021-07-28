//-----------------------------------------------------------------------------
//  フライパンの処理
//-----------------------------------------------------------------------------
#include "Pan.h"
#include "Enemy.h"
#include "EnemyStatic.h"
#include "Player.h"

#define _USE_MATH_DEFINES
#include <math.h>

//-----------------------------------------------------------------------------
//  コンストラクタ.
//-----------------------------------------------------------------------------
Pan::Pan(int sourceModelHandle)
    :EnemyBase(sourceModelHandle)
    , zcount(0)
{
    pos = VGet(0, 0, 0);
    rad = 0;
    hitRadius = 3.0f;

    // 投げる音読み込み
    panSound = LoadSoundMem("data/Sound/Frypan.mp3");

}
//-----------------------------------------------------------------------------
//  デストラクタ.
//-----------------------------------------------------------------------------
Pan::~Pan()
{
    //処理なし
}


//-----------------------------------------------------------------------------
//  更新.
//-----------------------------------------------------------------------------
void Pan::Update()
{
    rad += static_cast<float>((M_PI / 180) * 5);//static_castは暗黙の型変換を明示するもの。省略可

    //yの高さ、上下の揺れを作る
    pos.y = 10.0f + sinf(rad);

    //フライパンが‐100進んだら座標を100戻す
    zcount++;
    if (zcount == 200)
    {
        pos.z += 200;
        zcount = 0;

        // 音の再生を開始
        PlaySoundMem(panSound, DX_PLAYTYPE_BACK);
    }
    else
    {
        pos.z--;
    }

    //3Dモデルのポジション設定
    MV1SetPosition(modelHandle, pos);
}
