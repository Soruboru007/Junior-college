#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 定数宣言
	enum { NUM_NENGO = 6 };
	const char  eraStrings[NUM_NENGO][2 * 2 + 1] = {    // 年号の文字列
		"明治", "大正", "昭和", "平成", "令和", "西暦",
	};

	// 変数宣言
	int i;
	int era;

	// 入力
	printf("年号を入力してください。\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// 0～4までは同じ形なので繰り返しで表示
		printf("%d = %s, ", i, eraStrings[i]);
	}
	printf("%d = %s ==>", i, eraStrings[i]);	// 形の違う5だけ別で書く
	fflush(stdout);
	scanf("%d", &era);

	// 出力
	printf("入力された年号は%sです。\n", eraStrings[era]);


	return 0;
}