#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �������j���[�o�� -------------------------------------------------------
// �߂�l : �Ȃ�
// �����@ : �Ȃ�
void  printPrompt(void)
{
    printf("���L�̔ԍ�����͂��ď�����I�����Ă��������B\n");
    printf("1 �������Ƃ�\n");
    printf("2 �U��\n");
    printf("3 �c���Ɖ�\n");
    printf("4 ����\n");
    printf("�ԍ�����͂��Ă��������B( 1 - 4 ) ");
}

// ���j���[�ԍ����� -------------------------------------------------------
// �߂�l int : ���j���[�ԍ�
// �����@ �@�@: �Ȃ�
int  inputMenu(void)
{
    int  selection;

    printPrompt();
    fflush(stdout);
    scanf("%d", &selection);

    return  selection;
}

// ���j���[�ԍ��I�� -------------------------------------------------------
// �߂�l int : ���������j���[�ԍ�
// �����@ �@�@: �Ȃ�
int  selectMenu(void)
{
    int  selection;

    printf("��������Ⴂ�܂�\n");
    selection = inputMenu();
    while (!(1 <= selection && selection <= 4)) {
        printf("���͂��ꂽ %d �͏����ł��܂���B\n", selection);
        printf("������x���͂��Ă��������B\n");
        selection = inputMenu();
    }

    return  selection;
}


// �_���^
typedef enum { FALSE, TRUE, }  bool_t;

// �~���̒����Ɖ~�̖ʐς����߂�B---------------------------------------------
// �߂�l�@bool_t : �������v�Z�ł��� TRUE, ���a�����ł����� FALSE
// �����@�@radius : �~�̔��a
// �����@�@circum : �~�̉~��
// �����@�@area   : �~�̖ʐ�
bool_t  circle(double radius, double* circum, double* area)
{
    const double  pi = 3.14159265358979;
    bool_t        result;


    if (0 <= radius) {
        *circum = 2 * pi * radius;
        *area = pi * radius * radius;
        result = TRUE;
    }
    else {
        result = FALSE;
    }

    return  result;
}


// ���C���֐� ------------------------------------------------------------
int  main(void)
{
    int  selection;
    bool_t flg;
    double length, area;

    selection = selectMenu();

    flg = circle(-1,&length,&area);
    // �ȉ��A�����������B
}