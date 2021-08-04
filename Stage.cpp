#include "Stage.h"
#include "Player.h"
#include "EnemyBase.h"


//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Stage::Stage()
	: m_stage(-1)
	, m_hitRadius(5.0f)
	,m_goal(-1)
{
	// �R�c���f���̓ǂݍ���
	m_stage = MV1LoadModel("data/model/stage3/Old Town.pmx");
	m_goal = MV1LoadModel("data/�C���n�C�S�[���Q�[�g/���C���n�C�S�[���T�C�h�p�l����.pmx");
	
	//���̉摜�ǂݍ���
	m_arrow = LoadGraph("data/texture/Arrow.png");
	m_rightarrow = LoadGraph("data/texture/Right arrow.png");
	m_leftarrow = LoadGraph("data/texture/Left arrow.png");

	//�v���C���[�̃|�W�V����
	m_pos = VGet(0, 0, 0);

	m_goalpos= VGet(0, 0, 1200);

	MV1SetScale(m_stage, VGet(1.0f, 1.0f, 2.0f));//�X�e�[�W�������Ă��
	MV1SetScale(m_goal, VGet(2.0f, 1.0f, 2.0f));//�S�[���Q�[�g�������Ă��

}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Stage::~Stage()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(m_stage);
	MV1DeleteModel(m_goal);

}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Stage::Update()
{


	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_stage, m_pos);

	MV1SetPosition(m_goal, m_goalpos);


}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void Stage::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(m_stage);
	MV1DrawModel(m_goal);

	DrawGraph(0, 0, m_arrow, true);//��ɏo����̃A�C�R��
		// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Key & PAD_INPUT_LEFT)//�����A�E�L�[�����͂��ꂽ��A�C�R���ɐF����
	{
		DrawGraph(0, 0, m_leftarrow, true);
	}
	if (Key & PAD_INPUT_RIGHT)//�����A�E�L�[�����͂��ꂽ��A�C�R���ɐF����
	{
		DrawGraph(0, 0, m_rightarrow, true);
	}

}

