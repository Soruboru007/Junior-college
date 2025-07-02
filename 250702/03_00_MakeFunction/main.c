// *****************************************************
// 大きい方の整数値を求めるプログラム
// *****************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 大きい方の値を求める。-------------------------------
// 戻り値　int    : 引数の値のうち大きい方の値
// 引数　　value1 : 比較される値
// 　　　　value2 : 比較する値
int  big(int value1, int value2)
{
	int bigValue;	//戻り値と同じデータ型の変数を用意する

    if (value1 < value2) {
        bigValue = value2;
    }
    else {
        bigValue = value1;
    }

	return bigValue;// returnの後ろに書かれた式が関数が呼び出されたときに戻る
}


// メイン関数 ------------------------------------------
int  main(void)
{
    // 変数定義
    int num1, num2;      // 比較する値
    int bigNum;          // 大きい方の値

    // 入力
    printf("2つの値を比較します。\n");
    printf("整数値を2つ入力してください。");
    fflush(stdout);
    scanf("%d %d", &num1, &num2);

    // 計算
    bigNum = big(num1, num2);

    // 出力
    printf("%d と %d のうち、大きい方の値は %d です。\n", num1, num2, bigNum);

    return 0;
}