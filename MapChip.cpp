#include "DxLib.h"
#include "MapChip.h"

// �R���X�g���N�^�錾
MapChipClass::MapChipClass()
{
	//�X�R�A�̉摜�ǂݍ���
	LoadDivGraph("data/texture/kazu.png", 10, 10, 1, CHIP_SIZE, CHIP_SIZE, m_Score.mapChipImg);
	// �Q�[�W�̉摜�ǂݍ���
	LoadDivGraph("data/texture/gauge.png", 10, 10, 1,103, 720, m_gauge.mapChipImg);

}

// �f�X�g���N�^�錾
MapChipClass::~MapChipClass()
{

}

void MapChipClass::DrawArrayMapChip(int _column, int _num)
{

	//�X�R�A�̐����\���̕`��
	DrawGraph(_column * 60,0, m_Score.mapChipImg[_num], true);
}

void MapChipClass::Drawgauge(int _max)
{
	//�Q�[�W�̕\���`��
	DrawGraph(1200, 0, m_gauge.mapChipImg[_max], true);
}

