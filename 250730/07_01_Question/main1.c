#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	//型定義
	typedef enum { BILL, COIN, TYPE_COUNT, }  denom_t;    // 通貨の種類

	//定数定義
	const int	denoms[] = {								// 通貨単位
		10000, 5000, 2000, 1000, 500,  100,  50, 10,  5,  1,
	};
	enum {DENOM_COUNT=sizeof(denoms)/sizeof(denoms[0]) };	//通貨の種類数

	denom_t denomTypes[DENOM_COUNT] = {
	 BILL, BILL, BILL, BILL, COIN, COIN, COIN, COIN, COIN, COIN, };//種類（札、玉）     配列 【列挙型定数】
	
	const char* denomStr[TYPE_COUNT] = { "札","玉" };//"札"、"玉" の文字列    【文字型ポインタ定数】

	//変数定義
	int counts[DENOM_COUNT];//枚数 配列
	int price;
	int remain;
	int i;

	//入力
	printf("金種計算をします。\n");
	printf("金額を入力してください。 ");
	fflush(stdout);
	scanf("%d", &price);

	//計算
	remain = price;
	for (i = 0; i < DENOM_COUNT; i++) {
		counts[i] = remain / denoms[i];
		remain = remain % denoms[i];
	}

	//出力
	printf("金額 %8d円\n", price);
	for (i = 0; i < DENOM_COUNT; i++) {
		if (0 < counts[i]) {
			printf("%-5d円%s %2d枚\n", denoms[i], denomStr[denomTypes[i]], counts[i]);
		}
	}
	return 0;
}