#pragma once
#ifndef _FADEH
#define _FADEH

#include<Dxlib.h>

template<typename T>class Fade
{
private:


    //�t�F�[�h�C��
    int FeedInCount = 0;
    //�t�F�[�h�A�E�g
    int FeedOutCount = 255;
    //����
    bool Judg;
    //�摜
    int Img;

public:
    //�����̃Z�b�g("�t�F�[�h�A�E�g��true�B�C����false","�摜")
    void set(bool fade, int img)
    {

        Judg = fade;
        Img = img;

        // �摜�\��
        if (!Judg)
        {
            //�t�F�[�h�C��
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedInCount);
            DrawGraph(0, 0, Img, false);
            FeedInCount++;
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
        }
        else
        {
            //�t�F�[�h�A�E�g
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, FeedOutCount);
            DrawGraph(0, 0, Img, false);
            FeedOutCount--;
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }
    }
};

#endif _FADEH
