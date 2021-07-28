#pragma once

// 画面の横の大きさ
const int  SCREEN_WIDTH = 640;
// 画面の縦の大きさ
const int SCREEN_HEIGHT = 480;

// 一つのチップのサイズ
const int  CHIP_SIZE = 60;

//------------------
// 構造体定義
//------------------
struct MapChip
{
	// マップチップを保存する変数
	int mapChipImg[10];

	// ファイルから文字を取得する変数
	int getCharacter = 0;

	// 文字列変数
	/* charは文字型だが配列なため文字列型となる */
	char buffer[10];

	// bufferからマップチップの番号を受け取る
	int num = 0;
	// 横のマップチップの番号
	int widthNum = 0;
	// 縦のマップチップの番号
	int heightNum = 0;


};

//------------------
// クラス定義
//------------------
class MapChipClass
{
/* publicはどこでも呼べる */
public:
	// コンストラクタ定義
	/* コンストラクタとは、クラスのメンバーの初期化を行う */
	MapChipClass();

	// デストラクタ定義
	/* デストラクタとは、クラスのメンバーの後処理 */
	~MapChipClass();

	//// 配列を用いてマップチップを描画する関数
	void DrawArrayMapChip(int kurai,int num);
	void Drawgauge(int max);

/* privateはクラス内でしか呼べない */
private:
	// MapChipの変数宣言
	MapChip map;
	MapChip gauge;

};

