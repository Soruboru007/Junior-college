#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �萔�錾 --------------------------------------------------------------------------------
enum { LIMIT = 10 };			// �ő���͉\����
const int	finalValue = -1;	// ���͏I���l

//���l�̓��� �z��ɐ��l���͂��Ă����i2�͖��3�i2�j�Ɠ��������j
// �߂�l�@int        : ���ۂɓ��͂��ꂽ�l�̌���
// �����@�@nums       : ���͒l���i�[����z��
//         limit      : �ő���͉\����nums�̔z��
//         finalValue : ���͏I���l
int inputData(int* nums, int limit, int endValue) {
	int count;
	int i;
	int num;
	printf("�f�[�^����͂��Ă��������B\n");
	printf("%d ���ɒB���邩 %d ����͂���ƁA���͏������I�����܂��B\n", limit, endValue);

	for (i = 0; i < limit; i++) {
		fflush(stdout);
		scanf("%d", &num);
		if (num == endValue) {
			break;
		}
		nums[i] = num;
	}
	count = i;  //������ϐ� count �֑������
	return count;
}

//���a�Z�o�@�z��̂��ׂẴf�[�^�𑫂�
// �߂�l�@int   : ���� nums �̃f�[�^�̑��a
// �����@�@nums  : ���͒l���i�[����z��
// �@�@�@�@count : ���͌���
int getSum(const int* nums, int count) {
	int sum;
	int i;
	sum = 0;
	for (i = 0; i < count; i++) {
		sum += nums[i];
	}

	return sum;
}

//���ώZ�o ����0�̎��͕��ς����߂��A0�Ƃ��邱��
// �߂�l�@double : ���� nums �̃f�[�^�̕���
// �����@�@nums   : ���͒l���i�[����z��
// �@�@�@�@count  : ���͌���
double getAve(const int* nums, int count) {
	return count != 0 ? (double)getSum(nums, count) / count : 0;

	//�������Z�q�𗘗p���Ȃ��ꍇ
	double ave = 0;
	if (count != 0) {
		ave = (double)getSum(nums, count) / count;
	}
	return ave;
}

// MAIN�֐�-------------------------------------------------------
int main(void) {
	// �ϐ��錾
	int		nums[LIMIT];		// �f�[�^
	int		count;				// ����
	int		sum;				// ���a
	double	average;			// ����

	//����
	printf("���v�l���Z�o���܂��B\n");
	count = inputData(nums, LIMIT, finalValue);

	//�v�Z
	sum = getSum(nums, count);
	average = getAve(nums, count);

	// �o��
	printf("�f�[�^���� %d\n", count);
	printf("�f�[�^���a %d\n", sum);
	printf("�f�[�^���� %.3f\n", average);

	return 0;
}