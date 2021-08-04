#pragma once


// 一つのチップのサイズ
const int  CHIP_SIZE = 60;

//------------------
// 構造体定義
//------------------
struct MapChip
{
	// マップチップを保存する変数
	int mapChipImg[10];

};

//------------------
// クラス定義
//------------------
class MapChipClass
{
public:
	// コンストラクタ定義
	MapChipClass();

	// デストラクタ定義
	~MapChipClass();

	//// 配列を用いてマップチップを描画する関数
	void DrawArrayMapChip(int _column,int _num);
	void Drawgauge(int _max);

private:
	//スコアの変数
	MapChip m_Score;
	//ゲージの変数
	MapChip m_gauge;

};

