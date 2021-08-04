#include "EnemyBase.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
EnemyBase::EnemyBase(int _sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(-1)
{
	pos = VGet(0, 0, 0);

	// �R�c���f���̓ǂݍ���
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(_sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d", _sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("data/model/Kawasaki/Kawasaki.pmx");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:�f�[�^�ǂݍ��݂Ɏ��s");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
EnemyBase::~EnemyBase()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void EnemyBase::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
}