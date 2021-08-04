//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _HITCHECHER_H_
#define _HITCHECHER_H_

class Enemy;
class Player;
class Apple;

class HitChecker
{
public:
	//エネミーのチェックヒット
	static void Check(Player& player, Enemy& enemy);
	//りんごのチェックヒット
	static void Checkapple(Player& player, Apple& apple);

};

#endif //_HITCHECHER_H_