#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char moji[20];
	char* pmoji;
	
	//入力
	printf("10 文字程度の英数字の文字列を入力してください（スペースなし）\n");
	fflush(stdout);
	scanf("%s", moji);
	
	//値の代入
	/* ポインタに文字列のアドレスを代入 */
	pmoji = moji;

	//出力
	/* 文字列表示（先頭の 1 文字が順々に削除※文字列の末端には¥0 があることに注目） */
	while (*pmoji != '\0') {
		printf("%s\n", pmoji++);
	}
	return 0;
}