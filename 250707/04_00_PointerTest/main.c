#include <stdio.h>
int main(void) {
	int    num;    // int型 の変数
	int*   pNum;   // int型 の変数が存在するアドレス(ポインタ)の変数
	int    num2 ;   // int型 の変数をもう 1 つ

	num = 5;
	pNum = &num;   // ポインタ pNum に「変数 num のアドレス」を代入する。
	num2 = *pNum;  // 「100番地の中身」を変数 num2 に代入する。


	printf("変数     num  の値 %8d アドレス %p\n", num, &num);
	printf("ポインタ pNum の値 %p アドレス %p\n", pNum, &pNum);
	printf("変数     num2 の値 %8d アドレス %d\n", num2, &num2);

	char    string[] = "abcde";
	// char型 の配列変数 先頭アドレスを 100 とする
	char* pStr;     // char * 型 の変数 ( ポインタ )

	pStr = string;    // 配列変数 string の先頭アドレスをポインタ pStr に代入

	printf("string        = %d\n", string);       // &string[ 0 ] と同じ
	printf("pStr          = %d\n", pStr);         // string と同じ
	printf("string + 1    = %d\n", string + 1);   // 100 + 1 = 101
	printf("pStr + 1      = %d\n", pStr + 1);     // string + 1 つまり 101
	printf("*(pStr + 1)   = %c\n", *(pStr + 1));    // 101番地の中身
	printf("*(string + 1) = %c\n", *(string + 1));  // 101番地の中身
	printf("string[ 1 ]   = %c\n", string[1]);  // *(string + 1) と同じ

	int    nums[] = { 1, 2, 3, 4, 5, };
	// int 型 の配列変数 先頭アドレスを 100 とする
	

	pNum = nums;    // 配列変数 nums の先頭アドレスをポインタ pNum に代入

	printf("nums        = %d\n", nums);       // &nums[ 0 ] と同じ
	printf("pNum        = %d\n", pNum);       // nums と同じ
	printf("nums + 1    = %d\n", nums + 1);   // 100 + 1 × 4 = 104
	printf("pNum + 1    = %d\n", pNum + 1);   // nums + 1 つまり 104
	printf("*(pNum + 1) = %d\n", *(pNum + 1));  // 104番地の中身
	printf("*(nums + 1) = %d\n", *(nums + 1));  // 104番地の中身
	printf("nums[ 1 ]   = %d\n", nums[1]);  // *(nums + 1) と同じ
	return 0;


}