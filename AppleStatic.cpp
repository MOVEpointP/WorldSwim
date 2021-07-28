#include "AppleStatic.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
AppleStatic::AppleStatic(int sourceModelHandle)
	: EnemyBase(sourceModelHandle)
{
	
	hitRadius = 6.0f;
	pos = VGet(0.2f, 0.2f, 0.2f);
	MV1SetScale(modelHandle, pos);
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
AppleStatic::~AppleStatic()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void AppleStatic::Update()
{

	MV1SetPosition(modelHandle, pos);

}