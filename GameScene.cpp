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
	: hitOverSound(0)
	, player(nullptr)
	, camera(nullptr)
	, stage(nullptr)
	,apple(nullptr)
	, kawasakiOverSound(0)
	, GameSceneSound(0)
	, OverSound(0)
	,gauge(0)
	,meter(0)
	,now(0)
	,kawasakicount(0)
	
{
	// 音ファイルを読み込み
	hitOverSound = LoadSoundMem("data/Sound/kawasaki.wav");

	OverSound = LoadSoundMem("data/Sound/Over.wav");
	kawasakiOverSound = LoadSoundMem("data/Sound/kawasakiOver.wav");
	// 音ファイルを読み込み(ゲームシーン）
	GameSceneSound = LoadSoundMem("data/Sound/GameScene.wav");


	// プレイヤーを生成.
	player = new Player();

	// カメラを生成.
	camera = new Camera();

	// ステージを生成
	stage = new Stage();

	// エネミーを生成.
	enemy = new Enemy();
	enemy->CreateEnemy();

	map = new MapChipClass();

	apple = new Apple();
	apple->CreateApple();

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

	delete(stage);

	//// エネミーを削除.
	enemy->DestroyEnemys();

	delete(enemy);

	delete(map);

	delete(apple);

	delete(gauge);
}

// 更新処理
SceneBase* GameScene::Update()
{
	// プレイヤー制御.
	player->Update();
	// カメラ制御.
	camera->Update(*player);

	stage->Update();

	//エネミー制御.
	enemy->Update();

	apple->Update();

	// ヒットのチェック.
	HitChecker::Check(*player, *enemy);

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

		kawasakicount++;
		if (kawasakicount>240)
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


	apple->Draw();



	int point = apple->getapplepoint;

	int score = point / 10;
	int score2 = point % 10;
	map->DrawArrayMapChip(0, score);
	map->DrawArrayMapChip(1, score2);
	map->DrawArrayMapChip(2, 0);
	map->DrawArrayMapChip(3, 0);


	now++;

	if (now==346)
	{
		meter++;
		now = 0;
	}

	gauge->Drawgauge(meter);

}
