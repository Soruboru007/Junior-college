#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char moji[] = "AAAAAAAAAA";
	int num;		//Bに変える位置
	char* pmoji;	//文字ポインタ

	//入力
	printf("変更前の文字列は %s です。\n", moji);
	printf("文字'B'に変える位置を入力してください（0 ～ 9）＝＞");
	fflush(stdout);
	scanf("%d", &num);

	//計算
	/* ポインタに文字列のアドレスを代入 */
	pmoji = moji;

	/* 指定位置の文字 'A' を 'B' にポインタを利用して変える（上書きする） */
	// 今までなら　moji[num] = 'B';　としていた
	*(pmoji + num) = 'B';
	
	//出力
	 /* 文字列表示*/
	printf("%s\n", moji);
	return 0;
}