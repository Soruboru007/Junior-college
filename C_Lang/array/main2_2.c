#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	int  nums[] = {
		11, 15, 23, 35, 42, 28, 22, 16, 7,
		22, 16, 18, 22, 16, 15, 23, 23, 42,
	};
	int  target;                  // 検索値
	int  i;
	enum { NUMS_COUNT = sizeof(nums) / sizeof(nums[0]) };
	int  indices[NUMS_COUNT];   // 検索位置
	int  indexCount;              // 見つかった件数


	// 検索値の入力
	printf("次の数列から値を検索します。\n");
	for (i = 0; i < NUMS_COUNT; i++) {
		printf("%3d", nums[i]);
	}
	printf("\n");
	printf("検索する数値は? ");
	fflush(stdout);
	scanf("%d", &target);

	// 値の検索

	indexCount = 0;						// ( 1 ) 見つかった件数は 0
	for (i = 0; i < NUMS_COUNT; i++) {
		if (target == nums[i]) {		// ( 2 ) 配列の中身と入力値が一致したら
			indices[indexCount++] = i;  // ( 3 ) 検索位置を保存し、件数を1増やす
		}
	}

	// 検索結果の出力
	printf("%d は", target);
	if (0 < indexCount) {								  // ( 4 ) 見つかった
		printf("次の %d 箇所にあります。\n", indexCount); // ( 5 ) 件数
		for (i = 0; i < indexCount; i++) {				  // ( 6 ) 見つかった位置すべて
			printf("%3d 番目\n", indices[i] + 1);		  // ( 7 ) それぞれの位置
		}
	}
	else {
		printf("ありません。\n");
	}

	return 0;
}