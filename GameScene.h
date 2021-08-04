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
	int m_hitOverSound;
	// ゲームオーバーの音
	int m_OverSound;
	// 上二つの結合版
	int m_kawasakiOverSound;
	// ゲームシーンの音楽
	int m_GameSceneSound;
	// プレイヤーのポインタ
	Player* player;
	// カメラのポインタ
	Camera* camera;
	//ステージのポインタ
	Stage* stage;
	//エネミーのポインタ
	Enemy* enemy;
	//リンゴのポインタ
	Apple* apple;
	//スコア表示のポインタ
	MapChipClass* Score;
	//ゴールまでの距離を表すゲージのポインタ
	MapChipClass* gauge;

	int m_kawasakicount;
};
#endif	//_GAMESCENE_H_