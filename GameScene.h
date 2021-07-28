#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "SceneBase.h"
#include "Player.h"


// 前方宣言
class Camera;
class Player;
class Stage;
class Enemy;
class Apple;
class MapChipClass;

// ゲームシーン
class GameScene : public SceneBase
{
public:
	// 更新処理
	SceneBase* Update() override;
	// 描画処理
	void Draw() override;

	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();

	int meter;
	int now;


private:
	// カワサキの音
	int hitOverSound;
	// ゲームオーバーの音
	int OverSound;
	// 上二つの結合版
	int kawasakiOverSound;
	// ゲームシーンの音楽
	int GameSceneSound;
	// プレイヤーのポインタ
	Player* player;
	// カメラのポインタ
	Camera* camera;
	//ステージのポインタ
	Stage* stage;
	//エネミーのポインタ
	Enemy* enemy;

	Apple* apple;

	MapChipClass* map;

	MapChipClass* gauge;

	int kawasakicount;
};
#endif	//_GAMESCENE_H_