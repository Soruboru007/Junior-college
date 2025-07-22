#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 定数宣言 --------------------------------------------------------------------------------
enum { LIMIT = 10 };			// 最大入力可能件数
const int	finalValue = -1;	// 入力終了値

//数値の入力 配列に数値入力していく（2章問題3（2）と同じ処理）
// 戻り値　int        : 実際に入力された値の件数
// 引数　　nums       : 入力値を格納する配列
//         limit      : 最大入力可能数＝numsの配列数
//         finalValue : 入力終了値
int inputData(int* nums, int limit, int endValue) {
	int count;
	int i;
	int num;
	printf("データを入力してください。\n");
	printf("%d 件に達するか %d を入力すると、入力処理を終了します。\n", limit, endValue);

	for (i = 0; i < limit; i++) {
		fflush(stdout);
		scanf("%d", &num);
		if (num == endValue) {
			break;
		}
		nums[i] = num;
	}
	count = i;  //件数を変数 count へ代入する
	return count;
}

//総和算出　配列のすべてのデータを足す
// 戻り値　int   : 引数 nums のデータの総和
// 引数　　nums  : 入力値を格納する配列
// 　　　　count : 入力件数
int getSum(const int* nums, int count) {
	int sum;
	int i;
	sum = 0;
	for (i = 0; i < count; i++) {
		sum += nums[i];
	}

	return sum;
}

//平均算出 件数0の時は平均を求めず、0とすること
// 戻り値　double : 引数 nums のデータの平均
// 引数　　nums   : 入力値を格納する配列
// 　　　　count  : 入力件数
double getAve(const int* nums, int count) {
	return count != 0 ? (double)getSum(nums, count) / count : 0;

	//条件演算子を利用しない場合
	double ave = 0;
	if (count != 0) {
		ave = (double)getSum(nums, count) / count;
	}
	return ave;
}

// MAIN関数-------------------------------------------------------
int main(void) {
	// 変数宣言
	int		nums[LIMIT];		// データ
	int		count;				// 件数
	int		sum;				// 総和
	double	average;			// 平均

	//入力
	printf("統計値を算出します。\n");
	count = inputData(nums, LIMIT, finalValue);

	//計算
	sum = getSum(nums, count);
	average = getAve(nums, count);

	// 出力
	printf("データ件数 %d\n", count);
	printf("データ総和 %d\n", sum);
	printf("データ平均 %.3f\n", average);

	return 0;
}