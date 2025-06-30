#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 定数宣言
	// 年号
	typedef enum {
		MEIJI, TAISHOU, SHOUWA, HEISEI, REIWA, SEIREKI,
		NUM_NENGO, UNKNOWN_ERA,
	}  era_t;

	const char  eraStrings[NUM_NENGO][2 * 2 + 1] = {    // 年号の文字列
		"明治", "大正", "昭和", "平成", "令和", "西暦",
	};
	const char  eraHeadChars[NUM_NENGO + 1] = "mtshrw";  // 年号の頭文字

	// 変数宣言
	int i;
	char   eraInput;
	era_t  eraType;   // 識別した年号
	char   eraChar;   // 小文字変換後の年号の頭文字

	// 入力
	printf("年号を入力してください。\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// m～rまでは同じ形なので繰り返しで表示
		printf("%c = %s, ", eraHeadChars[i], eraStrings[i]);
	}
	printf("%c = %s ==>", eraHeadChars[i], eraStrings[i]);	// 形の違う5だけ別で書く
	fflush(stdout);
	scanf("%c", &eraInput);

	//小文字変換
	eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

	// 入力された文字で年号を確定させる
	eraType = UNKNOWN_ERA;
	if (eraChar == eraHeadChars[0]) {
		eraType = (era_t)0;
	}
	if (eraChar == eraHeadChars[1]) {
		eraType = (era_t)1;
	}
	if (eraChar == eraHeadChars[2]) {
		eraType = (era_t)2;
	}
	if (eraChar == eraHeadChars[3]) {
		eraType = (era_t)3;
	}
	if (eraChar == eraHeadChars[4]) {
		eraType = (era_t)4;
	}
	if (eraChar == eraHeadChars[5]) {
		eraType = (era_t)5;
	}

	// 出力
	printf("入力された");
	if (eraType != UNKNOWN_ERA) {
		printf("年号は%sです。\n", eraStrings[eraType]);
	}
	else {
		printf("文字'%c'は識別不能です。\n",eraInput);
	}

	return 0;
}