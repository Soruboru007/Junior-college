#include <stdio.h>
int main(void) {
	// �萔
	enum { STRING_SIZE = 26 };	// �z��̑傫��
	enum { COLUMN_COUNT = 6 };	// 1�s�ɕ\�����镶����
	enum { COUNT_RETURN = (STRING_SIZE - 1) / COLUMN_COUNT + 1 };		// ���s�����

	enum { ARRAY_SIZE = STRING_SIZE + COUNT_RETURN + 1 };
	const char startCH = 'a';

	// �ϐ���`
	char	string[ARRAY_SIZE];		// �A���t�@�x�b�g������z�� 
	char	ch;							// ������镶��
	int		column;
	int i;
	int index;						//�f�[�^��������z��̓Y�����i�v�f�̈ʒu�j

	//������
	ch = startCH;
	column = 0;
	index = 0;

	//�l�̑��	26��̌J��Ԃ��̒��ŉ��s���������
	for (i = 0; i < STRING_SIZE; i++) {
		string[index++] = ch++;
		if (COLUMN_COUNT <= ++column) { //6����������
			string[index++] = '\n';
			column = 0;
		}
	}
	if (0 < column) {
		string[index++] = '\n';
	}
	string[index] = '\0';
	// �o��
	printf("%s", string); //string�z���\0�܂őS���������o�͂���

	return 0;
}