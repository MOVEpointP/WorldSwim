#include "DxLib.h"

#ifndef _STAGE_H_
#define _STAGE_H_


class ObstructBase;

class Stage final
{
public:	
	Stage();					// コンストラクタ.
	~Stage();					// デストラクタ.

	void Update();				// 更新.
	void Draw();				// 描画.


	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle2; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return dir; }
	void SetDir(const VECTOR set) { dir = set; }


private:
	int		modelHandle2;		// モデルハンドル.
	VECTOR	pos;				// ポジション.

	int		modelHandlegoal;	// モデルハンドル.
	VECTOR	goalpos;			// ポジション.

	VECTOR	velocity;			// 移動力.

	VECTOR	dir;				// 回転方向.
	float	hitRadius;			// あたり判定の半径.

	int     arrow;				//矢印
	int		rightarrow;			//右矢印
	int		leftarrow;			//左矢印

};

#endif	 // _STAGE_H_