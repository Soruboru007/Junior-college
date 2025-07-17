#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 定数宣言 --------------------------------------------------------------------------------
enum { LIMIT = 10 };			// 最大入力可能件数
const int	finalValue = -1;	// 入力終了値

//数値の入力

//総和算出

//平均算出 件数0の時は平均を求めず0とする


int main(void) {
	// 変数宣言
	int		nums[LIMIT];		// データ
	int		count;				// 件数
	int		sum;				// 総和
	double	average;			// 平均

	//入力

	//計算

	// 出力
	printf("データ件数 %d\n", count);
	printf("データ総和 %d\n", sum);
	printf("データ平均 %.3f\n", average);

	return 0;
}