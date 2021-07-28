#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "SceneBase.h"
#include "fade.h"

// タイトルシーン
class TitleScene : public SceneBase
{
public:
	// 更新処理
	SceneBase* Update() override;
	// 描画処理
	void Draw() override;

	// コンストラクタ
	TitleScene();
	// デストラクタ
	~TitleScene();

private:
	// タイトル画像
	int titleImg[3];
	int titlepushSound;

	//フェードイン、フェードアウトに使う変数
	bool fade;
	int FeedInCount;
	int FeedOutCount;
	//画像をコマ送りする変数
	int number;
	int count;
	int change;


	//タイトル音楽
	int titleSound;


	Fade<int> inout;
};
#endif	_TITLESCENE_H_