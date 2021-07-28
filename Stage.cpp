#include "Stage.h"
#include "Player.h"
#include "EnemyBase.h"


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Stage::Stage()
	: modelHandle2(-1)
	, hitRadius(5.0f)
	,modelHandlegoal(-1)
{
	// ３Ｄモデルの読み込み
	modelHandle2 = MV1LoadModel("data/model/stage3/Old Town.pmx");
	modelHandlegoal = MV1LoadModel("data/インハイゴールゲート/★インハイゴールサイドパネルつき.pmx");
	
	arrow = LoadGraph("data/texture/Arrow.png");
	rightarrow = LoadGraph("data/texture/Right arrow.png");
	leftarrow = LoadGraph("data/texture/Left arrow.png");


	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);

	goalpos= VGet(0, 0, 1200);

	MV1SetScale(modelHandle2, VGet(1.0f, 1.0f, 2.0f));//ステージ長くしてるよ
	MV1SetScale(modelHandlegoal, VGet(2.0f, 1.0f, 2.0f));//ゴールゲート長くしてるよ

}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Stage::~Stage()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle2);
	MV1DeleteModel(modelHandlegoal);

}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Stage::Update()
{
	// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// 加速処理.
	VECTOR accelVec = VGet(0, 0, 0);


	// ベロシティ加速計算.
	velocity = VAdd(velocity, accelVec);


	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle2, pos);

	MV1SetPosition(modelHandlegoal, goalpos);


}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Stage::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle2);
	MV1DrawModel(modelHandlegoal);

	DrawGraph(0, 0, arrow, true);//常に出る矢印のアイコン
		// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & PAD_INPUT_LEFT)//もし、右キーが入力されたらアイコンに色がつく
	{
		DrawGraph(0, 0, leftarrow, true);
	}
	if (Key & PAD_INPUT_RIGHT)//もし、右キーが入力されたらアイコンに色がつく
	{
		DrawGraph(0, 0, rightarrow, true);
	}

}

