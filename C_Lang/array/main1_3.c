#include <stdio.h>
int main(void) {
	// 定数
	enum { STRING_SIZE = 26 };	// 配列の大きさ
	enum { COLUMN_COUNT = 6 };	// 1行に表示する文字数

	const char startCH = 'a';

	// 変数定義
	char	string[STRING_SIZE];		// アルファベットを入れる配列 
	char	ch;							// 代入する文字
	int		column;
	int i;
	//初期化
	ch = startCH;
	column = 0;

	for (i = 0; i < STRING_SIZE; i++) {
		string[i] = ch++;
	}

	// 出力
	for (i = 0; i < STRING_SIZE; i++) {
		printf("%c",string[i]);
		if (COLUMN_COUNT <= ++column) {
			printf("\n");
			column = 0;
		}
	}
	printf("\n");
	string[25] = '\0';
	printf("%s", string);
	return 0;
}