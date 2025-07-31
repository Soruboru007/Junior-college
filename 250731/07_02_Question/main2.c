#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum { LIMIT = 100 };	//フィボナッチ数を保存する配列の上限
enum { END_VAL = 0 };	//入力の終了値

// 値の入力  5章問題2　inputValueに終了値を入力するとループを終了するよう変更をする---------------------
// 戻り値　int    : 入力された値  
// 引数　　prompt : 入力促進文字列  
// 　　 　 min    : 入力可能最小値  
// 　　 　 max    : 入力可能最大値  
//		   end    : 入力終了値
int  inputValue(const char* prompt, int min, int max, int end) {
	int  value;
	printf("%s( %d - %d, %d = 終了 ) ", prompt, min, max, end);
	fflush(stdout);
	scanf("%d", &value);
	while (!(min <= value && value <= max||value==end)) { // 終了する条件(min≦value≦max、またはvalue=max)ではないとき
		printf("入力値 %d は範囲外です。\n", value);
		printf("もう一度、");
		printf("%s( %d - %d ) ", prompt, min, max);
		fflush(stdout);
		scanf("%d", &value);
	}
	return  value;
}



// メイン関数 ------------------------------------------------------------------------------
int main(void) {
	//変数定義
	long long int fibonaccies[LIMIT];	// フィボナッチ数列の各項
	int index;							// 求めたいフィボナッチ数列の項
	int i;

	// 初期化　※ここでfibonacciesにデータを入れる
	fibonaccies[0] = fibonaccies[1] = 1;

	for (i = 2; i < LIMIT; i++) {
		fibonaccies[i] = fibonaccies[i - 1] + fibonaccies[i - 2];
	}

	//出力
	printf("フィボナッチ数列の第 n 項を求めます。\n");
	index = inputValue("n を入力してください。", 1, LIMIT, END_VAL);
	while (index != END_VAL) {
		printf("第 %d 項は、%lld です。\n", index, fibonaccies[index - 1]);
		index = inputValue("n を入力してください。", 1, LIMIT, END_VAL);
	}
	

	return 0;
}