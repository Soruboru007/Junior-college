#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// 定数定義
	enum { NUMS_LIMIT = 10 };    // データの最大格納件数
	const int  endValue = -1;   // 終了値

	// 変数定義
	int  nums[NUMS_LIMIT];    // データ
	int  num;                   // 入力値
	int  count;                 // 入力件数
	int  i;
	int  max;					// 最大値
	int  maxIndexCount;			// 最大値の個数
	int  maxIndices[NUMS_LIMIT];//最大値のある添え字（要素番号）を保存する配列

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

	// 計算
	if (count > 0) {
		max = nums[0];		//仮で最大値を決定する
		maxIndexCount = 1;	//最大値1つ目なので初期値を1とする
		maxIndices[0] = 0;	//nums[0]の0を記憶する

		for (i = 1; i < count; i++) { //numsに入力された件数文繰り返す
			if (max < nums[i]) {	//最大値の更新がある時
				max = nums[i];
				maxIndices[0] = i;
				maxIndexCount = 1;
			}
			else if (max == nums[i]) {
				maxIndices[maxIndexCount++] = i;
			}
			//ネストして求める方法  この場合maxIndexCountの初期値は0になる。
			/*if (max <= nums[i]) {
				if (max == nums[i]) {
					max = nums[i];
					maxIndexCount = 0;
				}
				maxIndices[maxIndexCount++] = i;
			}*/
		}
	}

	// 出力
	if (0 < count) {
		for (i = 0; i < count; i++) {
			printf("%5d", nums[i]);         // ( 4 ) 配列を順番に出力する
		}
		printf("\n");

		printf("最大値は%dです。\n", max);
		if (1 < maxIndexCount) {
			printf("次の %d 箇所にあります。\n", maxIndexCount);
			for (i = 0; i < maxIndexCount; i++) {
				printf("%2d件目\n", maxIndices[i] + 1);
			}
		}
		else {
			printf(" % 2d件目\n", maxIndices[0] + 1);
		}
	}

	return 0;
}