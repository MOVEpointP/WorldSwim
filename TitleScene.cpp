#include "TitleScene.h"
#include "GameScene.h"


// コンストラクタ
TitleScene::TitleScene()
	: fade(false)
	, FeedInCount(0)
	, FeedOutCount(255)
	,count(0)
	,number(0)
	,change(0)

{
	// タイトル画像読み込み
	titleImg[0] = LoadGraph("data/texture/Game title.png");
	titleImg[1] = LoadGraph("data/texture/Game title2.png");
	titleImg[2] = LoadGraph("data/texture/Game title3.png");

	//キーを押したときの効果音
	titlepushSound = LoadSoundMem("data/Sound/push.MP3");

	//音ファイル読み込み
	titleSound = LoadSoundMem("data/Sound/Title.wav");

	//音再生
	PlaySoundFile("data/Sound/Title.wav", DX_PLAYTYPE_LOOP);


}

// デストラクタ
TitleScene::~TitleScene()
{
	//処理なし
}

// 更新処理
SceneBase* TitleScene::Update()
{
	// Enterキーが押されたら
	if (CheckHitKey(KEY_INPUT_RETURN))
	{

		fade = true;

		//画像をコマ送りで表示する
		PlaySoundMem(titlepushSound, DX_PLAYTYPE_NORMAL);

		for (int i=0; i < 255; i++)
		{
			ClearDrawScreen();                   // 裏画面のデータを全て削除

			inout.set(fade, titleImg[number]);

			// 裏画面の内容を表画面に反映させる
			ScreenFlip();
		}
		// テキスト消去
		clsDx();
		return new GameScene();
	}

	// 自分のポインタを返す
	return this;
}

// 描画処理
void TitleScene::Draw()
{
	//画像をコマ送りで表示する

	change++;

	if (change >= 50)
	{
		count++;

		number = count % 3;
		change = 0;
	}


	if (!fade)
	{
		//フェードイン
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedInCount);
		DrawGraph(0, 0, titleImg[number], true);
		FeedInCount++;
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	//else
	//{
	//	//フェードアウト
	//	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedOutCount);
	//	//DrawGraph(0, 0, titleImg[number], false);
	//	//FeedOutCount--;
	//	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}


	// 画像表示
	DrawGraph(0, 0, titleImg[number], false);
}