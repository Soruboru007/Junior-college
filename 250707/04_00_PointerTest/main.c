#include <stdio.h>
int main(void) {
	int    num;    // int�^ �̕ϐ�
	int*   pNum;   // int�^ �̕ϐ������݂���A�h���X(�|�C���^)�̕ϐ�
	int    num2 ;   // int�^ �̕ϐ������� 1 ��

	num = 5;
	pNum = &num;   // �|�C���^ pNum �Ɂu�ϐ� num �̃A�h���X�v��������B
	num2 = *pNum;  // �u100�Ԓn�̒��g�v��ϐ� num2 �ɑ������B


	printf("�ϐ�     num  �̒l %8d �A�h���X %p\n", num, &num);
	printf("�|�C���^ pNum �̒l %p �A�h���X %p\n", pNum, &pNum);
	printf("�ϐ�     num2 �̒l %8d �A�h���X %d\n", num2, &num2);

	char    string[] = "abcde";
	// char�^ �̔z��ϐ� �擪�A�h���X�� 100 �Ƃ���
	char* pStr;     // char * �^ �̕ϐ� ( �|�C���^ )

	pStr = string;    // �z��ϐ� string �̐擪�A�h���X���|�C���^ pStr �ɑ��

	printf("string        = %d\n", string);       // &string[ 0 ] �Ɠ���
	printf("pStr          = %d\n", pStr);         // string �Ɠ���
	printf("string + 1    = %d\n", string + 1);   // 100 + 1 = 101
	printf("pStr + 1      = %d\n", pStr + 1);     // string + 1 �܂� 101
	printf("*(pStr + 1)   = %c\n", *(pStr + 1));    // 101�Ԓn�̒��g
	printf("*(string + 1) = %c\n", *(string + 1));  // 101�Ԓn�̒��g
	printf("string[ 1 ]   = %c\n", string[1]);  // *(string + 1) �Ɠ���

	int    nums[] = { 1, 2, 3, 4, 5, };
	// int �^ �̔z��ϐ� �擪�A�h���X�� 100 �Ƃ���
	

	pNum = nums;    // �z��ϐ� nums �̐擪�A�h���X���|�C���^ pNum �ɑ��

	printf("nums        = %d\n", nums);       // &nums[ 0 ] �Ɠ���
	printf("pNum        = %d\n", pNum);       // nums �Ɠ���
	printf("nums + 1    = %d\n", nums + 1);   // 100 + 1 �~ 4 = 104
	printf("pNum + 1    = %d\n", pNum + 1);   // nums + 1 �܂� 104
	printf("*(pNum + 1) = %d\n", *(pNum + 1));  // 104�Ԓn�̒��g
	printf("*(nums + 1) = %d\n", *(nums + 1));  // 104�Ԓn�̒��g
	printf("nums[ 1 ]   = %d\n", nums[1]);  // *(nums + 1) �Ɠ���
	return 0;


}