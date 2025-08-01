// *****************************************************
// 半径から円の面積を求めるプログラム
// *****************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 円の面積を求める。-------------------------------
// 戻り値　double    : 半径radiusの円の面積
// 引数　　radius 　 : 円の半径
double  circleArea(double radius) {
	const double PI = 3.1415926535;
	double area;		//面積

	area = PI * radius * radius;
	area = PI * pow(radius, 2);	//math.h使う場合はこれでもOK
	
	return area;
}

//メイン--------------------------------------------
int main(void) {
	// 変数宣言
	double radius;	//円の半径
	double area;	//円の面積
	
	//入力
	printf("円の面積を求めます。\n");
	printf("半径を入力してください");
	fflush(stdout);
	scanf("%lf", &radius);

	// 計算
	area = circleArea(radius);

	// 出力
	printf("半径 %.2lfの円の面積は %.2lf です。\n", radius, area);

	return 0;
}