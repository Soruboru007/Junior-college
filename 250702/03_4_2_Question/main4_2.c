#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 曜日型
typedef enum { SUN, MON, TUE, WED, THU, FRI, SAT } weekday_t;

//曜日を求める
//戻り値 weekday_t : 算出された曜日
//引数   year    : 曜日を求めたい年
// 　　  month   : 曜日を求めたい月
// 　　　day     : 曜日を求めたい日
weekday_t dayOfWeek(int year, int month, int day) {
	weekday_t week;
	int num;
	if (month >= 3) {
		month -= 2;
	}
	else {
		month += 10;
		year--;
	}
	num = year + year / 4 - year / 100 + year / 400 + (13 * month - 1) / 5 + day;
	week = (weekday_t)(num % 7);

	return week;
}

//0年3月1日(基準日）からの経過日数を求める
//戻り値 int　　 : 算出された曜日
//引数   year    : 日数を求めたい年
// 　　  month   : 日数を求めたい月
// 　　　day     : 日数を求めたい日
int  daysFrom031(int year, int month, int day){
	int days;
	if (month >= 3) {
		month -= 2;
	}
	else {
		month += 10;
		year--;
	}
	days = year * 365 + year / 4 - year / 100 + year / 400 + (153 * month - 151) / 5 + day;
	return days;
}

//２つの日付間の経過日数を求める
//戻り値 int　　     : 算出された曜日
//引数   preYear     : 先の年
// 　　  preMonth    : 先の月
// 　　　preDay      : 先の日
//       postYear    : 後の年
// 　　  postMonth   : 後の月
// 　　　postDay     : 後の日
int  days(int preYear, int preMonth, int preDay, int postYear, int postMonth, int postDay) {
	int days;
	days = daysFrom031(postYear, postMonth, postDay);
	days -= daysFrom031(preYear, preMonth, preDay);
	return days;
}

//メイン
int main(void) {
	// 定数宣言
	
	// 変数宣言
	int year, month;	//入力年月
	weekday_t week;		//１日の曜日
	int count;			//入力した年月の日数
	int column;			//改行用カウンタ
	int i;

	// 入力
	printf("カレンダーを表示します。\n");
	printf("年月を入力してください。(年/月)  ");
	fflush(stdout);
	scanf("%d/%d", &year, &month);

	// 計算 入力した年月の１日の曜日と、その月に何日あるかを求める
	week = dayOfWeek(year, month, 1);
	count = days(year, month, 1, year, month + 1, 1);

	// 出力
	//タイトル行
	printf("       %d 年 %d 月\n",year,month);

	//曜日見出し
	printf("sun mon tue wed thu fri sat\n");

	//１日の曜日から空白を出力する
	for (i = 0; i < week; i++) {
		printf("    ");
	}
	column = week;	//空白を出力した分改行用カウンタを増やしておく

	//入力した年月の日数分数字を出力する(７回出力したら改行する）
	for (i = 0; i < count; i++) {
		printf("%3d ", i + 1);
		if (++column >= 7) {
			column = 0;
			printf("\n");
		}
	}
	if (column > 0) {
		printf("\n");
	}
	return 0;
}
