#include <stdio.h>
int main(void) {
	// 変数宣言	
	enum { NUMS_SIZE = 10 };    // 配列の大きさ
	//const int size = 10;
	int  nums[NUMS_SIZE];     // 表示する数値
	int i;
	int odd=1; //奇数の初期値
	int count = 0;			//改行用カウンタ

	// 値の設定
	for (i = 0; i < NUMS_SIZE; i++) {
		nums[i] = odd;
		odd += 2;
	}

	// 出力
	for (i = 0; i < NUMS_SIZE; i++) {
		printf("%3d ", nums[i]);

		if (4 <= ++count) {
			printf("\n");
			count = 0;
		}
	}

	return 0;
}