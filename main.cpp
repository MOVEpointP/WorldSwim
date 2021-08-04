//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "HitChecker.h"
#include "Stage.h"
#include "FryingPan.h"

#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "GameClear.h"
#include "GameOver.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);

	// 今のシーン生成
	SceneBase* nowScene;
	// 最初のシーンをTitleシーンに設定
	nowScene = new TitleScene;


	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		// 比較用tmpSceneを生成
		SceneBase* tmpScene;
		// 更新処理
		tmpScene = nowScene->Update();

		// 今のシーンのUpdateの返り値がtmpSceneと異なれば
		if (tmpScene != nowScene)
		{
			// 今のシーンのポインタを開放
			delete nowScene;

			// 次のシーンへ遷移
			nowScene = tmpScene;
		}

		// 画面を初期化する
		ClearDrawScreen();

		// シーンの描画処理
		nowScene->Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// 今のシーンのポインタをdelete
	delete nowScene;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}