#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		//fabs�𗘗p���邽�߂ɓ����

//�i1�j��`�̕��ƍ�������ʐς����߂�B
// �߂�l�@double : ��`�̖ʐ�
// �����@�@width : ��`�̕�
// �����@�@height : ��`�̍���
double  rectAreaByLength(double width, double height) {
	double area;
	area = fabs(width * height);
	return area;
}

// �i2�j��`�̕��ƍ�������O���̒��������߂�B
// �߂�l�@double : ��`�̊O���̒���
// �����@�@width : ��`�̕�
// �����@�@height : ��`�̍���
double  rectBoundsByLength(double width, double height) {
	double len;
	len = (fabs(width) + fabs(height)) * 2;
	return len;
}

//�i3�j��`�̑Ίp���W2�_����ʐς����߂�B
// �߂�l�@double : ��`�̖ʐ�
// �����@�@left : ��`�̍����W
// �����@�@top : ��`�̏���W
// �����@�@right : ��`�̉E���W
// �����@�@bottom : ��`�̉����W
double  rectAreaByEdge(double left, double top, double right, double bottom) {
	double area;
	double width, height;
	width = right - left;
	height = bottom - top;

	area = rectAreaByLength(width, height);
	return area;
}

//�i4�j��`�̑Ίp���W2�_����O���̒��������߂�B
// �߂�l�@double : ��`�̊O���̒���
// �����@�@left : ��`�̍����W
// �����@�@top : ��`�̏���W
// �����@�@right : ��`�̉E���W
// �����@�@bottom : ��`�̉����W
double  rectBoundsByEdge(double left, double top, double right, double bottom) {
	double length;
	double width, height;
	width = right - left;
	height = bottom - top;
	length = rectBoundsByLength(width, height);
	return length;
}

int main(void) {
	// �ϐ���`
	double w, h;			//���͒l�i���A�����j
	double area, length;	//�ʐρA�O���̒���
	double area2, length2;	//�ʐρA�O���̒���
	double r, l, t, b;		//���͒l�i�E�A���A��A���j

	// ����
	printf("���ƍ�������͂��Ă������� ");
	fflush(stdout);
	scanf("%lf %lf", &w, &h);

	printf("���A����W����͂��Ă��������@");
	fflush(stdout);
	scanf("%lf %lf", &l, &t);
	printf("�E�A�����W����͂��Ă��������@");
	fflush(stdout);
	scanf("%lf %lf", &r, &b);

	// �v�Z
	area = rectAreaByLength(w, h);
	length = rectBoundsByLength(w, h);

	area2 = rectAreaByEdge(l, t, r, b);
	length2 = rectBoundsByEdge(l, t, r, b);

	// �o��
	printf("�� %.2lf ���� %.2lf�̋�`�̖ʐς� %.2lf �A�O���̒����� %.2lf�@\n", w, h, area, length);
	printf("�Ίp���W( %.2lf , %.2lf),( %.2lf , %.2lf)�̖̂ʐς� %.2lf �A�O���̒����� %.2lf�@\n", l, t, r, b, area2, length2);

	return 0;
}