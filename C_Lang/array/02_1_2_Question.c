#include <stdio.h>
int main(void) {
	// 定数宣言
	enum { ROW_SIZE = 10 };	//行数
	enum { COL_SIZE = 3 };//列数

	// 変数宣言	
	int nums[ROW_SIZE][COL_SIZE]; // 10×3の配列の宣言
	int i, j;					  // くり返し用
	int numR, numC;				  // 計算用 行計算、列計算でそれぞれ利用

	// 値の設定
	numR = 1;
	for (i = 0; i < ROW_SIZE; i++) {
		numC = 1;
		for (j = 0; j < COL_SIZE; j++) {
			nums[i][j] = numR * numC;
			numC *= 10;		//1回目のループ：1、2回目のループ10、3回目のループ100
		}
		numR++;
	}


	// 出力
	for (i = 0; i < ROW_SIZE; i++) {
		for (j = 0; j < COL_SIZE; j++) {
			printf("%4d ", nums[i][j]);
		}
		printf("\n");
	}
		return 0;
}
