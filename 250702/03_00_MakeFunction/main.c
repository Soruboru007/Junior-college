// *****************************************************
// �傫�����̐����l�����߂�v���O����
// *****************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �傫�����̒l�����߂�B-------------------------------
// �߂�l�@int    : �����̒l�̂����傫�����̒l
// �����@�@value1 : ��r�����l
// �@�@�@�@value2 : ��r����l
int  big(int value1, int value2)
{
	int bigValue;	//�߂�l�Ɠ����f�[�^�^�̕ϐ���p�ӂ���

    if (value1 < value2) {
        bigValue = value2;
    }
    else {
        bigValue = value1;
    }

	return bigValue;// return�̌��ɏ����ꂽ�����֐����Ăяo���ꂽ�Ƃ��ɖ߂�
}


// ���C���֐� ------------------------------------------
int  main(void)
{
    // �ϐ���`
    int num1, num2;      // ��r����l
    int bigNum;          // �傫�����̒l

    // ����
    printf("2�̒l���r���܂��B\n");
    printf("�����l��2���͂��Ă��������B");
    fflush(stdout);
    scanf("%d %d", &num1, &num2);

    // �v�Z
    bigNum = big(num1, num2);

    // �o��
    printf("%d �� %d �̂����A�傫�����̒l�� %d �ł��B\n", num1, num2, bigNum);

    return 0;
}