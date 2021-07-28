//-----------------------------------------------------------------------------
//  �t���C�p���̏���
//-----------------------------------------------------------------------------
#include "Pan.h"
#include "Enemy.h"
#include "EnemyStatic.h"
#include "Player.h"

#define _USE_MATH_DEFINES
#include <math.h>

//-----------------------------------------------------------------------------
//  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Pan::Pan(int sourceModelHandle)
    :EnemyBase(sourceModelHandle)
    , zcount(0)
{
    pos = VGet(0, 0, 0);
    rad = 0;
    hitRadius = 3.0f;

    // �����鉹�ǂݍ���
    panSound = LoadSoundMem("data/Sound/Frypan.mp3");

}
//-----------------------------------------------------------------------------
//  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Pan::~Pan()
{
    //�����Ȃ�
}


//-----------------------------------------------------------------------------
//  �X�V.
//-----------------------------------------------------------------------------
void Pan::Update()
{
    rad += static_cast<float>((M_PI / 180) * 5);//static_cast�͈Öق̌^�ϊ��𖾎�������́B�ȗ���

    //y�̍����A�㉺�̗h������
    pos.y = 10.0f + sinf(rad);

    //�t���C�p�����]100�i�񂾂���W��100�߂�
    zcount++;
    if (zcount == 200)
    {
        pos.z += 200;
        zcount = 0;

        // ���̍Đ����J�n
        PlaySoundMem(panSound, DX_PLAYTYPE_BACK);
    }
    else
    {
        pos.z--;
    }

    //3D���f���̃|�W�V�����ݒ�
    MV1SetPosition(modelHandle, pos);
}