#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// 定数定義
	enum { NUMS_LIMIT = 5 };    // データの最大格納件数
	const int  endValue = -1;   // 終了値

	// 変数定義
	int  nums[NUMS_LIMIT];    // データ
	int  num;                   // 入力値
	int  count;                 // 入力件数
	int  i;

	// 入力
	printf("数値の入力を受け付けます。\n");
	for (i = 0; i < NUMS_LIMIT; i++) { // ( 1 ) 配列の要素数を超えない間
		printf("%d件目の数値を入力してください。(終了 = %d) ", i + 1, endValue);
		fflush(stdout);
		scanf("%d", &num);
		if (num == endValue) {
			break;
		}
		nums[i] = num;      // ( 2 ) 配列 nums に入力値を格納する
	}
	count = i;          // ( 3 ) 件数を変数 count へ代入する

	   // 出力
	printf("\n");
	for (i = 0; i < count; i++) {
		printf("%5d",nums[i] );         // ( 4 ) 配列を順番に出力する
	}
	printf("\n");

	return 0;
}