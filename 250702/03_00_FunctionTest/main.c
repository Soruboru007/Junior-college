#define _CRT_SECURE_NO_WARNINGS
#include <math.h>            // fabs( )関数を使用するために必要
#include <stdio.h>           // scanf( ),printf( )関数を使用するために必要

int  main(void)
{
    double   fig;           // 絶対値を求める元の数値
    double   absFig;        // fabs( )関数の戻り値を受け取る変数
    double   absFig1, absFig2, absFig3;


    scanf("%lf", &fig);   // scanf( )関数は入力された変数の個数を返すが、
                             // 今回は受け取らない。
    absFig = fabs(fig);   // 絶対値を受け取るので変数に代入する。
    printf("|%f| = %f\n", fig, absFig);
    // printf( )関数は出力した文字数を返すが、
    // 必要ないので受け取らない。


    absFig1 = fabs(fig);       // 変数を引数に渡す。
    absFig2 = fabs(-32);       // リテラル値を引数に渡す。
    absFig3 = fabs(fig - 32);  // 計算式を引数に渡す。
    printf("|%f| = %f\n", fig, absFig1);
    printf("|%f| = %f\n", -32.0, absFig2);
    printf("|%f| = %f\n", fig - 32, absFig3);


    return  0;
}