#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 処理メニュー出力 -------------------------------------------------------
// 戻り値 : なし
// 引数　 : なし
void  printPrompt(void)
{
    printf("下記の番号を入力して処理を選択してください。\n");
    printf("1 引き落とし\n");
    printf("2 振込\n");
    printf("3 残高照会\n");
    printf("4 入金\n");
    printf("番号を入力してください。( 1 - 4 ) ");
}

// メニュー番号入力 -------------------------------------------------------
// 戻り値 int : メニュー番号
// 引数　 　　: なし
int  inputMenu(void)
{
    int  selection;

    printPrompt();
    fflush(stdout);
    scanf("%d", &selection);

    return  selection;
}

// メニュー番号選択 -------------------------------------------------------
// 戻り値 int : 正しいメニュー番号
// 引数　 　　: なし
int  selectMenu(void)
{
    int  selection;

    printf("いらっしゃいませ\n");
    selection = inputMenu();
    while (!(1 <= selection && selection <= 4)) {
        printf("入力された %d は処理できません。\n", selection);
        printf("もう一度入力してください。\n");
        selection = inputMenu();
    }

    return  selection;
}


// 論理型
typedef enum { FALSE, TRUE, }  bool_t;

// 円周の長さと円の面積を求める。---------------------------------------------
// 戻り値　bool_t : 正しく計算できた TRUE, 半径が負であった FALSE
// 引数　　radius : 円の半径
// 引数　　circum : 円の円周
// 引数　　area   : 円の面積
bool_t  circle(double radius, double* circum, double* area)
{
    const double  pi = 3.14159265358979;
    bool_t        result;


    if (0 <= radius) {
        *circum = 2 * pi * radius;
        *area = pi * radius * radius;
        result = TRUE;
    }
    else {
        result = FALSE;
    }

    return  result;
}


// メイン関数 ------------------------------------------------------------
int  main(void)
{
    int  selection;
    bool_t flg;
    double length, area;

    selection = selectMenu();

    flg = circle(-1,&length,&area);
    // 以下、処理が続く。
}