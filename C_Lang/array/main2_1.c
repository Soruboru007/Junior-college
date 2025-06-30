#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	int  nums[] = { 11, 15, 23, 35, 42, 28, 22, 16, 7, };
	int  target;  // 検索値
	int  index;   // 見つかった位置
	int  i;
	enum { NUMS_COUNT = sizeof(nums) / sizeof(nums[0]) };

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
	index = -1;  // 見つからなかったときの値設定
	for (i = 0; i < NUMS_COUNT; i++) {
		if (target == nums[i]) {		 // ( 1 ) 配列の中身と入力値が一致したら
			index = i;            // ( 2 ) 見つかった部分の添え字を代入
			break;                    // ( 3 ) 見つかったのでループを抜ける
		}
	}

	// 検索結果の出力
	printf("%d は", target);
	if (0 <= index) {               // ( 4 ) 見つかった indexが更新されている（０～）
		printf(" %d 番目にあります。\n", index + 1); // ( 5 ) 位置
	}
	else {
		printf("ありません。\n");
	}

	return 0;
}