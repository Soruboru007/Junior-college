#include <math.h>            // fabs( )�֐����g�p���邽�߂ɕK�v
#include <stdio.h>
#include <stdlib.h>

int  main(void)
{
    // �ϐ��錾
    double figSqrt; // �������̌���
    double figFabs; // ������Βl�̌���
    double figPow;  // �ׂ���̌���
    int numAbs;     // ������Βl�̌���

    // �v�Z
    figSqrt = sqrt(10);
    figFabs = fabs(-3.5);
    figPow = pow(2, 10);
    numAbs = abs(-3);

    // �o��
    printf("( 1 ) 10 �̕�����    : %lf\n",figSqrt);
    printf("( 2 )  -3.5 �̐�Βl : %lf\n",figFabs);
    printf("( 3 ) 2 �� 10 ��     : %lf\n",figPow);
    printf("( 4 ) -3 �̐�Βl    : %d\n",numAbs);

    return  0;
}