#include <stdio.h>
int main(void) {
	// �萔
	enum { STRING_SIZE = 26 };	// �z��̑傫��
	enum { COLUMN_COUNT = 6 };	// 1�s�ɕ\�����镶����

	const char startCH = 'a';

	// �ϐ���`
	char	string[STRING_SIZE];		// �A���t�@�x�b�g������z�� 
	char	ch;							// ������镶��
	int		column;
	int i;
	//������
	ch = startCH;
	column = 0;

	for (i = 0; i < STRING_SIZE; i++) {
		string[i] = ch++;
	}

	// �o��
	for (i = 0; i < STRING_SIZE; i++) {
		printf("%c",string[i]);
		if (COLUMN_COUNT <= ++column) {
			printf("\n");
			column = 0;
		}
	}
	printf("\n");
	string[25] = '\0';
	printf("%s", string);
	return 0;
}