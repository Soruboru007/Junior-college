#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// �萔��`
	enum { NUMS_LIMIT = 5 };    // �f�[�^�̍ő�i�[����

	// �ϐ���`
	int  nums[NUMS_LIMIT];    // �f�[�^
	int  count;                 // ���͌���
	int  i;

	// ����
	printf("���l�̓��͂��󂯕t���܂��B\n");
	printf("��������͂��Ă��������B( 1 - %d ) ", NUMS_LIMIT);
	fflush(stdout);
	scanf("%d", &count);

	while (!(1 <= count && count <= 5)) {
		printf("%d ���̐��l�͈����܂���B", count);
		printf("��������͂��Ă��������B( 1 - %d ) ", NUMS_LIMIT);
		fflush(stdout);
		scanf("%d", &count);
	}

	for (i = 0; i < count; i++) {     // ( 1 ) ���͂��ꂽ�������J��Ԃ�
		printf("%d���ڂ̐��l����͂��Ă��������B", i + 1);
		fflush(stdout);
		scanf("%d", &nums[i]);          // ( 2 ) �z��ɏ��Ԃɓ��͂���
	}

	// �o��
	printf("\n");
	for (i = 0; i < count; i++) {     // ( 3 ) �������J��Ԃ�
		printf("%5d", nums[i]);         // ( 4 ) �z������Ԃɏo�͂���
	}
	printf("\n");

	return 0;
}