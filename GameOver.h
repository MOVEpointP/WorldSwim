#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "SceneBase.h"

// ゲームオーバー
class GameOver : public SceneBase
{
public:
	// 更新処理
	SceneBase* Update() override;
	// 描画処理
	void Draw() override;

	// コンストラクタ
	GameOver();
	// デストラクタ
	~GameOver();

private:
	// ゲームクリア画像
	int gameOverImg[2];
	//画面をコマ送りにするときに使う変数
	int number;
	int count;
	int change;

	int push;


};
#endif	//_GAMEOVER_H_