#include <stdio.h>

void  swap(int* num1, int* num2)
// 呼び出されたときの
// ( 1 ) num1 の値 5 (2) num2 の値 3
// ( 3 ) *num1 は 100番地の中身[答えは数値]
// ( 4 ) *num1 は main( )関数の変数 value1の値[答えは変数名]
// ( 5 ) *num2 は 200番地の中身[答えは数値]
// ( 6 ) *num2 は main( )関数の変数 value2の値[答えは変数名]
{
	int  num;

	// 以下は代入後のそれぞれの変数の値
	num = *num1;  // ( 7 ) num    の値5
	*num1 = *num2;  // ( 8 ) value1 の値 3
	*num2 = num;    // ( 9 ) value2 の値5

}

//値渡し版
void  swap_err(int num1, int num2)
// 呼び出されたときの
// ( 1 ) num1 の値 5(2) num2 の値3
{
	int  num;

	// 以下は代入後のそれぞれの変数の値
	num = num1;    // ( 3 ) num  の値 	5
	num1 = num2;    // ( 4 ) num1 の値 	3
	num2 = num;     // ( 5 ) num2 の値 	5

}

int  main(void)
{
	int  value1, value2;

	value1 = 5;
	value2 = 3;

	printf("value1:%d\n", value1);
	printf("value2:%d\n", value2);

	//値渡し
	swap_err(value1, value2);  // 2つの値を交換したい
	// swap( ) 関数実行後の
	// ( 10 ) value1 の値 	3		(11) value2 の値		5
	printf("err_value1:%d\n", value1);
	printf("err_value2:%d\n", value2);


	//ポインタ渡し
	swap(&value1, &value2);  // 2つの値を交換したい
	// swap( ) 関数実行後の
	// ( 10 ) value1 の値 	3		(11) value2 の値		5
	printf("value1:%d\n", value1);
	printf("value2:%d\n", value2);

	return  0;
}

