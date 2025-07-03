#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���̊K������߂�
// �߂�l�@int   :�������̊K�悵���l
// �����@�@int n :�K�悵�����l
int  factorial(int n) {
	int value;
	int i;
	value = 1;
	for (i = 2; i <= n; i++) { //2���炎�܂�value�ɂ����Ă���
		value *= i;
	}
	return value;
}

// n ���� r ����ׂ鏇��̏ꍇ�̐������߂�B
// �߂�l�@int   :����̏ꍇ�̐�
// �����@�@int n :������
// �@�@�@�@int r :���ׂ鐔��
int  permutation(int n, int r) {
	int value;
	value = factorial(n) / factorial(n - r);  //nPr=n!/(n-r)!
	return value;
}

// n ���� r �����o���g�ݍ��킹�̏ꍇ�̐������߂�B
// �߂�l�@int   :�g�ݍ��킹�̏ꍇ�̐�
// �����@�@int n :������
// �@�@�@�@int r :���o������
int  combination(int n, int r) {
	int value;
	value = permutation(n, r) / factorial(r);	//nCr = nPr/r!
	return value;
}

int main(void) {
	//�ϐ��錾
	int n, r; //���͒l
	int fac, nPr, nCr;	//�K��A����A�g�����̓�

	//����
	printf("�K��(n!)�A����(nPr)�A�g�����̏ꍇ�̐�(nCr)�����߂܂��B\n");
	printf("n��r�̒l����͂��Ă��������B\n");
	fflush(stdout);
	scanf("%d %d", &n, &r);

	// �v�Z�i�����Ŋ֐��𗘗p����j
	fac = factorial(n);
	nPr = permutation(n, r);
	nCr = combination(n, r);
	// �o��
	printf("�K��  ( %d!) �̓����F%d\n", n, fac);
	printf("����  (%dP%d) �̓����F%d\n", n,r, nPr);
	printf("�g����(%dC%d) �̓����F%d\n", n, r, nCr);

	return 0;
}