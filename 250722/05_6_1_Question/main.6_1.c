#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 型定義 -------------------------------------------------------------------
typedef enum { WIN, EVEN, LOSE, NUM_JUDGES, }        judge_t;  // 判定結果
typedef enum { STONE, SCISSORS, PAPER, NUM_HANDS, }  hand_t;   // 手

// 定数定義 -----------------------------------------------------------------
const char* chHands = "gcp";                        // 入力文字 グー,チョキ,パー
const char* handStrings[NUM_HANDS] = {             // 表示文字列
    "グー", "チョキ", "パー",
};
const judge_t judgeTable[NUM_HANDS][NUM_HANDS] = { // 勝敗表
    EVEN, WIN, LOSE,
    LOSE, EVEN, WIN,
    WIN, LOSE, EVEN,
};
const char* judgeStrings[NUM_JUDGES] = {           // 勝敗表示文字列
    "あなたの勝ち",
    "引き分け",
    "あなたの負け",
};

//プロンプトメッセージの表示
//戻り値・　引数　なし
void promptMessage() {
    int i;
    printf("じゃんけんを判定します。\n");
    for (i = 0; i < NUM_HANDS; i++) {
        printf("%c : %s  ", chHands[i], handStrings[i]);
    }
    printf("\n");
}

// 手を文字で入力 -----------------------------------------------------------------------------
// 戻り値 char   : 入力された手
// 引数　 prompt : 入力を促す文字列
char inputHand(const char* prompt) {
    char ch;
    printf("%s", prompt);
    fflush(stdout);
    scanf("%*[\r\n]");
    scanf("%c", &ch);
    return ch;
}

// 手を入力 -----------------------------------------------------------------------------------
// 戻り値 hand_t : 入力された手
// 引数　 prompt : 入力を促す文字列
hand_t getHand(const char* prompt) {
    hand_t hand;
    char inputCH, smallCh;
    const char* foundCh;

    inputCH =inputHand(prompt);
    //小文字化
    smallCh = tolower(inputCH);
    //gcpに存在するか判定
    foundCh = strchr(chHands, smallCh);

    //なかったら再入力
    while (foundCh==NULL) {
        printf("%c を識別できません。\n", inputCH);
        printf("もう一度、");
        inputCH = inputHand(prompt);
        //小文字化
        smallCh = tolower(inputCH);
        //gcpに存在するか判定
        foundCh = strchr(chHands, smallCh);
    }
    //見つかったら配列の何番目に入っているか計算する
    hand = (hand_t)(foundCh - chHands);

    return hand;
}

//main関数------------------------------------------------------------
int main(void) {
    //変数定義
    hand_t  myHand, otherHand;       //自分の手、相手の手
    judge_t judge;
    //入力
    promptMessage();
    myHand = getHand("自分の手を入力してください。");
    otherHand = getHand("相手の手を入力してください。");
    // 計算
    judge = judgeTable[myHand][otherHand];
    //出力
    printf("%s 対 %s で %s です。\n",
        handStrings[myHand], handStrings[otherHand], judgeStrings[judge]);
    return 0;
}