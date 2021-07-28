#include "Stage.h"
#include "Player.h"
#include "EnemyBase.h"


//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Stage::Stage()
	: modelHandle2(-1)
	, hitRadius(5.0f)
	,modelHandlegoal(-1)
{
	// �R�c���f���̓ǂݍ���
	modelHandle2 = MV1LoadModel("data/model/stage3/Old Town.pmx");
	modelHandlegoal = MV1LoadModel("data/�C���n�C�S�[���Q�[�g/���C���n�C�S�[���T�C�h�p�l����.pmx");
	
	arrow = LoadGraph("data/texture/Arrow.png");
	rightarrow = LoadGraph("data/texture/Right arrow.png");
	leftarrow = LoadGraph("data/texture/Left arrow.png");


	pos = VGet(0, 0, 0);
	velocity = VGet(0, 0, 0);
	dir = VGet(0, 0, 1);

	goalpos= VGet(0, 0, 1200);

	MV1SetScale(modelHandle2, VGet(1.0f, 1.0f, 2.0f));//�X�e�[�W�������Ă��
	MV1SetScale(modelHandlegoal, VGet(2.0f, 1.0f, 2.0f));//�S�[���Q�[�g�������Ă��

}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Stage::~Stage()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle2);
	MV1DeleteModel(modelHandlegoal);

}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Stage::Update()
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// ��������.
	VECTOR accelVec = VGet(0, 0, 0);


	// �x���V�e�B�����v�Z.
	velocity = VAdd(velocity, accelVec);


	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle2, pos);

	MV1SetPosition(modelHandlegoal, goalpos);


}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void Stage::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle2);
	MV1DrawModel(modelHandlegoal);

	DrawGraph(0, 0, arrow, true);//��ɏo����̃A�C�R��
		// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & PAD_INPUT_LEFT)//�����A�E�L�[�����͂��ꂽ��A�C�R���ɐF����
	{
		DrawGraph(0, 0, leftarrow, true);
	}
	if (Key & PAD_INPUT_RIGHT)//�����A�E�L�[�����͂��ꂽ��A�C�R���ɐF����
	{
		DrawGraph(0, 0, rightarrow, true);
	}

}

