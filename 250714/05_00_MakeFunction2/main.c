#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// �z��ɐ��l����͂���B---------------------------------------------------
// �߂�l�@int   : ���͂��ꂽ����
// �����@�@nums  : ���͐��l�����߂�z��
// �@�@�@�@limit : �z�� nums �̑傫��
int  inputArray(int* nums, int limit)
{
    int  count;

    int  num;
    int  i;

    printf("���̐���̑��a�����߂܂��B\n");
    for (i = 0; i < limit; i++) {
        printf("���l����͂��Ă��������B( �I�� = 0�ȉ��̒l �j");
        fflush(stdout);
        scanf("%d", &num);
        if (num <= 0) {
            break;
        }
        nums[i] = num;
    }
    count = i;

    return  count;
}

// �z��̑��a���v�Z����B---------------------------------------------------
// �߂�l�@int   : �z�� nums �̐��l�̑��a
// �����@�@nums  : �v�Z�Ώ۔z��
// �@�@�@�@count : �z�� nums �̌���
int  sumArray(const int* nums, int count)
{
    int  sum;
    int  i;

    sum = 0;
    for (i = 0; i < count; i++) {
        sum += nums[i];
    }
    return  sum;
}

// ���C���֐� ------------------------------------------------------------
int  main(void)
{
    // �萔��`
    enum { LIMIT = 100 };   // �z��̌�

    // �ϐ���`
    int  nums[LIMIT];     // �l���i�[����z��
    int  count;             // ����
    int  sum;               // ���a

    count = inputArray(nums, LIMIT);     // �z��ɐ��l����͂���B
    sum = sumArray(nums, count);     // �z��̑��a���v�Z����B
    printf("������ %d ���ł��B\n", count);  // �z��̑��a��\������B
    printf("���a�� %d �ł��B\n", sum);

    return  0;
}