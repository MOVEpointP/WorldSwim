#include "GameOver.h"
#include "TitleScene.h"

// コンストラクタ
GameOver::GameOver()
	: count(0)
	, number(0)
	, change(0)
	, push(0)


{
	// ゲームクリア画像読み込み
	gameOverImg[0] = LoadGraph("data/texture/GameOver.png");
	gameOverImg[1] = LoadGraph("data/texture/GameOver2.png");
	push = LoadSoundMem("data/Sound/push.MP3");

	// ゲームオーバー音楽再生
	PlaySoundFile("data/Sound/OverMusic.wav", DX_PLAYTYPE_LOOP);

}

// デストラクタ
GameOver::~GameOver()
{
	//処理なし
}

// 更新処理
SceneBase* GameOver::Update()
{
	// Enterキーが押されたら
	if (CheckHitKey(KEY_INPUT_RETURN))
	{

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
void GameOver::Draw()
{

	change++;

	if (change >= 50)
	{
		count++;

		number = count % 2;
		change = 0;
	}

	// 画像表示
	DrawGraph(0, 0, gameOverImg[number], false);
}
