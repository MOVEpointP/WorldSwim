#pragma once

#include "SceneBase.h"


// ゲームクリア
class GameClear : public SceneBase
{
public:
	// 更新処理
	SceneBase* Update() override;
	// 描画処理
	void Draw() override;

	// コンストラクタ
	GameClear();
	// デストラクタ
	~GameClear();

private:
	// ゲームクリア画像
	int gameClearImg[2];
	//画面をコマ送りにするときに使う変数
	int number;
	int count;
	int change;

	//キーを押したときの効果音
	int push;

	int gameClearSound;

};
