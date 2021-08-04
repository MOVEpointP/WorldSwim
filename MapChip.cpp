#include "DxLib.h"
#include "MapChip.h"

// コンストラクタ宣言
MapChipClass::MapChipClass()
{
	//スコアの画像読み込み
	LoadDivGraph("data/texture/kazu.png", 10, 10, 1, CHIP_SIZE, CHIP_SIZE, m_Score.mapChipImg);
	// ゲージの画像読み込み
	LoadDivGraph("data/texture/gauge.png", 10, 10, 1,103, 720, m_gauge.mapChipImg);

}

// デストラクタ宣言
MapChipClass::~MapChipClass()
{

}

void MapChipClass::DrawArrayMapChip(int _column, int _num)
{

	//スコアの数字表示の描画
	DrawGraph(_column * 60,0, m_Score.mapChipImg[_num], true);
}

void MapChipClass::Drawgauge(int _max)
{
	//ゲージの表示描画
	DrawGraph(1200, 0, m_gauge.mapChipImg[_max], true);
}

