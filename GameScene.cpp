#include "GameScene.h"
#include "Player.h"
#include "Camera.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Stage.h"
#include "DxLib.h"
#include "HitChecker.h"
#include "Enemy.h"
#include "apple.h"
#include "MapChip.h"


// コンストラクタ
GameScene::GameScene()
	: m_hitOverSound(0)
	, player(nullptr)
	, camera(nullptr)
	, stage(nullptr)
	,apple(nullptr)
	, m_kawasakiOverSound(0)
	, m_GameSceneSound(0)
	, m_OverSound(0)
	,gauge(0)
	,meter(0)
	,now(0)
	,m_kawasakicount(0)
	
{
	// 音ファイルを読み込み
	m_hitOverSound = LoadSoundMem("data/Sound/kawasaki.wav");

	m_OverSound = LoadSoundMem("data/Sound/Over.wav");
	m_kawasakiOverSound = LoadSoundMem("data/Sound/kawasakiOver.wav");
	// 音ファイルを読み込み(ゲームシーン）
	m_GameSceneSound = LoadSoundMem("data/Sound/GameScene.wav");


	// プレイヤーを生成.
	player = new Player();

	// カメラを生成.
	camera = new Camera();

	// ステージを生成
	stage = new Stage();

	// エネミーを生成.
	enemy = new Enemy();
	enemy->CreateEnemy();
	//スコア表示を生成
	Score = new MapChipClass();
	//リンゴを生成
	apple = new Apple();
	apple->CreateApple();
	//ゴールまでの距離を表すゲージを生成
	gauge = new MapChipClass();

	// ゲームシーンの音楽再生
	PlaySoundFile("data/Sound/GameScene.wav", DX_PLAYTYPE_LOOP);
}

// デストラクタ
GameScene::~GameScene()
{
	// プレイヤーを削除.
	delete(player);
	// カメラを削除.
	delete(camera);
	//ステージを生成
	delete(stage);

	//// エネミーを削除.
	enemy->DestroyEnemys();
	delete(enemy);
	//スコアを削除
	delete(Score);
	//リンゴを削除
	delete(apple);
	//ゲージを削除
	delete(gauge);
}

// 更新処理
SceneBase* GameScene::Update()
{
	// プレイヤー制御.
	player->Update();
	// カメラ制御.
	camera->Update(*player);
	//ステージの制御
	stage->Update();

	//エネミー制御.
	enemy->Update();
	//リンゴの制御
	apple->Update();

	// ヒットのチェック.
	HitChecker::Check(*player, *enemy);
	//リンゴのヒットチェック
	HitChecker::Checkapple(*player, *apple);





	// プレイヤーがゴールしたら
	if (player->goalflag == true)
	{
		// テキスト消去
		clsDx();

		// GameClearに遷移
		return new GameClear();
	}

	// プレイヤーがカワサキorフライパンに当たったら
	if (player->hitover==true)
	{

		if (!player->GetRotateGameover())
		{
			// 音再生
			PlaySoundFile("data/Sound/kawasakiOver.wav", DX_PLAYTYPE_BACK);
			player->rotationY();
			player->SetRotateGameover(true);
		}

		m_kawasakicount++;
		if (m_kawasakicount>240)
		{

			// GameOverに遷移
			return new GameOver();

		}

		// テキスト消去
		clsDx();

	}

	// 自分のポインタを返す
	return this;
}

// 描画処理
void GameScene::Draw()
{
	// プレイヤー描画.
	player->Draw();

	//ステージ描画.
	stage->Draw();


	// エネミー描画.S
	enemy->Draw();

	//リンゴの描画
	apple->Draw();


	//リンゴを取った数を代入
	int point = apple->getapplepoint;
	//スコア表示
	int score = point / 10;
	int score2 = point % 10;
	Score->DrawArrayMapChip(0, score);
	Score->DrawArrayMapChip(1, score2);
	Score->DrawArrayMapChip(2, 0);
	Score->DrawArrayMapChip(3, 0);

	//ゲームが始まったらカウントする
	now++;
	//カウントが一定までくるとメーターが一つたまる
	if (now==346)
	{
		meter++;
		now = 0;
	}

	gauge->Drawgauge(meter);

}
