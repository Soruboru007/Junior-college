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
	printf("%s( %d - %d ) ", /*( 4 )*/ prompt, min, max);
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

// 10 �i���� n �i���ŉ����ɂȂ邩�B-----------------------------------  
// �߂�l�@int     : radix �i���̌����A�l�����̏ꍇ 0  
// �����@�@decimal : 10�i��  
// �@�@�@�@radix   : �ϊ���̊  
int  getDigits(int decimal, int radix)
{
	int  digit;
	// ( 1 ) decimal �� 0 ���傫���Ԑ���������B  
	for (digit = 0; 0 < decimal; digit++) {
		// ( 2 ) �ϊ�����10�i��������B         
		decimal /= radix;
	}

	return  digit;
}

// 10 �i���� n �i���ɕϊ�����B-------------------------------------- -
// �߂�l�@�Ȃ�  
// �����@�@buffer  : �ϊ���̒l�i������j  
// �@�@�@�@decimal : 10�i��  
// �@�@�@�@radix   : �ϊ���̊  
void decToAnyRadix(char* buffer, int decimal, int radix)
{
	int     digit;
	int     index;
	int     i;
	// ( 1 ) getDigits( )���g���Č��������߂�B  
	digit = getDigits(decimal, radix);
	if (0 < digit) {
		index = digit;
		// ( 2 ) ������̍Ō�� '\0' ������B  
		buffer[index--] = '\0';
		for (i = 0; i < digit; i++) {
			// ( 3 ) 1 ���������߂�B10 �i������Ŋ������]������߁A  
			// ( 1 ) �Œ�߂��萔������ digits ����E���o���B  
			buffer[index--] = digits[decimal % radix];
			// ( 4 ) 10 �i������Ŋ���B              

			decimal /= radix;
		}
	}
	else {
		// ( 5 ) ( 6 ) "0" ���i�[����B  
		buffer[0] = '0';
		buffer[1] = '\0';
	}
}

// ���l�̊Ԃɋ�؂��}������B---------------------------------------- 
// �߂�l�@�Ȃ� 
// �����@�@buffer    : ��؂��}�����镶���� 
// �@�@�@�@delimiter : ��؂�ɑ}�����镶�� 
// �@�@�@�@interval  : ��؂������Ԋu 
// ���@string.h ���C���N���[�h����K�v���� 
void  insertDelimiter(char* buffer, char delimiter, int interval)
{
	char* src; 	    // �ړ��� 
	char* dst; 	    // �ړ��� 
	int     length;    // ������̒��� 
	int     count;     // ��؂蕶����}������� 
	int     i, j;

	length = strlen(buffer);
	if (interval < length) {
		count = (length - 1) / interval;         // ��؂�̌� 
		src = buffer + length;                     // �ړ����̈ʒu 
		dst = src + count;                         // �ړ���̈ʒu 
		*dst-- = *src--;                         // '\0' �ړ� 
		for (j = 0; j < count; j++) {
			for (i = 0; i < interval; i++) {    // ��؂�̊Ԋu����납��ړ� 
				*dst-- = *src--;
			}
			*dst-- = delimiter;                   // ��؂������ 
		}
	}
}

// ����؂��}������B----------------------------------------------- 
// �߂�l�@�Ȃ� 
// �����@�@buffer : ��؂��}�����镶���� 
// �@�@�@�@radix  : �ϊ���̊ 
void  arrangeColumn(char* buffer, int radix)
{
	// 10�i���A16�i���A����ȊO�ɂ킯�āA���ꂼ�� insertDelimiter( ) �֐����Ăяo���B
	switch(radix){
		case 10:
			insertDelimiter(buffer, ',', 3);
			break;
		case 16 :
			insertDelimiter(buffer, ' ', 2);
			break;
		default:
			insertDelimiter(buffer, ' ', 4);
			break;
	}
}

// ���C���֐� --------------------------------------------------------- 
int main(void)
{
	// �ϐ��錾  
	int  decimal;     // 10 �i��  
	int  dstRadix;    // �ϊ���̊  

	char dst[MAX_BITS + 1];//�ԊҌ�̐��l

	// ����  
	// ( 1 ) 10 �i���̓���  
	decimal = inputValue("10 �i���̒l����͂��Ă��������B", MIN_DECIMAL, MAX_DECIMAL);
	// ( 2 ) ��̓���  
	dstRadix = inputValue("�ϊ���̊����͂��Ă��������B", MIN_RADIX, MAX_RADIX);

	//�v�Z
	decToAnyRadix(dst, decimal, dstRadix);
	arrangeColumn(dst, dstRadix);

	//�o��
	printf("10 �i�� %d �� %d�i���� %s �ł��B\n", decimal, dstRadix, dst);

	return  0;
}