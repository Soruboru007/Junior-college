#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 半径から円の面積を求める。
// 戻り値　double : 引数で指定された半径の円の面積
// 引数　　radius : 円の半径
double circleArea(double radius) {
	const double	PI = 3.1415926535897932384626;
	double area;
	area = PI * radius * radius;
	return area;
}


// 半径から円周の長さを求める。
// 戻り値　double : 引数で指定された半径の円周の長さ
// 引数　　radius : 円の半径
double circumference(double radius) {
	const double	PI = 3.1415926535897932384626;
	double length;
	length = 2 * PI * radius;
	return length;
}

// 半径から円周の長さと円の面積を求める。
// 戻り値　なし
// 引数　　radius : 円の半径
// 　　　  length : 円周の長さ
// 　　　  area   : 円の面積
void circleProperty(double radius, double* length, double* area) {
	*length = circumference(radius);
	*area = circleArea(radius);
}

int main(void) {
	double radius;			//円の半径
	double length, area;	//円周の長さ、面積

	printf("円の面積を求めます。\n");
	printf("半径を入力してください。");
	fflush(stdout);
	scanf("%lf", &radius);

	circleProperty(radius, &length, &area);

	printf("半径 %.3lf の円周の長さは %lf 円の面積は %lf です。", radius, length, area);

	return 0;
}