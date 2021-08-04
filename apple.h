#ifndef _APPLE_H_
#define _APPLE_H_

#include "DxLib.h"

class EnemyBase;
class Apple;

// 障害物の数.
#define LINE_OBSTRUCT_COL 15
#define LINE_OBSTRUCT_RAW 30

#define OBSTRUCT_SPACE_D 40.0f// 障害物の縦間隔.
#define OBSTRUCT_SPACE_W 15.0f // 障害物の横間隔.

class Apple
{
public:
	Apple();// コンストラクタ.
	~Apple();// デストラクタ

	void Update();			// 更新.

	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	//ループ用
	int i;
	int getapplepoint;//リンゴを取った数

	void CreateApple();			//エネミー生成
	void DestroyApple();		// エネミー削除.
	EnemyBase* DestroyAppleHit(int _raw,int _col);

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR _set, int _n) { pos = _set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return hitRadius; }



	// 指定番号の障害物を取得.
	EnemyBase* GetApple(int _raw, int _col);


private:

	//リンゴの配列
	EnemyBase* apple[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];


	int m_appleModelSourceHandle;		//appleの大本のハンドル


protected:


	int		modelHandle;			// モデルハンドル.
	VECTOR	pos;					// ポジション.
	float	hitRadius;				// あたり判定の半径.

};

#endif // _APPLE_H_