#include "DxLib.h"
#include "MapChip.h"

// �R���X�g���N�^�錾
MapChipClass::MapChipClass()
{
	// LoadDivgraph(�t�@�C���̏ꏊ, �S�̖̂���, ���̖���, �c�̖���, �P���̑傫��(��), �P���̑傫��(�c), �ۑ�����ϐ���);
	LoadDivGraph("data/texture/kazu.png", 10, 10, 1, 60, 60, map.mapChipImg);
	// ���[�^�[
	LoadDivGraph("data/texture/gauge.png", 10, 10, 1,103, 720, gauge.mapChipImg);

}

// �f�X�g���N�^�錾
MapChipClass::~MapChipClass()
{

}

// �z���p���ă}�b�v�`�b�v��`�悷��֐�
void MapChipClass::DrawArrayMapChip(int kurai, int num)
{
	// MapData�ɓ����Ă��鐔�l�Ԗڂ̃}�b�v�`�b�v�摜���w�肵���ʒu�ɕ`�悷��
	/* DrawGraph(�w�肵���ʒu��x���W, �w�肵���ʒu��y���W, �\������摜. �����x��L���ɂ��邩(ture:�L���ɂ���, false:�L���ɂ��Ȃ�); */

	//�l����z�肵�č�
	DrawGraph(kurai * 60,0, map.mapChipImg[num], true);
}

void MapChipClass::Drawgauge(int max)
{
	// MapData�ɓ����Ă��鐔�l�Ԗڂ̃}�b�v�`�b�v�摜���w�肵���ʒu�ɕ`�悷��
	/* DrawGraph(�w�肵���ʒu��x���W, �w�肵���ʒu��y���W, �\������摜. �����x��L���ɂ��邩(ture:�L���ɂ���, false:�L���ɂ��Ȃ�); */

	//�l����z�肵�č�
	DrawGraph(1200, 0, gauge.mapChipImg[max], true);
}

