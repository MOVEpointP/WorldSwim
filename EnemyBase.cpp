#include "EnemyBase.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
EnemyBase::EnemyBase(int _sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(-1)
{
	pos = VGet(0, 0, 0);

	// ３Ｄモデルの読み込み
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(_sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("データ読み込みに失敗. sourceId:%d", _sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("data/model/Kawasaki/Kawasaki.pmx");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:データ読み込みに失敗");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
EnemyBase::~EnemyBase()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void EnemyBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}