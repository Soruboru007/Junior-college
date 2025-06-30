#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// 定数定義
	enum { NUMS_LIMIT = 5 };    // データの最大格納件数

	// 変数定義
	int  nums[NUMS_LIMIT];    // データ
	int  count;                 // 入力件数
	int  i;

	// 入力
	printf("数値の入力を受け付けます。\n");
	printf("件数を入力してください。( 1 - %d ) ", NUMS_LIMIT);
	fflush(stdout);
	scanf("%d", &count);

	while (!(1 <= count && count <= 5)) {
		printf("%d 件の数値は扱えません。", count);
		printf("件数を入力してください。( 1 - %d ) ", NUMS_LIMIT);
		fflush(stdout);
		scanf("%d", &count);
	}

	for (i = 0; i < count; i++) {     // ( 1 ) 入力された件数分繰り返す
		printf("%d件目の数値を入力してください。", i + 1);
		fflush(stdout);
		scanf("%d", &nums[i]);          // ( 2 ) 配列に順番に入力する
	}

	// 出力
	printf("\n");
	for (i = 0; i < count; i++) {     // ( 3 ) 件数分繰り返す
		printf("%5d", nums[i]);         // ( 4 ) 配列を順番に出力する
	}
	printf("\n");

	return 0;
}