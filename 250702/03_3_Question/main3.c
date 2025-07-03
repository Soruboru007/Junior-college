#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		//fabsを利用するために入れる

//（1）矩形の幅と高さから面積を求める。
// 戻り値　double : 矩形の面積
// 引数　　width : 矩形の幅
// 引数　　height : 矩形の高さ
double  rectAreaByLength(double width, double height) {
	double area;
	area = fabs(width * height);
	return area;
}

// （2）矩形の幅と高さから外周の長さを求める。
// 戻り値　double : 矩形の外周の長さ
// 引数　　width : 矩形の幅
// 引数　　height : 矩形の高さ
double  rectBoundsByLength(double width, double height) {
	double len;
	len = (fabs(width) + fabs(height)) * 2;
	return len;
}

//（3）矩形の対角座標2点から面積を求める。
// 戻り値　double : 矩形の面積
// 引数　　left : 矩形の左座標
// 引数　　top : 矩形の上座標
// 引数　　right : 矩形の右座標
// 引数　　bottom : 矩形の下座標
double  rectAreaByEdge(double left, double top, double right, double bottom) {
	double area;
	double width, height;
	width = right - left;
	height = bottom - top;

	area = rectAreaByLength(width, height);
	return area;
}

//（4）矩形の対角座標2点から外周の長さを求める。
// 戻り値　double : 矩形の外周の長さ
// 引数　　left : 矩形の左座標
// 引数　　top : 矩形の上座標
// 引数　　right : 矩形の右座標
// 引数　　bottom : 矩形の下座標
double  rectBoundsByEdge(double left, double top, double right, double bottom) {
	double length;
	double width, height;
	width = right - left;
	height = bottom - top;
	length = rectBoundsByLength(width, height);
	return length;
}

int main(void) {
	// 変数定義
	double w, h;			//入力値（幅、高さ）
	double area, length;	//面積、外周の長さ
	double area2, length2;	//面積、外周の長さ
	double r, l, t, b;		//入力値（右、左、上、下）

	// 入力
	printf("幅と高さを入力してください ");
	fflush(stdout);
	scanf("%lf %lf", &w, &h);

	printf("左、上座標を入力してください　");
	fflush(stdout);
	scanf("%lf %lf", &l, &t);
	printf("右、下座標を入力してください　");
	fflush(stdout);
	scanf("%lf %lf", &r, &b);

	// 計算
	area = rectAreaByLength(w, h);
	length = rectBoundsByLength(w, h);

	area2 = rectAreaByEdge(l, t, r, b);
	length2 = rectBoundsByEdge(l, t, r, b);

	// 出力
	printf("幅 %.2lf 高さ %.2lfの矩形の面積は %.2lf 、外周の長さは %.2lf　\n", w, h, area, length);
	printf("対角座標( %.2lf , %.2lf),( %.2lf , %.2lf)のの面積は %.2lf 、外周の長さは %.2lf　\n", l, t, r, b, area2, length2);

	return 0;
}