// *****************************************************
// ���a����~�̖ʐς����߂�v���O����
// *****************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// �~�̖ʐς����߂�B-------------------------------
// �߂�l�@double    : ���aradius�̉~�̖ʐ�
// �����@�@radius �@ : �~�̔��a
double  circleArea(double radius) {
	const double PI = 3.1415926535;
	double area;		//�ʐ�

	area = PI * radius * radius;
	area = PI * pow(radius, 2);	//math.h�g���ꍇ�͂���ł�OK
	
	return area;
}

//���C��--------------------------------------------
int main(void) {
	// �ϐ��錾
	double radius;	//�~�̔��a
	double area;	//�~�̖ʐ�
	
	//����
	printf("�~�̖ʐς����߂܂��B\n");
	printf("���a����͂��Ă�������");
	fflush(stdout);
	scanf("%lf", &radius);

	// �v�Z
	area = circleArea(radius);

	// �o��
	printf("���a %.2lf�̉~�̖ʐς� %.2lf �ł��B\n", radius, area);

	return 0;
}