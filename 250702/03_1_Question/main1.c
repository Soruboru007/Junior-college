#include <math.h>            // fabs( )関数を使用するために必要
#include <stdio.h>
#include <stdlib.h>

int  main(void)
{
    // 変数宣言
    double figSqrt; // 平方根の結果
    double figFabs; // 実数絶対値の結果
    double figPow;  // べき乗の結果
    int numAbs;     // 整数絶対値の結果

    // 計算
    figSqrt = sqrt(10);
    figFabs = fabs(-3.5);
    figPow = pow(2, 10);
    numAbs = abs(-3);

    // 出力
    printf("( 1 ) 10 の平方根    : %lf\n",figSqrt);
    printf("( 2 )  -3.5 の絶対値 : %lf\n",figFabs);
    printf("( 3 ) 2 の 10 乗     : %lf\n",figPow);
    printf("( 4 ) -3 の絶対値    : %d\n",numAbs);

    return  0;
}