#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 配列に数値を入力する。---------------------------------------------------
// 戻り値　int   : 入力された件数
// 引数　　nums  : 入力数値を収める配列
// 　　　　limit : 配列 nums の大きさ
int  inputArray(int* nums, int limit)
{
    int  count;

    int  num;
    int  i;

    printf("正の数列の総和を求めます。\n");
    for (i = 0; i < limit; i++) {
        printf("数値を入力してください。( 終了 = 0以下の値 ）");
        fflush(stdout);
        scanf("%d", &num);
        if (num <= 0) {
            break;
        }
        nums[i] = num;
    }
    count = i;

    return  count;
}

// 配列の総和を計算する。---------------------------------------------------
// 戻り値　int   : 配列 nums の数値の総和
// 引数　　nums  : 計算対象配列
// 　　　　count : 配列 nums の件数
int  sumArray(const int* nums, int count)
{
    int  sum;
    int  i;

    sum = 0;
    for (i = 0; i < count; i++) {
        sum += nums[i];
    }
    return  sum;
}

// メイン関数 ------------------------------------------------------------
int  main(void)
{
    // 定数定義
    enum { LIMIT = 100 };   // 配列の個数

    // 変数定義
    int  nums[LIMIT];     // 値を格納する配列
    int  count;             // 件数
    int  sum;               // 総和

    count = inputArray(nums, LIMIT);     // 配列に数値を入力する。
    sum = sumArray(nums, count);     // 配列の総和を計算する。
    printf("件数は %d 件です。\n", count);  // 配列の総和を表示する。
    printf("総和は %d です。\n", sum);

    return  0;
}