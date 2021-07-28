//-----------------------------------------------------------------------------
// @brief  ヒットチェック.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "HitChecker.h"
#include "Player.h"
#include "EnemyBase.h"
#include "Enemy.h"
#include "apple.h"

//-----------------------------------------------------------------------------
// @brief  ヒットチェック処理.
//-----------------------------------------------------------------------------

void HitChecker::Check(Player& player, Enemy& enemy)
{
	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
		{
			for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
			{
				EnemyBase* obstruct = enemy.GetEnemy(i, j);

				if (obstruct != NULL)
				{
					VECTOR yZeroObstruct = VGet(obstruct->GetPos().x, 0, obstruct->GetPos().z);

					// お互いのポジションと半径の距離が重なったら当たっていることになる.
					VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);
					if (VSize(playerToObs) < player.GetHitRadius() + obstruct->GetHitRadius())
					{
						//printfDx("Hit!");
						player.OnHitObstruct(*obstruct);
						isHit = true;
						break;
					}
				}
			}
			// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.@@@ここでゲームオーバーの方にもっていってほしい
			if (isHit)
			{
				player.hitover = true;
				yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
				break;
			}
		}
	}
}

void HitChecker::Checkapple(Player& player, Apple& apple)
{
	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
		{
			for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
			{
				EnemyBase* obstruct = apple.GetApple(i, j);

				if (obstruct != NULL)
				{
					VECTOR yZeroObstruct = VGet(obstruct->GetPos().x, 0, obstruct->GetPos().z);

					// お互いのポジションと半径の距離が重なったら当たっていることになる.
					VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);
					if (VSize(playerToObs) < player.GetHitRadius() + obstruct->GetHitRadius())
					{
						//printfDx("Hit!");
						player.OnHitObstructApple(*obstruct);
						isHit = true;
						obstruct = apple.DestroyAppleHit(i, j);

						break;
					}
				}
			}
			// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.@@@ここでゲームオーバーの方にもっていってほしい
			if (isHit)
			{
				//player.pointUp = true;
				yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
				break;
			}
		}
	}
}