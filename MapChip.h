#pragma once


// ��̃`�b�v�̃T�C�Y
const int  CHIP_SIZE = 60;

//------------------
// �\���̒�`
//------------------
struct MapChip
{
	// �}�b�v�`�b�v��ۑ�����ϐ�
	int mapChipImg[10];

};

//------------------
// �N���X��`
//------------------
class MapChipClass
{
public:
	// �R���X�g���N�^��`
	MapChipClass();

	// �f�X�g���N�^��`
	~MapChipClass();

	//// �z���p���ă}�b�v�`�b�v��`�悷��֐�
	void DrawArrayMapChip(int _column,int _num);
	void Drawgauge(int _max);

private:
	//�X�R�A�̕ϐ�
	MapChip m_Score;
	//�Q�[�W�̕ϐ�
	MapChip m_gauge;

};

