#include <stdio.h>
int main(void) {
	// 定数
	enum { STRING_SIZE = 26 };	// 配列の大きさ
	enum { COLUMN_COUNT = 6 };	// 1行に表示する文字数
	enum { COUNT_RETURN = (STRING_SIZE - 1) / COLUMN_COUNT + 1 };		// 改行する回数

	enum { ARRAY_SIZE = STRING_SIZE + COUNT_RETURN + 1 };
	const char startCH = 'a';

	// 変数定義
	char	string[ARRAY_SIZE];		// アルファベットを入れる配列 
	char	ch;							// 代入する文字
	int		column;
	int i;
	int index;						//データを代入する配列の添え字（要素の位置）

	//初期化
	ch = startCH;
	column = 0;
	index = 0;

	//値の代入	26回の繰り返しの中で改行も代入する
	for (i = 0; i < STRING_SIZE; i++) {
		string[index++] = ch++;
		if (COLUMN_COUNT <= ++column) { //6回代入したら
			string[index++] = '\n';
			column = 0;
		}
	}
	if (0 < column) {
		string[index++] = '\n';
	}
	string[index] = '\0';
	// 出力
	printf("%s", string); //string配列の\0まで全部文字を出力する

	return 0;
}