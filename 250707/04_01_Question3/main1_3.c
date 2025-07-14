#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, length;
	char moji[20];
	char* pmoji;

	//入力
	printf("10 文字程度の英数字の文字列を入力してください（スペースなし）\n");
	fflush(stdout);
	scanf("%s", moji);

	//計算
	/* ポインタに文字列のアドレスを代入 */
	pmoji = moji;

	/* ポインタの位置を文字列の末端に移動(※反復制御)※問題２を参考に */
	length = 0;
	while (*pmoji != '\0') {
		pmoji++;
		length++;  //ポインタの移動回数（文字数）
	}

	//出力
	/* 文字列表示（末端の 1 文字から順々に表示※反復制御） */
//length利用版
	for (i = 0; i < length; i++) {
		printf("%s\n", --pmoji);
	}

//アドレス比較版
	/* ポインタに文字列のアドレスを代入 */
	pmoji = moji;

	while (*pmoji != '\0') {
		pmoji++;
	}
	
	while (moji != pmoji) {
		printf("%s\n", --pmoji);
	}

	return 0;
}