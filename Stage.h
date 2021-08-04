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
	int GetModelHandle() { return m_stage; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR set) { m_pos = set; }

	// ディレクションのgetter/setter.
	const VECTOR& GetDir() const { return m_dir; }
	void SetDir(const VECTOR set) { m_dir = set; }


private:
	int		m_stage;		// モデルハンドル.
	VECTOR	m_pos;				// ポジション.

	int		m_goal;	// モデルハンドル.
	VECTOR	m_goalpos;			// ポジション.

	VECTOR	m_velocity;			// 移動力.

	VECTOR	m_dir;				// 回転方向.
	float	m_hitRadius;			// あたり判定の半径.

	int     m_arrow;				//矢印
	int		m_rightarrow;			//右矢印
	int		m_leftarrow;			//左矢印

};

#endif	 // _STAGE_H_