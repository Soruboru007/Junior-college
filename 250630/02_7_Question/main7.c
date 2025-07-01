#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  main(void)
{
	// 定数定義
	// 手の種類
	typedef enum {
		UNKNOWN = -1,    // 不明な手
		STONE,           // 石
		SCISSORS,        // はさみ
		PAPER,           // 紙
		NUM_HANDTYPE,    // 手の数
	}  handType_t;

	// 手を表す入力文字
	const char  inputChars[NUM_HANDTYPE + 1] = "gcp";
	// 手を表す文字列
	const char  handStrings[NUM_HANDTYPE][3 * 2 + 1] = {
		"グー", "チョキ", "パー",
	};
	// 判定の種類
	typedef enum {
		WIN,            // 勝ち
		EVEN,           // 引き分け
		LOSE,           // 負け
		NUM_JUDGETYPE,  // 判定の種類数
	}  judge_t;

	// 判定結果を表す文字列
	const char  judgeStrings[NUM_JUDGETYPE][6 * 2 + 1] = {
		"あなたの勝ち", "あいこ", "あなたの負け",
	};

	// 勝敗テーブル
	const judge_t  judgeTable[NUM_HANDTYPE][NUM_HANDTYPE] = {
		EVEN,WIN,LOSE,
		LOSE,EVEN,WIN,
		WIN,LOSE,EVEN,
	};

	// 変数定義
	int i;
	char inputCh, smallCh;			//入力値、小文字化した入力値
	handType_t myHand, otherHand;	//自分の手と相手の手
	judge_t judge;					//勝敗を保存

	// 入力
	// ①　「じゃんけんを判定します。」とグー、チョキ、パーの入力文字を表示する。
	printf("じゃんけんを判定します。\n");
	for (i = 0; i < NUM_HANDTYPE; i++) {
		printf("%c : %s ", inputChars[i], handStrings[i]);
	}
	printf("\n");
	//自分の手入力
	// ②　入力を受け付ける。
	printf("自分の手を入力してください。(%s)", inputChars);
	fflush(stdout);
	scanf("%*[\r\n]");
	scanf("%c", &inputCh);
	// ③　大文字 → 小文字変換する。
	smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
	// ④　手の判別を行う。（gcp → STONE, SCISSORS, PAPER 変換をする。）
	myHand = UNKNOWN;
	for (i = 0; i < NUM_HANDTYPE; i++) {
		if (inputChars[i] == smallCh) {
			myHand = (handType_t)i;
			break;
		}
	}
	// ⑤　while(手が判別できない) {
	while (myHand == UNKNOWN) {
		// ⑥　　　再入力を促す。
		printf("%c を識別できません。\n", inputCh);
		printf("もう一度自分の手を入力してください。(%s) \n ", inputChars);
		// ⑦　　　②～④を行う。（コードそのものをそのままコピーしてよい。）
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c", &inputCh);
		// ③　大文字 → 小文字変換する。
		smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
		// ④　手の判別を行う。（gcp → STONE, SCISSORS, PAPER 変換をする。）
		myHand = UNKNOWN;
		for (i = 0; i < NUM_HANDTYPE; i++) {
			if (inputChars[i] == smallCh) {
				myHand = (handType_t)i;
				break;
			}
		}

	}

	//相手の手入力
	// ②　入力を受け付ける。
	printf("相手の手を入力してください。(%s)", inputChars);
	fflush(stdout);
	scanf("%*[\r\n]");
	scanf("%c", &inputCh);
	// ③　大文字 → 小文字変換する。
	smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
	// ④　手の判別を行う。（gcp → STONE, SCISSORS, PAPER 変換をする。）
	otherHand = UNKNOWN;
	for (i = 0; i < NUM_HANDTYPE; i++) {
		if (inputChars[i] == smallCh) {
			otherHand = (handType_t)i;
			break;
		}
	}
	// ⑤　while(手が判別できない) {
	while (otherHand == UNKNOWN) {
		// ⑥　　　再入力を促す。
		printf("%c を識別できません。\n", inputCh);
		printf("もう一度相手の手を入力してください。(%s) \n", inputChars);
		// ⑦　　　②～④を行う。（コードそのものをそのままコピーしてよい。）
		fflush(stdout);
		scanf("%*[\r\n]");
		scanf("%c", &inputCh);
		// ③　大文字 → 小文字変換する。
		smallCh = inputCh + ('A' <= inputCh && inputCh <= 'Z' ? 'a' - 'A' : 0);
		// ④　手の判別を行う。（gcp → STONE, SCISSORS, PAPER 変換をする。）
		otherHand = UNKNOWN;
		for (i = 0; i < NUM_HANDTYPE; i++) {
			if (inputChars[i] == smallCh) {
				otherHand = (handType_t)i;
				break;
			}
		}

	}

	// 計算
	judge = judgeTable[myHand][otherHand];

	// 出力
	printf("%s 対 %s で %s です。\n", handStrings[myHand], handStrings[otherHand], judgeStrings[judge]);

	return 0;
}