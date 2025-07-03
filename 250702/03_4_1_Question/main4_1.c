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

//���C��
int main(void) {
	// �萔�錾
	const char	strWeeks[][1 * 2 + 1] = { "��", "��", "��", "��", "��", "��", "�y", };
	// �ϐ��錾
	int year, month, day;
	weekday_t week;

	// ����
	printf("�j�������߂܂��B\n");
	printf("���t����͂��Ă��������B(�N/��/��) ");
	fflush(stdout);
	scanf("%d/%d/%d", &year, &month, &day);

	// �v�Z
	week = dayOfWeek(year, month, day);
	// �o��
	printf("%d�N%d��%d���́A%s�j���ł��B\n", year, month, day, strWeeks[week]);
	return 0;
}
