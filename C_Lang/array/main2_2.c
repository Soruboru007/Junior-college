#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	int  nums[] = {
		11, 15, 23, 35, 42, 28, 22, 16, 7,
		22, 16, 18, 22, 16, 15, 23, 23, 42,
	};
	int  target;                  // �����l
	int  i;
	enum { NUMS_COUNT = sizeof(nums) / sizeof(nums[0]) };
	int  indices[NUMS_COUNT];   // �����ʒu
	int  indexCount;              // ������������


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

	indexCount = 0;						// ( 1 ) �������������� 0
	for (i = 0; i < NUMS_COUNT; i++) {
		if (target == nums[i]) {		// ( 2 ) �z��̒��g�Ɠ��͒l����v������
			indices[indexCount++] = i;  // ( 3 ) �����ʒu��ۑ����A������1���₷
		}
	}

	// �������ʂ̏o��
	printf("%d ��", target);
	if (0 < indexCount) {								  // ( 4 ) ��������
		printf("���� %d �ӏ��ɂ���܂��B\n", indexCount); // ( 5 ) ����
		for (i = 0; i < indexCount; i++) {				  // ( 6 ) ���������ʒu���ׂ�
			printf("%3d �Ԗ�\n", indices[i] + 1);		  // ( 7 ) ���ꂼ��̈ʒu
		}
	}
	else {
		printf("����܂���B\n");
	}

	return 0;
}