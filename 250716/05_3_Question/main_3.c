#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�萔
typedef enum { FALSE, TRUE } bool_t;

// ���Ƃ��܂�����߂�֐��@�O�̎�����Ȃ�������Y��Ȃ��悤�ɁI
bool_t divide(int num1, int num2, int* quot, int* remain) {
	bool_t result = FALSE;
	if (num2 != 0) {
		*quot = num1 / num2;
		*remain = num1 % num2;
		result = TRUE; //�v�Z�ł����Ƃ��Ɍ��ʂ�TRUE�ɂ���
	}
	return result;
}

int main(void) {
	//�ϐ��錾
	int num1;		//�����鐔
	int num2;		//���鐔
	int quot;		// ��
	int	remain;		// �]��
	bool_t result;	//�v�Z�ł�����

	// ����
	printf("2 �̐��̏��Ɨ]������߂܂��B\n");
	printf("�����鐔����͂��Ă��������B");
	fflush(stdout);
	scanf("%d", &num1);
	printf("���鐔����͂��Ă��������B");
	fflush(stdout);
	scanf("%d", &num2);

	//���Ɨ]�苁�߂�i�v�Z�ł������������ŋ��߂���j
	result = divide(num1, num2, &quot, &remain);

	// �o�́@�v�Z�ł��邩�ۂ��ŕ���
	if (result) {
		printf("%d �� %d �Ŋ����� ��  �� %d �ł��B\n", num1, num2, quot);
		printf("%d �� %d �Ŋ������]�� �� %d �ł��B\n", num1, num2, remain);
	}
	else {
		printf("���鐔�� 0 �Ȃ̂Ōv�Z�ł��܂���B\n");
	}
	return 0;
}