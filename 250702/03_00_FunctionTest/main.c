#define _CRT_SECURE_NO_WARNINGS
#include <math.h>            // fabs( )�֐����g�p���邽�߂ɕK�v
#include <stdio.h>           // scanf( ),printf( )�֐����g�p���邽�߂ɕK�v

int  main(void)
{
    double   fig;           // ��Βl�����߂錳�̐��l
    double   absFig;        // fabs( )�֐��̖߂�l���󂯎��ϐ�
    double   absFig1, absFig2, absFig3;


    scanf("%lf", &fig);   // scanf( )�֐��͓��͂��ꂽ�ϐ��̌���Ԃ����A
                             // ����͎󂯎��Ȃ��B
    absFig = fabs(fig);   // ��Βl���󂯎��̂ŕϐ��ɑ������B
    printf("|%f| = %f\n", fig, absFig);
    // printf( )�֐��͏o�͂�����������Ԃ����A
    // �K�v�Ȃ��̂Ŏ󂯎��Ȃ��B


    absFig1 = fabs(fig);       // �ϐ��������ɓn���B
    absFig2 = fabs(-32);       // ���e�����l�������ɓn���B
    absFig3 = fabs(fig - 32);  // �v�Z���������ɓn���B
    printf("|%f| = %f\n", fig, absFig1);
    printf("|%f| = %f\n", -32.0, absFig2);
    printf("|%f| = %f\n", fig - 32, absFig3);


    return  0;
}