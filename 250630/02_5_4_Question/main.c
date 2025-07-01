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

	const int  firstYears[NUM_NENGO] = {    // 各年号の元年の西暦年
	1868, 1912, 1926, 1989, 2019, 1,
	};

	// 変数宣言
	int i;
	char   eraInput;
	era_t  eraType;			// 識別した年号
	char   eraChar;			// 小文字変換後の年号の頭文字
	int    year;			// 入力年
	int	   westYear;		// 西暦に修正した年

	// 入力
	printf("和暦を西暦に変換します。\n");
	printf("年号は、次の文字を入力してください。\n");
	for (i = 0; i < NUM_NENGO - 1; i++) {		// m～rまでは同じ形なので繰り返しで表示
		printf("%c = %s, ", eraHeadChars[i], eraStrings[i]);
	}
	printf("%c = %s\n", eraHeadChars[i], eraStrings[i]);	// 形の違う5だけ別で書く
	printf("年号と和暦の年を入力してください。(例:平成22年 h22) ");
	fflush(stdout);
	scanf("%c%d", &eraInput, &year);

	//小文字変換
	eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

	// 入力された文字で年号を確定させる ※配列の添え字（要素番号）の決定
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

	while (eraType == UNKNOWN_ERA) {
		printf("入力された '%c' は年号として認識できません。",eraInput);
		printf("もう一度、年号と和暦の年を入力してください。(例:平成22年 h22) ");
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c%d", &eraInput, &year);

		//小文字変換
		eraChar = eraInput + ('A' <= eraInput && eraInput <= 'Z' ? 'a' - 'A' : 0);

		// 入力された文字で年号を確定させる ※配列の添え字（要素番号）の決定
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
	}

	// 計算  和暦→西暦変換
		westYear = year + firstYears[eraType] - 1;

	// 出力
		printf("%s %d年は、西暦 %d年です。\n", eraStrings[eraType], year, westYear);
	

	return 0;
}