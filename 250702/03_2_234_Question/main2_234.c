#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ｎの階乗を求める
// 戻り値　int   :引数ｎの階乗した値
// 引数　　int n :階乗したい値
int  factorial(int n) {
	int value;
	int i;
	value = 1;
	for (i = 2; i <= n; i++) { //2からｎまでvalueにかけていく
		value *= i;
	}
	return value;
}

// n 個から r 個を並べる順列の場合の数を求める。
// 戻り値　int   :順列の場合の数
// 引数　　int n :総数ｎ
// 　　　　int r :並べる数ｒ
int  permutation(int n, int r) {
	int value;
	value = factorial(n) / factorial(n - r);  //nPr=n!/(n-r)!
	return value;
}

// n 個から r 個を取り出す組み合わせの場合の数を求める。
// 戻り値　int   :組み合わせの場合の数
// 引数　　int n :総数ｎ
// 　　　　int r :取り出す数ｒ
int  combination(int n, int r) {
	int value;
	value = permutation(n, r) / factorial(r);	//nCr = nPr/r!
	return value;
}

int main(void) {
	//変数宣言
	int n, r; //入力値
	int fac, nPr, nCr;	//階乗、順列、組合せの答

	//入力
	printf("階乗(n!)、順列(nPr)、組合せの場合の数(nCr)を求めます。\n");
	printf("nとrの値を入力してください。\n");
	fflush(stdout);
	scanf("%d %d", &n, &r);

	// 計算（ここで関数を利用する）
	fac = factorial(n);
	nPr = permutation(n, r);
	nCr = combination(n, r);
	// 出力
	printf("階乗  ( %d!) の答え：%d\n", n, fac);
	printf("順列  (%dP%d) の答え：%d\n", n,r, nPr);
	printf("組合せ(%dC%d) の答え：%d\n", n, r, nCr);

	return 0;
}