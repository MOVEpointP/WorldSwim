#ifndef _SCENEBASE_H_
#define _SCENEBASE_H_

#include "DxLib.h"
#include "Player.h"

// シーンのベースクラス
class SceneBase
{
public:
	// 更新処理
	virtual SceneBase* Update() = 0;
	// 描画処理
	virtual void Draw() = 0;

	// コンストラクタ
	SceneBase() {};
	// デストラクタ
	virtual ~SceneBase() {};
};
#endif	//_SCENEBASE_H_
