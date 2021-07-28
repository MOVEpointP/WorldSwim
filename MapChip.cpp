#include "DxLib.h"
#include "MapChip.h"

// コンストラクタ宣言
MapChipClass::MapChipClass()
{
	// LoadDivgraph(ファイルの場所, 全体の枚数, 横の枚数, 縦の枚数, １枚の大きさ(横), １枚の大きさ(縦), 保存する変数名);
	LoadDivGraph("data/texture/kazu.png", 10, 10, 1, 60, 60, map.mapChipImg);
	// メーター
	LoadDivGraph("data/texture/gauge.png", 10, 10, 1,103, 720, gauge.mapChipImg);

}

// デストラクタ宣言
MapChipClass::~MapChipClass()
{

}

// 配列を用いてマップチップを描画する関数
void MapChipClass::DrawArrayMapChip(int kurai, int num)
{
	// MapDataに入っている数値番目のマップチップ画像を指定した位置に描画する
	/* DrawGraph(指定した位置のx座標, 指定した位置のy座標, 表示する画像. 透明度を有効にするか(ture:有効にする, false:有効にしない); */

	//四桁を想定して作
	DrawGraph(kurai * 60,0, map.mapChipImg[num], true);
}

void MapChipClass::Drawgauge(int max)
{
	// MapDataに入っている数値番目のマップチップ画像を指定した位置に描画する
	/* DrawGraph(指定した位置のx座標, 指定した位置のy座標, 表示する画像. 透明度を有効にするか(ture:有効にする, false:有効にしない); */

	//四桁を想定して作
	DrawGraph(1200, 0, gauge.mapChipImg[max], true);
}

