#pragma once

// ��ʂ̉��̑傫��
const int  SCREEN_WIDTH = 640;
// ��ʂ̏c�̑傫��
const int SCREEN_HEIGHT = 480;

// ��̃`�b�v�̃T�C�Y
const int  CHIP_SIZE = 60;

//------------------
// �\���̒�`
//------------------
struct MapChip
{
	// �}�b�v�`�b�v��ۑ�����ϐ�
	int mapChipImg[10];

	// �t�@�C�����當�����擾����ϐ�
	int getCharacter = 0;

	// ������ϐ�
	/* char�͕����^�����z��Ȃ��ߕ�����^�ƂȂ� */
	char buffer[10];

	// buffer����}�b�v�`�b�v�̔ԍ����󂯎��
	int num = 0;
	// ���̃}�b�v�`�b�v�̔ԍ�
	int widthNum = 0;
	// �c�̃}�b�v�`�b�v�̔ԍ�
	int heightNum = 0;


};

//------------------
// �N���X��`
//------------------
class MapChipClass
{
/* public�͂ǂ��ł��Ăׂ� */
public:
	// �R���X�g���N�^��`
	/* �R���X�g���N�^�Ƃ́A�N���X�̃����o�[�̏��������s�� */
	MapChipClass();

	// �f�X�g���N�^��`
	/* �f�X�g���N�^�Ƃ́A�N���X�̃����o�[�̌㏈�� */
	~MapChipClass();

	//// �z���p���ă}�b�v�`�b�v��`�悷��֐�
	void DrawArrayMapChip(int kurai,int num);
	void Drawgauge(int max);

/* private�̓N���X���ł����ĂׂȂ� */
private:
	// MapChip�̕ϐ��錾
	MapChip map;
	MapChip gauge;

};

