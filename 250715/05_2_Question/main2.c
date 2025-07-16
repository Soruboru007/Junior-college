#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 定数定義 ------------------------------------------------  
// 数字  
const char digits[] = "0123456789abcdef";

// 変換後の基数の最小値、最大値  
// -1 は '\0' 分を除いたもの  
enum { MIN_RADIX = 2 };
enum { MAX_RADIX = sizeof(digits) / sizeof(digits[0]) - 1 };
// 10 進数の最小値、最大値、最大変換後の桁数  
enum { MIN_DECIMAL = 0, MAX_DECIMAL = 65535, MAX_BITS = 16, };

// 値の入力	---------------------------------------------------------------  
// 戻り値　int    : 入力された値  
// 引数　　prompt : 入力促進文字列  
// 　　 　 min    : 入力可能最小値  
// 　　 　 max    : 入力可能最大値  
//             ( 1 )	prompt の型　( 2 ) min の型　( 3 ) max の型  
int  inputValue(const char* prompt, int    min, int    max)
{
	int  value;
	printf("%s( %d - %d ) ", /*( 4 )*/ prompt,  min, max);
	fflush(stdout);
	scanf("%d", &value);
	// ( 5 ) 入力値が範囲外である間  
	while (!(min <= value && value <= max)) {
		printf("入力値 %d は範囲外です。\n", value);
		printf("もう一度、");
		printf("%s( %d - %d ) ", /*( 6 )*/ prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}

// メイン関数 --------------------------------------------------------- 

int main(void)
{
	// 変数宣言  
	int  decimal;     // 10 進数  
	int  dstRadix;    // 変換後の基数  

	// 入力  
	// ( 1 ) 10 進数の入力  
	decimal = inputValue("10 進数の値を入力してください。", MIN_DECIMAL, MAX_DECIMAL);
	// ( 2 ) 基数の入力  
	dstRadix = inputValue("変換後の基数を入力してください。", MIN_RADIX, MAX_RADIX);

	// 仮出力  
	printf("入力された 10 進数は %d です。", /*( 3 )*/		decimal);
	printf("入力された基数は %d です。",     /*( 4 )*/		dstRadix);

	return  0;
}