#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"

class EnemyBase;
class Apple;

// 障害物の数.
#define LINE_OBSTRUCT_COL 15
#define LINE_OBSTRUCT_RAW 30

#define OBSTRUCT_SPACE_D 40.0f// 障害物の縦間隔.
#define OBSTRUCT_SPACE_W 15.0f // 障害物の横間隔.

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Update();			// 更新.

	void Draw();			// 描画.

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	//ループ用
	int i;

	void CreateEnemy();			//エネミー生成
	void DestroyEnemys();		// エネミー削除.

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set, int n) { pos = set; }

	// あたり判定半径の取得.
	float GetHitRadius() { return hitRadius; }

	//////フライパンかエネミーか判断する
	//int enemypan[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];

	int floatModelSourceHandle;		//フライパンの大本のハンドル

	// 指定番号の障害物を取得.
	EnemyBase* GetEnemy(int raw, int col);


private:

	EnemyBase* enemys[LINE_OBSTRUCT_RAW][LINE_OBSTRUCT_COL];
	

	int staticModelSourceHandle;	// 静止モデルの大本のハンドル.


protected:
	int		modelHandle;			// モデルハンドル.
	VECTOR	pos;					// ポジション.
	float	hitRadius;				// あたり判定の半径.

};

#endif // _ENEMY_H_