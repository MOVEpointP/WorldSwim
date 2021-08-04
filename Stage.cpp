#include "Stage.h"
#include "Player.h"
#include "EnemyBase.h"


//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Stage::Stage()
	: m_stage(-1)
	, m_hitRadius(5.0f)
	,m_goal(-1)
{
	// ３Ｄモデルの読み込み
	m_stage = MV1LoadModel("data/model/stage3/Old Town.pmx");
	m_goal = MV1LoadModel("data/インハイゴールゲート/★インハイゴールサイドパネルつき.pmx");
	
	//矢印の画像読み込み
	m_arrow = LoadGraph("data/texture/Arrow.png");
	m_rightarrow = LoadGraph("data/texture/Right arrow.png");
	m_leftarrow = LoadGraph("data/texture/Left arrow.png");

	//プレイヤーのポジション
	m_pos = VGet(0, 0, 0);

	m_goalpos= VGet(0, 0, 1200);

	MV1SetScale(m_stage, VGet(1.0f, 1.0f, 2.0f));//ステージ長くしてるよ
	MV1SetScale(m_goal, VGet(2.0f, 1.0f, 2.0f));//ゴールゲート長くしてるよ

}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Stage::~Stage()
{
	// モデルのアンロード.
	MV1DeleteModel(m_stage);
	MV1DeleteModel(m_goal);

}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Stage::Update()
{


	// ３Dモデルのポジション設定
	MV1SetPosition(m_stage, m_pos);

	MV1SetPosition(m_goal, m_goalpos);


}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Stage::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(m_stage);
	MV1DrawModel(m_goal);

	DrawGraph(0, 0, m_arrow, true);//常に出る矢印のアイコン
		// キー入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & PAD_INPUT_LEFT)//もし、右キーが入力されたらアイコンに色がつく
	{
		DrawGraph(0, 0, m_leftarrow, true);
	}
	if (Key & PAD_INPUT_RIGHT)//もし、右キーが入力されたらアイコンに色がつく
	{
		DrawGraph(0, 0, m_rightarrow, true);
	}

}

