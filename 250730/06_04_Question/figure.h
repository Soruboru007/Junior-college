#pragma once
// 型定義 ------------------------------------------------------------- 
typedef enum { FALSE, TRUE, }bool_t;
// 論理型 

// 定数定義 ----------------------------------------------------------- 
enum { MAX_SIZE = 40 };// 縦横の最大値 

// 画面を初期化する ----------------------------------------------------- 
// 戻り値　bool_t : 指定された大きさがスクリーンに収まっている場合は TRUE、 
//超えていれば FALSE 
// 引数　　screen : スクリーン 
// 　　　　fillChar : 埋める文字 
// 　　　　size : 大きさ 
bool_t initialize(char(*screen)[MAX_SIZE + 1], char fillChar, int size);

//画面を描画する(２次元配列を指定された行数分出力する）
// 戻り値  なし
// 引数　　screen : スクリーン 
// 　　　　size : 大きさ 
void  printScreen(const char(*screen)[MAX_SIZE + 1], int size);

// ×を描く ------------------------------------------------------------ 
// 戻り値　なし 
// 引数　　screen : スクリーン
// 　　　　drawChar : 描く文字
// 　　　　size : 大きさ
void drawEx(char(*screen)[MAX_SIZE + 1], char drawChar, int size);

//直角三角形を描く
// 戻り値　なし 
// 引数　　screen : スクリーン
// 　　　　drawChar : 描く文字
// 　　　　size : 大きさ
void drawTriangle(char(*screen)[MAX_SIZE + 1], char drawChar, int size);


// 枠を描く① ----------------------------------------------------------- 
// 戻り値　bool_t : 指定された開始位置がスクリーンに収まっている場合は TRUE、 
//超えていれば FALSE 
// 引数　　screen : スクリーン 
// 　　　　drawChar : 描く文字 
// 　　　　size : 大きさ 
// 　　　　start : 開始位置  
bool_t drawFrame1(char(*screen)[MAX_SIZE + 1], char drawChar,int size, int start);

// 枠を描く② ----------------------------------------------------------- 
// 戻り値　bool_t   : 開始位置 ≦ 終了位置なら TRUE、そうでなければ FALSE 
// 引数　　screen   : スクリーン 
// 　　　　drawChar : 描く文字 
// 　　　　start    : 開始位置  
// 　　　　end      : 終了位置 
bool_t  drawFrame2(char(*screen)[MAX_SIZE + 1], char drawChar,   int start, int end);