#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	int  nums[] = { 11, 15, 23, 35, 42, 28, 22, 16, 7, };
	int  target;  // �����l
	int  index;   // ���������ʒu
	int  i;
	enum { NUMS_COUNT = sizeof(nums) / sizeof(nums[0]) };

	// �����l�̓���
	printf("���̐��񂩂�l���������܂��B\n");
	for (i = 0; i < NUMS_COUNT; i++) {
		printf("%3d", nums[i]);
	}
	printf("\n");
	printf("�������鐔�l��? ");
	fflush(stdout);
	scanf("%d", &target);

	// �l�̌���
	index = -1;  // ������Ȃ������Ƃ��̒l�ݒ�
	for (i = 0; i < NUMS_COUNT; i++) {
		if (target == nums[i]) {		 // ( 1 ) �z��̒��g�Ɠ��͒l����v������
			index = i;            // ( 2 ) �������������̓Y��������
			break;                    // ( 3 ) ���������̂Ń��[�v�𔲂���
		}
	}

	// �������ʂ̏o��
	printf("%d ��", target);
	if (0 <= index) {               // ( 4 ) �������� index���X�V����Ă���i�O�`�j
		printf(" %d �Ԗڂɂ���܂��B\n", index + 1); // ( 5 ) �ʒu
	}
	else {
		printf("����܂���B\n");
	}

	return 0;
}