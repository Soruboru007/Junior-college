#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// �萔��`
	enum { NUMS_LIMIT = 10 };    // �f�[�^�̍ő�i�[����
	const int  endValue = -1;   // �I���l

	// �ϐ���`
	int  nums[NUMS_LIMIT];    // �f�[�^
	int  num;                   // ���͒l
	int  count;                 // ���͌���
	int  i;
	int  max;					// �ő�l
	int  maxIndexCount;			// �ő�l�̌�
	int  maxIndices[NUMS_LIMIT];//�ő�l�̂���Y�����i�v�f�ԍ��j��ۑ�����z��

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
	count = i;          // ( 3 ) ������ϐ� count �֑������

	// �v�Z
	if (count > 0) {
		max = nums[0];		//���ōő�l�����肷��
		maxIndexCount = 1;	//�ő�l1�ڂȂ̂ŏ����l��1�Ƃ���
		maxIndices[0] = 0;	//nums[0]��0���L������

		for (i = 1; i < count; i++) { //nums�ɓ��͂��ꂽ�������J��Ԃ�
			if (max < nums[i]) {	//�ő�l�̍X�V�����鎞
				max = nums[i];
				maxIndices[0] = i;
				maxIndexCount = 1;
			}
			else if (max == nums[i]) {
				maxIndices[maxIndexCount++] = i;
			}
			//�l�X�g���ċ��߂���@  ���̏ꍇmaxIndexCount�̏����l��0�ɂȂ�B
			/*if (max <= nums[i]) {
				if (max == nums[i]) {
					max = nums[i];
					maxIndexCount = 0;
				}
				maxIndices[maxIndexCount++] = i;
			}*/
		}
	}

	// �o��
	if (0 < count) {
		for (i = 0; i < count; i++) {
			printf("%5d", nums[i]);         // ( 4 ) �z������Ԃɏo�͂���
		}
		printf("\n");

		printf("�ő�l��%d�ł��B\n", max);
		if (1 < maxIndexCount) {
			printf("���� %d �ӏ��ɂ���܂��B\n", maxIndexCount);
			for (i = 0; i < maxIndexCount; i++) {
				printf("%2d����\n", maxIndices[i] + 1);
			}
		}
		else {
			printf(" % 2d����\n", maxIndices[0] + 1);
		}
	}

	return 0;
}