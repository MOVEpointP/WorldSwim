#include "EnemyBase.h"
#include "apple.h"
#include "AppleStatic.h"
//aaa
//プレイヤーをパクって作ってみる

//------------------------------------------------------------------------
//コンストラクタ
//------------------------------------------------------------------------
Apple::Apple()
	:appleModelSourceHandle(NULL)
	,getapplepoint(0)
{


	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			apple[i][j] = NULL;
		}
	}

	pos = VGet(0, 0, 0);
}

Apple::~Apple()
{
}

//-----------------------------------------------------------------------------
// @brief  障害物生成.
//-----------------------------------------------------------------------------
void Apple::CreateApple()
{
	// ３Ｄモデルの読み込み
	appleModelSourceHandle = MV1LoadModel("data/model/おりんご/りんご.pmx");



	// 障害物の配置図データとしてのlinemapを用意する.
	int line1001[LINE_OBSTRUCT_COL] = { 0,3,0,1,0,1,0,1,0,1,0,0,1 };
	int line1002[LINE_OBSTRUCT_COL] = { 0,1,0,1,0,2,1,1,1,2,0,0,1 };
	int line1003[LINE_OBSTRUCT_COL] = { 0,0,1,1,1,3,2,1,2,3,1,1,1 };
	int line1004[LINE_OBSTRUCT_COL] = { 0,0,0,1,2,0,0,1,3,0,0,0,1 };
	int line1005[LINE_OBSTRUCT_COL] = { 0,0,0,1,3,3,0,0,0,3,1,1,1 };
	int line1006[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0,1,0,0,0,0,1 };
	int line1007[LINE_OBSTRUCT_COL] = { 0,0,0,1,3,0,0,1,0,1,0,1,1 };
	int line1008[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0,1,1,2,0,1,1 };
	int line1009[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,1,1,0,3,1,0,1 };
	int line1010[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,1,0,1,1,0,1,0,1 };

	int line2001[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,2,0,0,1,3,1,0,1 };
	int line2002[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,3,1,0,0,0,0,0,1 };
	int line2003[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,0,0,1,0,1,0,1,1 };
	int line2004[LINE_OBSTRUCT_COL] = { 0,0,0,1,2,3,0,1,0,2,0,1,1 };
	int line2005[LINE_OBSTRUCT_COL] = { 0,0,0,1,3,0,0,1,1,3,0,0,1 };
	int line2006[LINE_OBSTRUCT_COL] = { 0,0,0,1,3,0,0,1,0,0,1,1,1 };
	int line2007[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,1,0,1,3,1,1,1 };
	int line2008[LINE_OBSTRUCT_COL] = { 0,0,0,1,3,1,0,1,1,0,0,1,1 };
	int line2009[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,1,0,1,1,3,1,1,1 };
	int line2010[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,1,1,0,1,0,1,1 };

	int line3001[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,1,0,0,0,1,0,0,1 };
	int line3002[LINE_OBSTRUCT_COL] = { 0,0,3,1,1,3,0,0,1,0,1,0,1 };
	int line3003[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,1,0,0,0,0,3,0,1 };
	int line3004[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,1,1,1,1,0,0,1 };
	int line3005[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,1,0,3,1,1,0,0,1 };
	int line3006[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0,1,3,0,1,1,1 };
	int line3007[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,3,0,0,1,1,1,1 };
	int line3008[LINE_OBSTRUCT_COL] = { 0,0,0,1,1,1,0,0,0,0,0,0,1 };
	int line3009[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0,0,3,0,1,1,1 };
	int line3010[LINE_OBSTRUCT_COL] = { 0,0,0,1,0,0,0,0,0,0,1,1,1 };
	int* lineMap[LINE_OBSTRUCT_RAW] =
	{
		line1001,
		line1002,
		line1003,
		line1004,
		line1005,
		line1006,
		line1007,
		line1008,
		line1009,
		line1010,

		line2001,
		line2002,
		line2003,
		line2004,
		line2005,
		line2006,
		line2007,
		line2008,
		line2009,
		line2010,

		line3001,
		line3002,
		line3003,
		line3004,
		line3005,
		line3006,
		line3007,
		line3008,
		line3009,
		line3010,
	};

	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			int* nowLine = lineMap[i];
			// linemapに入っている数値によって障害物の種類を決定する.
			if (nowLine[j] == 3)
			{
				apple[i][j] = new AppleStatic(appleModelSourceHandle);
			}
			else if (nowLine[j] == 0)
			{
				apple[i][j] = NULL;
			}

			// 位置の初期化.
			if (apple[i][j] != NULL)
			{
				apple[i][j]->SetPos(
					VGet(
						(OBSTRUCT_SPACE_W * j) - (OBSTRUCT_SPACE_W * LINE_OBSTRUCT_COL * 0.5f),
						0.0f,
						(OBSTRUCT_SPACE_D * LINE_OBSTRUCT_RAW) - (OBSTRUCT_SPACE_D * i)
					)
				);


			}

		}

	}

}


//-----------------------------------------------------------------------------
// @brief  障害物削除.
//-----------------------------------------------------------------------------
void Apple::DestroyApple()
{

	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (apple[i][j] != NULL)
			{
				delete(apple[i][j]);
				apple[i][j] = NULL;
			}
		}
	}
	MV1DeleteModel(modelHandle);

}


//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Apple::Update()
{
	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (apple[i][j] != NULL)
			{
				apple[i][j]->Update();


			}
		}
	}
}

//------------------------------------------------------------------------
//描画
//------------------------------------------------------------------------
void Apple::Draw()
{
	for (int i = 0; i < LINE_OBSTRUCT_RAW; i++)
	{
		for (int j = 0; j < LINE_OBSTRUCT_COL; j++)
		{
			if (apple[i][j] != NULL)
			{
				apple[i][j]->Draw();
			}

		}
	}
}

//-----------------------------------------------------------------------------
// @brief  指定番号の障害物を取得.
//-----------------------------------------------------------------------------
EnemyBase* Apple::GetApple(int raw, int col)
{
	return apple[raw][col];
}

EnemyBase* Apple::DestroyAppleHit(int raw, int col)
{
	delete(apple[raw][col]);
	apple[raw][col] = NULL;
	getapplepoint++;
	return apple[raw][col];
}
