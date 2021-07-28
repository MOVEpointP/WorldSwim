#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_


#include "GameClear.h"
#include "TitleScene.h"
#include "Player.h"


// コンストラクタ
GameClear::GameClear()
	: count(0)
	, number(0)
	, change(0)
	, push(0)
	, gameClearSound(0)



{
	// ゲームクリア画像読み込み
	gameClearImg[0] = LoadGraph("data/texture/GameClear.png");
	gameClearImg[1] = LoadGraph("data/texture/GameClear2.png");

	push = LoadSoundMem("data/Sound/push.MP3");

	// ゲームクリア音読み込み
	gameClearSound = LoadSoundMem("data/Sound/Clear.wav");
	
		// ゲームクリア音楽再生
	PlaySoundFile("data/Sound/Clear.wav", DX_PLAYTYPE_BACK);

}

// デストラクタ
GameClear::~GameClear()
{
	//処理なし
}

// 更新処理
SceneBase* GameClear::Update()
{

	// Enterキーが押されたら
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		//キーを押したら効果音が鳴る
		PlaySoundMem(push, DX_PLAYTYPE_NORMAL);

		// テキスト消去
		clsDx();

		// TitleSceneに遷移
		return new TitleScene();
	}

	// 自分のポインタを返す
	return this;
}

// 描画処理
void GameClear::Draw()
{


	//画像をコマ送りで表示する
	change++;

	if (change >= 50)
	{
		count++;

		number = count % 2;
		change = 0;
	}


	// 画像表示
	DrawGraph(0, 0, gameClearImg[number], false);


}

#endif