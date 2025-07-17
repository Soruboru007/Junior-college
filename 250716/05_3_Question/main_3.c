#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//定数
typedef enum { FALSE, TRUE } bool_t;

// 商とあまりを求める関数　０の時割らない処理を忘れないように！
bool_t divide(int num1, int num2, int* quot, int* remain) {
	bool_t result = FALSE;
	if (num2 != 0) {
		*quot = num1 / num2;
		*remain = num1 % num2;
		result = TRUE; //計算できたときに結果をTRUEにする
	}
	return result;
}

int main(void) {
	//変数宣言
	int num1;		//割られる数
	int num2;		//割る数
	int quot;		// 商
	int	remain;		// 余り
	bool_t result;	//計算できたか

	// 入力
	printf("2 つの数の商と余りを求めます。\n");
	printf("割られる数を入力してください。");
	fflush(stdout);
	scanf("%d", &num1);
	printf("割る数を入力してください。");
	fflush(stdout);
	scanf("%d", &num2);

	//商と余り求める（計算できたかもここで求められる）
	result = divide(num1, num2, &quot, &remain);

	// 出力　計算できるか否かで分岐
	if (result) {
		printf("%d を %d で割った 商  は %d です。\n", num1, num2, quot);
		printf("%d を %d で割った余り は %d です。\n", num1, num2, remain);
	}
	else {
		printf("割る数が 0 なので計算できません。\n");
	}
	return 0;
}