#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �萔��` ------------------------------------------------  
// ����  
const char digits[] = "0123456789abcdef";

// �ϊ���̊�̍ŏ��l�A�ő�l  
// -1 �� '\0' ��������������  
enum { MIN_RADIX = 2 };
enum { MAX_RADIX = sizeof(digits) / sizeof(digits[0]) - 1 };
// 10 �i���̍ŏ��l�A�ő�l�A�ő�ϊ���̌���  
enum { MIN_DECIMAL = 0, MAX_DECIMAL = 65535, MAX_BITS = 16, };

// �l�̓���	---------------------------------------------------------------  
// �߂�l�@int    : ���͂��ꂽ�l  
// �����@�@prompt : ���͑��i������  
// �@�@ �@ min    : ���͉\�ŏ��l  
// �@�@ �@ max    : ���͉\�ő�l  
//             ( 1 )	prompt �̌^�@( 2 ) min �̌^�@( 3 ) max �̌^  
int  inputValue(const char* prompt, int    min, int    max)
{
	int  value;
	printf("%s( %d - %d ) ", /*( 4 )*/ prompt,  min, max);
	fflush(stdout);
	scanf("%d", &value);
	// ( 5 ) ���͒l���͈͊O�ł����  
	while (!(min <= value && value <= max)) {
		printf("���͒l %d �͔͈͊O�ł��B\n", value);
		printf("������x�A");
		printf("%s( %d - %d ) ", /*( 6 )*/ prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}

// ���C���֐� --------------------------------------------------------- 

int main(void)
{
	// �ϐ��錾  
	int  decimal;     // 10 �i��  
	int  dstRadix;    // �ϊ���̊  

	// ����  
	// ( 1 ) 10 �i���̓���  
	decimal = inputValue("10 �i���̒l����͂��Ă��������B", MIN_DECIMAL, MAX_DECIMAL);
	// ( 2 ) ��̓���  
	dstRadix = inputValue("�ϊ���̊����͂��Ă��������B", MIN_RADIX, MAX_RADIX);

	// ���o��  
	printf("���͂��ꂽ 10 �i���� %d �ł��B", /*( 3 )*/		decimal);
	printf("���͂��ꂽ��� %d �ł��B",     /*( 4 )*/		dstRadix);

	return  0;
}