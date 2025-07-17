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
	printf("%s( %d - %d ) ", /*( 4 )*/ prompt, min, max);
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

// 10 進数は n 進数で何桁になるか。-----------------------------------  
// 戻り値　int     : radix 進数の桁数、値が負の場合 0  
// 引数　　decimal : 10進数  
// 　　　　radix   : 変換後の基数  
int  getDigits(int decimal, int radix)
{
	int  digit;
	// ( 1 ) decimal が 0 より大きい間数え続ける。  
	for (digit = 0; 0 < decimal; digit++) {
		// ( 2 ) 変換後基数で10進数を割る。         
		decimal /= radix;
	}

	return  digit;
}

// 10 進数を n 進数に変換する。-------------------------------------- -
// 戻り値　なし  
// 引数　　buffer  : 変換後の値（文字列）  
// 　　　　decimal : 10進数  
// 　　　　radix   : 変換後の基数  
void decToAnyRadix(char* buffer, int decimal, int radix)
{
	int     digit;
	int     index;
	int     i;
	// ( 1 ) getDigits( )を使って桁数を求める。  
	digit = getDigits(decimal, radix);
	if (0 < digit) {
		index = digit;
		// ( 2 ) 文字列の最後に '\0' を入れる。  
		buffer[index--] = '\0';
		for (i = 0; i < digit; i++) {
			// ( 3 ) 1 桁分を決める。10 進数を基数で割った余りを求め、  
			// ( 1 ) で定めた定数文字列 digits から拾い出す。  
			buffer[index--] = digits[decimal % radix];
			// ( 4 ) 10 進数を基数で割る。              

			decimal /= radix;
		}
	}
	else {
		// ( 5 ) ( 6 ) "0" を格納する。  
		buffer[0] = '0';
		buffer[1] = '\0';
	}
}

// 数値の間に区切りを挿入する。---------------------------------------- 
// 戻り値　なし 
// 引数　　buffer    : 区切りを挿入する文字列 
// 　　　　delimiter : 区切りに挿入する文字 
// 　　　　interval  : 区切りを入れる間隔 
// ※　string.h をインクルードする必要あり 
void  insertDelimiter(char* buffer, char delimiter, int interval)
{
	char* src; 	    // 移動元 
	char* dst; 	    // 移動先 
	int     length;    // 文字列の長さ 
	int     count;     // 区切り文字を挿入する個数 
	int     i, j;

	length = strlen(buffer);
	if (interval < length) {
		count = (length - 1) / interval;         // 区切りの個数 
		src = buffer + length;                     // 移動元の位置 
		dst = src + count;                         // 移動先の位置 
		*dst-- = *src--;                         // '\0' 移動 
		for (j = 0; j < count; j++) {
			for (i = 0; i < interval; i++) {    // 区切りの間隔分後ろから移動 
				*dst-- = *src--;
			}
			*dst-- = delimiter;                   // 区切りを入れる 
		}
	}
}

// 桁区切りを挿入する。----------------------------------------------- 
// 戻り値　なし 
// 引数　　buffer : 区切りを挿入する文字列 
// 　　　　radix  : 変換後の基数 
void  arrangeColumn(char* buffer, int radix)
{
	// 10進数、16進数、それ以外にわけて、それぞれ insertDelimiter( ) 関数を呼び出す。
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

// メイン関数 --------------------------------------------------------- 
int main(void)
{
	// 変数宣言  
	int  decimal;     // 10 進数  
	int  dstRadix;    // 変換後の基数  

	char dst[MAX_BITS + 1];//返還後の数値

	// 入力  
	// ( 1 ) 10 進数の入力  
	decimal = inputValue("10 進数の値を入力してください。", MIN_DECIMAL, MAX_DECIMAL);
	// ( 2 ) 基数の入力  
	dstRadix = inputValue("変換後の基数を入力してください。", MIN_RADIX, MAX_RADIX);

	//計算
	decToAnyRadix(dst, decimal, dstRadix);
	arrangeColumn(dst, dstRadix);

	//出力
	printf("10 進数 %d は %d進数で %s です。\n", decimal, dstRadix, dst);

	return  0;
}