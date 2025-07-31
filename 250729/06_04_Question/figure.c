#include"figure.h"
#include<stdio.h>

// 画面を初期化する ----------------------------------------------------- 
// 戻り値　bool_t : 指定された大きさがスクリーンに収まっている場合は TRUE、 
//超えていれば FALSE 
// 引数　　screen : スクリーン 
// 　　　　fillChar : 埋める文字 
// 　　　　size : 大きさ 
bool_t initialize(char(*screen)[MAX_SIZE + 1], char fillChar, int size) {
	int i, j;
	bool_t result=FALSE;

	if (0 <= size && size <= MAX_SIZE) { //指定されたsizeが０～４０の時だけ初期化
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				screen[i][j] = fillChar;
			}
			screen[i][j] = '\0';
		}
		result = TRUE;
	}

	return result;
}

//画面を描画する(２次元配列を指定された行数分出力する）
// 戻り値  なし
// 引数　　screen : スクリーン 
// 　　　　size : 大きさ 
void  printScreen(const char(*screen)[MAX_SIZE + 1], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s\n", screen[i]);
	}
}

// ×を描く ------------------------------------------------------------ 
// 戻り値　なし 
// 引数　　screen : スクリーン
// 　　　　drawChar : 描く文字
// 　　　　size : 大きさ
void drawEx(char(*screen)[MAX_SIZE + 1], char drawChar, int size) {
	int i;
	int c;
	c = size;
	for (i = 0; i < size; i++) {
		screen[i][i] = drawChar;
		screen[i][--c] = drawChar;
	}

}

//直角三角形を描く
// 戻り値　なし 
// 引数　　screen : スクリーン
// 　　　　drawChar : 描く文字
// 　　　　size : 大きさ
void drawTriangle(char(*screen)[MAX_SIZE + 1], char drawChar, int size) {
	int i, j;
	int c;
	for (i = 0; i < size; i++) {
		c = size;
		for (j = 0; j < (i + 1); j++) {
			screen[i][--c] = drawChar;
		}
	}
}

// 枠を描く① ----------------------------------------------------------- 
// 戻り値　bool_t : 指定された開始位置がスクリーンに収まっている場合は TRUE、 
//超えていれば FALSE 
// 引数　　screen : スクリーン 
// 　　　　drawChar : 描く文字 
// 　　　　size : 大きさ 
// 　　　　start : 開始位置  
bool_t drawFrame1(char(*screen)[MAX_SIZE + 1], char drawChar, int size, int start) {

}

// 枠を描く② ----------------------------------------------------------- 
// 戻り値　bool_t   : 開始位置 ≦ 終了位置なら TRUE、そうでなければ FALSE 
// 引数　　screen   : スクリーン 
// 　　　　drawChar : 描く文字 
// 　　　　start    : 開始位置  
// 　　　　end      : 終了位置 
bool_t  drawFrame2(char(*screen)[MAX_SIZE + 1], char drawChar, int start, int end) {

}
