#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum { LIMIT = 100 };	//�t�B�{�i�b�`����ۑ�����z��̏��
enum { END_VAL = 0 };	//���͂̏I���l

// �l�̓���  5�͖��2�@inputValue�ɏI���l����͂���ƃ��[�v���I������悤�ύX������---------------------
// �߂�l�@int    : ���͂��ꂽ�l  
// �����@�@prompt : ���͑��i������  
// �@�@ �@ min    : ���͉\�ŏ��l  
// �@�@ �@ max    : ���͉\�ő�l  
//		   end    : ���͏I���l
int  inputValue(const char* prompt, int min, int max, int end) {
	int  value;
	printf("%s( %d - %d, %d = �I�� ) ", prompt, min, max, end);
	fflush(stdout);
	scanf("%d", &value);
	while (!(min <= value && value <= max||value==end)) { // �I���������(min��value��max�A�܂���value=max)�ł͂Ȃ��Ƃ�
		printf("���͒l %d �͔͈͊O�ł��B\n", value);
		printf("������x�A");
		printf("%s( %d - %d ) ", prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}



// ���C���֐� ------------------------------------------------------------------------------
int main(void) {
	//�ϐ���`
	long long int fibonaccies[LIMIT];	// �t�B�{�i�b�`����̊e��
	int index;							// ���߂����t�B�{�i�b�`����̍�
	int i;

	// �������@��������fibonaccies�Ƀf�[�^������
	fibonaccies[0] = fibonaccies[1] = 1;

	for (i = 2; i < LIMIT; i++) {
		fibonaccies[i] = fibonaccies[i - 1] + fibonaccies[i - 2];
	}

	//�o��
	printf("�t�B�{�i�b�`����̑� n �������߂܂��B\n");
	index = inputValue("n ����͂��Ă��������B", 1, LIMIT, END_VAL);
	while (index != END_VAL) {
		printf("�� %d ���́A%lld �ł��B\n", index, fibonaccies[index - 1]);
		index = inputValue("n ����͂��Ă��������B", 1, LIMIT, END_VAL);
	}
	

	return 0;
}