#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// �萔��`
	enum { NUMS_LIMIT = 5 };  // �f�[�^�̍ő�i�[����
	const int  endValue = -1; // �I���l
	const char CH = '*';

	// �ϐ���`
	int  nums[NUMS_LIMIT];    // �f�[�^
	int  num;                 // ���͒l
	int  count;               // ���͌���
	int  i,j;

	// ����
	printf("���l�̓��͂��󂯕t���܂��B\n");
	for (i = 0; i < NUMS_LIMIT; i++) { // ( 1 ) �z��̗v�f���𒴂��Ȃ���
		printf("%d���ڂ̐��l����͂��Ă��������B(�I�� = %d) ", i + 1, endValue);
		fflush(stdout);
		scanf("%d", &num);
		if (num == endValue) {
			break;
		}
		nums[i] = num;      // ( 2 ) �z�� nums �ɓ��͒l���i�[����
	}
	count = i;				// ( 3 ) ������ϐ� count �֑������

	   // �o��

	for (i = 0; i < count; i++) {
		printf("%5d : ", nums[i]);       // ( 4 ) �z������Ԃɏo�͂���
		for (j = 0; j < nums[i]; j++) {  // nums[i]���J�Ԃ��񐔂ɂȂ�
			printf("%c", CH);
		}
		printf("\n");
	}

	return 0;
}