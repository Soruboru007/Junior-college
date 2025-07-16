#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	// 定数定義	
	// 変数定義
	int month;

	// 入力
	printf("月を入力してください。");
	fflush(stdout);
	scanf("%d", &month);

	while (!(1 <= month && month <= 12)) {
		printf("誤った月です。\n");
		printf("もう一度入力してください。");
		fflush(stdout);
		scanf("%d", &month);
	}
	// 出力
	printf("%d は", month);
	printf("正しい月です。\n");


	return 0;
}