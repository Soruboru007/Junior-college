#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �j���^
typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } weekday_t;

//�j�������߂�
//�߂�l weekday_t : �Z�o���ꂽ�j��
//����   year    : �j�������߂����N
// �@�@  month   : �j�������߂�����
// �@�@�@day     : �j�������߂�����
weekday_t dayOfWeek(int year, int month, int day) {
	weekday_t week;
	int num;
	if (month >= 3) {
		month -= 2;
	}
	else {
		month += 10;
		year--;
	}
	num = year + year / 4 - year / 100 + year / 400 + (13 * month - 1) / 5 + day;
	week = (weekday_t)(num % 7);

	return week;
}

//0�N3��1��(����j����̌o�ߓ��������߂�
//�߂�l int�@�@ : �Z�o���ꂽ�j��
//����   year    : ���������߂����N
// �@�@  month   : ���������߂�����
// �@�@�@day     : ���������߂�����
int  daysFrom031(int year, int month, int day){
	int days;
	if (month >= 3) {
		month -= 2;
	}
	else {
		month += 10;
		year--;
	}
	days = year * 365 + year / 4 - year / 100 + year / 400 + (153 * month - 151) / 5 + day;
	return days;
}

//�Q�̓��t�Ԃ̌o�ߓ��������߂�
//�߂�l int�@�@     : �Z�o���ꂽ�j��
//����   preYear     : ��̔N
// �@�@  preMonth    : ��̌�
// �@�@�@preDay      : ��̓�
//       postYear    : ��̔N
// �@�@  postMonth   : ��̌�
// �@�@�@postDay     : ��̓�
int  days(int preYear, int preMonth, int preDay, int postYear, int postMonth, int postDay) {
	int days;
	days = daysFrom031(postYear, postMonth, postDay);
	days -= daysFrom031(preYear, preMonth, preDay);
	return days;
}

//���C��
int main(void) {
	// �萔�錾
	
	// �ϐ��錾
	int year, month;	//���͔N��
	weekday_t week;		//�P���̗j��
	int count;			//���͂����N���̓���
	int column;			//���s�p�J�E���^
	int i;

	// ����
	printf("�J�����_�[��\�����܂��B\n");
	printf("�N������͂��Ă��������B(�N/��)  ");
	fflush(stdout);
	scanf("%d/%d", &year, &month);

	// �v�Z ���͂����N���̂P���̗j���ƁA���̌��ɉ������邩�����߂�
	week = dayOfWeek(year, month, 1);
	count = days(year, month, 1, year, month + 1, 1);

	// �o��
	//�^�C�g���s
	printf("       %d �N %d ��\n",year,month);

	//�j�����o��
	printf("sun mon tue wed thu fri sat\n");

	//�P���̗j������󔒂��o�͂���
	for (i = 0; i < week; i++) {
		printf("    ");
	}
	column = week;	//�󔒂��o�͂��������s�p�J�E���^�𑝂₵�Ă���

	//���͂����N���̓������������o�͂���(�V��o�͂�������s����j
	for (i = 0; i < count; i++) {
		printf("%3d ", i + 1);
		if (++column >= 7) {
			column = 0;
			printf("\n");
		}
	}
	if (column > 0) {
		printf("\n");
	}
	return 0;
}
