#include <stdio.h>

void  swap(int* num1, int* num2)
// �Ăяo���ꂽ�Ƃ���
// ( 1 ) num1 �̒l 5 (2) num2 �̒l 3
// ( 3 ) *num1 �� 100�Ԓn�̒��g[�����͐��l]
// ( 4 ) *num1 �� main( )�֐��̕ϐ� value1�̒l[�����͕ϐ���]
// ( 5 ) *num2 �� 200�Ԓn�̒��g[�����͐��l]
// ( 6 ) *num2 �� main( )�֐��̕ϐ� value2�̒l[�����͕ϐ���]
{
	int  num;

	// �ȉ��͑����̂��ꂼ��̕ϐ��̒l
	num = *num1;  // ( 7 ) num    �̒l5
	*num1 = *num2;  // ( 8 ) value1 �̒l 3
	*num2 = num;    // ( 9 ) value2 �̒l5

}

//�l�n����
void  swap_err(int num1, int num2)
// �Ăяo���ꂽ�Ƃ���
// ( 1 ) num1 �̒l 5(2) num2 �̒l3
{
	int  num;

	// �ȉ��͑����̂��ꂼ��̕ϐ��̒l
	num = num1;    // ( 3 ) num  �̒l 	5
	num1 = num2;    // ( 4 ) num1 �̒l 	3
	num2 = num;     // ( 5 ) num2 �̒l 	5

}

int  main(void)
{
	int  value1, value2;

	value1 = 5;
	value2 = 3;

	printf("value1:%d\n", value1);
	printf("value2:%d\n", value2);

	//�l�n��
	swap_err(value1, value2);  // 2�̒l������������
	// swap( ) �֐����s���
	// ( 10 ) value1 �̒l 	3		(11) value2 �̒l		5
	printf("err_value1:%d\n", value1);
	printf("err_value2:%d\n", value2);


	//�|�C���^�n��
	swap(&value1, &value2);  // 2�̒l������������
	// swap( ) �֐����s���
	// ( 10 ) value1 �̒l 	3		(11) value2 �̒l		5
	printf("value1:%d\n", value1);
	printf("value2:%d\n", value2);

	return  0;
}

