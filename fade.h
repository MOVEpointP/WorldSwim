#pragma once
#ifndef _FADEH
#define _FADEH

#include<Dxlib.h>

template<typename T>class Fade
{
private:


    //フェードイン
    int FeedInCount = 0;
    //フェードアウト
    int FeedOutCount = 255;
    //判定
    bool Judg;
    //画像
    int Img;

public:
    //引数のセット("フェードアウトはtrue。インはfalse","画像")
    void set(bool fade, int img)
    {

        Judg = fade;
        Img = img;

        // 画像表示
        if (!Judg)
        {
            //フェードイン
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedInCount);
            DrawGraph(0, 0, Img, false);
            FeedInCount++;
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        }
        else
        {
            //フェードアウト
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedOutCount);
            DrawGraph(0, 0, Img, false);
            FeedOutCount--;
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
};

#endif _FADEH
