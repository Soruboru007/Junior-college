#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���a����~�̖ʐς����߂�B
// �߂�l�@double : �����Ŏw�肳�ꂽ���a�̉~�̖ʐ�
// �����@�@radius : �~�̔��a
double circleArea(double radius) {
	const double	PI = 3.1415926535897932384626;
	double area;
	area = PI * radius * radius;
	return area;
}


// ���a����~���̒��������߂�B
// �߂�l�@double : �����Ŏw�肳�ꂽ���a�̉~���̒���
// �����@�@radius : �~�̔��a
double circumference(double radius) {
	const double	PI = 3.1415926535897932384626;
	double length;
	length = 2 * PI * radius;
	return length;
}

// ���a����~���̒����Ɖ~�̖ʐς����߂�B
// �߂�l�@�Ȃ�
// �����@�@radius : �~�̔��a
// �@�@�@  length : �~���̒���
// �@�@�@  area   : �~�̖ʐ�
void circleProperty(double radius, double* length, double* area) {
	*length = circumference(radius);
	*area = circleArea(radius);
}

int main(void) {
	double radius;			//�~�̔��a
	double length, area;	//�~���̒����A�ʐ�

	printf("�~�̖ʐς����߂܂��B\n");
	printf("���a����͂��Ă��������B");
	fflush(stdout);
	scanf("%lf", &radius);

	circleProperty(radius, &length, &area);

	printf("���a %.3lf �̉~���̒����� %lf �~�̖ʐς� %lf �ł��B", radius, length, area);

	return 0;
}